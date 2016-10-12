#ifndef _SALESASSOCIATE_H_
#define _SALESASSOCIATE_H_
#pragma once

#include "Order.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class SalesAssociate {

public:

	SalesAssociate(string Name, string employeeNum) : name(Name), employeeNumber(employeeNum) {}
	SalesAssociate() : name("unknown"), employeeNumber("unknown") {}
	
	string to_string();

	string getName();
	string getEmployeeNumber();
	void add_order(Order info);

private:

	string name;
	string employeeNumber;
	vector<Order> orders;


};

#endif

