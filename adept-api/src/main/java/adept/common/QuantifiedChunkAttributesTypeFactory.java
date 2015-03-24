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
package adept.common;

import java.io.IOException;
import java.io.InputStream;
import java.util.InvalidPropertiesFormatException;
import java.util.Properties;
import java.util.HashMap;

// TODO: Auto-generated Javadoc
/**
 * A factory for creating QuantifiedChunkAttributesType objects.
 */
public class QuantifiedChunkAttributesTypeFactory {

	/** The quantified chunk attributes type catalog. */
	private Properties qcAttributesTypeCatalog;
	
	/** The instance map. */
	private static HashMap<String,QuantifiedChunkAttributesTypeFactory> instances = new HashMap<String, QuantifiedChunkAttributesTypeFactory>();
	

	/**
	 * Instantiates a new quantified chunk attributes type factory.
	 */
	protected QuantifiedChunkAttributesTypeFactory() {

	}
	
	/**
	 * Gets the single instance of QuantifiedChunkAttributesTypeFactory.
	 *
	 * @param qcAttributesTypeCatalog the conversation element attributes type catalog
	 * @return single instance of QuantifiedChunkAttributesTypeFactory
	 * @throws InvalidPropertiesFormatException the invalid properties format exception
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	public static QuantifiedChunkAttributesTypeFactory getInstance(String qcAttributesTypeCatalog)
			throws InvalidPropertiesFormatException, IOException {
		QuantifiedChunkAttributesTypeFactory qcaFactory;
		if (instances.get(qcAttributesTypeCatalog) == null) {
			qcaFactory = new QuantifiedChunkAttributesTypeFactory();
			qcaFactory.loadQuantifiedChunkAttributesTypeCatalog(qcAttributesTypeCatalog);
			
			//insert into hashmap
           instances.put(qcAttributesTypeCatalog, qcaFactory);
		}
		else {
			qcaFactory = instances.get(qcAttributesTypeCatalog);
		}
		return qcaFactory;
	}

	/**
	 * Gets the single instance of QuantifiedChunkAttributesTypeFactory.
	 * 
	 * @return single instance of QuantifiedChunkAttributesTypeFactory
	 * @throws InvalidPropertiesFormatException
	 *             the invalid properties format exception
	 * @throws IOException
	 *             Signals that an I/O exception has occurred.
	 */
	public static QuantifiedChunkAttributesTypeFactory getInstance()
			throws InvalidPropertiesFormatException, IOException {
		return getInstance("adept/common/QuantifiedChunkAttributesTypeFactory.xml"); 
	}

	/**
	 * Gets the type.
	 * 
	 * @param type
	 *            the type
	 * @return the type
	 */
	public Type getType(String type) {
		String qcaType = qcAttributesTypeCatalog.getProperty(type);
		if (qcaType == null) {
			return new Type("UNKNOWN");
		}
		return new Type(qcaType);
	}

	/**
	 * Load quantified chunk attributes type catalog.
	 *
	 * @param qcAttributesTypeCatalog the qcAttributes type catalog
	 * @throws InvalidPropertiesFormatException the invalid properties format exception
	 * @throws IOException Signals that an I/O exception has occurred.
	 */
	private void loadQuantifiedChunkAttributesTypeCatalog(String qcAttributesTypeCatalogFile)
			throws InvalidPropertiesFormatException, IOException {
		qcAttributesTypeCatalog = new Properties();
		
		InputStream is = this.getClass().getClassLoader().getResourceAsStream(qcAttributesTypeCatalogFile);
		qcAttributesTypeCatalog.loadFromXML(is);
	}

}