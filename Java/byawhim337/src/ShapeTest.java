import java.util.Random;
import java.util.Scanner;

// Test Class
public class ShapeTest {

    // Static method to display the menu
    public static void displayMenu() {
        System.out.println("1. Circle\n" +
                "2. Triangle\n" +
                "3. Rectangle");
    }

    // Static method to get valid input for length
    public static double getInput(String message) {
        Scanner scanner = new Scanner(System.in);
        System.out.print(message);
        double value = Double.parseDouble(scanner.nextLine());

        // This loops continuous until user input positive value for length
        while (value <= 0) {
            System.out.println("Invalid Input");
            System.out.print(message);
            value = Double.parseDouble(scanner.nextLine());
        }

        return value;
    }


    // main method
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Create Shape array to hold 10 shapes
        Shape[] shapes = new Shape[10];


        // Get input from user for 5 shapes
        for (int i = 0; i < 5; i++) {
            displayMenu();
            System.out.print("Choose shape : ");
            int option = Integer.parseInt(scanner.nextLine());
            while (option < 1 || option > 3) {
                System.out.print("Invalid Input\nChoose shape again: ");
                option = Integer.parseInt(scanner.nextLine());
            }

            System.out.print("Enter name : ");
            String name = scanner.nextLine();

            System.out.print("Enter color : ");
            String color = scanner.nextLine();

            if (option == 1) {
                double radius = getInput("Enter radius : ");
                shapes[i] = new Circle(name, color, radius);
            } else if (option == 2) {
                double base = getInput("Enter base : ");
                double height = getInput("Enter height : ");
                double side1 = getInput("Enter side1 length : ");
                double side2 = getInput("Enter side2 length : ");
                shapes[i] = new Triangle(name, color, base, height, side1, side2);
            } else {
                double length = getInput("Enter length : ");
                double width = getInput("Enter width : ");

                shapes[i] = new Rectangle(name, color, length, width);
            }

        }

        // Randomly generate 5 shapes
        for (int i = 5; i < 10; i++) {
            Random random = new Random();
            int option = random.nextInt(3);
            if (option == 0) {
                double radius = random.nextDouble() * 50;
                shapes[i] = new Circle(radius);
            } else if (option == 1) {
                double base = random.nextDouble() * 50;
                double height = random.nextDouble() * 50;
                double side1 = random.nextDouble() * 50;
                double side2 = random.nextDouble() * 50;
                shapes[i] = new Triangle(base, height, side1, side2);
            } else {
                double length = random.nextDouble() * 50;
                double width = random.nextDouble() * 50;

                shapes[i] = new Rectangle(length, width);
            }
        }

        // Calculate total parameter and total area
        double total_perimeter = 0;
        double total_area = 0;
        for (int i = 0; i < 10; i++) {
            System.out.println(shapes[i]);
            total_area += shapes[i].computeArea();
            total_perimeter += shapes[i].computePerimeter();
        }

        // Display total parameter and total area
        System.out.printf("\nTotal Perimeter : %.2f\n", total_perimeter);
        System.out.printf("Total Area : %.2f\n", total_area);

        // Display total number of objects
        System.out.println("\nTotal Number of Circle Objects : " + Circle.getNumCircles());
        System.out.println("Total Number of Triangle Objects : " + Triangle.getNumTris());
        System.out.println("Total Number of Rectangle Objects : " + Rectangle.getNumRects());

        System.out.println("\nTotal Number of All Objects : " + Shape.getNumShapes());


    }
}
