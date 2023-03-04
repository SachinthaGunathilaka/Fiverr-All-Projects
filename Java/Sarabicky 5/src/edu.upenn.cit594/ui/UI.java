package edu.upenn.cit594.ui;

import edu.upenn.cit594.datamanagement.State;
import edu.upenn.cit594.datamanagement.Tweet;
import edu.upenn.cit594.util.Data;

public class UI {
    public static void displayTweets() {
        for (Tweet tweet : Data.getData().getTweets()) {
            System.out.println(tweet);
        }
    }

    public static void displayFilteredTweets() {
        for (Tweet tweet : Data.getData().getFilteredTweets()) {
            System.out.println(tweet);
        }
    }

    public static void displayStates() {
        for (State state : Data.getData().getStates()) {
            System.out.println(state);
        }
    }

    public static void displayStateMap() {
        for (State state : Data.getData().getStates()) {
            if (state.getCount() != 0)
                System.out.println(state.getName() + " : " + state.getCount());
        }
    }

    public static void displayError(String error){
        System.out.println("ERROR! : " + error);
    }
}
