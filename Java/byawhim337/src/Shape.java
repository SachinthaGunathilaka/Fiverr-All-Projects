// Shape class
public class Shape {
    // Attributes
    private String color;
    private String name;
    private static int numShapes = 0;

    // Default Constructor
    public Shape() {
        this.name = "default";
        this.color = "default";
        numShapes++;
    }

    // Constructor with 2 parameters
    public Shape(String name, String color) {
        this.color = color;
        this.name = name;
        numShapes++;
    }

    // Constructor with 1 parameter
    public Shape(String name) {
        this.name = name;
        this.color = "default";
        numShapes++;
    }

    // getters
    public String getColor() {
        return color;
    }

    public String getName() {
        return name;
    }

    public static int getNumShapes() {
        return numShapes;
    }

    // setters
    public void setColor(String color) {
        this.color = color;
    }

    public void setName(String name) {
        this.name = name;
    }


    // Method to calculate the area
    public double computeArea() {
        return 0.0;
    }

    // Method to calculate the perimeter
    public double computePerimeter() {
        return 0.0;
    }

    // Overriding toString method
    public String toString() {
        return "Name : " + name + ", Color : " + color;
    }
}
