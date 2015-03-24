/*
* ------
* Adept
* -----
* Copyright (C) 2014 Raytheon BBN Technologies Corp.
* -----
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
* -------
*/

package adept.io;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;

import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import adept.common.Pair;
import adept.common.ConversationElement;
import adept.common.ConversationElementAttributesTypeFactory;
import adept.common.ConversationElementEntityRelationTypeFactory;
import adept.common.ConversationElementRelationTypeFactory;
import adept.common.ChannelName;
import adept.common.CharOffset;
import adept.common.ContentType;
import adept.common.Corpus;
import adept.common.HltContentContainer;
import adept.common.ConversationElementTag;
import adept.common.Token;
import adept.common.TokenOffset;
import adept.common.TokenStream;
import adept.common.TokenizerType;
import adept.common.TranscriptType;
import adept.utilities.PassageAttributes;
import adept.utilities.StanfordTokenizer;

import java.util.*;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static com.google.common.base.Preconditions.checkArgument;

// TODO: Auto-generated Javadoc

/**
 * The Class LDCCorpusReader.
 */
public class LDCCorpusReader {
    /**
     * Singleton instance and getter method.
     */
    private static LDCCorpusReader instance;

    /**
     * Gets the single instance of LDCCorpusReader.
     *
     * @return single instance of LDCCorpusReader
     */
    public static LDCCorpusReader getInstance() {
        if (instance == null)
            instance = new LDCCorpusReader();
        return instance;
    }

