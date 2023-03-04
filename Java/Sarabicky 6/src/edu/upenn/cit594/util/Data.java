package edu.upenn.cit594.util;

import edu.upenn.cit594.datamanagement.CovidDataEntry;
import edu.upenn.cit594.datamanagement.PropertyDataEntry;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Data {
    private Map<String, Integer> population;
    private List<CovidDataEntry> covid_data;
    private List<PropertyDataEntry> property_data;


    public static Data data;

    public Data() {
        this.population = new HashMap<String, Integer>();
        this.covid_data = new ArrayList<>();
        this.property_data = new ArrayList<>();
    }

    public void addPopulation(String zip, int count) {
        this.population.put(zip, count);
    }

    public void addCovidDataEntry(CovidDataEntry entry) {
        this.covid_data.add(entry);
    }

    public void addPropertyDataEntry(PropertyDataEntry entry) {
        this.property_data.add(entry);
    }

    public static Data getInstance() {
        return data;
    }

    public Map<String, Integer> getPopulation() {
        return population;
    }

    public int getPopulationZipCode(String zipcode){
        if(this.population.containsKey(zipcode))
            return this.population.get(zipcode);

        return 0;
    }

    public List<CovidDataEntry> getCovid_data() {
        return covid_data;
    }

    public List<PropertyDataEntry> getProperty_data() {
        return property_data;
    }

}
