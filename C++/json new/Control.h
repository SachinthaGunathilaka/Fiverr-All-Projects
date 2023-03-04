
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "View.h"

class Store;

using namespace std;

class Control {
		
	public:
		
		void launch();


	private:
		Store* store;
		View view;
		void initStore(Store*);
		void receiveProduct();
		void fillOrder();
		void locationTest();
		void queueTest();

		static const string PRODUCTS[10];
		static const int QUANTITIES[10];
		
		
		
	
};
#endif