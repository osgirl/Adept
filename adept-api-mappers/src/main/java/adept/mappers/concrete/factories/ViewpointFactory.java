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

package adept.mappers.concrete.factories;

import org.dozer.BeanFactory;
import adept.common.Viewpoint;

public class ViewpointFactory implements org.dozer.BeanFactory {
	public Viewpoint createBean(Object source, Class sourceClass, String targetBeanId) {

		return new adept.common.Viewpoint("", "");
	}
}
