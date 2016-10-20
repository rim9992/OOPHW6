#ifndef _ROBOTMODEL_H
#define _ROBOTMODEL_H
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




class RobotModel {

public:

	

	RobotModel(string Name, int ModelNumber) : name(Name),
		modelNumber(ModelNumber) {}

	double getPrice();
	string getName();
	int getModelNumber();
	double getPartsCost();
	void updatePrice(double newPrice);
	double getWeight();
        
        // Need to make the methods
        int getTorso();
        int getHead();
        int getLocomotor();
        int getBattery();
        int getMaxBatteries();
        int getnumOfArms();
        
	void restoreValues(int torso, int head, int locomotor, int battery, 
            string name, string description, int modelNumber, double price, int maxBatteries,
            int numOfArms, double partsCost,double totalWeight);


	void setTorso(Torso tor);
	void setHead(Head part_head);
	void setLocomotor(Locomotor loco);
	void addArm(Arm arm);
	void setBatteries(Battery batteries);
	void setDescription(string des);
	string getDescription();

        vector<int> arms;

private:
	int torso;
	int head;
	int locomotor;
	int battery;
	string name;
	string description;
	int modelNumber;
	double price;
	int maxBatteries;
	int numOfArms=0;
	double partsCost = 0;
	double totalWeight = 0;

};

#endif
