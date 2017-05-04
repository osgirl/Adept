package adept.utilities;

/*-
 * #%L
 * adept-kb
 * %%
 * Copyright (C) 2012 - 2017 Raytheon BBN Technologies
 * %%
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * #L%
 */

import com.google.common.base.Objects;
import com.google.common.base.Optional;
import com.google.common.collect.ImmutableSet;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;

import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.CommandLineParser;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Option;
import org.apache.commons.cli.Options;
import org.apache.commons.collections4.MultiValuedMap;
import org.apache.commons.collections4.multimap.ArrayListValuedHashMap;
import org.apache.commons.lang3.StringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import adept.common.KBID;
import adept.common.OntType;
import adept.kbapi.KB;
import adept.kbapi.KBConfigurationException;
import adept.kbapi.KBEntity;
import adept.kbapi.KBEvent;
import adept.kbapi.KBOntologyMap;
import adept.kbapi.KBParameters;
import adept.kbapi.KBPredicateArgument;
import adept.kbapi.KBProvenance;
import adept.kbapi.KBQueryException;
import adept.kbapi.KBRelation;
import adept.kbapi.KBRelationArgument;
import adept.kbapi.KBTextProvenance;
import adept.kbapi.KBThing;
import adept.kbapi.KBUpdateException;

import static com.google.common.base.Preconditions.checkNotNull;

/**
 * Utility that connects to a database and dumps some information for human analysis.
 */
public class TacFormatConverter {
    /**
     * Explicit UTF-8 byte-order marks that we need to insert to make Microsoft Excel
     * automatically detect UTF-8 encoding.
     */
    private static final String bom = "\uFEFF";
    /**
     * Log report generation.
     */
    private static final Logger log = LoggerFactory.getLogger(TacFormatConverter.class);
    /**
     * Connection to knowledge base.
     */
    private KB kb;
    /**
     * Directory where analyses will be written.
     */
    private final File outputDirectory;
    /**
     * Analysis run name.
     */
    private final String runName;
    /**
     * Whether to resume a previously output run.
     */
    private final boolean resumeRun;
    /**
     * How many objects of each type to sample.
     */
    private final int sampleSize;
    /**
     * Maximum count of justifications to generate for each KB item.
     */
    private static final int maxJustifications = 10;
    /**
     * Maximum count of justifications to generate for each slotfill argument.
     */
    private static final int maxArgJustifications = 2;

    /**
     * Map of names of types to TAC abbreviations of types
     */
    private static final Map<String, String> typeToCodeMap;
    static
    {
        typeToCodeMap = new HashMap<String, String>();
        typeToCodeMap.put("GeoPoliticalEntity", "GPE");
        typeToCodeMap.put("Person", "PER");
        typeToCodeMap.put("Organization", "ORG");
        typeToCodeMap.put("Location", "LOC");
    }
    /**
     * Open a connection to the specified knowledge base.
     *
     * @param parameters A knowledge base configuration read from XML.
     * @throws KBConfigurationException
     */
    public TacFormatConverter(KBParameters parameters, File outputDirectory, String runName, boolean resumeRun, int sampleSize) throws KBConfigurationException {
        this.kb = new KB(parameters);
        this.outputDirectory = new File(outputDirectory, runName);
        this.runName = runName;
        this.resumeRun = resumeRun;
        this.sampleSize = sampleSize;
    }

    /**
     * Close knowledge base connection; used when handling exceptions.
     */
    public void close() {
        try {
            if (kb != null) {
                kb.close();
            }
        } catch (KBUpdateException e) {
            // We can let close silently fail
        }
    }

    public Map<KBSummary.ArtifactType, KBSummary> generate() throws KBQueryException, IOException {
        // Make sure output directory exists
        if (!outputDirectory.exists()) {
            outputDirectory.mkdirs();
        }

        // Run each kind of analysis
        log.info("Generating report for {}", runName);
        log.info("Output directory is {}", outputDirectory);
        if (resumeRun) {
            log.info("Resuming existing run");
        }

        Map<KBSummary.ArtifactType, KBSummary> kbSummaryMap = new HashMap<>();

        // Run beliefs and sentiments first since they might require a relation or event
        MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> beliefTargets = generateSlotfills("beliefs", "adept-core:Belief",kbSummaryMap);
        MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> sentimentTargets = generateSlotfills("sentiments",
                "adept-core:Sentiment",kbSummaryMap);

        // Run relations and events next since they require entities
        List<KBID> requiredRelations = new ArrayList<>();
        requiredRelations.addAll(beliefTargets.get(KBRelation.class));
        requiredRelations.addAll(sentimentTargets.get(KBRelation.class));
        MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> relationTargets = generateSlotfills("relations", "adept-base:Relation",
                new String[]{
                        "adept-base:Event",
                        "adept-base:TemporalSpan",
                        "adept-core:Belief",
                        "adept-core:Sentiment",
                },
                requiredRelations,kbSummaryMap);
        List<KBID> requiredEvents = new ArrayList<>();
        requiredEvents.addAll(beliefTargets.get(KBEvent.class));
        requiredEvents.addAll(sentimentTargets.get(KBEvent.class));
        MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> eventTargets = generateSlotfills("events", "adept-base:Event",
                requiredEvents,kbSummaryMap);

        // Run entities last since the others all require them
        List<KBID> requiredEntities = new ArrayList<>();
        requiredEntities.addAll(beliefTargets.get(KBEntity.class));
        requiredEntities.addAll(sentimentTargets.get(KBEntity.class));
        requiredEntities.addAll(relationTargets.get(KBEntity.class));
        requiredEntities.addAll(eventTargets.get(KBEntity.class));
        generateColdStart(requiredEntities, requiredRelations, kbSummaryMap);
        return kbSummaryMap;
    }

