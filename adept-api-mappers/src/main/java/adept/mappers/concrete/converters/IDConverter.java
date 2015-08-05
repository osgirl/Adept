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

package adept.mappers.concrete.converters;
import org.dozer.DozerBeanMapper;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class IDConverter implements org.dozer.CustomConverter {
  
  public Object convert(Object destination, Object source, 
      Class destClass, Class sourceClass) {
    if (source == null) {
      return null;
    }
    DozerBeanMapper mapper = new DozerBeanMapper(Arrays.asList(new String[]{"adept/mappers/concrete/ConcreteAdeptMappings.xml"}));
    if (source instanceof adept.common.ID) {
	adept.common.ID id = (adept.common.ID) source;
	edu.jhu.hlt.concrete.UUID uuid = new edu.jhu.hlt.concrete.UUID();
	adept.mappers.concrete.ID tempId = new adept.mappers.concrete.ID();
	tempId.setId(id.getId());
	mapper.map(tempId, uuid);
	return uuid;
   } else if (source instanceof edu.jhu.hlt.concrete.UUID) {
	edu.jhu.hlt.concrete.UUID uuid = (edu.jhu.hlt.concrete.UUID) source;
	adept.common.ID id = new adept.common.ID();
	adept.mappers.concrete.ID tempId = new adept.mappers.concrete.ID();
//	tempId.setId(uuid.getHigh(), uuid.getLow());		
	mapper.map(tempId, id);
	return id;
    } else {
      throw new org.dozer.MappingException("Converter IDConverter "
          + "used incorrectly. Arguments passed in were:"
          + destination + " and " + source);
    }
  } 
}