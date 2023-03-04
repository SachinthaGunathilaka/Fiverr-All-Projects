public class Main {
    public static void main(String[] args) {
        // Create 1D array to store 50 integers
        int [] data = new int[50];

        // Store values form 0 to 49 in the array
        for (int i = 0; i < 50; i++) {
            data[i] = i;
        }

        // Create new String object with no-arg constructor
        String str = new String();

        // Record the time before append the elements
        long lStartTime = System.nanoTime();

        // Append elements in the array to the String object
        for (int i = 0; i < 50; i++) {
            str += data[i];
        }

        // Record time after appending
        long lEndTime = System.nanoTime();

        // Calculate elapsed time for appending
        long output = lEndTime - lStartTime;

        // Display results
        System.out.println("\nFinal string: " + str);
        System.out.println("It took " + output + " nanoseconds to append 50 integers to the String");

        // ----------------------------------------------------------------------------------------
        // Part 2

        // Create new StringBuilder object with no-arg constructor
        StringBuilder stringBuilder = new StringBuilder();

        // Record the time before append the elements
        lStartTime = System.nanoTime();

        // Append elements in the array to the String Builder object
        for (int i = 0; i < 50; i++) {
            stringBuilder.append(data[i]);
        }

        // Record time after appending
        lEndTime = System.nanoTime();

        // Calculate elapsed time for appending
        output = lEndTime - lStartTime;

        // Display results
        System.out.println("\nFinal string: " + str);
        System.out.println("It took " + output + " nanoseconds to append 50 integers to the StringBuilder");
    }
}
