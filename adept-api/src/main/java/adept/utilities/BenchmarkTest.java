/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
// Next line is site-specific.
package adept.utilities;


import java.io.DataInputStream;
import java.io.IOException;
import java.io.File;
import java.util.InvalidPropertiesFormatException;
import java.util.Properties;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

import org.apache.log4j.PropertyConfigurator;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import adept.common.Corpus;
import adept.common.Document;
import adept.common.HltContentContainer;
import adept.common.Passage;
import adept.common.Sentence;
import adept.io.Writer;
import adept.io.Reader;
import adept.common.TokenizerType;


// TODO: Auto-generated Javadoc
/**
 * The Class StanfordCoreNlpRegressionTest.
 */
public abstract class BenchmarkTest 
{
	/** The logger. */
	private static Logger logger;

	/** The log config file path. */
	private static String logConfigFilePath;

	/** The input file path. And list of file names. */
	private static String inputDirectory;
	
	/** The input file list. */
	private static List<String> inputFileList;
	
	/** The output directory. */
	private static String outputDirectory;
	
	/** The package path. */
	private static String packagePath;
	
	/** The working directory. */
	private static String workingDirectory;

	/** The config file path. */
	private static String configFilePath;
	
	/** The algorithm config. */
	private static String algorithmConfig; 

	/** files to be written on serialization. */
	private static Reader theReader = new Reader();
	
	/** The writer. */
	private static Writer theWriter = new Writer();

    /** The type of tokenizer to be used. */
    protected TokenizerType tokenizerType = TokenizerType.STANFORD_CORENLP;

    
	/**
	 * Abstract methods.
	 *
	 * @param workingDirectory the working directory
	 * @param algorithmConfig the algorithm config
	 */
	protected abstract void doActivate(String workingDirectory, String algorithmConfig);
	
	/**
	 * Do deactivate.
	 */
	protected abstract void doDeactivate();
	
	/**
	 * Do process.
	 *
	 * @param document the document
	 * @param hltContentContainer the hlt content container
	 * @return the hlt content container
	 */
	protected abstract HltContentContainer doProcess(Document document, HltContentContainer hltContentContainer);		
	
	/**
	 * Do score.
	 *
	 * @param document the document
	 * @param hltContentContainer the hlt content container
	 * @return the float
	 */
	protected abstract float doScore(Document document, HltContentContainer hltContentContainer);

	/**
	 * The Class TestFile.
	 */
	static class TestFile
	{
		
		/** The name. */
		public String name;
		
		/** The in bytes. */
		public long inBytes;
		
		/** The out chars xml. */
		public long outCharsXml;
		
		/** The out chars json. */
		public long outCharsJson;
		
		/** The out bytes bin. */
		public long outBytesBin;
		
		/** The total seconds. */
		public long totalSeconds;
		
		/** The process seconds. */
		public long processSeconds;
		
		/** The result. */
		public String result;
		
		/**
		 * Instantiates a new test file.
		 *
		 * @param name the name
		 */
		public TestFile(String name) {
			this.name = name;
			this.result = "";
		}
		
		/**
		 * Plus.
		 *
		 * @param tf the tf
		 */
		public void plus(TestFile tf)
		{
			this.inBytes += tf.inBytes;
			this.outCharsXml += tf.outCharsXml;
			this.outCharsJson += tf.outCharsJson;
			this.outBytesBin += tf.outBytesBin;
			this.totalSeconds += tf.totalSeconds;
			this.processSeconds += tf.processSeconds;
			if ( tf.result == "fail") this.result = tf.result;
		}
		
		/**
		 * Divide.
		 *
		 * @param tf the tf
		 * @param divisor the divisor
		 */
		public void divide(TestFile tf, int divisor)
		{
			if ( divisor == 0 ) return;
			this.inBytes = tf.inBytes / divisor;
			this.outCharsXml = tf.outCharsXml / divisor;
			this.outCharsJson = tf.outCharsJson / divisor;
			this.outBytesBin = tf.outBytesBin / divisor;
			this.totalSeconds = tf.totalSeconds / divisor;
			this.processSeconds = tf.processSeconds / divisor;
		}
	}
	
