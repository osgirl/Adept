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

package adept.mappers.thrift.converters;

import com.google.common.collect.ImmutableList;

import org.dozer.DozerBeanMapper;

import java.util.Arrays;

import adept.mappers.thrift.ThriftAdeptMapper;

/**
 * Created by jdeyoung on 11/12/15.
 */
public final class MorphTokenConverter implements org.dozer.CustomConverter {

  // the ThriftAdeptMapper supports nice, sane, conversion methods, but the Dozer bean mapper only supports simple changes.
  private final static DozerBeanMapper mapper = new DozerBeanMapper(
      Arrays.asList(new String[]{"adept/mappers/thrift/ThriftAdeptMappings.xml"}));
  private final static ThriftAdeptMapper generalMapper = ThriftAdeptMapper.getInstance();

  @Override
  public Object convert(final Object dest, final Object source, final Class<?> destClass,
      final Class<?> sourceClass) {
    if (source instanceof adept.common.MorphToken) {
      adept.common.MorphToken adept = (adept.common.MorphToken) source;
      thrift.adept.common.MorphToken thrift = generalMapper.convert(adept);
      return thrift;
    } else if (source instanceof thrift.adept.common.MorphToken) {
      thrift.adept.common.MorphToken thrift = (thrift.adept.common.MorphToken) source;
      adept.common.MorphToken adept = generalMapper.convert(thrift);
      return adept;
    } else if (source instanceof java.util.List){
      final Object fst = ((java.util.List) source).get(0);
      if(fst instanceof  thrift.adept.common.MorphToken) {
        final ImmutableList.Builder<adept.common.MorphToken> ret = ImmutableList.builder();
        for(final Object o: (java.util.List) source) {
          ret.add(generalMapper.convert((thrift.adept.common.MorphToken) o));
        }
        return ret.build();
      } else if (fst instanceof  adept.common.MorphToken) {
        final ImmutableList.Builder<thrift.adept.common.MorphToken> ret = ImmutableList.builder();
        for(final Object o: (java.util.List) source) {
          ret.add(generalMapper.convert((adept.common.MorphToken) o));
        }
        return ret.build();
      } else {
        throw new org.dozer.MappingException("Converter MorphTokenConverter "
            + "used incorrectly. Arguments passed in were:"
            + destClass + " and " + source + " of " + fst.getClass());
      }
    }
    else {
      throw new org.dozer.MappingException("Converter MorphTokenConverter "
          + "used incorrectly. Arguments passed in were:"
          + destClass + " and " + source);
    }
  }
}
