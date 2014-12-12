/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
package adept.common;

import adept.data.IValue;

// TODO: Auto-generated Javadoc
/**
 * The Class Value.
 */
public class Value implements IValue {

	/** The value id. */
	private final long valueId;

	/**
	 * Instantiates a new value.
	 * 
	 * @param valueId
	 *            the value id
	 */
	public Value(long valueId) {
		super();
		this.valueId = valueId;
	}

	/**
	 * Gets the value id.
	 * 
	 * @return the value id
	 */
	public long getValueId() {
		return valueId;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see adept.data.IValue#getValue()
	 */
	@Override
	public String getValue() {
		// TODO Auto-generated method stub
		return null;
	}

}