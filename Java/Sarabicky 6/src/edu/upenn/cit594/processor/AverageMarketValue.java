package edu.upenn.cit594.processor;

import edu.upenn.cit594.datamanagement.PropertyDataEntry;
import edu.upenn.cit594.util.Data;

import java.util.Objects;

public class AverageMarketValue implements AverageStratergy{
    @Override
    public int calculateAverage(String zipcode) {
        double totalMarketValue = 0;
        int count = 0;
        for (PropertyDataEntry entry: Data.getInstance().getProperty_data()) {
            if(Objects.equals(zipcode, entry.getZip_code())){
                totalMarketValue += entry.getMarket_value();
                count++;
            }
        }

        if(count == 0)
            return 0;


        return (int)totalMarketValue/count;
    }
}
