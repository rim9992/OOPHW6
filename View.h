
#ifndef _VIEW_H_
#define _VIEW_H_
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "RobotPart.h"
#include "RobotModel.h"

using namespace std;

class View{

public: 


	void viewHeads(vector<Head> list);
	void viewArms(vector<Arm> list);
	void viewBatteries(vector<Battery> list);
	void viewLocomotors(vector<Locomotor> list);
	void viewTorsos(vector<Torso> list);
	void viewModels(vector<RobotModel> list);

	void printMenu();

};

#endif