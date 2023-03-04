/**
 * In this you task will implement the method getMostFrequentIntensityValue that will return the most frequent intensity value
 * in the image, i.e., the intensity that appears most often.
 * <p>
 * Your program should output the following.
 * <p>
 * Most frequent intensity value is 194
 **/

public class Lab4 {
    public Lab4() {
        Img img = new Img("Fig0314a.png");
        int i = getMostFrequentIntensityValue(img);
        System.out.println("Most frequent intensity value is " + i);
    }

    /**
     * Retrieve the intensity value that occurs most often in the image
     *
     * @param img
     * @return the intensity value that occurs most often in the image
     */
    public int getMostFrequentIntensityValue(Img img) {
        //Your code here

        // Initialize counts array
        int[] counts = new int[256];

        // Declare abs_value variable
        int abs_value;

        // Value of j increment from 0 to height of the image
        for (int j = 0; j < img.height; j++) {
            // Value of k increment from 0 to width of the image
            for (int k = 0; k < img.width; k++) {

                // Extract the value of the current coordinate
                abs_value = img.img[j * img.width + k];

                // If it is negative convert it to a positive value
                if (abs_value < 0) {
                    abs_value = 256 + abs_value;
                }

                // Increment count of the relavant coordinate value by 1
                counts[abs_value]++;
            }
        }

        // Initialize max_value to 0 and max_count to 0
        int max_value = 0, max_count = 0;

        // Iterate through each value in the counts array and find maximum count value
        for (int i = 0; i < 256; i++) {
            if (counts[i] > max_count) {
                max_count = counts[i];
                max_value = i;
            }
        }

        // return most frequent intensity value
        return max_value;
    }

    public static void main(String[] args) {
        new Lab4();
    }
}
