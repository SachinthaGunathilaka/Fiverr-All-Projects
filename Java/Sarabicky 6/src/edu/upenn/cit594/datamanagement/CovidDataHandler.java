package edu.upenn.cit594.datamanagement;

import java.io.IOException;
import java.util.List;
import edu.upenn.cit594.processor.FileType;
import edu.upenn.cit594.ui.ScreenWriter;
import org.json.simple.parser.ParseException;


public class CovidDataHandler {


    private String fileName;

    public CovidDataHandler(String fileName) {
        this.fileName = fileName;
    }

    public void readData() throws IOException, ParseException {

        if (FileType.checkIfCsv(this.fileName)) {
            handleFromCsv();
        } else if (FileType.checkIfJson(this.fileName)) {
            handleFromJson();
        } else {
            ScreenWriter.DisplayErrorAndQuit("Wrong Type of File for Covid Data!");
        }
    }


    public void handleFromJson() throws IOException, ParseException {
        FileHandler jsonHandler = new JsonHandler(fileName);

        List<Object> covid_lines = jsonHandler.getFileAsList();//get a list of objects from the Json file

//        JSONArray a = (JSONArray) new JSONParser().parse(new FileReader(this.fileName));


		DataHandler.getInstance().handleCovidJsonFile(covid_lines);


    }

    public void handleFromCsv() {
        CsvHandler covidHandler = new CsvHandler(DataHandler.getInstance().getCovid_filename());
        List<Object> covid_lines = covidHandler.getFileAsList();
        DataHandler.getInstance().handleCovidTxtFile(covid_lines);
    }

}
