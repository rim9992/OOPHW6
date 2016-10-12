#include "Shop.h"


void Shop::cli()
{
	int choice = 1;

	while (choice != 0)
	{
		view.printMenu();
		cin >> choice;
		if (choice == 1)
		{
			view.viewModels(models);
		}
		else if (choice == 2)
			createNewModel();
		else if (choice == 3)
			createNewPart();


	}
}



Head Shop::searchHeads(int partNum) {

	int length = heads.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (heads[i].getPartNumber() == partNum)
			return heads[i];
	}

	throw partNotFound();
}

Locomotor Shop::searchLocomotors(int partNum) {

	int length = locomotors.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (locomotors[i].getPartNumber() == partNum)
			return locomotors[i];
	}

	throw partNotFound();
}

Torso Shop::searchTorsos(int partNum) {

	int length = torsos.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (torsos[i].getPartNumber() == partNum)
			return torsos[i];
	}

	throw partNotFound();
}
Battery Shop::searchBattery(int partNum) {

	int length = batteries.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (batteries[i].getPartNumber() == partNum)
			return batteries[i];
	}

	throw partNotFound();
}

Arm Shop::searchArms(int partNum) {

	int length = arms.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (arms[i].getPartNumber() == partNum)
			return arms[i];
	}

	throw partNotFound();
}

int Shop::checkInt(string val)
{
	int result;
	try {
		result = stoi(val);
		if (result < 0) throw negativeNumber();
	}
	catch (invalid_argument& e) { cout << "Must enter a Integer\n"; return NULL; }
	catch (negativeNumber& e) { cout << "Must be a positive Integer\n"; return NULL; }

	return result;
	
}
double Shop::checkDub(string val)
{
	double result;
	try {
		result = stod(val);
		if (result < 0) throw negativeNumber();
	}
	catch (invalid_argument& e) { cout << "Must enter a number\n"; return NULL; }
	catch (negativeNumber& e) { cout << "Must be a positive number\n"; return NULL; }

	return result;

}





void Shop::createNewPart() 
{

	string name;
	string value;
	int partNumber=NULL;
	ComponentType componentType;
	int type = NULL;
	double weight=NULL;
	double cost=NULL;
	string description;
	cout << "Creating a New Part\n___________________\nEnter the Name: ";

	//delimeter set at ':' becasuse new line wasnt working. Needs to be fixed. Same situation for the description
	getline(cin, name,':');
	
	//Gets and validates input from the user to create a new Robot part
	
	while(partNumber==NULL)
	{
		cout << "Part Number: ";
		cin >> value;
		partNumber = checkInt(value);		
	 }


	while (weight == NULL)
	{
		cout << "Weight: ";
		cin >> value;
		weight = checkDub(value);

	}


	while (cost == NULL)
	{
		cout << "Cost: ";
		cin >> value;
		cost = checkDub(value);


	}

	//determines the type of part and gets more input accordingly

	cout << "Description: ";
	getline(cin, description,':');

	cout << "Head(1)\nArm(2)\nLocomotor(3)\nTorso(4)\nBattery(5)\nComponent Type: ";


	while (type == NULL)
	{
		cin >> value;
		type = checkInt(value);
		
		if (type > 5 || type < 1)
		{
			cout << "Integer must be between 1 and 5\n";
			type = NULL;
		}

	}
	//splits between the different part types

	if (type == 1)
	{
		Head head(name, partNumber, ComponentType::head, weight, cost, description);
		heads.push_back(head);

	}
	else if (type == 2)
	{
		int speed = NULL;
		while (speed ==NULL)
		{
			cout << "Speed: ";
			cin >> value;
			speed = checkInt(value);

		}
		Arm arm(name, partNumber, ComponentType::arm, weight, cost, description, speed);
		arms.push_back(arm);

	}
	else if (type == 3)
	{
		
		int speed = NULL;
		while (speed == NULL)
		{
			cout << "Speed: ";
			cin >> value;
			speed = checkInt(value);

		}
		Locomotor loco(name, partNumber, ComponentType::locomotor, weight, cost, description, speed);
		locomotors.push_back(loco);
	}
	if (type == 4)
	{
		int battery = NULL;
		while (battery == NULL)
		{
			cout << "Number of battery Compartments: ";
			cin >> value;
			battery = checkInt(value);


		}
		
		Torso torso(name, partNumber, ComponentType::torso, weight, cost, description, battery);
		torsos.push_back(torso);
	 }
	if (type == 5)
	{
		double energy = NULL;
		while (energy ==NULL)
		{
			cout << "Energy: ";
			cin >> value;
			energy = checkDub(value);
			
		}

		double power = NULL;
		while (power == NULL)
		{
			cout << "Power: ";
			cin >> value;
			power = checkDub(value);

		}

		Battery batt(name, partNumber, ComponentType::battery, weight, cost, description, energy, power);
		batteries.push_back(batt);
	}



}

