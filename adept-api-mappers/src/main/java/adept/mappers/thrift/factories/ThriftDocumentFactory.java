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

package adept.mappers.thrift.factories;

import org.dozer.BeanFactory;
import thrift.adept.common.Document;

public class ThriftDocumentFactory implements org.dozer.BeanFactory {
	public Document createBean(Object source, Class sourceClass, String targetBeanId) {
		final adept.common.Document document = (adept.common.Document) source;

		thrift.adept.common.Corpus corpus = new thrift.adept.common.Corpus("", "", "", "");

		return new thrift.adept.common.Document("", corpus, "", "", "");
	}
}