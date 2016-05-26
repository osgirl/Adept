/*
* Copyright (C) 2016 Raytheon BBN Technologies Corp.
*
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
*
*/

package adept.common;

import adept.data.IValue;


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