    protected Set<String> getUniqueArgumentJustifications(final KBPredicateArgument pa, Set<KBID> uniqueProvenanceIDs) throws KBQueryException {
        Set<String> unusedUniqueDocumentIDs = new HashSet<String>();
        Set<String> unusedUniqueText = new HashSet<String>();
        return getUniqueJustificationsWithText(pa, maxArgJustifications, unusedUniqueDocumentIDs, unusedUniqueText, uniqueProvenanceIDs);
    }

    protected Set<String> getUniqueJustificationsWithText(final KBPredicateArgument pa,
                                                          final int nJustifications, Set<String> uniqueDocumentIDs,
                                                          Set<String> uniqueText, Set<KBID> uniqueProvenanceIDs) throws KBQueryException {
        Iterator<KBProvenance> provenances = pa.getProvenances().iterator();
        Set<String> uniqueJustifications = new HashSet<String>();
        while (provenances.hasNext()) {
            KBTextProvenance textProvenance = (KBTextProvenance) provenances.next();
            String documentID = textProvenance.getDocumentID();
            String text = textProvenance.getValue();
            if (text == null) {
                log.warn("Provenance string for {} {} was null", pa.getClass().getName(), pa.getKBID().getObjectID());
            } else if (text.isEmpty()) {
                log.warn("Provenance string for {} {} was empty", pa.getClass().getName(), pa.getKBID().getObjectID());
            }

            // Accumulate in a HashSet to get unique justifications up to specified maximum

                if (uniqueJustifications.size() < nJustifications) {
                    uniqueJustifications.add(  String.format("%s:%d-%d %s",
                            documentID,
                            textProvenance.getBeginOffset(),
                            textProvenance.getEndOffset(),
                            text
                    ));

            }

            // Accumulate some combined stats
            uniqueDocumentIDs.add(documentID);
            uniqueText.add(text);
            uniqueProvenanceIDs.add(textProvenance.getKBID());
        }
        return uniqueJustifications;
    }

    protected Set<String> getUniqueJustifications(final KBPredicateArgument pa,
                                                          final int nJustifications, Set<String> uniqueDocumentIDs,
                                                          Set<String> uniqueText, Set<KBID> uniqueProvenanceIDs) throws KBQueryException {
        Iterator<KBProvenance> provenances = pa.getProvenances().iterator();
        Set<String> uniqueJustifications = new HashSet<String>();
        int count = 0;
        while (provenances.hasNext() && count < 4) {
            count++;

            KBTextProvenance textProvenance = (KBTextProvenance) provenances.next();
            String documentID = textProvenance.getDocumentID();

            // Accumulate in a HashSet to get unique justifications up to specified maximum
            if (uniqueJustifications.size() < nJustifications) {
                uniqueJustifications.add(  String.format("%s:%d-%d",
                        documentID,
                        textProvenance.getBeginOffset(),
                        textProvenance.getEndOffset()
                ));
            }

            // Accumulate some combined stats
            uniqueDocumentIDs.add(documentID);
            uniqueProvenanceIDs.add(textProvenance.getKBID());
        }
        return uniqueJustifications;
    }

    protected Set<List<String>> getEntityMentionFields(final KBPredicateArgument pa,
                                                       final int nJustifications, Set<String> uniqueDocumentIDs,
                                                       Set<String> uniqueText, Set<KBID> uniqueProvenanceIDs) throws KBQueryException {
        Iterator<KBProvenance> provenances = pa.getProvenances().iterator();
        Set<List<String>> uniqueJustifications = new HashSet();
        while (provenances.hasNext()) {
            KBTextProvenance textProvenance = (KBTextProvenance) provenances.next();
            String documentID = textProvenance.getDocumentID();
            String text = textProvenance.getValue();
            if (text == null) {
                log.warn("Provenance string for {} {} was null", pa.getClass().getName(), pa.getKBID().getObjectID());
            } else if (text.isEmpty()) {
                log.warn("Provenance string for {} {} was empty", pa.getClass().getName(), pa.getKBID().getObjectID());
            }

            // Accumulate in a HashSet to get unique justifications up to specified maximum

            if (uniqueJustifications.size() < nJustifications) {
                String justification = String.format("%s:%d-%d",
                        documentID,
                        textProvenance.getBeginOffset(),
                        textProvenance.getEndOffset());
                ArrayList<String> just = new ArrayList<String>();
                just.add(justification);
                just.add(text);
                uniqueJustifications.add(just);
            }

            // Accumulate some combined stats
            uniqueDocumentIDs.add(documentID);
            uniqueText.add(text);
            uniqueProvenanceIDs.add(textProvenance.getKBID());
        }
        return uniqueJustifications;
    }

