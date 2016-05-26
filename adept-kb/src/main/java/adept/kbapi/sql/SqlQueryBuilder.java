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

package adept.kbapi.sql;

import java.sql.*;
import java.util.List;

/**
 * Utility to build SQL query and update statements
 */
public class SqlQueryBuilder {

	/** SQL templates for querying metadata */
	public static final String getExternalKbIds =
			"SELECT \"ExternalKBReferences\".\"ExternalID\", \"ExternalKBReferences\".\"ExternalKB\" FROM"
					+ "\"ExternalKBReferences\" WHERE \"ExternalKBReferences\".\"AdeptKBID\" = ?";

	public static final String getAdeptIdByExternalId =
			"SELECT \"ExternalKBReferences\".\"AdeptKBID\" FROM"
					+ "\"ExternalKBReferences\" WHERE \"ExternalKBReferences\".\"ExternalID\" = ? AND \"ExternalKBReferences\".\"ExternalKB\" = ?";

	public static final String textChunkById =
			"SELECT * FROM \"TextChunks\" WHERE \"ID\" = ?";

	public static final String textProvenanceByOwnerId =
			"SELECT "
					+ "TP.\"confidence\" AS \"TP_confidence\", "
					+ "Chunk.\"beginOffset\" AS \"Chunk_beginOffset\", "
					+ "Chunk.\"endOffset\" AS \"Chunk_endOffset\", "
					+ "Chunk.\"value\" AS \"Chunk_value\", "
					+ "SA.\"algorithmName\" AS \"SA_algorithmName\", "
					+ "SA.\"contributingSiteName\" AS \"SA_contributingSiteName\", "
					+ "CORPUS.\"name\" AS \"CORPUS_name\", "
					+ "CORPUS.\"ID\" AS \"CORPUS_ID\", "
					+ "CORPUS.\"URI\" AS \"CORPUS_URI\", "
					+ "CORPUS.\"type\" AS \"CORPUS_type\", "
					+ "SD.\"ID\" AS \"SD_ID\", "
					+ "SD.\"publicationDate\" AS \"SD_publicationDate\", "
					+ "SD.\"URI\" AS \"SD_URI\", "
					+ "SD.\"sourceLanguage\" AS \"SD_sourceLanguage\", "
					+ "TP.\"ID\" AS \"TP_ID\" "
					+ "FROM \"TextProvenances\" AS TP "
					+ "INNER JOIN \"TextChunks\" AS CHUNK ON TP.chunk = CHUNK.\"ID\" "
					+ "LEFT JOIN \"SourceAlgorithms\" AS SA ON TP.\"sourceAlgorithm\" = SA.\"algorithmName\" "
					+ "LEFT JOIN \"SourceDocuments\" AS SD ON CHUNK.\"sourceDocument\"=SD.\"ID\" "
					+ "LEFT JOIN \"Corpus\" as CORPUS on CORPUS.\"ID\"=SD.CORPUS "
					+ "WHERE TP.\"KBId\" = ?";

	public static final String textProvenanceByOwnerIds =
			"SELECT "
					+ "TP.\"KBId\" AS \"TP_KBId\", "
					+ "TP.\"confidence\" AS \"TP_confidence\", "
					+ "Chunk.\"beginOffset\" AS \"Chunk_beginOffset\", "
					+ "Chunk.\"endOffset\" AS \"Chunk_endOffset\", "
					+ "Chunk.\"value\" AS \"Chunk_value\", "
					+ "SA.\"algorithmName\" AS \"SA_algorithmName\", "
					+ "SA.\"contributingSiteName\" AS \"SA_contributingSiteName\", "
					+ "CORPUS.\"ID\" AS \"CORPUS_ID\", "
					+ "CORPUS.\"name\" AS \"CORPUS_name\", "
					+ "CORPUS.\"URI\" AS \"CORPUS_URI\", "
					+ "CORPUS.\"type\" AS \"CORPUS_type\", "
					+ "SD.\"ID\" AS \"SD_ID\", "
					+ "SD.\"publicationDate\" AS \"SD_publicationDate\", "
					+ "SD.\"URI\" AS \"SD_URI\", "
					+ "SD.\"sourceLanguage\" AS \"SD_sourceLanguage\", "
					+ "TP.\"ID\" AS \"TP_ID\" "
					+ "FROM \"TextProvenances\" AS TP "
					+ "INNER JOIN \"TextChunks\" AS CHUNK ON TP.chunk = CHUNK.\"ID\" "
					+ "LEFT JOIN \"SourceAlgorithms\" AS SA ON TP.\"sourceAlgorithm\" = SA.\"algorithmName\" "
					+ "LEFT JOIN \"SourceDocuments\" AS SD ON CHUNK.\"sourceDocument\"=SD.\"ID\" "
					+ "LEFT JOIN \"Corpus\" as CORPUS on CORPUS.\"ID\"=SD.CORPUS "
					+ "WHERE TP.\"KBId\" IN (";

