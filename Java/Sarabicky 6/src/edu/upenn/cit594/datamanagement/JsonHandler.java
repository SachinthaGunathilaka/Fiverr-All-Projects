package edu.upenn.cit594.datamanagement;


import java.io.IOException;
import java.util.List;

import org.json.simple.JSONArray;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import edu.upenn.cit594.ui.ScreenWriter;


public class JsonHandler extends FileHandler{
	
	private JSONArray jsonArray;
	
	/**
	 * Constructor taking a single fileName parameter
	 * @param fileName represents the name of the Json file
	 */
	public JsonHandler(String fileName){
		
		super(fileName);
		setJSONArray();
	}
	
	/**
	 * Creates the JsonArray
	 */
	private void setJSONArray() {
		
		
		JSONParser parser = new JSONParser();
		
		try {
			this.jsonArray = (JSONArray)parser.parse(fileReader);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			ScreenWriter.DisplayErrorAndQuit("IOException for creating the JSON array");
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			ScreenWriter.DisplayErrorAndQuit("ParseException for creating the JSON array");
		}
		
		
	}
	
	/**
	 * Returns a list of Json objects
	 * @return
	 */
	public List<Object> getFileAsList() {
		
		for(Object obj : jsonArray) {
			objArray.add(obj);
		}
		
		return objArray;
	}
	
	
	
	
}
