import java.util.Scanner;

public class Triangle extends Shape {
    // Attributes
    private double base;
    private double height;
    private static int numTris = 0;

    private double side1;
    private double side2;


    // Constructor with 4 parameters
    public Triangle(double base, double height, double side1, double side2) {
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        numTris++;

    }

    // Constructor with 6 parameters
    public Triangle(String name, String color, double base, double height, double side1, double side2) {
        super(name, color);
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        numTris++;

    }

    // Constructor with 5 parameters
    public Triangle(String name, double base, double height, double side1, double side2) {
        super(name);
        this.base = base;
        this.height = height;
        this.side1 = side1;
        this.side2 = side2;
        numTris++;

    }

    // getters
    public double getBase() {
        return base;
    }

    public double getHeight() {
        return height;
    }

    public static int getNumTris() {
        return numTris;
    }

    // setters
    public void setBase(double base) {
        this.base = base;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    // Method to calculate the area
    public double computeArea() {
        return (base * height) / 2;
    }

    // Method to calculate the area
    public double computePerimeter() {
        return base + side1 + side2;
    }

    // Overriding toString method
    public String toString() {
        return String.format("%s, Base : %.2f, Height : %.2f, Area : %.2f, Perimeter : %.2f", super.toString(), base, height, computeArea(), computePerimeter());

    }
}
