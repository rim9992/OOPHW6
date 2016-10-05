#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "RobotPart.h"
#include "Locomotor.h"


int main()
{


	Locomotor loc("SpinMaster", 45, ComponentType::locomotor, 45, 76, "Spins Really Fast",76);
	int speed = 32;



	

	cout << "Locomotor: name:" << loc.getName() << " weight: " << loc.getWeight() << " cost:"<<loc.getCost()<<endl;
	cout <<"part Number: "<< loc.getPartNumber() << " Description:"<<loc.getDescription()<< endl;

	cout << "power: " << loc.powerConsumed(speed) << endl;
		
	cin.get();



	return 0;
}