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

/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
package adept.mappers.thrift.serialization;

import adept.mappers.thrift.ThriftAdeptMapper;

import adept.serialization.XMLSerializer;
import adept.serialization.AbstractSerializer;

import java.nio.ByteBuffer;

import thrift.adept.serialization.*;

import adept.data.*;
import thrift.adept.common.*;
import adept.serialization.*;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

import java.io.UnsupportedEncodingException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;

// TODO: Auto-generated Javadoc
/**
 * Performs XML serialization.
 */
public class XMLSerializerWrapper implements Serializer.Iface {
	// Serializer instance
	/** The xstream. */
	private static XMLSerializer xmlSerializer = new XMLSerializer(adept.serialization.SerializationType.XML);

	private ThriftAdeptMapper mapper;

	/**
	 * Instantiates a new xML serializer.
	 * 
	 * @param serializationType
	 *            the serialization type
	 */
	public XMLSerializerWrapper(thrift.adept.serialization.SerializationType serializationType) {
                mapper = new ThriftAdeptMapper();
	}

	/**
	 * Method to serialize input object into string.
	 * 
	 * @param object
	 *            the object
	 * @return the string
	 * @throws UnsupportedEncodingException
	 *             the unsupported encoding exception
	 */
	@Override
	public String serializeAsString(thrift.adept.common.HltContentContainer hltContentContainer) {

		adept.common.HltContentContainer adeptHltcc = mapper.convert(hltContentContainer);
		try {
		String xml = xmlSerializer.serializeAsString(adeptHltcc);
		// System.out.println("In serializer class: " + "\n" + xml);
		return xml;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	/**
	 * Method to deserialize input object from string.
	 * 
	 * @param data
	 *            the data
	 * @param c
	 *            the c
	 * @return the object
	 * @throws UnsupportedEncodingException
	 *             the unsupported encoding exception
	 */
	@Override
	public thrift.adept.common.HltContentContainer deserializeString(String data) {
		try {
			adept.common.HltContentContainer hltContentContainer = (adept.common.HltContentContainer) xmlSerializer.deserializeString(data, adept.common.HltContentContainer.class);
			thrift.adept.common.HltContentContainer thriftHltcc = mapper.convert(hltContentContainer);
			return thriftHltcc;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * adept.serialization.ISerializer#serializeAsByteArray(java.lang.Object)
	 */
	@Override
	public ByteBuffer serializeAsByteArray(thrift.adept.common.HltContentContainer hltContentContainer) {
		// Unimplemented yet
		return null;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see adept.serialization.ISerializer#deserializeByteArray(byte[],
	 * java.lang.Class)
	 */
	@Override
	public thrift.adept.common.HltContentContainer deserializeByteArray(ByteBuffer data) {
		// Unimplemented yet
		return null;
	}

}