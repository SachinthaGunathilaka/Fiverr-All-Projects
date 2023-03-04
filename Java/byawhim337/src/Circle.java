public class Circle extends Shape{
    // Attributes
    private double radius;
    private static int numCircles=0;

    // Default Constructor
    public Circle(double radius) {
        this.radius = radius;
        numCircles++;

    }

    // Constructor with 3 parameters
    public Circle(String name, String color, double radius) {
        super(name, color);
        this.radius = radius;
        numCircles++;

    }

    // Constructor with 2 parameters
    public Circle(String name, double radius) {
        super(name);
        this.radius = radius;
        numCircles++;

    }

    // getters
    public double getRadius() {
        return radius;
    }

    public static int getNumCircles() {
        return numCircles;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    // Method to calculate the area
    public double computeArea(){
        return Math.PI * radius * radius;
    }

    // Method to calculate the perimeter
    public double computePerimeter(){
        return 2 * Math.PI * radius;
    }


    // Overriding toString method
    public String toString(){
        return String.format("%s, Radius : %.2f, Area : %.2f, Perimeter : %.2f", super.toString(), radius, computeArea(), computePerimeter());
    }
}
