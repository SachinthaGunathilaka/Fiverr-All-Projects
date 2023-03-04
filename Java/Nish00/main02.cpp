// Name : XXXXXXXXXXXXXXXXXXX,  ID : XXXXX

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Shape {
public:
    virtual double volume() = 0;
};

class Sphere : public Shape {
private:
    double radius;

public:
    Sphere(double radius) : radius(radius) {}

    double volume() {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
};

class Cuboid : public Shape {
private:
    double width;
    double height;
    double depth;

public:
    Cuboid(double width, double height, double depth) : width(width), height(height), depth(depth) {}

    double volume() {
        return width * height * depth;
    }
};

class Cube : public Cuboid {
public:
    Cube(double width) : Cuboid(width, width, width) {}
};

int main() {
    vector<Shape *> shapes;
    shapes.push_back(new Cuboid(1.5, 2.7, 5.5));
    shapes.push_back(new Sphere(3.9));
    shapes.push_back(new Cuboid(2.5, 3.4, 4.4));
    shapes.push_back(new Cube(5.9));
//
// Add code here for parts (f) and (g)
//

    for (auto &shape: shapes) {
        cout << shape->volume() << endl;
    }

    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    return 0;
}
