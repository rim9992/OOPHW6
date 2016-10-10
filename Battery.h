#ifndef _BATTERY_H_
#define _BATTERY_H_
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "RobotPart.h"

using namespace std;

class Battery:public RobotPart{

public: 
    
	Battery(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description, double Energy, double Power) :
		RobotPart(Name, PartNumber, comp, Weight, Cost, Description),energy(Energy),maxPower(Power) {};

      double getEnergy();
      double getMaxPower();
      
private:
       
       double energy;
       double maxPower;
       
};

#endif
