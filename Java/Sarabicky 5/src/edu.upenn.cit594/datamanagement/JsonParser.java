package edu.upenn.cit594.datamanagement;

import edu.upenn.cit594.util.Data;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class JsonParser {


    private String filename;

    public JsonParser(String filename) {
        this.filename = filename;
    }

    public void readJsonFile() throws IOException, ParseException {

        JSONArray a = (JSONArray) new JSONParser().parse(new FileReader(this.filename));


        for (Object o : a) {
            try {
                JSONObject line = (JSONObject) o;//
                JSONArray location = (JSONArray) line.get("location");
                String text = (String) line.get("text");
                Tweet tweet = new Tweet((double) location.get(0), (double) location.get(1), text);
                Data.getData().addTweet(tweet);
            } catch (Exception ignored) {
            }

        }


    }
}
