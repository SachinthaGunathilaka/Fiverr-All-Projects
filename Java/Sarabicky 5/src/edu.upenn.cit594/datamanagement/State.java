package edu.upenn.cit594.datamanagement;

import java.util.Arrays;

public class State {
    private String name;
    private double latitude;
    private double longitude;
    private int count;

    public State(String name, double latitude, double longitude) {
        this.name = name;
        this.latitude = latitude;
        this.longitude = longitude;
        this.count = 0;

    }

    public String toString() {
        return "name = " + name +
                ",\tlocation =" + latitude + ", " + longitude;
    }

    public String getName() {
        return name;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public int getCount() {
        return count;
    }

    public void incrementCount(){
        count++;
    }
}
