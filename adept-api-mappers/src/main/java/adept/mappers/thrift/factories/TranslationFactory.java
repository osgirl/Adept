package adept.mappers.thrift.factories;

import org.dozer.BeanFactory;
import adept.common.Translation;

public class TranslationFactory implements org.dozer.BeanFactory {
	public Translation createBean(Object source, Class sourceClass, String targetBeanId) {

		return new adept.common.Translation(null, null);
	}
}
