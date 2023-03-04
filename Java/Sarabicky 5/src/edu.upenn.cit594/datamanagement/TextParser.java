package edu.upenn.cit594.datamanagement;

import java.io.FileInputStream;

import java.io.FileNotFoundException;
import java.util.Scanner;

import edu.upenn.cit594.util.Data;

public class TextParser {
    private String filename;

    public TextParser(String filename) {
        this.filename = filename;
    }

    public void readTextFile() throws FileNotFoundException {
        FileInputStream fis = new FileInputStream(this.filename);
        Scanner sc = new Scanner(fis);
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] data = line.split("\t");
            data[0] = data[0].strip().substring(1, data[0].length() - 1);
            String[] location = data[0].split(",");

            Tweet tweet = new Tweet(Double.parseDouble(location[0]), Double.parseDouble(location[1]), data[3]);
            Data.getData().addTweet(tweet);

        }
        sc.close();

    }


}
