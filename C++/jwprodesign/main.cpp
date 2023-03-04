#include <iostream>
#include <fstream>
#include <vector>

#include "Product.h"

using namespace std;

void displayMenu(){
    cout << "\n1) Read Products from a file \n"
            "2) Display all Products \n"
            "3) Display specific Product\n"
            "4) Add a new Product \n"
            "5) Update Product information\n"
            "6) Produce a Monthly Sales Report\n"
            "7) Save updated Product/Services information to file\n"
            "8) Quit" << endl;
}

int getOption(){
    int option;
    cout << "\nSelect option: ";
    cin >> option;

    while (option < 1 || option > 8){
        cout << "Invalid option" << endl;
        cout << "Select option: ";
        cin >> option;
    }

    return option;
}
void readFromFile(vector<Product> &products, const string& filename){
    ifstream infile(filename);


    string color, size;
    int quantity;
    double price;

    while (infile >> color >> size >> quantity >> price) {
        Product product(color, size, quantity, price);
        products.push_back(product);
    }
    infile.close();
    cout << "Data has read from the file successfully!" << endl;


}

void displayProducts(const vector<Product> &products) {
    cout << endl;

    for (Product product: products) {
        product.display();
    }
}

void displayProduct(const vector<Product> &products, const string &color, const string &size) {
    for (Product product: products) {
        if (product.getColor() == color && product.getSize() == size) {
            cout << endl;
            product.display();
            return;
        }
    }

    cout << "\nProduct does not exits" << endl;
}

void addProduct(vector<Product> &products, const string &color, const string &size, int quantity, double price) {
    Product product(color, size, quantity, price);
    products.push_back(product);

    cout << "Product added successfully!" << endl;
}

void updateProduct(vector<Product> &products, const string &color, const string &size) {
    for (Product &product: products) {
        if (product.getColor() == color && product.getSize() == size) {
            int quantity;
            double price;

            cout << "\nEnter quantity: ";
            cin >> quantity;

            cout << "Enter price: $";
            cin >> price;

            product.setQuantity(quantity);
            product.setPrice(price);
            return;
        }
    }

    cout << "\nProduct does not exits" << endl;

}

void displayReport(vector<Product> &products){
    double total_sales = 0;
    int total_quantities = 0;
    Product  max_quantity_product;
    Product  max_price_product;
    for (Product &product: products) {
        total_sales += product.getPrice();
        total_quantities += product.getQuantity();
        if (product.getQuantity() > max_quantity_product.getQuantity()) {
            max_quantity_product = product;
        }

        if (product.getQuantity() > max_price_product.getPrice()) {
            max_price_product = product;
        }
    }

    cout << "\nTotal Sales: $" << total_sales << endl;
    cout << "Total Quantities: $" << total_quantities << endl;
    cout << "\nProduct with max quantity: " << endl;
    max_quantity_product.display();

    cout << "\nProduct with max price: " << endl;
    max_price_product.display();
}

void writeToFile(vector<Product> &products, string filename){
    ofstream outFile(filename);
    for (Product &product: products) {
        outFile << product.getColor() << " " << product.getSize() << " " << product.getQuantity() << " " << product.getPrice() << endl;
    }

    outFile.close();
    cout << "Data has written to the file successfully!" << endl;
}

int main() {

    vector<Product> products;

    while (true){
        displayMenu();
        int option = getOption();

        if(option == 1){
            string filename;
            cout << "\nEnter filename to read: ";
            cin >> filename;
            readFromFile(products, filename);
        }

        else if(option == 2){
            displayProducts(products);
        }
        else if(option == 3){
            string color, size;
            cout << "\nEnter product color: ";
            cin >> color;

            cout << "Enter product size: ";
            cin >> size;

            displayProduct(products, color, size);
        }

        else if(option == 4){
            string color, size;
            int quantity;
            double price;
            cout << "\nEnter product color: ";
            cin >> color;

            cout << "Enter product size: ";
            cin >> size;

            cout << "Enter quantity: ";
            cin >> quantity;

            cout << "Enter price: $";
            cin >> price;


            addProduct(products, color, size, quantity, price);
        }

        else if(option == 5){
            string color, size;
            cout << "\nEnter product color: ";
            cin >> color;

            cout << "Enter product size: ";
            cin >> size;

            updateProduct(products, color, size);
        } else if(option == 6){
            displayReport(products);
        } else if(option == 7){
            string filename;
            cout << "\nEnter filename to write: ";
            cin >> filename;
            writeToFile(products, filename);
        }
        else {
            break;
        }
    }



    return 0;
}