	/** The test file list. */
	private static List<TestFile> testFileList  = new ArrayList<TestFile>();
	
	/** The test file. */
	private static TestFile testFile;
	
	/** The format stats. */
	private static String formatStats = "%40s %8d %6d %6d %4s %8d %8d %8d%n";
	
	/** The header. */
	private static String[] header = { "Test input file name", "Length", "TotSec", "PrcSec", "P/F", "Out xml ", "Out json", "Out bin "};
	
	/** The separator. */
	private static String[] separator = { "-------------------------------", "---------", "------", "------", "----", "---------","---------","---------"};
	
	/** The out line list. */
	private static List<String> outLineList = new ArrayList<String>();
	
	/** The statistics filename. */
	private static String statisticsFilename = "TestStatistics.txt";
	
	/** The diff line list. */
	private static List<String> diffLineList = new ArrayList<String>();
	
	/** The differences filename. */
	private static String differencesFilename = "TestDifferences.txt";


	/**
	 * The main method.
	 *
	 * @param packagePathIn the package path in
	 * @param configFilename the config filename
	 */
	public void Run(String packagePathIn, String configFilename)
	{
		/** initialize and configure */
		long totalStart = System.nanoTime();
		packagePath = packagePathIn;
		System.out.format("In %s config is %s.\n", packagePath,  configFilename);
		initialize(configFilename);
		boolean bFirst = true;
		boolean bSuccess = true;
		int fileCount = 0;
		for ( String filename : inputFileList)
		{
			if ( filename.startsWith("#")) continue;	// commented out
			if ( bFirst ) doActivate(workingDirectory, algorithmConfig);
			bFirst = false;
			//
			float score = processInputFile( filename );
			++ fileCount;
			System.out.format("File %d %s score=%f\n", fileCount, filename,score);
		}	
		printStatistics();
		String filename = outputDirectory + differencesFilename;
		theWriter.linesToFile(filename,diffLineList);
		doDeactivate();
		long totalSeconds = TimeUnit.SECONDS.convert(System.nanoTime() - totalStart, TimeUnit.NANOSECONDS);
		System.out.format("%s  Processed %d files in %d seconds.\n", bSuccess?"SUCCESS!":"ERROR!", fileCount, totalSeconds);
	}

	/**
	 * Initialize.
	 *
	 * @param configFilename the config filename
	 */
	public static void initialize(String configFilename)
	{
		System.out.println("Current Directory: " + System.getProperty("user.dir"));
		//		String packageName = new Object(){}.getClass().getPackage().getName();
		//		packagePath = packageName.replace(".", "/") + "/";

		/** Initialize logger instance */
		logger = LoggerFactory.getLogger(new Object(){}.getClass());
		try {
			/** The log config file path. */
			logConfigFilePath = packagePath + "log4j.file.properties";
			DataInputStream rf = new DataInputStream(Reader.findStreamInClasspathOrFileSystem(logConfigFilePath));
			PropertyConfigurator.configure(rf);
		} catch (IOException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();			
		}	
		logger.info("JUnit version " + junit.runner.Version.id());

		Properties testAppConfig = new Properties();		
		try {
			/** The config file path. */
			configFilePath = packagePath + configFilename;
			DataInputStream dis = new DataInputStream(Reader.findStreamInClasspathOrFileSystem(configFilePath));
			testAppConfig.loadFromXML(dis);
		} catch (InvalidPropertiesFormatException e1) {
			e1.printStackTrace();				
		} catch (IOException e1) {
			e1.printStackTrace();				
		}
		// set config values
		// Must set working directory in Eclipse to /stanford/target/test-classes
		workingDirectory = System.getProperty("user.dir") + "/" + packagePath;
		algorithmConfig = testAppConfig.getProperty("algorithmConfig");
		String name = testAppConfig.getProperty("inputFileList");
		String listFile = workingDirectory + "/" + name;		
		System.out.println("Input List File: " + listFile);		
		// TODO - generalize
		inputFileList = theReader.fileToLines( listFile );
		inputDirectory = workingDirectory + "input.benchmark/";
		File inDir = new File(inputDirectory);
		if ( inDir.exists())
		{
			int count = inDir.list().length;
			System.out.println("count=" + count);
		}
		else
		{
			throw new RuntimeException("input directory does not exist");
		}
		outputDirectory = workingDirectory + "output/";
		File outDir = new File(outputDirectory);
		if (!outDir.exists())
		{
			System.out.println("creating directory: " + outputDirectory);
			boolean result = outDir.mkdir();  
			if(result){    
				System.out.println("created directory: " + outputDirectory);
			}
		}
	}

