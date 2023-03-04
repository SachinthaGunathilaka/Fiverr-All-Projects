package edu.upenn.cit594.util;

import edu.upenn.cit594.datamanagement.State;
import edu.upenn.cit594.datamanagement.Tweet;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class Data {

    public static Data data;

    private ArrayList<Tweet> tweets;
    private ArrayList<Tweet> filteredTweets;
    private ArrayList<State> states;


    public Data(){
        tweets = new ArrayList<>();
        filteredTweets = new ArrayList<>();
        states = new ArrayList<>();
    }
    public void addTweet(Tweet tweet) {
        tweets.add(tweet);
    }

    public void addFilteredTweet(Tweet tweet) {
        filteredTweets.add(tweet);
    }

    public void addState(State state) {
        states.add(state);
    }

    public void IncrementFluTweets(State state) {
        if (state == null)
            return;
        for (int i = 0; i < states.size(); i++) {
            if (Objects.equals(states.get(i).getName(), state.getName())) {
                states.get(i).incrementCount();
                break;
            }
        }
    }

    public static Data getData(){
        return data;
    }


    public ArrayList<Tweet> getTweets() {
        return tweets;
    }

    public ArrayList<Tweet> getFilteredTweets() {
        return filteredTweets;
    }

    public ArrayList<State> getStates() {
        return states;
    }

}