	public static final String sourceDocumentById =
			"SELECT * FROM \"SourceDocuments\" WHERE \"ID\" = ?";

	public static final String sourceAlgorithmByName =
			"SELECT * FROM \"SourceAlgorithms\" WHERE \"algorithmName\" = ?";

	public static final String corpusById =
			"SELECT * FROM \"Corpus\" WHERE \"ID\" = ?";

	public static final String entityIdsByChunkValue =
			"SELECT \"TextProvenances\".\"KBId\", \"TextProvenances\".\"confidence\""
					+ "FROM \"TextProvenances\" JOIN \"TextChunks\" ON \"TextProvenances\".\"chunk\" = \"TextChunks\".\"ID\" "
					+ "WHERE LOWER(\"TextChunks\".\"value\") = ?";

	public static final String entityIdsByChunkCaseSensitiveRegex =
			"SELECT \"TextProvenances\".\"KBId\", \"TextProvenances\".\"confidence\""
					+ "FROM \"TextProvenances\" JOIN \"TextChunks\" ON \"TextProvenances\".\"chunk\" = \"TextChunks\".\"ID\" "
					+ "WHERE \"TextChunks\".\"value\" ~ ?";

	public static final String entityIdsByChunkCaseInsensitiveRegex =
			"SELECT \"TextProvenances\".\"KBId\", \"TextProvenances\".\"confidence\""
					+ "FROM \"TextProvenances\" JOIN \"TextChunks\" ON \"TextProvenances\".\"chunk\" = \"TextChunks\".\"ID\" "
					+ "WHERE \"TextChunks\".\"value\" ~* ?";

	public static final String relationIdsByChunkValue =
			"SELECT DISTINCT \"TextProvenances\".\"KBId\", \"TextProvenances\".\"confidence\" "
					+ "FROM \"TextProvenances\" JOIN \"TextChunks\" ON \"TextProvenances\".\"chunk\" = \"TextChunks\".\"ID\" "
					+ "WHERE \"TextChunks\".\"value\" = ?";

	public static final String getTextProvenanceKbIdsWithinChunkOffset =
			"SELECT DISTINCT \"TextProvenances\".\"KBId\" "
					+ "FROM \"TextProvenances\" JOIN \"TextChunks\" ON \"TextProvenances\".\"chunk\" = \"TextChunks\".\"ID\""
					+ "WHERE \"TextChunks\".\"sourceDocument\" = ? AND \"TextChunks\".\"beginOffset\" >= ?"
					+ "AND \"TextChunks\".\"endOffset\" <= ?";

	/** SQL templates for updating metadata */
	public static final String checkExists =
			"SELECT * from \"%s\" WHERE \"%s\"= ?";

	public static final String doesExternalKbIdExist =
			"SELECT * FROM \"ExternalKBReferences\" WHERE \"ExternalID\"= ? AND \"ExternalKB\" = ?";

	public static final String insertTextChunk =
			"INSERT INTO \"TextChunks\"(\"ID\", \"value\", \"beginOffset\", \"endOffset\", \"sourceDocument\") "
					+ "values (?, ?, ?, ?, ?)";

