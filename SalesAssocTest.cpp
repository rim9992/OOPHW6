#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "SalesAssociate.h"

int main()
{
	bool passed = true;

	string name = "Rabab Antria";
	string number = "817-214-8642";

	SalesAssociate S(name, number);

	if (S.getName() != name) {
		passed = false;
		cerr << "Name was ' " << S.getName() <<
			"' should be '" << name << " ' " << endl;
	}

	if (S.getEmployeeNumber() != number) {
		passed = false;
		cerr << "Number was '" << S.getEmployeeNumber() <<
			" ' should be '" << number << " ' " << endl;
	}

	cout << S.to_string() << endl;

	cout << (passed ? "passed" : "failed") << endl;


	return 0;
}