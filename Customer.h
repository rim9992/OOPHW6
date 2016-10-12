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

class Customer {

public:

	Customer(string Name, string CustomerNum, double Wallet) : name(Name), customerNumber(CustomerNum), wallet(Wallet) {}

	string to_string();

	string getName();
	string getCustomerNumber();
	double getWallet();
	void add_order(Order info);

private:

	string name;
	string customerNumber;
	double wallet;
	vector<Order> orders;
	

};

#endif
