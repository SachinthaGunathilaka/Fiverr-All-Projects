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

        String result = String.format("%-10d %-20s %-25s %-20s %s",id, name, email, city, simpleDateFormat.format(date));
        return result;
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

public class Coursework {

    // Please do not hardcode the filename into the program! It's ok to change the program to prompt the user
    // for the filename, but when I download assignments from LC the filenames get changed so hardcoding can cause problems.

    private PriorityQueue<Customer> customers_pq;
    Map<String, Integer> city_customers;


    public Coursework(String filename) {

        try {
            customers_pq = new PriorityQueue<Customer>(5, new DateComparator());
            city_customers = new HashMap<String, Integer>();

            // Use map to store City name and number of customers

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

                // Create customer object and add it to the customers_pq
                customers_pq.add(new Customer(Integer.parseInt(row_data[0]), row_data[1], row_data[2], row_data[3], date));
            }
        } catch (Exception e) {
            System.out.println("File Not Found");
        }

    }

    //A main method that will take command line arguments to call the given methods.
    //args [0] = data file filename
    //args [1] = customer ID
    //args [2] = city c -- as a String e.g. "Aylesbury"
    //args [3] = n for the customers of the most recent n orders
    public static void main(String[] args) {
        // add validation of args -- please do not change the orderings of these
        Coursework cw = new Coursework(args[0]); // add arguments if needed
        System.out.println(cw.getCustomer(Integer.parseInt(args[1])));
        System.out.println();
        System.out.println(cw.getCountOfCustomersWhoLiveIn(args[2]));
        System.out.println();
        String[] customers = cw.getCustomersForMostRecentOrders(Integer.parseInt(args[3]));
        for (int i = 0; i < Integer.parseInt(args[3]); i++) {
            System.out.println(customers[i] + ",");
        }
        System.out.println();
    }

    //    Your application will provide a method to return details of a customer chosen via the ID
    public String getCustomer(int id) {
        String customer = "User Not Found";

        for (Customer cus : customers_pq) {
            if (cus.id == id) {
                customer = cus.toString();
                break;
            }
        }
        return customer;
    }

    //    Your application will provide a method to return the number of customers that live in a specific city c
    public int getCountOfCustomersWhoLiveIn(String c) {
        c = c.toUpperCase(Locale.ROOT);
        if(!city_customers.containsKey(c))
            return 0;
        return city_customers.get(c);
    }

    //    Your application will provide a method to return the n customers that most recently made an order
    public String[] getCustomersForMostRecentOrders(int n) {
        String[] customers = new String[n];

        for (int i = 0; i < n; i++) {
            customers[i] = customers_pq.peek().toString();
            customers_pq.poll();
        }
        return customers;
    }

}
