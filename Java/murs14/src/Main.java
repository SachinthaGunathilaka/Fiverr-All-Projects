import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        // Input file name (Change it as you want)
        String filename = "input.txt";

        // Number of maximum products (Change this as you want)
        int max_num_of_products = 100;

        Product[] products = new Product[max_num_of_products];
        int count = 0;
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String line = myReader.nextLine().strip();
                if (line.length() == 0)
                    continue;
                String[] data = line.split("#");
                Product product = new Product(Integer.parseInt(data[0]), data[1], data[2], Integer.parseInt(data[3]));
                products[count++] = product;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found!");
        }

        // To display every product
        for (int i = 0; i < count; i++) {
            System.out.println(products[i]);
        }
    }
}
