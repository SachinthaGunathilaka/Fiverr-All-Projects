package edu.upenn.cit594.datamanagement;

import java.io.IOException;
import java.util.List;

import edu.upenn.cit594.ui.ScreenWriter;

public class TxtHandler extends FileHandler {

    /**
     * Constructor taking a single parameter
     * @param fileName for the txtFile
     */
    public TxtHandler(String fileName){
        super(fileName);
    }

    /**
     * Return a list of objects representing the lines from the text file
     * @return
     */
    @Override
    public List<Object> getFileAsList() {
        // TODO Auto-generated method stub
        String line;

        try {
            while((line = br.readLine()) != null) {
                objArray.add(line);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            ScreenWriter.DisplayErrorAndQuit("IOException when trying to read the line");
        }
        return objArray;
    }






}
