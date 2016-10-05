#ifndef _HEAD_H
#define _HEAD_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#pragma once
#include "RobotPart.h"

class Head: public RobotPart {

public:
	Head(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description, int speed) :
		RobotPart(Name, PartNumber, comp, Weight, Cost, Description){}

};

#endif
