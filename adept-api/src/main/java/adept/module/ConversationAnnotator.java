/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
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
package adept.module;

import adept.common.Document;
import adept.common.HltContentContainer;

// TODO: Auto-generated Javadoc
/**
 * The Class ConversationAnnotator.
 */
public abstract class ConversationAnnotator extends AbstractModule implements
		IDocumentProcessor {

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * adept.module.IConversationProcessor#process(adept.common.Conversation)
	 */
	@Override
	public HltContentContainer process(Document document, HltContentContainer hltContentContainer) {
		// TODO Auto-generated method stub
		return null;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * adept.module.IConversationProcessor#processAsync(adept.common.Conversation
	 * )
	 */
	@Override
	public long processAsync(Document document, HltContentContainer hltContentContainer) {
		// TODO Auto-generated method stub
		return 0;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see adept.module.IConversationProcessor#tryGetResult(long,
	 * adept.common.Conversation)
	 */
	@Override
	public Boolean tryGetResult(long requestId, HltContentContainer hltContentContainer) {
		// TODO Auto-generated method stub
		return null;
	}

}