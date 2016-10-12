#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Customer.h"

int main()
{
	bool passed = true;

	string Name = "Rabab Antria";
	string number = "817-214-8642";
	double Wallet = 30.6;  //total price in dollars

	Customer C(Name, number, Wallet);

	if (C.getName() != Name) {
		passed = false;
		cerr << "Name was ' " << C.getName() <<
			"' should be '" << Name << " ' " << endl;
	}

	if (C.getCustomerNumber() != number) {
		passed = false;
		cerr << "Number was '" << C.getCustomerNumber() <<
			" ' should be '" << number << " ' " << endl;
	}

	if (C.getWallet() != Wallet) {
		passed = false;
		cerr << "Wallet was '" << C.getWallet() <<
			" ' should be '" << Wallet << " ' " << endl;
	}

	cout << C.to_string() << endl;

	cout << (passed ? "passed" : "failed") << endl;


	return 0;
}