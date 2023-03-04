package edu.upenn.cit594.datamanagement;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import edu.upenn.cit594.logging.Logger;
import edu.upenn.cit594.ui.ScreenWriter;

public abstract class FileHandler {
	
	protected File file;
	protected FileReader fileReader;
	protected BufferedReader br;
	protected List<Object> objArray = new ArrayList<Object>();
	private String fileName;
	
	public FileHandler(String fileName) {
		this.fileName = fileName;
		open(fileName);
		setFileReader();
		setBufferedReader();
		
	}
	
	public String getFileName() {
		return fileName;
	}
	
	/**
	 * Open the file
	 * @param fileName of the file we are opening
	 */
	protected void open(String fileName) {
		
		file = new File(fileName);
		Logger.getInstance().log(fileName);
		
		if(!file.canRead()) {
			ScreenWriter.DisplayErrorAndQuit("Cannot read the file");
		}
		
		if(!file.setReadable(true)) {
			ScreenWriter.DisplayErrorAndQuit("Cannot set to readable!");
		}
		
	}
	
	/**
	 * Create the fileReader for the file
	 */
	protected void setFileReader() {
		try {
			this.fileReader = new FileReader(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			ScreenWriter.DisplayErrorAndQuit("Could not create file reader");
		}
	}
	
	/**
	 * Create the buffered reader using the file reader
	 */
	protected void setBufferedReader() {
		this.br = new BufferedReader(fileReader);
	}
	
	/**
	 * to be implemented by the subclasses
	 * @return a List of objects
	 */
	public abstract List<Object> getFileAsList();

	
	/**
	 * close the file reader
	 */
	public void closeFileReader() {
	
		try {
			fileReader.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			ScreenWriter.DisplayErrorAndQuit("Failed to close file reader!");
		}
		
		
	}
}
