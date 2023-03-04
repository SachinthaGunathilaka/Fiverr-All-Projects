package edu.upenn.cit594.datamanagement;

import java.io.IOException;
import java.util.List;

import edu.upenn.cit594.ui.ScreenWriter;

public class CsvHandler extends FileHandler{
	
	public CsvHandler(String fileName) {
		super(fileName);
		// TODO Auto-generated constructor stub
		
		
		
	}
	
	/**
	 * Create a list of objects, representing lines from the csv file
	 * @return
	 */
	@Override
	public List<Object> getFileAsList() {
		// TODO Auto-generated method stub
		String line;
		try {
			while((line = br.readLine()) != null) {
				objArray.add(line);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			ScreenWriter.DisplayErrorAndQuit("IOException when trying to read line from CSV file");
		}
		
		return objArray;
	}
	
}
