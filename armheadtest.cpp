#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "RobotPart.h"
#include "Head.h"
#include "Arm.h"



int main()
{


	Head head1("Big Head", 20, ComponentType::head, 10, 057272750, "The head for the robot");
	Arm arm1("arms", 10, ComponentType::arm, 5, 54557785, "The arm for the robot");
	int speed = 23;




	cout << "Head: name:" << head1.getName() << " weight: " << head1.getWeight() << " cost:"<<head1.getCost()<<endl;
	cout <<"part Number: "<< head1.getPartNumber() << " Description:"<<head1.getDescription()<< endl;

    cout << "Arm: name:" << arm1.getName() << " weight: " << arm1.getWeight() << " cost:"<<arm1.getCost()<<endl;
	cout <<"part Number: "<< arm1.getPartNumber() << " Description:"<<arm1.getDescription()<< endl;

	cout << "Arm power: " << arm1.powerConsumed(speed) << endl;


	cin.get();



	return 0;
}