//the skip option when choosing a part does not work
void Shop::createNewModel()
{
	string name;
	string value;
	bool partAdded = false;
	bool tors = false;

	double price = NULL;
	int partNumber = NULL;
	int num = NULL;
	cout << "Enter Name:";
	getline(cin, name, ':');

	while (num == NULL)
	{
		cout << "Enter Model Part Number:";
		cin >> value;
		num = checkInt(value);


	}
	RobotModel newModel(name, num);


	//choosing the head
	view.viewHeads(heads);

	while (!partAdded)
	{
		while (partNumber == -1)
		{
			cout << "Enter the part number of the desired head, 0 to skip:";
			cin >> value;
			partNumber = checkInt(value);
			
			
		}

		
		if (partNumber == 0) partAdded = true;		
		
		if (partNumber != 0)
		{
			try
			{
				Head head = searchHeads(partNumber);
				newModel.setHead(head);
				partAdded = true;
			}
			catch (partNotFound& e) { cout << "The part Number was not found in the data base"; }
		}

		
	}

	partNumber = NULL;
	partAdded = false;
	//choosing the Arms

	view.viewArms(arms);
	while (partNumber == NULL)
	{
		cout << "Enter the part number of the desired arm, 0 to skip:";
		cin >> value;
		partNumber = checkInt(value);
	}

	if (partNumber != 0)
	{

		int armNum = NULL;
		while (armNum == NULL)
		{
			cout << "Enter the number of arms, either 1 or 2:";
			cin >> value;
			armNum = checkInt(value);
			if (armNum != 1 && armNum != 2) { cout << "Has to be either 1 or 2\n"; armNum = NULL; }
		}

		while (!partAdded)
		{
			try
			{
				Arm arm = searchArms(partNumber);
				newModel.addArm(arm);
				if (armNum == 2) newModel.addArm(arm);
				partAdded = true;
			}
			catch (partNotFound& e) { cout << "The part Number was not found in the data base"; }


		}
	}
	
	partNumber = NULL;
	partAdded = false;
	//choosing the locomotor

	view.viewLocomotors(locomotors);


	while (partNumber == NULL)
	{
		cout << "Enter the part number of the desired locomotor, 0 to skip:";
		cin >> value;
		partNumber = checkInt(value);
	}
	if (partNumber != 0)
	{
		while (!partAdded)
		{
			try
			{
				Locomotor loco = searchLocomotors(partNumber);
				newModel.setLocomotor(loco);
				partAdded = true;
			}
			catch (partNotFound& e) { cout << "The part Number was not found in the data base"; }

		}
	}

	partNumber = NULL;
	partAdded = false;
	//choosing the Torso
	view.viewTorsos(torsos);

	while (!partAdded)
	{
		while (partNumber == NULL)
		{
			cout << "Enter the part number of the desired torso, 0 to skip:";
			cin >> value;
			partNumber = checkInt(value);
		}

		if (partNumber != 0)
		{
			try
			{
				Torso tor = searchTorsos(partNumber);
				newModel.setTorso(tor);
				partAdded = true;
				tors = true;
			}
			catch (partNotFound& e) { cout << "The part Number was not found in the data base"; }
		}


	}

	partNumber = NULL;
	partAdded = false;
	//choosing the battery, if torso was skipped also skip battery
	if (tors)
	{
		view.viewBatteries(batteries);

		while (!partAdded)
		{
			while (partNumber == NULL)
			{
				cout << "Enter the part number of the desired Battery, 0 to skip:";
				cin >> value;
				partNumber = checkInt(value);
			}

			if (partNumber != 0)
			{
				try
				{
					Battery batt = searchBattery(partNumber);
					newModel.setBatteries(batt);
					partAdded = true;
				}
				catch (partNotFound& e) { cout << "The part Number was not found in the data base"; }
			}


		}

		

	}

	//Showing the total price of all the chosen parts to determine model price
	cout << "Total Part Cost:$" << newModel.getPartsCost() << endl;

	while (price == NULL)
	{
		cout << "Enter Model Price:";
		cin >> value;
		price = checkDub(value);
	}
	newModel.updatePrice(price);

	cout << "Enter Description:";
	getline(cin, value,':');
	newModel.setDescription(value);

	models.push_back(newModel);
}


