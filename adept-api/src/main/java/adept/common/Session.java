/*******************************************************************************
 * Raytheon BBN Technologies Corp., November 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
/*
 * 
 */
package adept.common;

import java.util.List;

// TODO: Auto-generated Javadoc
/**
 * The Class Session.
 */
public class Session extends Chunk {

	/** The sequence id. */
	private final long sequenceId;

	/** The content type. */
	private final String contentType;

	/** The sentences. */
	private final List<Sentence> sentences;
	

	/**
	 * Instantiates a new session.
	 *
	 * @param tokenOffset the token offset
	 * @param tokenStream the token stream
	 * @param sequenceId the sequence id
	 * @param contentType the content type
	 * @param sentences the sentences
	 */
	public Session(TokenOffset tokenOffset, TokenStream tokenStream,
			long sequenceId, String contentType, List<Sentence> sentences) {
		super(tokenOffset, tokenStream);
		this.sequenceId = sequenceId;
		this.contentType = contentType;
		this.sentences = sentences;
	}

	/**
	 * Gets the sequence id.
	 *
	 * @return the sequence id
	 */
	public long getSequenceId() {
		return sequenceId;
	}

	/**
	 * Gets the content type.
	 *
	 * @return the content type
	 */
	public String getContentType() {
		return contentType;
	}

	/**
	 * Gets the sentences.
	 *
	 * @return the sentences
	 */
	public List<Sentence> getSentences() {
		return sentences;
	}
	
}