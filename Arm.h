#ifndef _ARM_H
#define _ARM_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#pragma once
#include "Arm.h"

class Arm: public RobotPart {

public:
	Arm(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description, int speed) : 
		RobotPart(Name, PartNumber, comp, Weight, Cost, Description), maxSpeed(speed) {};
	
		
	

	int powerConsumed(int speed);



};

#endif