package edu.upenn.cit594.logging;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Logger {
    public static Logger logger = new Logger();
    private String filename;

    public void log(String text) throws IOException {

        FileWriter fileWriter = new FileWriter(filename, true);
        PrintWriter printWriter = new PrintWriter(fileWriter);
        printWriter.println(text);
        printWriter.close();


    }

    public void SetDestination(String filename) throws IOException {
        this.filename = filename;

            FileWriter fileWriter = new FileWriter(filename, true);

    }

    public static Logger getLogger() {
        return logger;
    }
}
