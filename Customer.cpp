#include "Customer.h"


string Customer::getName() {

	return name;
}

string Customer::getCustomerNumber() {

	return customerNumber;

}

double Customer::getWallet() {

	return wallet;
}

void Customer::add_order(Order info) {

	orders.push_back(info);
}

string Customer::to_string() {

	return name + " (" + customerNumber + ") ";

}