	public static final String insertTextProvenance =
			"INSERT INTO \"TextProvenances\"(\"ID\", \"chunk\", \"sourceAlgorithm\", \"KBId\", \"confidence\") "
					+ "values (?, ?, ?, ?, ?)";

	// Since TextChunks are 1:1 with TextProvenances, deleting the TextChunk
	// entry will cascade delete the TextProvenance entry
	public static final String deleteTextProvenance =
			"DELETE " +
					"FROM \"TextChunks\" " +
					"WHERE \"ID\" IN " +
					"	(SELECT \"chunk\" " +
					"	 FROM \"TextProvenances\" " +
					"	 WHERE \"ID\" = ?)";

	public static final String deleteTextProvenancesByObjectId =
			"DELETE " +
					"FROM \"TextChunks\" " +
					"WHERE \"ID\" IN " +
					"	(SELECT \"chunk\" " +
					"	 FROM \"TextProvenances\" " +
					"	 WHERE \"KBId\" = ?)";

	public static final String deleteOrphanSourceAlgorithms =
			"DELETE " +
					"FROM \"SourceAlgorithms\" " +
					"WHERE \"algorithmName\" NOT IN " +
					"	(SELECT DISTINCT \"sourceAlgorithm\" " +
					"	 FROM \"TextProvenances\")";

	public static final String deleteOrphanSourceDocuments =
			"DELETE " +
					"FROM \"SourceDocuments\" " +
					"WHERE \"ID\" NOT IN " +
					"	(SELECT DISTINCT \"sourceDocument\" " +
					"	 FROM \"TextChunks\")";

	public static final String deleteOrphanCorpus =
			"DELETE " +
					"FROM \"Corpus\" " +
					"WHERE \"ID\" NOT IN " +
					"	(SELECT DISTINCT \"corpus\" " +
					"	 FROM \"SourceDocuments\")";

	public static final String deleteExternalKbIdMapsForAdeptElement =
			"DELETE FROM \"ExternalKBReferences\" WHERE \"AdeptKBID\" = ?";

	public static final String deleteSingleExternalKbIdMapRecord =
			"DELETE FROM \"ExternalKBReferences\" WHERE \"AdeptKBID\" = ? "
					+ "AND \"ExternalID\" = ? AND \"ExternalKB\" = ?";

	public static final String insertSourceDocument =
			"INSERT INTO \"SourceDocuments\"(\"ID\", \"sourceLanguage\", \"corpus\", \"publicationDate\", \"URI\") "
					+ "values (?, ?, ?, ?, ?)";

	public static final String insertSourceAlgorithm =
			"INSERT INTO \"SourceAlgorithms\"(\"algorithmName\", \"contributingSiteName\") "
					+ "values (?, ?)";

	public static final String insertCorpus =
			"INSERT INTO \"Corpus\"(\"ID\", \"type\", \"name\", \"URI\") "
					+ "values (?, ?, ?, ?)";

	public static final String insertExternalKbIdMap =
			"INSERT INTO \"ExternalKBReferences\"(\"AdeptKBID\", \"ExternalID\", \"ExternalKB\") "
					+ "values (?,?,?)";

	public static final String insertDocumentText = "INSERT INTO \"DocumentTexts\"(docID, corpusID, content) "
			+ "values (?, ?, ?)";

	public static final String deleteDocumentText = "DELETE FROM \"DocumentTexts\" WHERE docID = ? AND corpusID = ?";

	public static final String queryDocumentText =
			"SELECT content " +
					"FROM \"DocumentTexts\"\n" +
					"WHERE docID = ? AND corpusID = ?";

	/**
	 * create SQL query to get text chunk given the primary key ID.
	 */
	public static PreparedStatement createTextChunkByIdQuery(String textChunkId,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(textChunkById);
		preparedStatement.setString(1, textChunkId);
		return preparedStatement;
	}

	/**
	 * create SQL query to get source document given primary key ID.
	 */
	public static PreparedStatement createSourceDocumentByIdQuery(String sourceDocumentId,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(sourceDocumentById);
		preparedStatement.setString(1, sourceDocumentId);
		return preparedStatement;
	}

