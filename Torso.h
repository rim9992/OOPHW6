#ifndef _TORSO_H_
#define _TORSO_H_
#pragma once

#include "head.h"
#include "locomotor.h"
//#include "Battery.h"
//#include "Arm.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

class Torso {

public:
	Torso(int final BatteryComp, Head HEAD, Locomotor Loco) : 
		(batteryCompartments(BatteryComp), head(HEAD), locomotor(Loco){}

	void add_battery(Battery batteryCompartments);
	void add_arm(Arm arm);



private:
	int final batteryCompartments;
	Head head;
	Locomotor locomotor;
	vector<Battery> batteries;
	vector<Arm> arms;

	

};

#endif