#include "Product.h"

Product::Product() {
    this->color = "";
    this->size = "";
    this->quantity = 0;
    this->price = 0;
}

Product::Product(string color, string size, int quantity, double price) {
    this->color = std::move(color);
    this->size = std::move(size);
    this->quantity = quantity;
    this->price = price;
}

void Product::display() {
    cout << setw(10) << left << this->color << setw(10) << left << this->size << setw(10) << left << this->quantity
          << "$" << fixed << setprecision(2) << right << this->price << endl;
}

const string &Product::getColor() const {
    return color;
}

const string &Product::getSize() const {
    return size;
}

int Product::getQuantity() const {
    return quantity;
}

double Product::getPrice() const {
    return price;
}

void Product::setColor(const string &color) {
    Product::color = color;
}

void Product::setSize(const string &size) {
    Product::size = size;
}

void Product::setQuantity(int quantity) {
    Product::quantity = quantity;
}

void Product::setPrice(double price) {
    Product::price = price;
}