	/**
	 * create SQL query to get source algorithm given primary key ID.
	 */
	public static PreparedStatement createSourceAlgorithmByIdQuery(String sourceAlgorithmId,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(sourceAlgorithmByName);
		preparedStatement.setString(1, sourceAlgorithmId);
		return preparedStatement;
	}

	/**
	 * create SQL query to get corpus record given primary key ID.
	 */
	public static PreparedStatement createCorpusIdQuery(String corpusId, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(corpusById);
		preparedStatement.setString(1, corpusId);
		return preparedStatement;
	}

	/**
	 * create SQL query to get the KB Entity IDs that contain mentions within a
	 * given span of text.
	 */
	public static PreparedStatement createEntityIdsByChunkValueQuery(String chunkValue,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(entityIdsByChunkValue);
		preparedStatement.setString(1, chunkValue);
		return preparedStatement;
	}

	/**
	 * create SQL query to get the KB Entity IDs that contain mentions within a
	 * given span of text.
	 */
	public static PreparedStatement createEntityIdsByChunkRegexQuery(String regex,
			Connection connection, boolean caseSensitive) throws SQLException {
		String statementString = caseSensitive ? entityIdsByChunkCaseSensitiveRegex
				: entityIdsByChunkCaseInsensitiveRegex;
		PreparedStatement preparedStatement = connection.prepareStatement(statementString);
		preparedStatement.setString(1, regex);
		return preparedStatement;
	}

	/**
	 * create SQL query to get KB relation IDs that contain mentions within a
	 * given span of text.
	 */
	public static PreparedStatement createRelationIdsByChunkValueQuery(String chunkValue,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(relationIdsByChunkValue);
		preparedStatement.setString(1, chunkValue);
		return preparedStatement;
	}

	/**
	 * add to a SQL update statement batch to insert a new text chunk.
	 */
	public static void addTextChunkInsertQueryToBatch(String chunkId, String value,
			int beginOffset, int endOffset, String sourceDocument,
			PreparedStatement chunkInsertBatchStatement) throws SQLException {
		chunkInsertBatchStatement.setString(1, chunkId);
		chunkInsertBatchStatement.setString(2, value);
		chunkInsertBatchStatement.setInt(3, beginOffset);
		chunkInsertBatchStatement.setInt(4, endOffset);
		chunkInsertBatchStatement.setString(5, sourceDocument);
		chunkInsertBatchStatement.addBatch();
	}

	/**
	 * add to a SQL update statement batch to insert a new text provenance.
	 */
	public static void addTextProvenanceInsertQueryToBatch(String provenanceId, String chunk,
			String sourceAlgorithm, String sourceKbId, float confidence,
			PreparedStatement textProvenanceInsertBatchStatement) throws SQLException {
		textProvenanceInsertBatchStatement.setString(1, provenanceId);
		textProvenanceInsertBatchStatement.setString(2, chunk);
		textProvenanceInsertBatchStatement.setString(3, sourceAlgorithm);
		textProvenanceInsertBatchStatement.setString(4, sourceKbId);
		textProvenanceInsertBatchStatement.setDouble(5, confidence);
		textProvenanceInsertBatchStatement.addBatch();
	}

	public static void addTextProvenanceDeleteQueryToBatch(String provenanceId,
			PreparedStatement textProvenanceDeleteBatchStatement) throws SQLException {
		textProvenanceDeleteBatchStatement.setString(1, provenanceId);
		textProvenanceDeleteBatchStatement.addBatch();
	}

	/**
	 * create SQL query to check if a text chunk already exists in the DB given
	 * its primary key ID.
	 */
	public static PreparedStatement doesChunkExistQuery(String ID, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(String.format(
				checkExists, "TextChunks", "ID"));
		preparedStatement.setString(1, ID);

		return preparedStatement;
	}

