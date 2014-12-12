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

package adept.mapreduce;

import java.io.IOException;
import java.util.StringTokenizer;
import java.util.*;

//import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
//import org.apache.hadoop.mapreduce.Job;
//import org.apache.hadoop.mapreduce.Mapper;
//import org.apache.hadoop.mapreduce.Reducer;
//import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
//import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.conf.*;

public class MapReduceExample extends Configured implements Tool
{
	public static class MapClass extends MapReduceBase

    implements Mapper<Text, Text, Text, Text> {

    public void map(Text key, Text value,

                    OutputCollector<Text, Text> output,

                    Reporter reporter) throws IOException {

        output.collect(value, key);

    }

}

public static class Reduce extends MapReduceBase

    implements Reducer<Text, Text, Text, Text> {

    public void reduce(Text key, Iterator<Text> values,

                       OutputCollector<Text, Text> output,

                       Reporter reporter) throws IOException {

        String csv = "";

        while (values.hasNext()) {

            if (csv.length() > 0) csv += ",";

            csv += values.next().toString();

        }

        output.collect(key, new Text(csv));

    }

}

public int run(String[] args) throws Exception {

    Configuration conf = getConf();
    //Configuration conf = new Configuration();

    JobConf job = new JobConf(conf, MapReduceExample.class);

    Path in = new Path(args[0]);

    Path out = new Path(args[1]);

    FileInputFormat.setInputPaths(job, in);

    FileOutputFormat.setOutputPath(job, out);

    job.setJobName("MapReduecExample");

    job.setMapperClass(MapClass.class);

    job.setReducerClass(Reduce.class);

    job.setInputFormat(KeyValueTextInputFormat.class);

    job.setOutputFormat(TextOutputFormat.class);

   job.setOutputKeyClass(Text.class);

   job.setOutputValueClass(Text.class);

   job.set("key.value.separator.in.input.line", ",");

   JobClient.runJob(job);

   return 0;

}

public static void main(String[] args) throws Exception 
 { 

   int res = ToolRunner.run(new Configuration(), new MapReduceExample(), args);

   System.exit(res);

 }
}
