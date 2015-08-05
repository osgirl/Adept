package adept.kbapi.sql;

import adept.kbapi.KBParameters;

import adept.common.*;
import java.sql.*;
import javax.sql.*;
import javax.naming.*;
import java.text.SimpleDateFormat;
import org.apache.commons.dbcp2.BasicDataSource;

/**
 * Utility class that interacts with the SQL metadata database.
 * Provides wrappers for connecting to database, executing queries
 * and updates, committing, rolling back and closing connections.
 *
 */
public class QuickJDBC {
	private static BasicDataSource connectionPool;
        private static final int MAX_ACTIVE_CONNECTIONS = 50; 
        private static final int MAX_IDLE_CONNECTIONS = 8;
        
	/**
	 * initialize connection pool. This connection pool is to
	 * be used by the entire KB setup.
	 */
	private static void initialize()
	{
            try
            {
                connectionPool = new BasicDataSource();
                connectionPool.setUrl(KBParameters.metadataUrl);
                connectionPool.setUsername(KBParameters.metadataUsername);
                connectionPool.setPassword(KBParameters.metadataPassword);
                connectionPool.setDriverClassName("org.postgresql.Driver");
                connectionPool.setInitialSize(3);
                connectionPool.setDefaultAutoCommit(false);
                connectionPool.setMaxTotal(MAX_ACTIVE_CONNECTIONS);
                connectionPool.setMaxIdle(MAX_IDLE_CONNECTIONS);
            }
            catch(Exception e)
            {
                    e.printStackTrace();
            }
	}
	
	/**
	 * retrieve connection instance
	 */
	public static Connection getConnection() throws SQLException
	{
            if(connectionPool == null)
            {
                initialize();
            }
            return connectionPool.getConnection();
	}
	
    /**
     * execute database update
     */
	public static void executeSqlUpdate(PreparedStatement preparedStmt) throws SQLException
	{
            try {
		preparedStmt.executeUpdate();
            } finally {
                preparedStmt.close();
            }
	}
	
	/**
	 * execute query to check if object exists in the database
	 */
	public static boolean recordExists(PreparedStatement preparedStmt) throws SQLException
	{
                boolean doesRecordExist = false;
		java.sql.ResultSet rs = preparedStmt.executeQuery();
		doesRecordExist = rs.next();
		rs.close();
                return doesRecordExist;
	}
        
        public static void printPoolInfo() {
            if (connectionPool != null) {
                System.out.println("Connection pool active connections: " + connectionPool.getNumActive());
                System.out.println("Connection pool idle connections: " + connectionPool.getNumIdle());
            }
        }
}