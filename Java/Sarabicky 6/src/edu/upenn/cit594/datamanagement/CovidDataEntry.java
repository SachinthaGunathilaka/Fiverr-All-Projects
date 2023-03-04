package edu.upenn.cit594.datamanagement;

import java.sql.Timestamp;

public class CovidDataEntry {
    private String date;
    private String zipCode;
    private int negative;
    private int positive;
    private int deaths;
    private int hospitalized;
    private int partiallyVaccinated;
    private int fullyVacinated;
    private int boosted;

    public CovidDataEntry(){
        date = "";
        zipCode = "";
        negative = 0;
        positive = 0;
        deaths = 0;
        hospitalized = 0;
        partiallyVaccinated = 0;
        fullyVacinated = 0;
        boosted = 0;
    }
    public CovidDataEntry(String date, String zipCode, int negative, int positive, int deaths, int hospitalized, int partiallyVaccinated, int fullyVacinated, int boosted) {
        this.date = date;
        this.zipCode = zipCode;
        this.negative = negative;
        this.positive = positive;
        this.deaths = deaths;
        this.hospitalized = hospitalized;
        this.partiallyVaccinated = partiallyVaccinated;
        this.fullyVacinated = fullyVacinated;
        this.boosted = boosted;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getDate() {
        return this.date;
    }

    public String getZipCode() {
        return zipCode;
    }

    public void setZipCode(String zipCode) {
        this.zipCode = zipCode;
    }

    public int getNegative() {
        return negative;
    }

    public void setNegative(int negative) {
        this.negative = negative;
    }

    public int getPositive() {
        return positive;
    }

    public void setPositive(int positive) {
        this.positive = positive;
    }

    public int getDeaths() {
        return deaths;
    }

    public void setDeaths(int deaths) {
        this.deaths = deaths;
    }

    public int getHospitalized() {
        return hospitalized;
    }

    public void setHospitalized(int hospitalized) {
        this.hospitalized = hospitalized;
    }

    public int getPartiallyVaccinated() {
        return partiallyVaccinated;
    }

    public void setPartiallyVaccinated(int partiallyVaccinated) {
        this.partiallyVaccinated = partiallyVaccinated;
    }

    public int getFullyVacinated() {
        return fullyVacinated;
    }

    public void setFullyVacinated(int fullyVacinated) {
        this.fullyVacinated = fullyVacinated;
    }

    public int getBoosted() {
        return boosted;
    }

    public void setBoosted(int boosted) {
        this.boosted = boosted;
    }

    @Override
    public String toString() {
        return "CovidDataEntry{" +
                "date='" + date + '\'' +
                ", zipCode='" + zipCode + '\'' +
                ", negative=" + negative +
                ", positive=" + positive +
                ", deaths=" + deaths +
                ", hospitalized=" + hospitalized +
                ", partiallyVaccinated=" + partiallyVaccinated +
                ", fullyVacinated=" + fullyVacinated +
                ", boosted=" + boosted +
                '}';
    }


}


