#include "SalesAssociate.h"



string SalesAssociate::getName() {

	return name;
}

int SalesAssociate::getEmployeeNumber() {

	return employeeNumber;

}

void SalesAssociate::add_order(Order info) {

	orders.push_back(info.get_num());
}

string SalesAssociate::assoc_to_string() {
	
	return name + " (" + to_string(employeeNumber) + ")\n";
}
