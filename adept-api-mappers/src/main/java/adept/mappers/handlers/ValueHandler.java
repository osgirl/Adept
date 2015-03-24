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

/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
package adept.mappers.handlers;

import thrift.adept.common.*;


// TODO: Auto-generated Javadoc
/**
 * The Class Value.
 */
public class ValueHandler implements ValueService.Iface {

	private Value myValue;

	/**
	 * Instantiates a new value.
	 * 
	 * @param valueId
	 *            the value id
	 */
	public ValueHandler(long valueId) {
		super();
		myValue = new Value();
		myValue.valueId = valueId;
	}

	/**
	 * Gets the value id.
	 * 
	 * @return myValue.the value id
	 */
	public long getValueId() {
		return myValue.valueId;
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

	public Value getValueStruct() {
		return myValue;
	}

}