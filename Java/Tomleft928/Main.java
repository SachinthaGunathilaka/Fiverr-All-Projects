import java.io.*;
import java.text.*;
import java.util.*;


// Customer class
class Customer {

    // Attributes
    public String name;
    public Date date;
    public int id;
    public String email;
    String city;

    // Constructor
    public Customer(int id, String name, String email, String city, Date date) {
        this.id = id;
        this.name = name;
        this.date = date;
        this.email = email;
        this.city = city;
    }

    // Method to print Customer object
    public String toString() {
        String pattern = "yyyy-MM-dd";
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat(pattern);

        return id + "\t\t" + name + "\t\t" + email + "\t\t" + city  +simpleDateFormat.format(date);
    }
}

// DateComparator (Used to compare dates)
class DateComparator implements Comparator<Customer> {

    // Implement compare method
    public int compare(Customer c1, Customer c2) {
        if (c1.date.compareTo(c2.date) < 0)
            return 1;
        else if (c1.date.compareTo(c2.date) > 0)
            return -1;
        return 0;
    }
}

// Main Class
public class Main {
    // main method
    public static void main(String[] args) {
        try {

            // Use priority queue to store Customer objects (Sorted by date)
            PriorityQueue<Customer> date_pq = new PriorityQueue<Customer>(5, new DateComparator());
            // Use map to store City name and number of customers
            Map<String, Integer> city_customers = new HashMap<String, Integer>();

            // Read the csv file line by line
            BufferedReader reader = new BufferedReader(new FileReader("data.csv"));
            String line = "";
            int line_no = 0;

            // This loop runs until end of the file
            while ((line = reader.readLine()) != null) {
                // If the line is empty skip it
                if (line.trim().length() == 0)
                    continue;

                // Increment line number by 1
                line_no++;

                // Skip the first line (titles of the columns)
                if (line_no == 1)
                    continue;

                // split the line by commas
                String[] row_data = line.trim().split(",");

                // get city and convert it to upper case.
                String city = row_data[3].toUpperCase(Locale.ROOT);

                // If the city already exists in the city_customers map
                if (city_customers.containsKey(city)) {
                    // Increment value by 1
                    city_customers.put(city, city_customers.get(city) + 1);
                }
                // Else put the city into the city_customers map
                else {
                    city_customers.put(city, 1);
                }

                // Create Date Object using date string
                SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
                Date date = formatter.parse(row_data[4]);

                // Create customer object and add it to the date_pq
                date_pq.add(new Customer(Integer.parseInt(row_data[0]), row_data[1], row_data[2], row_data[3], date));
            }

            // Sort keys in the city_customers
            SortedSet<String> keys = new TreeSet<>(city_customers.keySet());

            // Display each city along with the number of customers
            System.out.printf("\n%-23s %s\n", "CITY", "NUMBER OF CUSTOMERS");
            System.out.println("--------------------------------------------");
            for (String key : keys) {
                System.out.printf("%-30s  %d\n", key, city_customers.get(key));
            }

            // Display most recent orders
            System.out.println("\nMOST RECENT ORDERS");
            System.out.println("--------------------------------------------------------------------------");

            // Display top 5 nodes of the priority queue
            for (int i = 0; i < 5; i++) {
                System.out.println(date_pq.peek());
                date_pq.poll();
            }

            // Error handling
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        } catch (IOException e) {
            System.out.println("IO Exception Found");
        } catch (ParseException e) {
            System.out.println("Invalid Date Format");
        }

    }
}
