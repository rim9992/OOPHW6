#include "View.h"


//each one of the functions for viewing the parts needs to be modified to show all the data for each specific part
void View::viewHeads(vector<Head> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout <<"Name :" << list[i].getName() << "\nPart Number: " << list[i].getPartNumber() << "\nCost: "<<list[i].getCost()<<endl;
	}
}

void View::viewArms(vector<Arm> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName() << "\nPart Number: " << list[i].getPartNumber() << "\nCost: " << list[i].getCost() << endl;
	}
}
void View::viewLocomotors(vector<Locomotor> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName() << "\nPart Number: " << list[i].getPartNumber() << "\nCost: " << list[i].getCost() << endl;
	}
}
void View::viewTorsos(vector<Torso> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName() << "\nPart Number: " << list[i].getPartNumber() << "\nCost: " << list[i].getCost() << endl;
	}
}
void View::viewBatteries(vector<Battery> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName() << "\nPart Number: " << list[i].getPartNumber() << "\nCost: " << list[i].getCost() << endl;
	}
}

void View::viewModels(vector<RobotModel> list)
{
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << list[i].getName() << "\nPrice:" << list[i].getPrice() << "\nDescription:" << list[i].getDescription() << endl;
	}
}


void View::printMenu()
{
	cout << "Menu\n_______\n"
		 <<"View Robot Models(1)\n"
		 <<"Create New Model(2)\n"
		 <<"Create new Robot Part(3)\n"
		 <<"Exit(0)\n << endl;
}