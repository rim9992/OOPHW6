#ifndef _SHOP_H
#define _SHOP_H
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "tinyxml2.h"
using namespace tinyxml2;

#include "Head.h"
#include "Locomotor.h"
#include "Arm.h"
#include "Torso.h"
#include "Battery.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"
#include "Order.h"
#include "SalesAssociate.h"
#include "Customer.h"




class Shop {

public:
	

	Head searchHeads(int partNum);
	Arm searchArms(int partNum);
	Locomotor searchLocomotors(int partNum);
	Torso searchTorsos(int partNum);
	Battery searchBattery(int partNum);
	RobotModel searchModels(int partNum);


	void createNewPart();
	void createNewModel();
	void createCustomer();
	void createAssociate();
	void createOrder();
	class partNotFound {};
	class negativeNumber {};
	void cli();
	int checkInt(string val);
	double checkDub(string val);
        void save();
        void load();
        char* stringToChar(string str);

private:

	vector<Head> heads;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Battery> batteries;
	vector<Torso> torsos;
	vector<RobotModel> models;
	vector<Customer> customers;
	vector<SalesAssociate> associates;
	vector<Order> orders;
	View view;


};

#endif
