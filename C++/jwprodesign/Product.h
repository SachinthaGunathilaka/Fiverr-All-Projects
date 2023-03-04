#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include <utility>
#include <iomanip>

using namespace std;

class Product {

private:
    string color;
    string size;
    int quantity;
    double price;

public:

    Product();
    Product(string color, string size, int quantity, double price);

    const string &getColor() const;

    const string &getSize() const;

    int getQuantity() const;

    double getPrice() const;

    void setColor(const string &color);

    void setSize(const string &size);

    void setQuantity(int quantity);

    void setPrice(double price);

    void display();

};


#endif
