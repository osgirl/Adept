package adept.common;

/*-
 * #%L
 * adept-api
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

import static com.google.common.base.Preconditions.checkArgument;
import java.io.Serializable;


/**
 * A generic, simple pair class for storing key-value or pair data. This class
 * is immutable.
 * 
 * @param <L>
 *            the generic type
 * @param <R>
 *            the generic type
 */
public final class Pair<L, R> implements Serializable {

	private static final long serialVersionUID = 4831626048881814355L;

	/** The l. */
	private final L l;

	/** The r. */
	private final R r;

	/**
	 * Instantiates a new pair.
	 * 
	 * @param l
	 *            the l
	 * @param r
	 *            the r
	 */
	public Pair(L l, R r) {
                checkArgument(l!=null);
                checkArgument(r!=null);
		this.l = l;
		this.r = r;
	}

	/**
	 * Gets the l.
	 * 
	 * @return the l
	 */
	public L getL() {
		return l;
	}

	/**
	 * Gets the r.
	 * 
	 * @return the r
	 */
	public R getR() {
		return r;
	}

	@Override
	public boolean equals(final Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

		final Pair<?, ?> pair = (Pair<?, ?>) o;

		if (!l.equals(pair.l)) {
			return false;
		}
		return r.equals(pair.r);
	}

	@Override
	public int hashCode() {
		int result = l.hashCode();
		result = 31 * result + r.hashCode();
		return result;
	}
}
