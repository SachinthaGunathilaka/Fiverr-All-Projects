package edu.upenn.cit594.datamanagement;

import edu.upenn.cit594.ui.ScreenWriter;
import edu.upenn.cit594.util.Data;
import org.json.simple.JSONObject;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DataHandler {


    private String population_filename;
    private String properties_filename;
    private String covid_filename;
    private String log_filename;

    public static DataHandler dataHandler;

    public DataHandler(){
        population_filename = null;
        properties_filename = null;
        covid_filename = null;
        log_filename = null;
    }

    public boolean validateArguments(Map<String, String> arguments) {

        for (Map.Entry<String, String> entry : arguments.entrySet()) {
            if (Objects.equals(entry.getKey(), "population")) {
                population_filename = entry.getValue();

                Path path = Paths.get(population_filename);
                if (Files.notExists(path)) {
                    ScreenWriter.DisplayErrorAndQuit(entry.getValue() + " File does not exists");
                    return false;
                }
            } else if (Objects.equals(entry.getKey(), "properties")) {
                properties_filename = entry.getValue();

                Path path = Paths.get(properties_filename);
                if (Files.notExists(path)) {
                    ScreenWriter.DisplayErrorAndQuit(entry.getValue() + " File does not exists");
                    return false;
                }
            } else if (Objects.equals(entry.getKey(), "covid")) {
                covid_filename = entry.getValue();

                if (!Objects.equals(covid_filename.split("\\.")[1], "json") && !Objects.equals(covid_filename.split("\\.")[1], "csv")) {
                    ScreenWriter.DisplayErrorAndQuit("The format of the covid data file can not be determined from the filename extension");
                    return false;
                }

                Path path = Paths.get(covid_filename);
                if (Files.notExists(path)) {
                    ScreenWriter.DisplayErrorAndQuit(entry.getValue() + " File does not exists");
                    return false;
                }
            } else if (Objects.equals(entry.getKey(), "log")) {
                log_filename = entry.getValue();

                Pattern pattern_filename = Pattern.compile("^[A-za-z0-9.]{1,255}$", Pattern.CASE_INSENSITIVE);
                Matcher matcher_filename = pattern_filename.matcher(log_filename);

                if (!matcher_filename.find()) {
                    ScreenWriter.DisplayErrorAndQuit("The logger cannot be correctly initialized");
                    return false;

                }
            } else {
                ScreenWriter.DisplayErrorAndQuit("Invalid name for the argument");
                return false;
            }
        }

        return true;

    }

    public static DataHandler getInstance() {
        return dataHandler;
    }

    public String getPopulation_filename() {
        return population_filename;
    }

    public String getProperties_filename() {
        return properties_filename;
    }

    public String getCovid_filename() {
        return covid_filename;
    }

    public String getLog_filename() {
        return log_filename;
    }

    public void handlePopulation(List<Object> population_lines) {
        int i = 0;
        for (Object line : population_lines) {
            if (i == 0) {
                i++;
                continue;

            }


            String zip = line.toString().split("\"")[1].split(",")[0];
            int count = Integer.parseInt(line.toString().split(",")[1]);
            Data.getInstance().addPopulation(zip, count);
        }
    }


    public void handleCovidJsonFile(List<Object> covid_lines) {
        for (Object o : covid_lines) {
            try {
                CovidDataEntry entry = new CovidDataEntry();
                JSONObject line = (JSONObject) o;
                String etl_timestamp = (String) line.get("etl_timestamp");
                String zip_code = String.valueOf(line.get("zip_code"));
//
                String NEG = String.valueOf(line.get("NEG"));
                String POS = String.valueOf(line.get("POS"));
                String deaths = String.valueOf(line.get("deaths"));
                String hospitalized = String.valueOf(line.get("hospitalized"));
                String partially_vaccinated = String.valueOf(line.get("partially_vaccinated"));
                String fully_vaccinated = String.valueOf(line.get("fully_vaccinated"));
                String boosted = String.valueOf(line.get("boosted"));

                if (etl_timestamp != null)
                    entry.setDate(etl_timestamp.split(" ")[0]);

                if (zip_code != null && !zip_code.equals("null"))
                    entry.setZipCode(zip_code);

                if (NEG != null && !NEG.equals("null")) {
                    entry.setNegative(Integer.parseInt(NEG));
                }
                if (POS != null && !POS.equals("null")) {
                    entry.setPositive(Integer.parseInt(POS));

                }

                if (deaths != null && !deaths.equals("null")) {
                    entry.setDeaths(Integer.parseInt(deaths));
                }

                if (hospitalized != null && !hospitalized.equals("null"))
                    entry.setHospitalized(Integer.parseInt(hospitalized));

                if (partially_vaccinated != null && !partially_vaccinated.equals("null"))
                    entry.setPartiallyVaccinated(Integer.parseInt(partially_vaccinated));

                if (fully_vaccinated != null && !fully_vaccinated.equals("null"))
                    entry.setFullyVacinated(Integer.parseInt(fully_vaccinated));

                if (boosted != null && !boosted.equals("null"))
                    entry.setBoosted(Integer.parseInt(boosted));

                Data.getInstance().addCovidDataEntry(entry);


            } catch (Exception ignored) {
            }

        }
    }

    public void handleCovidTxtFile(List<Object> covid_lines) {
        int i = 0;
        for (Object line : covid_lines) {
            if (i == 0) {
                i++;
                continue;
            }


            String[] temp, data = new String[9];
            temp = line.toString().split(",");

            Arrays.fill(data, "0");
            for (int j = 0; j < temp.length; j++) {
                if (Objects.equals(temp[j], ""))
                    data[j] = "0";
                else
                    data[j] = temp[j];
            }


            String time_stamp = data[0].substring(1).split(" ")[0];
            String zip = data[1];
            int negatives = Integer.parseInt(data[2]);
            int positives = Integer.parseInt(data[3]);
            int deaths = Integer.parseInt(data[4]);
            int hospitalized = Integer.parseInt(data[5]);
            int partially = Integer.parseInt(data[6]);
            int fully = Integer.parseInt(data[7]);
            int boosted = Integer.parseInt(data[8]);

            CovidDataEntry entry = new CovidDataEntry(time_stamp, zip, negatives, positives, deaths, hospitalized, partially, fully, boosted);
            Data.getInstance().addCovidDataEntry(entry);
//            System.out.println(entry);
        }
    }

    public void handleProperties(List<Object> properties_lines) {
//        total_livable_area,market_value,zip_code

        int i = 0;
        for (Object line : properties_lines) {
            if (line.toString().strip().length() == 0)
                continue;

            if (i == 0) {
                i++;
                continue;

            }

            String[] data = line.toString().split(",");
            if (data.length != 3)
                continue;

            for (int j = 0; j < data.length; j++) {
                if (Objects.equals(data[j], ""))
                    data[j] = "0";

            }

            double area = Double.parseDouble(data[0]);
            double market_value = Double.parseDouble(data[1]);
            String zip_code = data[2];

            PropertyDataEntry entry = new PropertyDataEntry(zip_code, area, market_value);
            Data.getInstance().addPropertyDataEntry(entry);
        }
    }


}
