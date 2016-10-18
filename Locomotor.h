#ifndef _LOCOMOTOR_H
#define _LOCOMOTOR_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#pragma once
#include "RobotPart.h"

class Locomotor: public RobotPart {

public:
	Locomotor(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description, int speed) : 
		RobotPart(Name, PartNumber, comp, Weight, Cost, Description), maxSpeed(speed) {};
	
		
	

	int powerConsumed();

private:
	int maxSpeed;


};

#endif
