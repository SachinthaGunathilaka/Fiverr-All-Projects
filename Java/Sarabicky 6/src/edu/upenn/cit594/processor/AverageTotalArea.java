package edu.upenn.cit594.processor;

import edu.upenn.cit594.datamanagement.PropertyDataEntry;
import edu.upenn.cit594.util.Data;

import java.util.Objects;

public class AverageTotalArea implements AverageStratergy{
    @Override
    public int calculateAverage(String zipcode) {
        double totalArea = 0;
        int count = 0;
        for (PropertyDataEntry entry: Data.getInstance().getProperty_data()) {
            if(Objects.equals(zipcode, entry.getZip_code())){
                totalArea += entry.getArea();
                count++;
            }
        }

        if(count == 0)
            return 0;


        return (int)totalArea/count;
    }
}
