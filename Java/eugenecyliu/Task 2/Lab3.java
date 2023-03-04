/**
 * In this task you will implement the method getColourValue of the class Lab3.
 * <p>
 * To check the actual intensity value of a pixel at x=111 y=20 you may use the following command in the terminal.
 * <p>
 * convert 'example.png[1x1+20+111]' txt:
 * <p>
 * Note that the colour image is stored is of type TYPE_3BYTE_BGR which stores the blue component first,
 * then the green component and finally the red component. As before, all pixels are stored in a row major 1D array.
 * <p>
 * Here a few test cases:
 * <p>
 * Input coordinates: 1 1
 * Colour value (rgb) at (1,1) is 224 17 95
 * <p>
 * Input coordinates: 100 20
 * Colour value (rgb) at (100,20) is 234 18 99
 * <p>
 * Input coordinates: 100 100
 * Colour value (rgb) at (100,100) is 0 0 0
 **/

import javax.management.timer.TimerMBean;
import java.util.Scanner;

public class Lab3 {
    public Lab3() {
        Img img = new Img("example.png");
        System.out.print("Input coordinates: ");
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int y = in.nextInt();
        int[] i = getColourValue(img, x, y);
        System.out.println("Colour value (rgb) at (" + x + "," + y + ") is " + i[0] + " " + i[1] + " " + i[2]);
    }

    /**
     * Retrieve the colour value at location (x, y) of the image and
     * return it as an RGB integer array.
     *
     * @param img in row major format
     * @param x   coordinate
     * @param y   coordinate
     * @return the intensity value at (x, y)
     */
    public int[] getColourValue(Img img, int x, int y) {
        //Your code here

        // Initialise output array
        int[] output = new int[3];

        // Extract B value of the given coordinate
        output[2] = img.img[(x * img.width + y) * 3];

        // Extract G value of the given coordinate
        output[1] = img.img[(x * img.width + y) * 3 + 1];

        // Extract R value of the given coordinate
        output[0] = img.img[(x * img.width + y) * 3 + 2];

        // Iterate through each value in the output array
        for (int i = 0; i < 3; i++) {

            // If a value is negative convert that to a positive value
            if (output[i] < 0) {
                output[i] = 256 + output[i];
            }
        }

        // return the output
        return output;

    }

    public static void main(String[] args) {
        new Lab3();
    }
}