    protected String getReferenceString(KBThing thing) {
        return String.format("%s %s", thing.getClass().getName(), thing.getCanonicalString());
    }

    protected String getReferenceString(KBEntity entity) {
        StringBuilder builder = new StringBuilder();
        builder.append(entity.getClass().getName());
        for (Map.Entry<OntType, Float> typeEntry : entity.getTypes().entrySet()) {
            builder.append(String.format(" %s[%f]", typeEntry.getKey().getType(), typeEntry.getValue()));
        }
        return builder.toString();
    }

    protected String getReferenceString(KBRelation relation) {
        return String.format("%s %s", relation.getClass().getName(), relation.getType().getType());
    }

    protected String getReferenceString(KBRelationArgument argument) {
        return String.format("%s %s", argument.getClass().getName(), argument.getRole().getType());
    }

    protected Set<String> readExistingIDs(File outputFile, int idColumn) throws IOException {
        Set<String> existingIDs = new HashSet<String>();
        if (resumeRun) {
            try {
                CSVReader reader = new CSVReader(new FileReader(outputFile));
                String[] csvFields;
                while ((csvFields = reader.readNext()) != null) {
                    if (csvFields.length > idColumn && !csvFields[idColumn].equals("ID")) {
                        existingIDs.add(csvFields[idColumn]);
                    }
                }
                reader.close();
            } catch (FileNotFoundException e) {
                log.error("--resume specified but output doesn't exist", e);
            }
        }
        return existingIDs;
    }

    protected void generateColdStart(final List<KBID> requiredEntities, final List<KBID> requiredRelations,
                                     Map<KBSummary.ArtifactType,KBSummary> kbSummaryMap) throws KBQueryException,
            IOException {
        // Load any existing object IDs
        File outputFile = new File(outputDirectory, String.format("%s.ColdStart.tsv", runName));
        boolean appending = resumeRun && outputFile.exists();
        Set<String> existingIDs = readExistingIDs(outputFile, 2);
        if (existingIDs.size() > 0) {
            log.info("Read {} existing entities", existingIDs.size());
        }

        // Open the output CSV file with headers
        FileWriter fileWriter = new FileWriter(outputFile, resumeRun);
        if (!appending) {
            fileWriter.write(bom);
        }
        CSVWriter writer = new CSVWriter(fileWriter, '\t', CSVWriter.NO_QUOTE_CHARACTER, CSVWriter.NO_ESCAPE_CHARACTER);
        writer.writeNext(new String[] {runName});

        // Select entity IDs
        List<KBID> entityIDs = kb.getKBIDsByType("adept-base:Entity", new String[] {});
        int written = 0;
        log.info("Found {} entities", entityIDs.size());
        if (sampleSize > 0) {
            Collections.shuffle(entityIDs);
            entityIDs = entityIDs.subList(0, Math.min(entityIDs.size(), sampleSize));
            log.info("Randomly selected {} entities", entityIDs.size());
            if (requiredEntities.size() > 0) {
                entityIDs.addAll(requiredEntities);
                log.info("Injected {} required entities", requiredEntities.size());
            }
        }

        int maxDistinctDocs=0;
        int maxUniqueStrings=0;
        ImmutableSet.Builder<KBSummary.TypeWithOptionalArgTypes> typesForSummary = ImmutableSet
                .builder();

        // Loop over all of the entity IDs
        for (KBID entityID : entityIDs) {
            // Check if we've already loaded this slotfill
            if (existingIDs.contains(entityID.getObjectID())) {
                continue;
            }

            // Get the entity by ID
            KBEntity entity;
            try {
                entity = kb.getEntityById(entityID);
            } catch (Exception e) {
                log.error("Could not get Entity {}", entityID.getObjectID(), e);
                continue;
            }

            // Convert interesting entity fields
            List<String> types = new ArrayList<String>();
            for (Map.Entry<OntType, Float> entry : entity.getTypes().entrySet()) {
                types.add(entry.getKey().getType());
                typesForSummary.add(KBSummary.TypeWithOptionalArgTypes.create(entry.getKey().getType(),
                        Optional.absent()));
            }

            // Accumulate and convert provenances
            Set<String> uniqueDocumentIDs = new HashSet<String>();
            Set<String> uniqueText = new HashSet<String>();
            Set<KBID> uniqueProvenanceIDs = new HashSet<KBID>();
            Set<List<String>> entityMentionFields = getEntityMentionFields(entity, maxJustifications, uniqueDocumentIDs, uniqueText, uniqueProvenanceIDs);

            List<String> line1 = new ArrayList<String>();
            line1.add(String.format(":%s", entity.getKBID().getObjectID()));
            line1.add("type");
            String t = types.get(0);
            if (types.size() > 1){
                for ( String type : types) {
                    if (typeToCodeMap.containsKey(type)) {
                        t = type;
                        break;
                    }
                }
            }
            line1.add(typeToCodeMap.get(t));

            String[] csvFields = new String[line1.size()];
            line1.toArray(csvFields);
            writer.writeNext(csvFields, false);

            for ( List<String> justification : entityMentionFields ) {
                if(uniqueDocumentIDs.size()>maxDistinctDocs){
                    maxDistinctDocs=uniqueDocumentIDs.size();
                }
                if(uniqueText.size()>maxUniqueStrings){
                    maxUniqueStrings=uniqueText.size();
                }

                List<String> line2 = new ArrayList<String>();
                line2.add(String.format(":%s", entity.getKBID().getObjectID()));
                line2.add("canonical_mention");
                line2.add(String.format("\"%s\"", entity.getCanonicalString().replace('\n', ' ')));
                line2.add(justification.get(0));

                List<String> line3 = new ArrayList<String>();
                line3.add(String.format(":%s", entity.getKBID().getObjectID()));
                line3.add("mention");
                line3.add(String.format("\"%s\"", justification.get(1).replace('\n', ' ')));
                line3.add(justification.get(0));

                // Convert to CSV
                csvFields = new String[line2.size()];
                line2.toArray(csvFields);
                writer.writeNext(csvFields, false);
                csvFields = new String[line3.size()];
                line3.toArray(csvFields);
                writer.writeNext(csvFields, false);
                written++;
            }

        }

        // Now it's time to print the relations
            printRelations(requiredRelations, writer, "adept-base:Relation",
                new String[]{
                        "adept-base:Event",
                        "adept-base:TemporalSpan",
                        "adept-core:Belief",
                        "adept-core:Sentiment",
                });

        // Done
        writer.close();
    }

