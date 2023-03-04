package edu.upenn.cit594.processor;

import edu.upenn.cit594.ui.ScreenWriter;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Validator {
    public static Validator validator = new Validator();

    public static Validator getInstance() {
        return validator;
    }

    public boolean validateDate(String date){
        Pattern pattern = Pattern.compile("^\\d{4}-(0?[1-9]|1[012])-(0?[1-9]|[12][0-9]|3[01])$", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(date);
        return matcher.find();
    }

    public boolean validateZipCode(String zipcode){
        Pattern pattern = Pattern.compile("^(\\d{5})?$", Pattern.CASE_INSENSITIVE);
        Matcher matcher = pattern.matcher(zipcode);
        return matcher.find();
    }
}
