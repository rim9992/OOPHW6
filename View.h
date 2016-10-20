
#ifndef _VIEW_H_
#define _VIEW_H_
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iomanip>

#include "RobotPart.h"
#include "RobotModel.h"
#include "Order.h"
#include "SalesAssociate.h"
#include "Customer.h"

using namespace std;

class View {

public:


	void viewHeads(vector<Head> list);
	void viewArms(vector<Arm> list);
	void viewBatteries(vector<Battery> list);
	void viewLocomotors(vector<Locomotor> list);
	void viewTorsos(vector<Torso> list);
	void viewModels(vector<RobotModel> list);
	void viewCustomers(vector<Customer> list);
	void viewAssociates(vector<SalesAssociate> list);
	void viewOrders(vector<Order> list);
	void viewCustomerOrders(Customer cust, vector<Order> list);
	void viewAssociateOrders(SalesAssociate assoc, vector<Order> list);
	void printMenu();
	void printCreateMenu();
	void printReportMenu();

};
#endif