    protected HashMap<Optional<String>, KBRelationArgument> getRelationFields(KBOntologyMap ontologyMap, KBRelation slotfill){
        HashMap<Optional<String>, KBRelationArgument> hash = new HashMap<>();
        Integer count = 0;
        for ( KBRelationArgument arg : slotfill.getArguments() ) {
            if (!(ontologyMap.getTypeforKBRole(slotfill.getType(), arg.getRole()).equals(Optional.of("arg-1|arg-2")))) {
                hash.put(ontologyMap.getTypeforKBRole(slotfill.getType(), arg.getRole()), arg);
            } else {
                count++;
                hash.put(Optional.of(String.format("arg-%s", count.toString())), arg);
            }
        }
        return hash;
    }
    protected void printRelations(final List<KBID> requiredItems, CSVWriter writer, String
            slotfillType, final String[] ignoredTypes) throws KBQueryException, IOException {
        // Load any existing object IDs
        String KBExtractionType = "relations";

            // Select entity IDs
            List<KBID> ids = kb.getKBIDsByType(slotfillType, ignoredTypes);
            log.info("Found {} {}", ids.size(), KBExtractionType);
            if (sampleSize > 0) {
                Collections.shuffle(ids);
                ids = ids.subList(0, Math.min(ids.size(), sampleSize));
                log.info("Randomly selected {} {}", ids.size(), KBExtractionType);
                if (requiredItems.size() > 0) {
                    ids.addAll(requiredItems);
                    log.info("Injected {} required {}", requiredItems.size(), KBExtractionType);
                }
            }
            int missingArgs = 0;
            // Loop over all of the event IDs
            for (KBID id : ids) {
                // Check if we've already loaded this relation
//                if (existingIDs.contains(id.getObjectID())) {
//                    continue;
//                }

                // Get the relation by ID
                KBRelation relation;
                try {
                        relation = kb.getRelationById(id);
                } catch (IllegalArgumentException e) {
                    throw e;
                } catch (Exception e) {
                    log.error("Could not get KB object {}", id.getObjectID(), e);
                    continue;
                }


                // Convert interesting relation fields
                List<String> fields = new ArrayList<String>();
                KBOntologyMap ontologyMap = KBOntologyMap.getTACOntologyMap();
                HashMap<Optional<String>, KBRelationArgument> argumentHashMap = getRelationFields(ontologyMap, relation);
                String arg1;
                String arg2;
                try {
                    arg1 = argumentHashMap.get(Optional.of("arg-1")).getKBID().getObjectID();
                    arg2 = argumentHashMap.get(Optional.of("arg-2")).getKBID().getObjectID();
                } catch (NullPointerException e) {
//                    System.out.println("Missing an argument. Relation type and present arguments are:");
//                    System.out.println(relation.getType().getType());
//                    for ( KBRelationArgument arg : relation.getArguments() ){
//                        System.out.println(arg.getRole().getType());
//                    }
//                    missingArgs++;
                    continue;
                }


                //First field: unique main argument's ID
                fields.add(String.format(":%s", arg1));

                //Second field: type of relation
                KBEntity entity = null;
                try {
                    KBRelationArgument kbArg = argumentHashMap.get(Optional.of("arg-2"));
                    if (kbArg.getTarget() instanceof KBEntity) {
                        entity = (KBEntity) kbArg.getTarget();
                    }
                } catch (IllegalArgumentException e) {
                    throw e;
                } catch (Exception e) {
                    log.error("Could not get KB object {}", id.getObjectID(), e);
                    continue;
                }
                if (ontologyMap.getTypeStringForKBType(relation.getType()).isPresent()) {
                    if (relation.getType().getType().equals("OrgHeadquarter")){
                        for ( OntType type : entity.getTypes().keySet() ) {
                            if (type.getType().equals("City")){
                                fields.add("org:city_of_headquarters");
                                break;
                            } else if (type.getType().equals("Country")){
                                fields.add("org:stateprovince_of_headquarters");
                                break;
                            } else if (type.getType().equals("Country")) {
                                fields.add("org:country_of_headquarters");
                                break;
                            }
                        }
                    } else if (relation.getType().getType().equals("Resident")){
                        for ( OntType type : entity.getTypes().keySet() ) {
                                if (type.getType().equals("City")){
                                    fields.add("org:city_of_residence");
                                    break;
                                } else if (type.getType().equals("Country")){
                                    fields.add("org:stateprovince_of_residence");
                                    break;
                                } else if (type.getType().equals("Country")) {
                                    fields.add("org:country_of_residence");
                                    break;
                                }
                            }
                    } else {
                        String f = ontologyMap.getTypeStringForKBType(relation.getType()).get();
                        if (f.equals("")) {
                            System.out.println(relation.getKBID().getObjectID());
                            System.out.println(relation.getType().getType());
                        }
                        fields.add(f);
                    }
                } else {
                    System.out.println(String.format("Type missing from adept-to-tac.xml: %s", relation.getType().getType()));
                }

                //Third field: Secondary argument's unique ID
                fields.add(String.format(":%s", arg2));

                // Provenances
                Set<String> uniqueDocumentIDs = new HashSet<String>();
                Set<String> uniqueText = new HashSet<String>();
                Set<KBID> uniqueProvenanceIDs = new HashSet<KBID>();
                Set<String> uniqueJustifications = getUniqueJustifications(relation, maxJustifications, uniqueDocumentIDs, uniqueText, uniqueProvenanceIDs);

                String join = StringUtils.join(uniqueJustifications, ",");
                fields.add(join);

                // confidence
                fields.add(Float.toString(relation.getConfidence()));

                // Convert to CSV
                String[] csvFields = new String[fields.size()];
                fields.toArray(csvFields);
                writer.writeNext(csvFields, false);
            }
    }

