package edu.upenn.cit594;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

//import edu.upenn.cit594.datamanagement.*;
import edu.upenn.cit594.datamanagement.*;
import edu.upenn.cit594.logging.Logger;
import edu.upenn.cit594.processor.*;
import edu.upenn.cit594.ui.ScreenWriter;
import edu.upenn.cit594.util.Data;
import edu.upenn.cit594.util.LoggerHelper;
import org.json.simple.parser.ParseException;

public class Main {

    public static void main(String[] args) throws IOException, ParseException {

        Data.data = new Data();
        DataHandler.dataHandler = new DataHandler();

        // TODO Auto-generated method stub

        //get the logger instance
        Logger logger = Logger.getInstance();
        DataHandler dataHandler = DataHandler.getInstance();
        DataProcessor dataProcessor = DataProcessor.getInstance();
        CovidDataHandler covidDataHandler;
        Validator validator = Validator.getInstance();


        Map<String, String> arguments = new HashMap<>();


        boolean isError = false;

        for (String arg : args) {
            Pattern pattern = Pattern.compile("^--(?<name>.+?)=(?<value>.+)$", Pattern.CASE_INSENSITIVE);
            Matcher matcher = pattern.matcher(arg);
            if (!matcher.find()) {
                ScreenWriter.DisplayErrorAndQuit("Argument do not match the form \"--name=value\"");
                return;
            }

            String name = arg.toLowerCase(Locale.ROOT).split("--")[1].split("=")[0];
            String value = arg.toLowerCase(Locale.ROOT).split("--")[1].split("=")[1];

            arguments.put(name, value);

        }

        if(!dataHandler.validateArguments(arguments)){
            return;
        }

        if(dataHandler.getLog_filename() == null) {
            ScreenWriter.DisplayErrorAndQuit("Log file name not provided");
            return;
        }

        if (args.length > 4) {
            ScreenWriter.DisplayErrorAndQuit("The name of an argument is use more than once");
            return;
        }

        logger.setFile(dataHandler.getLog_filename());
        LoggerHelper.log(args);


        TxtHandler populationHandler = new TxtHandler(dataHandler.getPopulation_filename());
        List<Object> population_lines = populationHandler.getFileAsList();

//        ScreenWriter.displayObjectList(population_lines);
        dataHandler.handlePopulation(population_lines);

//        ScreenWriter.displayMap(Data.getInstance().getPopulation());
//        System.out.println((Data.getInstance().getPopulationZipCode("19104")));


        covidDataHandler = new CovidDataHandler((dataHandler.getCovid_filename()));
        covidDataHandler.readData();

//        ScreenWriter.displayObjectList(covid_lines);

        TxtHandler propertiesHandler = new TxtHandler(dataHandler.getProperties_filename());
        List<Object> properties_lines = propertiesHandler.getFileAsList();

//        ScreenWriter.displayObjectList(properties_lines);
        dataHandler.handleProperties(properties_lines);

        int option;


        boolean running = true;
        while (running) {
            ScreenWriter.displayMenu();
            option = Integer.parseInt(ScreenWriter.getInput("\nEnter option"));
            while (option < 0 || option > 7) {
                option = Integer.parseInt(ScreenWriter.getInput("Invalid Input. Enter option"));
            }

            switch (option) {
                case 0:
                    running = false;
                    break;
                case 1:
                    List<String> dataset = dataProcessor.getAvailableDataSet();
                    ScreenWriter.displayList(dataset);
                    break;
                case 2:
                    int total_population = dataProcessor.getTotalPopulation();
                    ScreenWriter.displayString(String.valueOf(total_population));
                    break;

                case 3:
                    String input = ScreenWriter.getInput("Enter Partial or Full");
                    while (!input.equals("full") && !input.equals("partial")) {
                        input = ScreenWriter.getInput("Invalid Input. Enter Partial or Full");
                    }

                    String date = ScreenWriter.getInput("Enter Date (YYYY-MM-DD)");
                    while (!validator.validateDate(date)) {
                        date = ScreenWriter.getInput("Invalid date. Enter Date (YYYY-MM-DD)");
                    }

                    boolean full = input.equals("full");

                    TreeMap<String, Double> vaccination_details = dataProcessor.vaccinationsPerCapita(date, full);
                    ScreenWriter.displayVaccinationDetails(vaccination_details);
                    break;

                case 4:
                    String zipcode = ScreenWriter.getInput("Enter Zip Code");
//                String zipcode = "19149";

                    while (!validator.validateZipCode(zipcode)) {
                        zipcode = ScreenWriter.getInput("Invalid Zip Code. Enter Zip Code");
                    }

                    Average average = new Average(new AverageMarketValue());
                    int average_market_value = average.executeStrategy(zipcode);
                    ScreenWriter.displayString(String.valueOf(average_market_value));
                    break;

                case 5:
                    zipcode = ScreenWriter.getInput("Enter Zip Code");
//                String zipcode = "19149";

                    while (!validator.validateZipCode(zipcode)) {
                        zipcode = ScreenWriter.getInput("Invalid Zip Code. Enter Zip Code");
                    }

                    average = new Average(new AverageTotalArea());
                    int average_area = average.executeStrategy(zipcode);
                    ScreenWriter.displayString(String.valueOf(average_area));
                    break;

                case 6:
                    zipcode = ScreenWriter.getInput("Enter Zip Code");
                    while (!validator.validateZipCode(zipcode)) {
                        zipcode = ScreenWriter.getInput("Invalid Zip Code. Enter Zip Code");
                    }
                    int total_market_capita = dataProcessor.totalMarketCapita(zipcode);
                    ScreenWriter.displayString(String.valueOf(total_market_capita));
                    break;

                /*
                    By choosing this option user can get full report for a given zip code.
                    Input :
                        Get zipcode from the user

                    Output:
                        Average market value
                        Average total area
                        Market value per capita
                        Population of the zipcode
                        Total covid deaths
                        Percentage of the total covid deaths (covid deaths * 100 / population of the zipcode)

                 */
                case 7:
//                zipcode = "19149";
                    zipcode = ScreenWriter.getInput("Enter Zip Code");
                    while (!validator.validateZipCode(zipcode)) {
                        zipcode = ScreenWriter.getInput("Invalid Zip Code. Enter Zip Code");
                    }

                    average = new Average(new AverageMarketValue());
                    average_market_value = average.executeStrategy(zipcode);

                    average = new Average(new AverageTotalArea());
                    average_area = average.executeStrategy(zipcode);

                    TreeMap<String, String> report = dataProcessor.fullReport(zipcode);
                    report.put("Average Market Value", String.valueOf(average_market_value));
                    report.put("Average Total Area", String.valueOf(average_area));

                    ScreenWriter.displayReport(zipcode, report);
            }
        }
        logger.closeLogger();

    }
}
