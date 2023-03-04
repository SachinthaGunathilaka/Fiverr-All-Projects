package edu.upenn.cit594.ui;


import java.util.*;
import java.util.stream.Collectors;

import edu.upenn.cit594.logging.Logger;
import edu.upenn.cit594.util.Format;

public class ScreenWriter {


    public static void DisplayErrorAndQuit(String error) {
        System.out.println("\nBEGIN OUTPUT");
        System.err.println(error);
        System.out.println("END OUTPUT");

    }

    public static void displayString(String string) {
        Logger.getInstance().log(string);
        System.out.println("\nBEGIN OUTPUT");
        System.out.println(string);
        System.out.println("END OUTPUT");

    }

    public static void displayMap(Map<String, Integer> map) {
        System.out.println("\nBEGIN OUTPUT");
        for (String key : map.keySet()) {
            System.out.println(Format.formatStateCountForPrint(key, map.get(key)));
        }
        System.out.println("END OUTPUT");
    }

    public static void displayList(List<String> list) {
        System.out.println("\nBEGIN OUTPUT");
        for (String item : list) {
            System.out.println(item);
        }
        System.out.println("END OUTPUT");

    }

    public static void displayObjectList(List<Object> list) {
        System.out.println("\nBEGIN OUTPUT");

        for (Object item : list) {
            System.out.println(item);
        }
        System.out.println("END OUTPUT");

    }

    public static void displayVaccinationDetails(TreeMap<String, Double> vaccination_details){
        System.out.println("\nBEGIN OUTPUT");
        for (String key : vaccination_details.keySet()) {
            System.out.printf("%s %.4f\n", key, vaccination_details.get(key));
        }

        System.out.println("END OUTPUT");

    }

    public static void displayReport(String zipcode, Map<String, String> map){
        System.out.println("\nBEGIN OUTPUT");

        System.out.printf("%-30s %s\n", "ZIP CODE", zipcode);
        for (String key : map.keySet()) {
            System.out.printf("%-30s %s\n", key, map.get(key));
        }

        System.out.println("END OUTPUT");

    }
    public static String getInput(String prompt) {
        Scanner scanner = new Scanner(System.in);
        System.out.println(prompt);
        System.out.print("> ");

        System.out.flush();
        String input = "0";
        if(scanner.hasNextLine())
            input = scanner.nextLine().toLowerCase(Locale.ROOT);
        Logger.getInstance().log(input);
        return input;

    }

    public static void displayMenu(){
        System.out.println("\n0. Exit the program.\n" +
                "1. Show the available data sets\n" +
                "2. Show the total population for all ZIP Codes\n" +
                "3. Show the total vaccinations per capita for each ZIP Code for the specified date\n" +
                "4. Show the average market value for properties in a specified ZIP Code\n" +
                "5. Show the average total livable area for properties in a specified ZIP Code\n" +
                "6. Show the total market value of properties, per capita, for a specified ZIP Code\n" +
                "7. Show report for specified ZIP Code");
    }

}
