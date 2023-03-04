/**
 * In this task you will implement the method setOdd of the class Lab2 which will set all intensity values with odd
 * coordinates to white (255), all others will be set to black (0). An odd coordinate is defined as a coordinate that
 * has an odd x value or an odd y value.
 * <p>
 * The expected output is provided in the file solution.png.
 **/

public class Lab2 {
    public Lab2() {
        Img img = new Img("Fig0314a.png");
        setOdd(img);
        img.save();
    }

    /**
     * Sets all odd coordinates to 255 and others to 0.
     *
     * @param img in row major format
     */
    public void setOdd(Img img) {

        // Value of j increment from 0 to height of the image
        for (int j = 0; j < img.height; j++) {
            // Value of k increment from 0 to width of the image
            for (int k = 0; k < img.width; k++) {

                // Check whether at least one coordinate value is odd
                if (j % 2 == 1 || k % 2 == 1) {

                    /*
                        If at least one coordinate value is odd set the coordinate value to 255
                        Position of the array correspond to the coordinate(j, k) value is obtained by following equation.
                                Position = j * img.width + k
                     */

                    img.img[j * img.width + k] = (byte) 255;
                } else {
                    // Otherwise set the coordinate value to 0
                    img.img[j * img.width + k] = (byte) 0;
                }
            }
        }
    }

    public static void main(String[] args) {
        new Lab2();
        Validator validator = new Validator();
    }
}