    protected MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> generateSlotfills(String outputFilePrefix, String
            slotfillType, Map<KBSummary.ArtifactType,KBSummary> kbSummaryMap) throws KBQueryException, IOException {
        return generateSlotfills(outputFilePrefix, slotfillType, new String[]{}, new ArrayList<KBID>(),
                kbSummaryMap);
    }

    protected MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> generateSlotfills(String outputFilePrefix, String
            slotfillType, Map<KBSummary.ArtifactType,KBSummary> kbSummaryMap, final String[]
                                                                                                   ignoredTypes) throws KBQueryException, IOException {
        return generateSlotfills(outputFilePrefix, slotfillType, ignoredTypes, new ArrayList<KBID>(), kbSummaryMap);
    }

    protected MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> generateSlotfills(String outputFilePrefix, String
            slotfillType, final List<KBID> requiredItems, Map<KBSummary.ArtifactType,KBSummary> kbSummaryMap) throws KBQueryException, IOException {
        return generateSlotfills(outputFilePrefix, slotfillType, new String[] {}, requiredItems,kbSummaryMap);
    }

    protected MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> generateSlotfills(String outputFilePrefix, String
            slotfillType, final String[] ignoredTypes, final List<KBID> requiredItems, Map<KBSummary.ArtifactType,KBSummary> kbSummaryMap) throws KBQueryException, IOException {
        // Load any existing object IDs
        File outputFile = new File(outputDirectory, String.format("%s.%s.tsv", runName, outputFilePrefix));
        boolean appending = resumeRun && outputFile.exists();
        Set<String> existingIDs = readExistingIDs(outputFile, 1);
        if (existingIDs.size() > 0) {
            log.info("Read {} existing {}", existingIDs.size(), outputFilePrefix);
        }

        // Open the output CSV file with headers
        FileWriter fileWriter = new FileWriter(outputFile, resumeRun);
        if (!appending) {
            fileWriter.write(bom);
        }

        int count=0;
        float minConfidence=Float.MAX_VALUE;
        float maxConfidence=Float.MIN_VALUE;
        int minNumArguments=Integer.MAX_VALUE;
        int maxNumArguments=0;
        int maxMentionCount=0;
        int maxDistinctDocs=0;
        int written = 0;

        ImmutableSet.Builder<KBSummary.TypeWithOptionalArgTypes> typesForSummary = ImmutableSet
                .builder();

        KBSummary.ArtifactType artifactType = KBSummary.ArtifactType.RELATION;

        final int maxArguments = 5;

        // Accumulate targeted objects
        MultiValuedMap<Class<? extends KBPredicateArgument>, KBID> slotfillTargetIDs = new ArrayListValuedHashMap<>();

        try (CSVWriter writer = new CSVWriter(fileWriter, '\t')) {
            final int nFields = 6;
            final int nArgFields = 4;
            String[] csvFields = new String[nFields + maxJustifications + maxArguments*(nArgFields + maxArgJustifications)];
            csvFields[0] = "Type";
            csvFields[1] = "ID";
            csvFields[2] = "Confidence";
            csvFields[3] = "# Mentions";
            csvFields[4] = "# Unique Docs";
            int i = 5;
            for (int j = 1; j <= maxJustifications; i++, j++) {
                csvFields[i] = String.format("Justification %d", j);
            }
            csvFields[i] = "# Arguments";
            i++;
            for (int a = 1; a <= maxArguments; a++) {
                csvFields[i] = String.format("Arg %d Role", a);
                csvFields[i + 1] = String.format("Arg %d Confidence", a);
                csvFields[i + 2] = String.format("Arg %d ID", a);
                if (outputFilePrefix.equals("beliefs") || outputFilePrefix.equals("sentiments")) {
                    csvFields[i + 3] = String.format("Arg %d Type", a);
                } else {
                    csvFields[i + 3] = String.format("Arg %d Canonical String", a);
                }
                i += nArgFields;
                for (int j = 1; j <= maxArgJustifications; i++, j++) {
                    csvFields[i] = String.format("Arg %d Justification %d", a, j);
                }
            }
            if (!appending) {
                writer.writeNext(csvFields, false);
            }

            // Select entity IDs
            List<KBID> ids = kb.getKBIDsByType(slotfillType, ignoredTypes);
            log.info("Found {} {}", ids.size(), outputFilePrefix);
            if (sampleSize > 0) {
                Collections.shuffle(ids);
                ids = ids.subList(0, Math.min(ids.size(), sampleSize));
                log.info("Randomly selected {} {}", ids.size(), outputFilePrefix);
                if (requiredItems.size() > 0) {
                    ids.addAll(requiredItems);
                    log.info("Injected {} required {}", requiredItems.size(), outputFilePrefix);
                }
            }

            // default type

            // Loop over all of the event IDs
            for (KBID id : ids) {
                // Check if we've already loaded this slotfill
                if (existingIDs.contains(id.getObjectID())) {
                    continue;
                }

                // Get the slotfill by ID
                KBRelation slotfill;
                try {
                    if (outputFilePrefix.equals("relations")) {
                        slotfill = kb.getRelationById(id);
                        artifactType= KBSummary.ArtifactType.RELATION;
                    } else if (outputFilePrefix.equals("events")) {
                        slotfill = kb.getEventById(id);
                        artifactType= KBSummary.ArtifactType.EVENT;
                    } else if (outputFilePrefix.equals("beliefs")) {
                        slotfill = kb.getBeliefById(id);
                        artifactType= KBSummary.ArtifactType.BELIEF;
                    } else if (outputFilePrefix.equals("sentiments")) {
                        slotfill = kb.getSentimentById(id);
                        artifactType= KBSummary.ArtifactType.SENTIMENT;
                    } else {
                        throw new IllegalArgumentException("Invalid slotfill prefix: " + outputFilePrefix);
                    }
                } catch (IllegalArgumentException e) {
                    throw e;
                } catch (Exception e) {
                    log.error("Could not get KB object {}", id.getObjectID(), e);
                    continue;
                }

                count++;
                // Convert interesting slotfill fields
                List<String> fields = new ArrayList<String>();
//                fields.add(slotfill.getType().getType());
                String type = slotfill.getType().getType();
//                fields.add(slotfill.getKBID().getObjectID());
//                fields.add(Float.toString(slotfill.getConfidence()));
                if(slotfill.getConfidence()>maxConfidence){
                    maxConfidence = slotfill.getConfidence();
                }
                if(slotfill.getConfidence()<minConfidence){
                    minConfidence = slotfill.getConfidence();
                }
                // Accumulate and convert provenances and add some general stats
                Set<String> uniqueDocumentIDs = new HashSet<String>();
                Set<String> uniqueText = new HashSet<String>();
                Set<KBID> uniqueProvenanceIDs = new HashSet<KBID>();
                Set<String> uniqueJustifications = getUniqueJustificationsWithText(slotfill, maxJustifications, uniqueDocumentIDs, uniqueText, uniqueProvenanceIDs);
//                fields.add(Integer.toString(slotfill.getProvenances().size()));
                if(slotfill.getProvenances().size()>maxMentionCount){
                    maxMentionCount=slotfill.getProvenances().size();
                }
                fields.add(Integer.toString(uniqueDocumentIDs.size()));
                if(uniqueDocumentIDs.size()>maxDistinctDocs){
                    maxDistinctDocs = uniqueDocumentIDs.size();
                }
//                fields.addAll(uniqueJustifications);
                for (int j = uniqueJustifications.size(); j < maxJustifications; j++) {
                    fields.add("");
                }

                // Accumulate and convert arguments
//                fields.add(Integer.toString(slotfill.getArguments().size()));
                if(slotfill.getArguments().size()>maxNumArguments){
                    maxNumArguments = slotfill.getArguments().size();
                }
                if(slotfill.getArguments().size()<minNumArguments){
                    minNumArguments = slotfill.getArguments().size();
                }
                ImmutableSet.Builder<String> argTypes = ImmutableSet.builder();
                for (KBRelationArgument argument : slotfill.getArguments()) {
//                    fields.add(argument.getRole().getType());
                    argTypes.add(argument.getRole().getType());
//                    fields.add(Float.toString(argument.getConfidence()));
                    KBPredicateArgument target = argument.getTarget();
                    fields.add(target.getKBID().getObjectID());
//                    if (target instanceof KBThing) {
//                        if (outputFilePrefix.equals("beliefs") || outputFilePrefix.equals("sentiments")) {
//                            if (target instanceof KBEntity) {
//                                fields.add(getReferenceString((KBEntity) target));
//                            } else {
//                                fields.add(getReferenceString((KBThing) target));
//                            }
//                        } else {
//                            fields.add(((KBThing) target).getCanonicalString());
//                        }
//                    } else if (target instanceof KBRelation) {
//                        fields.add(getReferenceString((KBRelation) target));
//                    } else if (target instanceof KBRelationArgument) {
//                        fields.add(getReferenceString((KBRelationArgument) target));
//                    } else {
//                        log.warn("Could not generate string for {} argument target {} for {} {} {}",
//                                target.getClass().getName(), target.getKBID().getObjectID(), slotfillType, slotfill.getType().getType(), id);
//                        fields.add("");
//                    }
                    if (sampleSize > 0) {
                        slotfillTargetIDs.put(target.getClass(), target.getKBID());
                    }
                    Set<KBID> uniqueArgProvenanceIDs = new HashSet<KBID>();
                    Set<String> uniqueArgJustifications = getUniqueArgumentJustifications(target, uniqueArgProvenanceIDs);
//                    fields.addAll(uniqueArgJustifications);
                    for (int j = uniqueArgJustifications.size(); j < maxArgJustifications; j++) {
                        fields.add("");
                    }

                    // Check for justification overlap
                    for (KBID uniqueArgProvenanceID : uniqueArgProvenanceIDs) {
                        if (uniqueProvenanceIDs.contains(uniqueArgProvenanceID)) {
                            log.warn("Argument provenance {} used for {} provenance of {}", uniqueArgProvenanceID, target.getClass().getName(), id);
                        }
                    }
                }
                KBSummary.TypeWithOptionalArgTypes typeForSummary =
                        KBSummary.TypeWithOptionalArgTypes.create(type,Optional.of(argTypes.build()));
                typesForSummary.add(typeForSummary);
                // Convert to CSV
//                csvFields = new String[fields.size()];
//                fields.toArray(csvFields);
//                writer.writeNext(csvFields, false);
//                written++;
            }
        }
        // Done
        if(count==0) {
            minConfidence=0.0f;
            maxConfidence=0.0f;
            minNumArguments=0;
        }
        KBSummary kbSummary   = KBSummary.create(artifactType,count,maxMentionCount,maxDistinctDocs,
                minConfidence,maxConfidence,Optional.absent(),Optional.of(minNumArguments),Optional.of
                        (maxArguments),typesForSummary.build());
        kbSummaryMap.put(artifactType,kbSummary);
        log.info("Wrote {} {}", written, outputFilePrefix);
        return slotfillTargetIDs;
    }

