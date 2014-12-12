/*******************************************************************************
 * Raytheon BBN Technologies Corp., March 2013
 * 
 * THIS CODE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS
 * OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 * Copyright 2013 Raytheon BBN Technologies Corp.  All Rights Reserved.
 ******************************************************************************/
package adept.restapi;

import org.eclipse.jetty.plus.servlet.ServletHandler;
import org.eclipse.jetty.server.Connector;
import org.eclipse.jetty.server.Server;
import org.eclipse.jetty.servlet.ServletHolder;

// TODO: Auto-generated Javadoc
/**
 * The Class StanfordCoreNlpServer.
 */
public class RestServer 
{

	/** The server instance. */
	private Server server;
	
	/**
	 * Instantiates a new Stanford Core NLP server.
	 *
	 */
	public RestServer() {
	}
	
	/**
	 * Start server.
	 *
	 * @param port the port
	 * @param sh the sh
	 * @throws Exception the exception
	 */
	public void run(int port, ServletHolder sh) throws Exception
	{
	    server = new Server(port);
	    ServletHandler handler = new ServletHandler();	    
	    handler.addServletWithMapping(sh, "/*");	    
	    server.setHandler(handler);
	    server.start();
	    server.join();
	}

	/**
	 * Start server in background.
	 *
	 * @param port the port
	 * @param sh the sh
	 * @throws Exception the exception
	 */
	public void runInBackground(int port, ServletHolder sh) throws Exception
	{
	    server = new Server(port);
	    ServletHandler handler = new ServletHandler();
	    handler.addServletWithMapping(sh, "/*");
	    server.setHandler(handler);
	    server.start();
	}

	/**
	 * Stop server.
	 *
	 * @throws Exception the exception
	 */
	public void stopServer() throws Exception
	{
		if (server != null)
			server.stop();
	}
	
	/**
	 * Get the port the server is listening on.
	 * 
	 * @return The port the server is running on, if port 0 was specified.
	 */
	public int getPort()
	{
		if (server != null) {
			Connector[] connectors = server.getConnectors();
			if (connectors.length >= 1) {
				// If the server is running, there should be just
				return connectors[0].getLocalPort();
			}
		}
		return -1;
	}

}