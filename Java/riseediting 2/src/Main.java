import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        // create graph object
        Graph graph = new Graph();

        String[] drivers = new String[graph.max_size]; // To store names of the drivers
        int[] weights = new int[graph.max_size]; // To store path weights
        int index = 0;

        try {
            // get input for graph data file name
            Scanner scanner_input = new Scanner(System.in);
            String filename = scanner_input.nextLine();
            FileInputStream fis = new FileInputStream(filename);
            Scanner scanner = new Scanner(fis);

            // read line by line of the file
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
//                System.out.println(line);
                String[] data = line.split(" ");
                String start_city = data[0];

                // insert each edge to graph
                for (int i = 1; i < data.length; i++) {
                    String[] edge_data = data[i].split(",");
                    String end_city = edge_data[0];
                    int weight = Integer.parseInt(edge_data[1]);

                    graph.insertEdge(start_city, end_city, weight);

                }
            }
            scanner.close();

            // get input for routes data file name
            filename = scanner_input.nextLine();

            fis = new FileInputStream(filename);
            scanner = new Scanner(fis);

            // read line by line of the file
            System.out.println("\n");
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
//                System.out.println(line);
                String[] data = line.split(" ");
                String driver = data[0];

                int path_weight = 0;

                // calculate the path weight
                for (int i = 1; i < data.length - 1; i++) {
                    if (graph.getWeight(data[i], data[i + 1]) == Integer.MAX_VALUE) {
                        path_weight = 0;
                        break;
                    }

                    path_weight += graph.getWeight(data[i], data[i + 1]);
                }

                // Store driver name and path weight
                drivers[index] = driver;
                weights[index++] = path_weight;

            }
            scanner.close();


        } catch (FileNotFoundException e) {

        }

        // Sort the path weights from least to greatest
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index - i - 1; j++) {
                if (weights[j] > weights[j + 1] || ((weights[j] == weights[j + 1] && drivers[j].compareToIgnoreCase(drivers[j + 1]) > 0))) {
                    int temp = weights[j];
                    weights[j] = weights[j + 1];
                    weights[j + 1] = temp;

                    String temp_ = drivers[j];
                    drivers[j] = drivers[j + 1];
                    drivers[j + 1] = temp_;
                }
            }
        }

        // Display the result
        for (int i = 0; i < index; i++) {
            System.out.print(drivers[i] + "\t" + weights[i]);
            if (weights[i] == 0)
                System.out.println("\tInvalid");
            else
                System.out.println("\tValid");
        }


    }
}
