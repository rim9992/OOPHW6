#ifndef _SALESASSOCIATE_H
#define _SALESASSOCIATE_H
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;


#include "Order.h"


class SalesAssociate {

public:

	SalesAssociate(string Name, int employeeNum) : name(Name), employeeNumber(employeeNum) {}
	SalesAssociate() : name("unknown"), employeeNumber(0) {}
	
	string assoc_to_string();

	string getName();
	int getEmployeeNumber();
	void add_order(Order info);
        
        vector<int> orders;

private:

	string name;
	int employeeNumber;
	


};



#endif

