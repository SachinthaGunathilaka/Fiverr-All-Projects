package edu.upenn.cit594;

import edu.upenn.cit594.datamanagement.JsonParser;
import edu.upenn.cit594.datamanagement.StatesParser;
import edu.upenn.cit594.datamanagement.TextParser;
import edu.upenn.cit594.logging.Logger;
import edu.upenn.cit594.processor.TweetProcessor;
import edu.upenn.cit594.ui.UI;
import edu.upenn.cit594.util.Data;
import org.json.simple.parser.ParseException;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Locale;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {


        if (args.length != 3) {
            UI.displayError("The number of arguments is incorrect.");
            return;
        }

        Data.data = new Data();


        try {
            if (Objects.equals(args[0].split("\\.")[1].toLowerCase(Locale.ROOT), "json")) {
                JsonParser jsonParser = new JsonParser(args[0]);
                jsonParser.readJsonFile();

            } else if (Objects.equals(args[0].split("\\.")[1].toLowerCase(Locale.ROOT), "txt")) {
                TextParser textParser = new TextParser(args[0]);
                textParser.readTextFile();

            } else {
                UI.displayError("Invalid extension for tweets file.");
            }
        } catch (IOException | ParseException e) {
            UI.displayError(e.getMessage());
        } catch (Exception e) {
            UI.displayError("Invalid extension for tweets file.");
            return;
        }


        try {
            StatesParser statesParser = new StatesParser(args[1]);
            statesParser.readStatesFile();
        } catch (FileNotFoundException e) {
            UI.displayError(e.getMessage());
        }


        try {
            Logger.getLogger().SetDestination(args[2]);

        } catch (IOException e) {
            UI.displayError("Cannot create/open the  log file for writing");

        }


        TweetProcessor.filterTweets();

        try {
            TweetProcessor.categorizeTweets();
        } catch (IOException e) {
            UI.displayError(e.getMessage());
        }
        UI.displayStateMap();


    }
}
