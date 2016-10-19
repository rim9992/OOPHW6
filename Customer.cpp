#include "Customer.h"
#include "Order.h"


string Customer::getName() {

	return name;
}

int Customer::getCustomerNumber() {

	return customerNumber;

}

double Customer::getWallet() {

	return wallet;
}

void Customer::add_order(Order info) {

	orders.push_back(info.get_num());
}

string Customer::cust_to_string() {

	return name + " (" + to_string(customerNumber) + ")\n ";

}

void Customer::setWallet(double wall) {
    wallet = wall;
}
