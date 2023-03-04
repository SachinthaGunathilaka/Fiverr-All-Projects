package edu.upenn.cit594.util;

public class Format {
	
	public static String formatStateCountForFile(String state, Integer count) {
		String formatted = "";
		
		formatted += state + " " + count +"\n";
		
		
		return formatted;
	}
	
	public static String formatStateCountForPrint(String state, Integer count) {
		String formatted = "";
		
		formatted += state + ": " + count;
		
		
		return formatted;
	}
	
	public static String formatStateTweetForFile(String state, String text) {
		String formatted = "";
		
		formatted += state + '\t' + text +"\n";
		
		
		return formatted;
	}
	
	public static String formatStateTweetForFileLastLine(String state, String text) {
		String formatted = "";
		
		formatted += state + '\t' + text;
		
		
		return formatted;
	}
	
	
	
}
