#include "SalesAssociate.h"
#include "Order.h"


string SalesAssociate::getName() {

	return name;
}

string SalesAssociate::getEmployeeNumber() {

	return employeeNumber;

}

void SalesAssociate::add_order(Order info) {

	orders.push_back(info);
}

string SalesAssociate::to_string() {
	
	return name + " (" + employeeNumber + ")";
}
