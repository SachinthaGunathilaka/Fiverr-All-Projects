package edu.upenn.cit594.datamanagement;

import edu.upenn.cit594.util.Data;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class StatesParser {

    private String filename;

    public StatesParser(String filename) {
        this.filename = filename;
    }

    public void readStatesFile() throws FileNotFoundException {

        FileInputStream fis = new FileInputStream(filename);
        Scanner sc = new Scanner(fis);
        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            String[] data = line.split(",");

            State state = new State(data[0], Double.parseDouble(data[1]), Double.parseDouble(data[2]));
            Data.getData().addState(state);

        }
        sc.close();

    }

}
