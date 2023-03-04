package edu.upenn.cit594.processor;

import edu.upenn.cit594.datamanagement.State;
import edu.upenn.cit594.datamanagement.Tweet;
import edu.upenn.cit594.logging.Logger;
import edu.upenn.cit594.util.Data;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TweetProcessor {
    public static boolean isFluTweet(String text) {
        Pattern pattern = Pattern.compile("^(flu|#flu)(?![a-zA-Z])", Pattern.CASE_INSENSITIVE);

        String[] words = text.split(" ");
        for (String word : words) {
            Matcher matcher = pattern.matcher(word);
            if (matcher.find()) {
                return true;
            }
        }
        return false;
    }

    public static void filterTweets() {
        for (Tweet tweet : Data.getData().getTweets()) {
            if (isFluTweet(tweet.getText()))
                Data.getData().addFilteredTweet(tweet);
        }
    }

    public static double calculateDistance(double la1, double lo1, double la2, double lo2) {
        return Math.sqrt(Math.pow(la1 - la2, 2) + Math.pow(lo1 - lo2, 2));
    }

    public static void categorizeTweets() throws IOException {
        for (Tweet tweet : Data.getData().getFilteredTweets()) {
            double min_distance = Double.POSITIVE_INFINITY;
            State nearest_state = null;
            for (State state : Data.getData().getStates()) {
                double cur_distance = calculateDistance(tweet.getLocation()[0], tweet.getLocation()[1], state.getLatitude(), state.getLongitude());
//                System.out.println(cur_distance);
                if (cur_distance < min_distance) {
                    min_distance = cur_distance;
                    nearest_state = state;
                }
            }

            if (nearest_state != null) {
                Logger.getLogger().log(nearest_state.getName() + "\t" + tweet.getText());
                Data.getData().IncrementFluTweets(nearest_state);
            }

        }
    }

}
