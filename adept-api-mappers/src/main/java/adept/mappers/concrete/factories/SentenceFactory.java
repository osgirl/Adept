package adept.mappers.concrete.factories;

import org.dozer.BeanFactory;
import adept.common.Sentence;

public class SentenceFactory implements org.dozer.BeanFactory {
	public Sentence createBean(Object source, Class sourceClass, String targetBeanId) {
		adept.common.Document document = new adept.common.Document("Doc1", null, "Sentence", "EXURI111", "English");
		document.setValue("Default");
		adept.common.TokenStream tokenStream = new adept.common.TokenStream(null, null, null, null, null, document);
		tokenStream.add(new adept.common.Token(0, new adept.common.CharOffset(0,0), null));
		return new adept.common.Sentence(0, new adept.common.TokenOffset(0, 0), tokenStream);
	}
}