	/**
	 * create SQL query to check if an entity mention already exists in the DB
	 * given its primary key ID.
	 */
	public static PreparedStatement doesEntityMentionExistQuery(String ID, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(String.format(
				checkExists, "EntityMentions", "ID"));
		preparedStatement.setString(1, ID);

		return preparedStatement;
	}

	/**
	 * create SQL query to check if a source document already exists.
	 */
	public static PreparedStatement doesSourceDocExistQuery(String ID, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(String.format(
				checkExists, "SourceDocuments", "ID"));
		preparedStatement.setString(1, ID);

		return preparedStatement;
	}

	/**
	 * create SQL update statement to insert a new source document.
	 */
	public static PreparedStatement createSourceDocumentInsertQuery(String sourceDocId,
			String sourceDocUri, String language, String corpusId, Date pubDate,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(insertSourceDocument);
		preparedStatement.setString(1, sourceDocId);
		preparedStatement.setString(2, language);
		preparedStatement.setString(3, corpusId);
		preparedStatement.setDate(4, pubDate);
		preparedStatement.setString(5, sourceDocUri);
		return preparedStatement;
	}

	/**
	 * create SQL query to check if a source algorithm already exists in the DB.
	 */
	public static PreparedStatement doesSourceAlgorithmExistQuery(String ID, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(String.format(
				checkExists, "SourceAlgorithms", "algorithmName"));
		preparedStatement.setString(1, ID);

		return preparedStatement;
	}

	/**
	 * create SQL update statement to insert a new source algorithm.
	 */
	public static PreparedStatement createSourceAlgorithmInsertQuery(String algName, String site,
			Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(insertSourceAlgorithm);
		preparedStatement.setString(1, algName);
		preparedStatement.setString(2, site);

		return preparedStatement;
	}

	/**
	 * create SQL query to check if corpus already exists in the DB.
	 */
	public static PreparedStatement doesCorpusExistQuery(String ID, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(String.format(
				checkExists, "Corpus", "ID"));
		preparedStatement.setString(1, ID);

		return preparedStatement;
	}

	/**
	 * create SQL update statement to insert new corpus.
	 */
	public static PreparedStatement createCorpusInsertQuery(String ID, String type, String name,
			String uri, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(insertCorpus);
		preparedStatement.setString(1, ID);
		preparedStatement.setString(2, type);
		preparedStatement.setString(3, name);
		preparedStatement.setString(4, uri);

		return preparedStatement;
	}

	public static PreparedStatement createGetKBIDsByChunkQuery(String sourceDocId, int beginOffset,
			int endOffset, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection
				.prepareStatement(getTextProvenanceKbIdsWithinChunkOffset);
		preparedStatement.setString(1, sourceDocId);
		preparedStatement.setInt(2, beginOffset);
		preparedStatement.setInt(3, endOffset);

		return preparedStatement;
	}

	/**
	 * create SQL query to check if an external KB element is already mapped to
	 * an existing Adept KB element with any amount of confidence.
	 */
	public static PreparedStatement createdoesExternalKBIdExistQuery(String externalKbUri,
			String externalKbName, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(doesExternalKbIdExist);
		preparedStatement.setString(1, externalKbUri);
		preparedStatement.setString(2, externalKbName);

		return preparedStatement;
	}

	/**
	 * create SQL query to add a new entry into the external KB references table
	 * in the metadata store.
	 */
	public static PreparedStatement createInsertMappingToExternalKBQuery(String adeptKbElementId,
			String externalKbElementId, String externalKbName, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(insertExternalKbIdMap);
		preparedStatement.setString(1, adeptKbElementId);
		preparedStatement.setString(2, externalKbElementId);
		preparedStatement.setString(3, externalKbName);

		return preparedStatement;
	}

	/**
	 * delete all records concerning a specified Adept KB entity from the
	 * external KB references table.
	 */
	public static PreparedStatement createDeleteExternalKBIdMapsForAdeptElementQuery(
			String adeptKbUri, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection
				.prepareStatement(deleteExternalKbIdMapsForAdeptElement);
		preparedStatement.setString(1, adeptKbUri);

		return preparedStatement;
	}

