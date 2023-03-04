public class Rectangle extends Shape {
    // Attributes
    private double length;
    private double width;
    private static int numRects = 0;

    // Constructor with 2 parameters
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
        numRects++;
    }

    // Constructor with 4 parameters
    public Rectangle(String name, String color, double length, double width) {
        super(name, color);
        this.length = length;
        this.width = width;
        numRects++;

    }

    // Constructor with 3 parameters
    public Rectangle(String name, double length, double width) {
        super(name);
        this.length = length;
        this.width = width;
        numRects++;

    }

    // getters
    public double getLength() {
        return length;
    }

    public double getWidth() {
        return width;
    }

    public static int getNumRects() {
        return numRects;
    }


    // setters
    public void setLength(double length) {
        this.length = length;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    // Method to calculate the area
    public double computeArea() {
        return length * width;
    }

    // Method to calculate the perimeter
    public double computePerimeter() {
        return 2 * (length + width);
    }

    // Overriding toString method
    public String toString() {
        return String.format("%s, Length : %.2f, Width : %.2f, Area : %.2f, Perimeter : %.2f", super.toString(), length, width, computeArea(), computePerimeter());
    }
}