    /**
     * Entry point for {@link TacFormatConverter} that loads configuration from
     * command line or default configuration, connects to knowledge base, and generates reports.
     */
    public static void main(String[] args) {
        TacFormatConverter reportGenerator = null;
        try {
            // Define command line options
            CommandLineParser parser = new DefaultParser();
            HelpFormatter formatter = new HelpFormatter();
            Options options = new Options();
            options.addOption("r", "resume", false, "do no requery objects that already exist in output");
            options.addOption(Option.builder("p")
                    .longOpt("params")
                    .argName("kb parameter file")
                    .hasArg()
                    .desc("optional path to KB parameter file")
                    .build());
            options.addOption(Option.builder("s")
                    .longOpt("sample")
                    .argName("N objects")
                    .hasArg()
                    .desc("number of objects to randomly sample from the KB")
                    .build());

            // Read parameters
            CommandLine line = parser.parse(options, args);
            if (line.getArgs().length != 2) {
                formatter.printHelp("TacFormatConverter <output dir> <run name>", options);
                System.exit(1);
            }
            File outputDirectory = new File(line.getArgs()[0]);
            String systemName = line.getArgs()[1];
            final KBParameters kbParameters;
            if (line.hasOption("params")) {
                kbParameters = new KBParameters(line.getOptionValue("params"));
            } else {
                kbParameters = new KBParameters();
            }
            boolean resumeRun = line.hasOption("resume");
            int sampleSize = 0;
            if (line.hasOption("sample")) {
                sampleSize = Integer.valueOf(line.getOptionValue("sample")).intValue();
            }

            // Initialize connections
            reportGenerator = new TacFormatConverter(kbParameters, outputDirectory, systemName, resumeRun, sampleSize);

            // Generate reports
            reportGenerator.generate();
        } catch (Exception e) {
            System.err.println("Could not generate reports");
            e.printStackTrace(System.err);
        } finally {
            if (reportGenerator != null) {
                reportGenerator.close();
            }
        }
    }

