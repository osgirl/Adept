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

package adept.kbapi.sql.objects;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * This class provides temporary instances used by the KBQueryProcessor
 * in retrieving ADEPT objects from the KB.
 */
public class SourceAlgorithmsResult {
    private String algorithmName;
    private String contributingSiteName;
    
    // parses the current row in the passed ResultSet and parses it. Does not move the cursor forward in the result set
    public SourceAlgorithmsResult(ResultSet resultSet) throws SQLException {
        if (resultSet.getRow() > 0) {
            algorithmName = resultSet.getString("algorithmName");
            contributingSiteName = resultSet.getString("contributingSiteName");
        }
    }
    
    public String getAlgorithmName() { return algorithmName; }
    public String getContributingSiteName() { return contributingSiteName; }
}