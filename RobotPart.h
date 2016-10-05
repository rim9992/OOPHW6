
#ifndef _ROBOTPART_H_
#define _ROBOTPART_H_
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

enum class ComponentType { head, arm, locomotor, torso, battery };

class RobotPart {

public:
	
	RobotPart(string Name, int PartNumber, ComponentType comp, double Weight, double Cost, string Description) : name(Name), 
		partNumber(PartNumber),componentType(comp), weight(Weight),cost(Cost),description(Description){}

	double getCost();
	double getWeight();
	int getPartNumber();
	string getName();
	string getDescription();


protected:
	string name;
	int partNumber;
	ComponentType componentType;
	double weight;
	double cost;
	string description;

};

#endif