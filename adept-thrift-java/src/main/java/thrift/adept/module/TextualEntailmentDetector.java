/*******************************************************************************
 * Raytheon BBN Technologies Corp., December 2014
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2014 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
/**
 * 
 */

package thrift.adept.module;

import java.util.List;

import thrift.adept.common.HltContentUnion;
import thrift.adept.common.Passage;

// TODO: Auto-generated Javadoc
/**
 * The Class TextualEntailmentDetector.
 */
public class TextualEntailmentDetector extends AbstractModule implements
		PassagePairProcessor.Iface {

	/**
	 * Instantiates a new textual entailment detector.
	 */
	public TextualEntailmentDetector() {

	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see adept.module.IPassagePairProcessor#process(adept.common.Passage,
	 * adept.common.Passage)
	 */
	@Override
	public List<HltContentUnion> process(Passage text, Passage hypothesis) {
		// TODO Auto-generated method stub
		return null;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * adept.module.IPassagePairProcessor#processAsync(adept.common.Passage,
	 * adept.common.Passage)
	 */
	@Override
	public long processAsync(Passage text, Passage hypothesis) {
		// TODO Auto-generated method stub
		return 0;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see adept.module.IPassagePairProcessor#tryGetResult(long,
	 * java.util.List)
	 */
	@Override
	public boolean tryGetResult(long requestId, List<HltContentUnion> entailments) {
		// TODO Auto-generated method stub
		return false;
	}

}