	/**
	 * Process input file.
	 *
	 * @param filename the filename
	 * @return the float
	 */
	private float processInputFile( String filename) 
	{
		long totalStart = System.nanoTime();    
		testFile = new TestFile(filename);

		/** Create a document object. */
		File file = new File(inputDirectory+filename);
		testFile.inBytes = file.length();
		String docId = filename;
		Corpus corpus = null;
		String docType = "Text";
		String uri = file.getAbsolutePath();
		String language = "English";
		HltContentContainer hltcc = new HltContentContainer();
		Document document = DocumentMaker.getInstance().createDefaultDocument(
				docId, 	
				corpus,		
				docType, 	
				uri, 		
				language,
				uri,		// filename
				hltcc,
                tokenizerType);

		// create the HltContentContainer object
		long processStart = System.nanoTime();    
		HltContentContainer hltContentContainer = doProcess(document,hltcc);
		testFile.processSeconds = TimeUnit.SECONDS.convert(System.nanoTime() - processStart, TimeUnit.NANOSECONDS); 

		/** serialization */
		float score = doScore( document, hltContentContainer);
		testFile.totalSeconds = TimeUnit.SECONDS.convert(System.nanoTime() - totalStart, TimeUnit.NANOSECONDS);

		testFileList.add(testFile);
		return score;
	}

	/**
	 * Prints the statistics.
	 */
	private static void printStatistics(){
		String filename = outputDirectory + statisticsFilename;
		String formatHeader = formatStats.replace("d",  "s");
		outLineList.add(String.format(formatHeader, (Object[]) header));
		outLineList.add(String.format(formatHeader, (Object[]) separator));
		TestFile totalFile = new TestFile("TOTAL");
		totalFile.result = "pass";
		TestFile averageFile = new TestFile("AVERAGE");
		for ( TestFile tf : testFileList)
		{
			printTestFileStatistics( tf );
			totalFile.plus(tf);
		}
		outLineList.add(String.format(formatHeader, (Object[]) separator));
		printTestFileStatistics( totalFile );
		outLineList.add(String.format("%n", ""));
		averageFile.divide(totalFile, testFileList.size());
		printTestFileStatistics( averageFile );
		theWriter.linesToFile(filename ,outLineList);
	}

	/**
	 * Prints the test file statistics.
	 *
	 * @param tf the tf
	 */
	private static void  printTestFileStatistics( TestFile tf ) {
		String name = tf.name;
		int chunk = 40;	// Corresponds to format string
		int index = 0;
		while ( name.length() > chunk )
		{
			outLineList.add( String.format("%s%n",name.substring(index, index + chunk)));
			name = name.substring(chunk);
		}
		outLineList.add( String.format(formatStats, 
				name, 
				tf.inBytes,
				tf.totalSeconds,tf.processSeconds,tf.result,
				tf.outCharsXml, tf.outCharsJson, tf.outBytesBin));
	}

}