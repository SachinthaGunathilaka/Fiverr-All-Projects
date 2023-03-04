package edu.upenn.cit594.datamanagement;

import java.sql.Timestamp;

public class PropertyDataEntry {
    private String zip_code;
    private double area;
    private double market_value;

    public PropertyDataEntry(String zip_code, double area, double market_value) {
        this.zip_code = zip_code;
        this.area = area;
        this.market_value = market_value;
    }

    public String getZip_code() {
        return zip_code;
    }

    public double getArea() {
        return area;
    }

    public double getMarket_value() {
        return market_value;
    }

    @Override
    public String toString() {
        return "PropertyDataEntry{" +
                "zip_code='" + zip_code + '\'' +
                ", area=" + area +
                ", market_value=" + market_value +
                '}';
    }
}


