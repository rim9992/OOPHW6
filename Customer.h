#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#pragma once

#include "Order.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

//class Order;

class Customer {

public:

	Customer(string Name, int CustomerNum) : name(Name), customerNumber(CustomerNum) {}

	string cust_to_string();
	string getName();
	int getCustomerNumber();
	double getWallet();
	void add_order(Order info);
        
        void setWallet(double wall);
        
        vector<int> orders;

private:

	string name;
	int customerNumber;
	double wallet = 0;
	
	

};



#endif
