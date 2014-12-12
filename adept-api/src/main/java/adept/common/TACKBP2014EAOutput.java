package adept.common;

import java.util.Map;

import com.google.common.base.Strings;
import com.google.common.collect.ImmutableMap;

import static com.google.common.base.Preconditions.checkArgument;

/**
 * Represents the output of a a 2014 TAC KBP event argument system on a document.
 */
public final class TACKBP2014EAOutput {

    private final String documentId;
    private final ImmutableMap<TACKBP2014EventArgument, Float> scoredResponses;

    private TACKBP2014EAOutput(String documentId,
                               Map<TACKBP2014EventArgument, Float> scoredResponses) {
        this.documentId = documentId;
        this.scoredResponses = ImmutableMap.copyOf(scoredResponses);
    }

    /**
     * @param documentId      May not be {@code null}.
     * @param scoredResponses May not have {@code null} keys or values. If any response has
     *                        a {@link TACKBP2014EventArgument#getDocumentID()} that does not
     *                        match {@code documentId}, an {@link java.lang.IllegalArgumentException}
     *                        will be thrown.
     * @return
     */
    public static TACKBP2014EAOutput create(String documentId,
                                            Map<TACKBP2014EventArgument, Float> scoredResponses) {
        checkArgument(!Strings.isNullOrEmpty(documentId));        
        checkArgument(scoredResponses!=null);
        for( TACKBP2014EventArgument arg : scoredResponses.keySet()) {
            checkArgument(arg!=null);
            checkArgument(scoredResponses.get(arg)!=null);
            checkArgument(documentId==arg.getDocumentID());
        }
        return new TACKBP2014EAOutput(documentId, scoredResponses);
    }

    /**
     * @return Will never be {@code null}.
     */
    public String getDocumentID() {
        return documentId;
    }

    public ImmutableMap<TACKBP2014EventArgument, Float> getScoredResponses() {
        return (ImmutableMap<TACKBP2014EventArgument, Float>) scoredResponses;
    }
}