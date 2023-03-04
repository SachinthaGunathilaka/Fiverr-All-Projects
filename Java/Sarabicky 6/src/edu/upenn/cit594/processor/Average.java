package edu.upenn.cit594.processor;

public class Average {
    private AverageStratergy strategy;

    public Average(AverageStratergy strategy) {
        this.strategy = strategy;
    }

    public int executeStrategy(String zipcode) {
        return strategy.calculateAverage(zipcode);
    }
}
