package edu.upenn.cit594.processor;

public class FileType {
	
	
	public static boolean checkIfJson(String fileName) {
		String jsonExtension = ".json";
		if(jsonExtension.equalsIgnoreCase(fileName.substring(fileName.length()-5))){
			return true;
		}
		else {
			return false;
		}
	}
	
	public static boolean checkIfTxt(String fileName) {
		String txtExtension = ".txt";
		if(txtExtension.equalsIgnoreCase(fileName.substring(fileName.length()-4))){
			return true;
		}
		else {
			return false;
		}
	}

	public static boolean checkIfCsv(String fileName) {
		String csvExtension = ".csv";
		if(csvExtension.equalsIgnoreCase(fileName.substring(fileName.length()-4))){
			return true;
		}
		else {
			return false;
		}
	}
}