    public static class KBSummary{
        public enum ArtifactType{BELIEF,SENTIMENT,RELATION,EVENT,ENTITY};

        public static class TypeWithOptionalArgTypes{
            final String type;
            final Optional<ImmutableSet<String>> argTypes;

            private TypeWithOptionalArgTypes(String type,Optional<ImmutableSet<String>> argTypes){
                this.type = type;
                this.argTypes = argTypes;

            }
            static TypeWithOptionalArgTypes create(String type,Optional<ImmutableSet<String>> argTypes){
                checkNotNull(type);
                return new TypeWithOptionalArgTypes(type,argTypes);
            }

            public String type(){
                return type;
            }

            public Optional<ImmutableSet<String>> argTypes(){
                return argTypes;
            }

            @Override
            public boolean equals(Object that){
                if(that!=null && that instanceof TypeWithOptionalArgTypes &&
                        this.type.equals(((TypeWithOptionalArgTypes) that).type()) &&
                        this.argTypes.equals(((TypeWithOptionalArgTypes)that).argTypes())){
                    return true;
                }
                return false;
            }

            @Override
            public int hashCode(){
                return Objects.hashCode(this.type,this.argTypes);
            }
        }

        final ArtifactType artifactType;
        final int count;
        final int maxMentionCount;
        final int maxDistinctDocs;
        final float minConfidence;
        final float maxConfidence;
        final Optional<Integer> maxUniqueStrings; //for entities
        final Optional<Integer> minNumArguments; //for non-entities
        final Optional<Integer> maxNumArguments; //for non-entities
        final ImmutableSet<TypeWithOptionalArgTypes> types;

