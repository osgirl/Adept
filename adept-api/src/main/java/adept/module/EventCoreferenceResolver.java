package adept.module;

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

import adept.common.Document;
import adept.common.DocumentList;
import adept.common.HltContentContainer;


/**
 * The Class EventCoreferenceResolver.
 */
public abstract class EventCoreferenceResolver extends AbstractModule implements
IDocumentProcessor, IDocumentListProcessor {

	/* (non-Javadoc)
	 * @see adept.module.IDocumentListProcessor#process(adept.common.DocumentList, adept.common.HltContentContainer)
	 */
	@Override
	public HltContentContainer process(DocumentList documentList,
			HltContentContainer hltContentContainer)
			throws AdeptModuleException {
		// TODO Auto-generated method stub
		return null;
	}

	/* (non-Javadoc)
	 * @see adept.module.IDocumentListProcessor#processAsync(adept.common.DocumentList, adept.common.HltContentContainer)
	 */
	@Override
	public long processAsync(DocumentList documentList,
			HltContentContainer hltContentContainer)
			throws AdeptModuleException {
		// TODO Auto-generated method stub
		return 0;
	}

	/* (non-Javadoc)
	 * @see adept.module.IDocumentProcessor#process(adept.common.Document, adept.common.HltContentContainer)
	 */
	@Override
	public HltContentContainer process(Document document,
			HltContentContainer hltContentContainer)
			throws AdeptModuleException {
		// TODO Auto-generated method stub
		return null;
	}

	/* (non-Javadoc)
	 * @see adept.module.IDocumentProcessor#processAsync(adept.common.Document, adept.common.HltContentContainer)
	 */
	@Override
	public long processAsync(Document document,
			HltContentContainer hltContentContainer)
			throws AdeptModuleException {
		// TODO Auto-generated method stub
		return 0;
	}

	/* (non-Javadoc)
	 * @see adept.module.IDocumentProcessor#tryGetResult(long, adept.common.HltContentContainer)
	 */
	@Override
	public Boolean tryGetResult(long requestId,
			HltContentContainer hltContentContainer)
			throws AdeptModuleException {
		// TODO Auto-generated method stub
		return Boolean.FALSE;
	}

}
