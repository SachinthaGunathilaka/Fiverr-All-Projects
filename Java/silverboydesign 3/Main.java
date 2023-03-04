public class Main {
    public static void main(String[] args) {
        // Create 1D array to store 50 integers
        int [] data = new int[50];

        // Store values form 0 to 49 in the array
        for (int i = 0; i < 50; i++) {
            data[i] = i;
        }

        // Create no-arg constructor
        String str = new String();

        // Record the time before append the elements
        long lStartTime = System.nanoTime();

        // Append elements in the array to the empty string
        for (int i = 0; i < 50; i++) {
            str += data[i];
        }

        // Record time after appending
        long lEndTime = System.nanoTime();

        // Calculate elapsed time for appending
        long output = lEndTime - lStartTime;

        // Display results
        System.out.println("Final string: " + str);
        System.out.println("It took " + output + " nanoseconds to append 50 integers to the String");
    }
}