	/**
	 * delete a specific record in the external KB references table.
	 */
	public static PreparedStatement createDeleteSingleExternalKBIdMapRecordQuery(String adeptUri,
			String externalUri, String externalKb, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection
				.prepareStatement(deleteSingleExternalKbIdMapRecord);
		preparedStatement.setString(1, adeptUri);
		preparedStatement.setString(2, externalUri);
		preparedStatement.setString(3, externalKb);

		return preparedStatement;
	}

	/**
	 * get external KB IDs that the given Adept KB ID maps to.
	 */
	public static PreparedStatement getExternalKBIDsQuery(String adeptKbUri, Connection connection)
			throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(getExternalKbIds);
		preparedStatement.setString(1, adeptKbUri);

		return preparedStatement;
	}

	/** get Adept KB ID that an external KBID maps to */
	public static PreparedStatement getAdeptIdByExternalIdQuery(String externalId,
			String externalKbName, Connection connection) throws SQLException {
		PreparedStatement preparedStatement = connection.prepareStatement(getAdeptIdByExternalId);
		preparedStatement.setString(1, externalId);
		preparedStatement.setString(2, externalKbName);
		return preparedStatement;
	}

	/**
	 * @param string
	 * @param sqlConnection
	 * @return
	 * @throws SQLException
	 */
	public static PreparedStatement doesNumberPhraseExistQuery(String id, Connection sqlConnection)
			throws SQLException {
		PreparedStatement preparedStatement = sqlConnection.prepareStatement(String.format(
				checkExists, "NumberMentions", "ID"));
		preparedStatement.setString(1, id);

		return preparedStatement;
	}

	/**
	 * @param id
	 * @param sqlConnection
	 * @return
	 * @throws SQLException
	 */
	public static PreparedStatement createTextProvenanceByIdQuery(String id,
			Connection sqlConnection) throws SQLException {
		PreparedStatement preparedStatement = sqlConnection
				.prepareStatement(textProvenanceByOwnerId);
		preparedStatement.setString(1, id);
		return preparedStatement;
	}

	/**
	 * @param objectUri
	 * @param sqlConnection
	 * @return
	 * @throws SQLException
	 */
	public static PreparedStatement createTextProvenanceDeleteQuery(String objectId,
			Connection sqlConnection) throws SQLException {
		PreparedStatement preparedStatement = sqlConnection
				.prepareStatement(deleteTextProvenancesByObjectId);
		preparedStatement.setString(1, objectId);
		return preparedStatement;
	}

	public static PreparedStatement createDeleteOrphanSourceAlgorithmsQuery(Connection sqlConnection)
			throws SQLException {
		PreparedStatement preparedStatement = sqlConnection
				.prepareStatement(deleteOrphanSourceAlgorithms);
		return preparedStatement;
	}

	public static PreparedStatement createDeleteOrphanSourceDocumentsQuery(Connection sqlConnection)
			throws SQLException {
		PreparedStatement preparedStatement = sqlConnection
				.prepareStatement(deleteOrphanSourceDocuments);
		return preparedStatement;
	}

	public static PreparedStatement createDeleteOrphanCorpusQuery(Connection sqlConnection)
			throws SQLException {
		PreparedStatement preparedStatement = sqlConnection.prepareStatement(deleteOrphanCorpus);
		return preparedStatement;
	}

	/**
	 * @param ids
	 * @param sqlConnection
	 * @return
	 * @throws SQLException
	 */
	public static PreparedStatement createTextProvenancesByIdsQuery(List<String> ids,
			Connection sqlConnection) throws SQLException {
		StringBuilder query = new StringBuilder(textProvenanceByOwnerIds);
		for (int i = 0; i < ids.size(); i++) {
			query.append("?,");
		}
		query.deleteCharAt(query.length() - 1);
		query.append(")");

		PreparedStatement preparedStatement = sqlConnection.prepareStatement(query.toString());
		for (int i = 0; i < ids.size(); i++) {
			preparedStatement.setString(i + 1, ids.get(i));
		}
		return preparedStatement;
	}
}