    /**
     * reads text document for specific tags.
     *
     * @param text                  the text of the document
     * @param passageAttributesList the passage attribute list
     * @param corpus                the corpus
     * @param uri                   the uri
     * @param language              the language
     * @return the adept.common. document
     */
    public HltContentContainer readPosts(String text, List<PassageAttributes> passageAttributesList,
                                         Corpus corpus,
                                         String uri,
                                         String language) throws InvalidPropertiesFormatException, IOException {

        String docType = "sgm";
        String docID = uri;
        if(docID == null)
        	docID = "UNKNOWN";
        
        List<ConversationElementTag> tags = new ArrayList<ConversationElementTag>();
        //contains name, attributes, start
        //Stack<Pair<Pair<String, Map<String, String>>, Integer>> tagStack = new Stack<Pair<Pair<String, Map<String, String>>, Integer>>();
        Stack<ConversationElement> postStack = new Stack<ConversationElement>();
        Stack<ConversationElement> quoteStack = new Stack<ConversationElement>();
        List<ConversationElement> postList = new ArrayList<ConversationElement>();

        Pattern tagPattern = Pattern.compile("<.*?>");
        Pattern tagNamePattern = Pattern.compile("\\w+");
        Pattern tagAttrPattern = Pattern.compile("\\s\\w*?=\".*?\"");

        Matcher tagMatcher = tagPattern.matcher(text);

//        System.out.println("Finding matches...");

        int lastTagEnd = 0;
        int currTagBegin = 0;

        // TODO null docID
        adept.common.Document adeptDocument = new adept.common.Document(docID, corpus, docType, uri, language);
//		adeptDocument.setValue(value);
        adeptDocument.setValue(text);
//        tokenStream.setDocument(adeptDocument);

        TokenizerType tokenizerType = TokenizerType.STANFORD_CORENLP;
        TranscriptType transcriptType = TranscriptType.SOURCE;
        ChannelName channelName = ChannelName.NONE;
        ContentType contentType = ContentType.TEXT;
        TokenStream tokenStream = new TokenStream(tokenizerType, transcriptType, language, channelName,
                contentType, adeptDocument);

        //find tags
        while (tagMatcher.find()) {
            int tagStart = tagMatcher.start();
            int tagEnd = tagMatcher.end();
//            System.out.print("Start index: " + tagStart + " ");
//            System.out.print("Start index: " + tagEnd + " ");
            String tag = tagMatcher.group();
//            System.out.println(tag);

            int tokenBegin = tokenStream.size();

            currTagBegin = tagStart;
            String contentString = text.substring(lastTagEnd, currTagBegin);
//	    System.out.println("Content: " + contentString);					 
            TokenStream contentTokenStream = StanfordTokenizer.getInstance().tokenize(contentString, adeptDocument);
            for (Token t : contentTokenStream) {
                CharOffset tOffset = t.getCharOffset();
                Token newToken = new Token(tokenStream.size(), new CharOffset(lastTagEnd + tOffset.getBegin(), lastTagEnd + tOffset.getEnd()), t.getValue());
                tokenStream.add(newToken);
            }
            lastTagEnd = tagEnd;

            if (tag.contains("<?xml")) // messy
                continue;

            Matcher tagNameMatcher = tagNamePattern.matcher(tag);
            Matcher tagAttrMatcher = tagAttrPattern.matcher(tag);

            // TODO - remove while()
            //get the tag name
            String tagName = "";
            while (tagNameMatcher.find()) {
                tagName = tagNameMatcher.group().trim().toLowerCase();
//                System.out.println("\t Name: " + tagName);
                break;
            }

            //get the tag attributes
            Map<String, Token> attributes = new HashMap<String, Token>();
            while (tagAttrMatcher.find()) {
                String attr = tagAttrMatcher.group().trim();
                int split = attr.indexOf("=");
                int attrBegin = tagAttrMatcher.start();
                int attrEnd = tagAttrMatcher.end();
                Token token = new Token(tokenStream.size(), new CharOffset(tagStart + split + attrBegin + 3, tagStart + attrEnd - 1), attr.substring(split + 2, attr.length() - 1));
                token.setTokenType(adept.common.TokenType.TAG);
                tokenStream.add(token);
//		System.out.println("Token: " + token.getValue() + " " + token.getCharOffset().getBegin() + " " + token.getCharOffset().getEnd());
                attributes.put(attr.substring(0, split).toLowerCase(), token);
            }
//            for (String key : attributes.keySet()) {
//                System.out.println("\t attr: " + key + ": " + attributes.get(key));
//            }

            boolean isEnd = tag.contains("</"); //closes another
            boolean isUnit = tag.contains("/>"); //is its own

            boolean isPost = (tag.contains("<post") || tag.contains("post>"));
            boolean isQuote = (tag.contains("<quote") || tag.contains("quote>"));

//            System.out.println("\t End: " + isEnd);

            // TODO - tags variable is unused.
            ConversationElementTag currTag = new ConversationElementTag(tagName, attributes, tagStart, tagEnd);
            tags.add(currTag);

            if (isEnd) {
                if (isQuote) {
                    ConversationElement openQuote = quoteStack.pop();                    
                    ConversationElement newQuote = new ConversationElement(new TokenOffset(openQuote.getMessageChunk().getTokenOffset().getBegin(), tokenStream.size() - 1), tokenStream);
                    newQuote.getFreeTextAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID"),
                    		openQuote.getFreeTextAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID")));
                    newQuote.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"),
                    		openQuote.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")));
                    newQuote.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG"),
                    		openQuote.getConversationElementTagAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG")));
                    newQuote.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG"),
                    		openQuote.getConversationElementTagAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG")));

                    if (!quoteStack.isEmpty()) {
                        ConversationElement superQuote = quoteStack.pop();
                        if(superQuote.getConversationElementRelations().containsKey(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")))
                           superQuote.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")).add(newQuote);
                        else
                        {
                        	List<ConversationElement> newQuotes = new ArrayList<ConversationElement>();
                        	newQuotes.add(newQuote);
                        	superQuote.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"), newQuotes);
                        }
                        quoteStack.push(superQuote);
                    } else {
                        ConversationElement superPost = postStack.pop();
                        if(superPost.getConversationElementRelations().containsKey(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")))
                          superPost.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")).add(newQuote);
                        else
                        {
                        	List<ConversationElement> newQuotes = new ArrayList<ConversationElement>();
                        	newQuotes.add(newQuote);
                        	superPost.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"), newQuotes);
                        }
                        postStack.push(superPost);
                    }
                } else if (isPost) {
                    ConversationElement openPost = postStack.pop();
                    ConversationElement newPost = new ConversationElement(new TokenOffset(openPost.getMessageChunk().getTokenOffset().getBegin(), tokenStream.size() - 1), tokenStream);
                    newPost.getFreeTextAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID"),
                    		openPost.getFreeTextAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID")));
                    newPost.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG"),
                    		openPost.getConversationElementTagAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG")));
                    newPost.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG"),
                    		openPost.getConversationElementTagAttributes().get(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG")));
                    newPost.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"),
                    		openPost.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")));
                    postStack.push(newPost);
                    postList.add(newPost);
                }
//                Pair<Pair<String, Map<String,String>>,Integer> partner = tagStack.pop();
//                tags.add(new Tag(partner.getL().getL(), partner.getL().getR(), partner.getR(), tagEnd));
            }
/*            else if(isUnit)
            {
	        tags.add(new Tag(tagName, attributes, tagStart, tagEnd));
            }*/
            else if (!isUnit) {
                if (isQuote) {
                    String sequenceId;
                    if (!quoteStack.isEmpty()) {
                        ConversationElement superQuote = quoteStack.peek();
                        try
                        {
                        	sequenceId = Integer.toString(superQuote.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")).size());
                        }
                        catch(NullPointerException e)
                        {
                        	sequenceId = "1";
                        }
                    } else {
                        ConversationElement superPost = postStack.peek();
                        try
                        {
                        	sequenceId = Integer.toString(superPost.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES")).size());
                        }
                        catch(NullPointerException e)
                        {
                        	sequenceId = "1";
                        }
                        
                    }
                    if (tokenBegin > tokenStream.size() - 1) {
                        tokenBegin = tokenStream.size() - 1;
                    }
                    ConversationElement newQuote = new ConversationElement(new TokenOffset(tokenBegin, tokenStream.size() - 1), tokenStream);
                    newQuote.getFreeTextAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID"),
                    		sequenceId);
                    newQuote.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG"),currTag);
                    newQuote.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG"),currTag);
                    quoteStack.push(newQuote);
                } else if (isPost) {
                    String sequenceId = Long.toString(postList.size());
                    ConversationElement newPost = new ConversationElement(new TokenOffset(tokenBegin, tokenStream.size() - 1), tokenStream);
                    newPost.getFreeTextAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("SEQUENCE ID"),
                    		sequenceId);
                    newPost.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("OPEN TAG"),currTag);
                    newPost.getConversationElementTagAttributes().put(ConversationElementAttributesTypeFactory.getInstance().getType("CLOSE TAG"),currTag);
                    postStack.push(newPost);
                }
//                Pair<String, Map<String,String>> nameAndAttrs = new Pair<String, Map<String,String>>(tagName, attributes);
//                Pair<Pair<String, Map<String,String>>,Integer> partial = new Pair<Pair<String, Map<String,String>>,Integer>(nameAndAttrs, tagStart);
//                tagStack.push(partial);
            }

        }

//	System.out.println("Post Count: " + postStack.size());

        //		adeptDocument.setHeadline(headline);

        List newPostList = new ArrayList<ConversationElement>();
        for (ConversationElement p : postList) {
            ConversationElement newPost = assignPostToQuotes(p);
            newPostList.add(newPost);
        }

        adeptDocument.addTokenStream(tokenStream);
        HltContentContainer hltcc = new HltContentContainer();
        hltcc.setConversationElements(newPostList);

//		return new Pair<List<Tag>,adept.common.Document>(tags,adeptDocument);

        return hltcc;
    }

    private ConversationElement assignPostToQuotes(ConversationElement post) throws InvalidPropertiesFormatException, IOException {
    	List<ConversationElement> quotes = post.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"));
        if (quotes == null || quotes.size() == 0) {
            return post;
        } else {
            List<ConversationElement> newQuotes = new ArrayList<ConversationElement>();
            for (ConversationElement quote : quotes) {
                ConversationElement newQuote = assignPostToSubQuotes(quote, post);
                newQuotes.add(newQuote);
            }
            post.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"), newQuotes);
            return post;
        }
    }

    private ConversationElement assignPostToSubQuotes(ConversationElement quote, ConversationElement post) throws InvalidPropertiesFormatException, IOException {
    	List<ConversationElement> subQuotes = quote.getConversationElementRelations().get(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"));
        if (subQuotes == null || subQuotes.size() == 0) {
        	List<ConversationElement> posts = new ArrayList<ConversationElement>();
        	posts.add(post);
        	quote.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("PARENT POST"), posts);
            return quote;
        } else {
        	List<ConversationElement> posts = new ArrayList<ConversationElement>();
        	posts.add(post);
            List<ConversationElement> newQuotes = new ArrayList<ConversationElement>();
            for (ConversationElement subQuote : subQuotes) {
                ConversationElement newQuote = assignPostToSubQuotes(subQuote, post);
                newQuotes.add(newQuote);
            }
            quote.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("QUOTES"), newQuotes);
            quote.getConversationElementRelations().put(ConversationElementRelationTypeFactory.getInstance().getType("PARENT POST"), posts);
            return quote;
        }
    }


    /**
     * reads the DOM format document for specific tags.
     *
     * @param doc                   the  w3c Document
     * @param passageAttributesList the passage attributes list
     * @param corpus                the corpus
     * @param uri                   the uri
     * @param language              the language
     * @return the adept.common. document
     */
    public adept.common.Document readCorpus(org.w3c.dom.Document doc,
                                            List<PassageAttributes> passageAttributesList,
                                            Corpus corpus,
                                            String uri,
                                            String language) {
        adept.common.Document adeptDocument;    // distinguish from w3c Document type
        String docID = null;
        String docType = null;
        String headline;
        StringBuffer documentTextBuffer = new StringBuffer();
        doc.getDocumentElement().normalize();

        /** get text */
        // TODO - there should be a clearer way of distinguishing XML formats.
        Element textElement = (Element) doc.getElementsByTagName("TEXT").item(0);
        if (textElement == null) {
            // HUB4 format for CoNLL read itemid from element such as this:
            // <newsitem itemid="23489" id="root" date="1996-08-30" xml:lang="en">
            // TODO - should also read "headline" and "dateline" elements?
            textElement = (Element) doc.getElementsByTagName("text").item(0);
            NodeList passagesNodeList = textElement.getElementsByTagName("p");
            //System.out.println("passages: " + passagesNodeList.toString() + " " + passagesNodeList.getLength());
            for (int i = 0; i < passagesNodeList.getLength(); i++) {
                Element passage = (Element) passagesNodeList.item(i);
                if (passage != null) {
                    String passageValue = passage.getFirstChild().getNodeValue();
                    String passageValueTrimmed = passageValue.replaceAll("^\\s+", "").replaceAll("\\s+$", "");
                    String passageValueSurrogatesRemoved = Reader.checkSurrogates(passageValueTrimmed);
                    if (!passageValueSurrogatesRemoved.equals("")) {
                        documentTextBuffer.append(passageValueSurrogatesRemoved);
                        documentTextBuffer.append("\n");
                    }
                }
            }
            /** get adept Document ID and type */
            Element DOCElement = (Element) doc.getElementsByTagName("newsitem").item(0);
            if (DOCElement != null) {
                docID = DOCElement.getAttribute("itemid");
//					NodeList dcList = textElement.getElementsByTagName("dc");
                //				for (int i = 0; i < dcList.getLength(); i++) {
                //					Node dc = dcList.item(i).getFirstChild();
                //					String source = ((Element) dc).getAttribute("element");
                //				}
                docType = "HUB4";//DOCElement.getAttribute("type");
            }

        } else {
            System.out.println("textElement!=NULL");
            NodeList passages = textElement.getElementsByTagName("P");
            if (passages != null && passages.getLength() > 0) {
                //System.out.println("passages: " + passages.toString() + " " + passages.getLength());
                for (int i = 0; i < passages.getLength(); i++) {
                    Element passage = (Element) passages.item(i);
                    if (passage != null) {
                        String passageText = passage.getFirstChild().getNodeValue();
                        long passageId = (long) i;
                        String sarcasmValue = "";
                        if (!passage.getAttribute("pid").equals("")) {
                            passageId = Long.valueOf(passage.getAttribute("pid"));
                        }
                        if (!passage.getAttribute("sarcasm").equals("")) {
                            sarcasmValue = passage.getAttribute("sarcasm");
                        }
                        String passageValueTrimmed = passageText.replaceAll("^\\s+", "").replaceAll("\\s+$", "");
                        String passageValueSurrogatesRemoved = Reader.checkSurrogates(passageValueTrimmed);
                        if (!passageValueSurrogatesRemoved.equals("")) {
                            documentTextBuffer.append(passageValueSurrogatesRemoved);
                            documentTextBuffer.append("\n");
                            PassageAttributes pa = new PassageAttributes();
                            pa.setPassageId(passageId);
                            pa.setSarcasmValue(sarcasmValue);
                            pa.setValue(passageValueSurrogatesRemoved);
                            passageAttributesList.add(pa);
                        } else {
                            System.out.println(passageText);
                        }

                    }
                }
                // TODO - for CoNLL read itemid from element such as this:
                // <newsitem itemid="23489" id="root" date="1996-08-30" xml:lang="en">

                // TODO redundant code
                // TODO get more than one POST
            } else if (doc.getElementsByTagName("BODY").item(0) != null) {
                Element bodyElement = (Element) doc.getElementsByTagName("BODY").item(0);
                textElement = (Element) bodyElement.getElementsByTagName("TEXT").item(0);
                Element postElement = (Element) textElement.getElementsByTagName("POST").item(0);
                Element textOrPost = (postElement == null) ? textElement : postElement;
                NodeList nodes = textOrPost.getChildNodes();
                for (int i = 0; i < nodes.getLength(); i++) {
                    Node child = nodes.item(i);
                    if (child.getNodeType() == Node.TEXT_NODE)
                        documentTextBuffer.append(child.getTextContent());
                }
                getPassages(passageAttributesList, documentTextBuffer.toString().trim());
            } else {
                textElement = (Element) doc.getElementsByTagName("TEXT").item(0);
                Element postElement = (Element) textElement.getElementsByTagName("POST").item(0);
                Element textOrPost = (postElement == null) ? textElement : postElement;
                NodeList nodes = textOrPost.getChildNodes();
                for (int i = 0; i < nodes.getLength(); i++) {
                    Node child = nodes.item(i);
                    if (child.getNodeType() == Node.TEXT_NODE)
                        documentTextBuffer.append(child.getTextContent());
                }
                getPassages(passageAttributesList, documentTextBuffer.toString().trim());
            }

            /** get adept Document ID and type */
            Element DOCElement = (Element) doc.getElementsByTagName("DOC").item(0);
            docID = DOCElement.getAttribute("id");
            docType = DOCElement.getAttribute("type");
            if (docID.equals("")) {		
                try {
                    System.out.println("DOCID was empty on the first attempt");
		    /** Get Adept Document ID */
		    NodeList docElements = doc.getElementsByTagName("DOCID");
		    if (docElements != null && docElements.getLength() != 0) {
			docID = docElements.item(0).getFirstChild().getNodeValue();
		    }
		    if (docElements == null || docElements.getLength() == 0 || docID == null || 
			(docID != null && docID.equals(""))) {
			System.out.println("DOCID was empty in the second attempt (DOCID)");
			docID = doc.getElementsByTagName("DOCNO").item(0).getFirstChild()
			    .getNodeValue();
		    }

                } catch (Exception e) {
		    e.printStackTrace();
		    // Unrecoverable error, so made this an unchecked exception
                    throw new RuntimeException("Unable to set DOC ID. Adept documents are required to have a non-empty document ID.");
                }

            }
            if (docType.equals("")) {
                /** get adept Document Type */
                try {
                    docType = doc.getElementsByTagName("DOCTYPE").item(0)
                            .getFirstChild().getNodeValue();
                } catch (NullPointerException e) {
                	docType = "UNKNOWN";
                }
            }

        }

        String documentText = documentTextBuffer.toString().trim();

        /** convert to utf-8 */
        Charset charset = Charset.forName("UTF-8");
        try {
            ByteBuffer bbuf = charset.newEncoder().encode(CharBuffer.wrap(documentText));
            CharBuffer cbuf = charset.newDecoder().decode(bbuf);
            documentText = cbuf.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }

        /** get headline */
        headline = "";
        Element headlineElement = (Element) doc.getElementsByTagName("HEADLINE").item(0);
        if (headlineElement != null && headlineElement.getFirstChild() != null) {
            headline = headlineElement.getFirstChild().getNodeValue();
        } else {
            // HUB4
            headlineElement = (Element) doc.getElementsByTagName("headline").item(0);
            if (headlineElement != null && headlineElement.getFirstChild() != null) {
                headline = headlineElement.getFirstChild().getNodeValue();
            }
        }

        /** create adept document and return */
        // TODO - more languages

        System.out.println("Doc URI: " + uri);
        System.out.println("Doc Id: " + docID);
        System.out.println("Doc type: " + docType);
        adeptDocument = new adept.common.Document(docID, corpus, docType, uri, language);
        adeptDocument.setValue(documentText);
        adeptDocument.setHeadline(headline);    // TODO should this be trimmed?
        return adeptDocument;
    }

    // TODO break passages at the end of one or more blank lines.
    public int getPassages(List<PassageAttributes> passageAttributesList, String text) {

//        PassageAttributes pa = new PassageAttributes();
//        pa.setPassageId(0);
//        pa.setValue(text.trim());
//        passageAttributesList.add(pa);
//        return 0;
//    }
        BufferedReader bufReader = new BufferedReader(new StringReader(text));
       String line = null;
       int passageId = 0;
        StringBuffer sb = new StringBuffer();
        boolean wasPrevBlank = false;
        char[] charList = text.toCharArray();
        int offset = 0;
        try {
            while (true) {
                line = bufReader.readLine();
                boolean isBlank = ( line != null && line.trim().length()==0);

                PassageAttributes pa = new PassageAttributes();
		boolean addPassage = false;
                if (line == null || (wasPrevBlank && ! isBlank)) {
		    addPassage = true;
                    pa.setPassageId(passageId++);
                    pa.setValue(sb.toString().trim());
                    sb = new StringBuffer();
                }
                if (line == null) {
                    passageAttributesList.add(pa);
		    break;
		}
                wasPrevBlank = isBlank;
                if ( !isBlank ) sb.append(line );
                offset += line.length();
               // Add EOL characters
		int postOffset = 0;
                while ( offset < charList.length ) {
                    char c = charList[offset];
                    if ( c=='\r' || c=='\n' ) {
                        sb.append(c);
                        ++offset;
                        ++postOffset;
                    }
                    else break;
                }
		if (addPassage) {
		    pa.setPostPassageOffset(postOffset);
                    passageAttributesList.add(pa);
		}
            }
        } catch (Exception ex) {
            System.out.println(ex);
        }

//        System.out.println("Breaking passages =" + passageId);
        return passageId;
    }

}