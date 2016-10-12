#ifndef _SHOP_H
#define _SHOP_H
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "Head.h"
#include "Locomotor.h"
#include "Arm.h"
#include "Torso.h"
#include "Battery.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"




class Shop {

public:
	

	Head searchHeads(int partNum);
	Arm searchArms(int partNum);
	Locomotor searchLocomotors(int partNum);
	Torso searchTorsos(int partNum);
	Battery searchBattery(int partNum);


	void createNewPart();
	void createNewModel();
	class partNotFound {};
	class negativeNumber {};
	void cli();
	int checkInt(string val);
	double checkDub(string val);

private:

	vector<Head> heads;
	vector<Locomotor> locomotors;
	vector<Arm> arms;
	vector<Battery> batteries;
	vector<Torso> torsos;
	vector<RobotModel> models;
	View view;


};

#endif