        private KBSummary(ArtifactType artifactType, int count, int maxMentionCount, int
                maxDistinctDocs, float minConfidence, float maxConfidence, Optional<Integer> maxUniqueStrings,
                          Optional<Integer> minNumArguments, Optional<Integer> maxNumArguments,
                          ImmutableSet<TypeWithOptionalArgTypes> types){
            this.artifactType=artifactType;
            this.count=count;
            this.maxMentionCount=maxMentionCount;
            this.maxDistinctDocs=maxDistinctDocs;
            this.minConfidence=minConfidence;
            this.maxConfidence=maxConfidence;
            this.maxUniqueStrings=maxUniqueStrings;
            this.minNumArguments=minNumArguments;
            this.maxNumArguments=maxNumArguments;
            this.types=types;

        }

        static KBSummary create(ArtifactType artifactType, int count, int maxMentionCount, int
                maxDistinctDocs, float minConfidence, float maxConfidence, Optional<Integer> maxUniqueStrings,
                                Optional<Integer> minNumArguments, Optional<Integer> maxNumArguments,
                                ImmutableSet<TypeWithOptionalArgTypes> types){
            checkNotNull(artifactType);
            return new KBSummary(artifactType, count, maxMentionCount, maxDistinctDocs, minConfidence,
                    maxConfidence, maxUniqueStrings, minNumArguments, maxNumArguments, types);
        }

        public ArtifactType artifactType(){
            return artifactType;
        }

        public int count(){
            return count;
        }

        public int maxMentionCount(){
            return maxMentionCount;
        }

        public int maxDistinctDocs(){
            return maxDistinctDocs;
        }

        public float minConfidence(){
            return minConfidence;
        }

        public float maxConfidence(){
            return maxConfidence;
        }

        public Optional<Integer> maxUniqueStrings(){
            return maxUniqueStrings;
        }

        public Optional<Integer> minNumArguments(){
            return minNumArguments;
        }

        public Optional<Integer> maxNumArguments(){
            return maxNumArguments;
        }

        public ImmutableSet<TypeWithOptionalArgTypes> types(){
            return types;
        }

    }




}
