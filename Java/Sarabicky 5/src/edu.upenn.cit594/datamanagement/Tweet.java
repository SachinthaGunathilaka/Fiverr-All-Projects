package edu.upenn.cit594.datamanagement;

import java.util.Arrays;

public class Tweet {
    private double[] location;
    private String text;

    public Tweet(double latitude, double longitude, String text) {
        this.location = new double[2];
        this.location[0] = latitude;
        this.location[1] = longitude;
        this.text = text;
    }

    public String toString() {
        return "location = " + Arrays.toString(location) +
                ",\ttext='" + text;
    }

    public double[] getLocation() {
        return location;
    }

    public String getText() {
        return text;
    }
}
