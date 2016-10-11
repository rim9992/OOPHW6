#ifndef _TORSO_H_
#define _TORSO_H_
#pragma once

#include "RobotPart.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

class Torso: public RobotPart {

public:
	Torso(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description, int battery) :
		RobotPart(Name, PartNumber, comp, Weight, Cost, Description), batteryCompartments(battery) {};

	int max_batteries();


private:
	const int  batteryCompartments;
	


};

#endif