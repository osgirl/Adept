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

/*
 * 
 */
package adept.common;

import com.google.common.base.Objects;
import static com.google.common.base.Preconditions.checkArgument;


/**
 * Captures the begin and end integer positions of token spans.
 * The begin and end positions are both inclusive.
 * This class is immutable.
 */
public final class TokenOffset {

	/** The begin index, which is inclusive. */
	private final int begin;

	/** The end index, which is inclusive. */
	private final int end;

	/**
	 * @param begin
	 *            The (inclusive) index that points to the beginning of the token span.
	 * @param end
	 *            The (inclusive) index that points to the end of the token span.
	 */
	public TokenOffset(int begin, int end) {
            checkArgument(begin <= end, "A TokenOffset's begin must be less than or equal to its end, but got begin %s and end %s", begin, end);
            this.begin = begin;
            this.end = end;
	}

	/**
	 * @return The (inclusive) index that points to the beginning of the token span.
	 */
	public int getBegin() {
            return begin;
	}

	/**
	 * @return The (inclusive) index that points to the end of the token span.
	 */
	public int getEnd() {
            return end;
	}

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof TokenOffset)) {
                return false;
            }
            TokenOffset that = (TokenOffset) o;
            return that.begin == this.begin && that.end == this.end;
        }

        @Override
        public int hashCode() {
            return Objects.hashCode(begin, end);
        }
}
