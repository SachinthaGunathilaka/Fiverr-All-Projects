package edu.upenn.cit594.processor;

import edu.upenn.cit594.datamanagement.CovidDataEntry;
import edu.upenn.cit594.datamanagement.DataHandler;
import edu.upenn.cit594.datamanagement.PropertyDataEntry;
import edu.upenn.cit594.ui.ScreenWriter;
import edu.upenn.cit594.util.Data;
import edu.upenn.cit594.util.Format;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;

public class DataProcessor {


    private static DataProcessor dataProcessor = new DataProcessor();

    public static DataProcessor getInstance() {
        return dataProcessor;
    }

    public List<String> getAvailableDataSet() {
        List<String> dataset = new ArrayList<String>();

        DataHandler dataHandler = DataHandler.getInstance();

        if (dataHandler.getCovid_filename() != null) {
            dataset.add("covid");
        }
        if (dataHandler.getPopulation_filename() != null) {
            dataset.add("population");
        }
        if (dataHandler.getProperties_filename() != null) {
            dataset.add("properties");
        }

        return dataset;
    }

    public int getTotalPopulation() {
        int total_population = 0;
        for (Map.Entry<String, Integer> entry : Data.getInstance().getPopulation().entrySet()) {
            total_population += entry.getValue();
        }

        return total_population;
    }

    public TreeMap<String, Double> vaccinationsPerCapita(String date, boolean full) {
//        Data.getInstance().getPopulation();

        TreeMap<String, Double> vaccination_details = new TreeMap<>();
        for (CovidDataEntry entry : Data.getInstance().getCovid_data()) {
//            System.out.println(entry);
//            System.out.println(entry.getDate() + ":" + date);
            if (Objects.equals(entry.getDate(), date)) {
//                System.out.println(entry.getZipCode() + " " + entry.getPartiallyVaccinated());
                int population = Data.getInstance().getPopulationZipCode(entry.getZipCode());
                int vaccination = entry.getPartiallyVaccinated();
                if (full)
                    vaccination = entry.getFullyVacinated();
//
                if (population == 0 || vaccination == 0)
                    continue;
                double vaccination_capita = (double) vaccination / population;
                vaccination_details.put(entry.getZipCode(), vaccination_capita);
            }
        }
        return vaccination_details;

    }

    public int totalMarketCapita(String zipcode) {
        double totalMarketValue = 0;
        for (PropertyDataEntry entry : Data.getInstance().getProperty_data()) {
            if (Objects.equals(zipcode, entry.getZip_code())) {
                totalMarketValue += entry.getMarket_value();
            }
        }

        int count = Data.getInstance().getPopulationZipCode(zipcode);

        if (count == 0)
            return 0;


        return (int) totalMarketValue / count;
    }

    public TreeMap<String, String> fullReport(String zipcode) {
        TreeMap<String, String> report = new TreeMap<>();

        int population = Data.getInstance().getPopulationZipCode(zipcode);
        int market_capita = totalMarketCapita(zipcode);
        List<CovidDataEntry> covidData = Data.getInstance().getCovid_data();
        int deaths = 0;

        for (int i = covidData.size() - 1; i >= 0; i--) {
            if (Objects.equals(covidData.get(i).getZipCode(), zipcode)) {
                deaths = covidData.get(i).getDeaths();
                break;
            }
        }

        String death_percentage = "0";
        if (population != 0)
            death_percentage = String.format("%.2f", deaths * 100.0 / population) + "%";


        report.put("Population", String.valueOf(population));
        report.put("Market Value Per Capita", String.valueOf(market_capita));
        report.put("Total Covid Deaths", String.valueOf(deaths));
        report.put("Total Covid Deaths %", death_percentage);
        return report;
    }


}
