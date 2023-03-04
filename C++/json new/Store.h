
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Product.h"
#include "List.h"


using namespace std;

class Store {
		
	public:
		//constructor
		Store(const string& name);
		
		//destructor
		~Store();

		//other
		void findAvailableSLoc(StoreLocation**);
		void findAvailableWHLoc(WHLocation**);

		void printStoreStock();
		void printWareHouseStock();
		void printProducts();

		//these are done for you
		void findProduct(const string&, Product**);
		void receiveProduct(const string&, int quantity);
		void fillOrder(const string&, int &quantity);
		void print();
	
	private:
		string name;
		
	
};
#endif