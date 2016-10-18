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
		else if (choice == 4)
			createCustomer();
		else if (choice == 5)
			createAssociate();
		else if (choice == 6)
			createOrder();


	}
}

RobotModel Shop::searchModels(int partNum)
{
	int length = models.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (models[i].getModelNumber() == partNum)
			return models[i];
	}

	throw partNotFound();
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
	catch (invalid_argument& e) { cout << "Must enter a Integer\n"; return -1; }
	catch (negativeNumber& e) { cout << "Must be a positive Integer\n"; return -1; }

	return result;
	
}
double Shop::checkDub(string val)
{
	double result;
	try {
		result = stod(val);
		if (result < 0) throw negativeNumber();
	}
	catch (invalid_argument& e) { cout << "Must enter a number\n"; return -1; }
	catch (negativeNumber& e) { cout << "Must be a positive number\n"; return -1; }

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

        save();

}

void Shop::createNewModel()
{
	string name;
	string value;
	bool partAdded = false;
	bool tors = false;

	double price = NULL;
	int partNumber = -1;
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
		partNumber = -1;
		while (partNumber == -1)
		{
			cout << "Enter the part number of the desired head, 0 to skip:";
			cin >> value;
			partNumber = checkInt(value);
		}

		
		if (partNumber == 0)
		{
			partAdded = true;

		}
						
		else
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

	partAdded = false;
	//choosing the Arms

	view.viewArms(arms);
	int armNum = NULL;
		

		while (!partAdded)
		{
			partNumber = -1;
			while (partNumber == -1)
			{
				std::cout << "Enter the part number of the desired arm, 0 to skip:";
				cin >> value;
				partNumber = checkInt(value);
			}

			if (partNumber == 0)
				partAdded = true;

			else
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

		
	

	partAdded = false;
	//choosing the locomotor

	view.viewLocomotors(locomotors);


		while (!partAdded)
		{
			partNumber =-1;
			while (partNumber == -1)
			{
				cout << "Enter the part number of the desired locomotor, 0 to skip:";
				cin >> value;
				partNumber = checkInt(value);
			}
			if (partNumber == 0)
				partAdded = true;
			else
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


	partAdded = false;
	//choosing the Torso
	view.viewTorsos(torsos);

	while (!partAdded)
	{
		partNumber = -1;
		while (partNumber ==-1 )
		{
			cout << "Enter the part number of the desired torso, 0 to skip:";
			cin >> value;
			partNumber = checkInt(value);
		}

		if (partNumber == 0)
			partAdded = true;
		else
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

	partAdded = false;
	//choosing the battery, if torso was skipped also skip battery
	if (tors)
	{
		view.viewBatteries(batteries);

		while (!partAdded)
		{
			partNumber = -1;
			while (partNumber == -1)
			{
				cout << "Enter the part number of the desired Battery, 0 to skip:";
				cin >> value;
				partNumber = checkInt(value);
			}

			if (partNumber == 0)
				partAdded = true;
			else
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
	printf("Total Part Cost:$%3.2f\n", newModel.getPartsCost());
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
        
        
        save();
}

void Shop::createOrder()
{	
	int num = orders.size() + 1;
	string value;
	int more = 1;
	bool empty = true;
	int cust=-1;
	int assoc=-1;
	int modelNum = -1;


	Order od(num);

	//sets the customer
	view.viewCustomers(customers);	
	while (cust == -1)
	{
		cout << "Enter the number of the customer, or enter 0 to create a new Customer: ";
		cin >> value;
		cust = checkInt(value);
	}

	if (cust == 0) 
	{
		createCustomer();
		cust = customers.back().getCustomerNumber();
	}
	od.choose_customer(cust);
	customers[cust - 1].add_order(od);

	//sets the associates
	view.viewAssociates(associates);
	while (assoc == -1)
	{
		cout << "Enter the number of the Associate, or enter 0 to create a new associate: ";
		cin >> value;
		assoc = checkInt(value);
	}

	if (assoc == 0)
	{
		createAssociate();
		assoc = associates.back().getEmployeeNumber();
	}
	od.choose_salesAssoc(assoc);
	associates[assoc - 1].add_order(od);

	//sets the models

	view.viewModels(models);

	while (more==1||empty)
	{
		while (modelNum == -1)
		{
			cout << "Enter the number of the desired Robot model:";
			cin >> value;
			modelNum = checkInt(value);
		}

		try
		{
			RobotModel mod = searchModels(modelNum);
			empty = false;
			od.choose_RobotModel(mod);
			cout << "To add a model to the order, enter 1, to finish the order, enter 0:";
			cin >> value;
			more = checkInt(value);
			modelNum = -1;
			
			
		}
		catch (partNotFound& e)
		{
			cout << "The model number was not found\n";
			modelNum = -1;
		}

	}

	od.calculateShipping();
	od.calculateTax();

	printf("Total Price (includeing tax and shipping): $%3.2f\n", od.totalPrice());

	orders.push_back(od);
	
	save();

}

void Shop::createCustomer() {

	string name;
	int num;
	num = customers.size()+1;

	printf("Enter Customer name: ");
	getline(cin, name, ':');
	Customer cust(name, num);
	customers.push_back(cust);
        
        save();
	
}

void Shop::createAssociate() {

	string name;
	int num;
	num = associates.size() + 1;

	printf("Enter Associate name: ");
	getline(cin, name, ':');
	SalesAssociate assoc(name, num);
	associates.push_back(assoc);
        
        save();

}


void Shop::save() {
    
    XMLElement * pElement;
    
     // Populate XMLDocument
    XMLDocument xmlDoc;
    
    // Create Root node
    XMLNode * pRoot = xmlDoc.NewElement("Root");
    xmlDoc.InsertFirstChild(pRoot);
    
    // Store Head
    pElement = xmlDoc.NewElement("headList");
    for (int i = 0; i < heads.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("head");
        pListElement->SetAttribute("name", stringToChar(heads[i].getName()));
        pListElement->SetAttribute("partNumber", heads[i].getPartNumber());
        pListElement->SetAttribute("weight", heads[i].getWeight());
        pListElement->SetAttribute("cost", heads[i].getCost());
        pListElement->SetAttribute("description", stringToChar(heads[i].getDescription()));
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store locomotors
    pElement = xmlDoc.NewElement("locomotorsList");
    for (int i = 0; i < locomotors.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("locomotors");
        pListElement->SetAttribute("name", stringToChar(locomotors[i].getName()));
        pListElement->SetAttribute("partNumber", locomotors[i].getPartNumber());
        pListElement->SetAttribute("weight", locomotors[i].getWeight());
        pListElement->SetAttribute("cost", locomotors[i].getCost());
        pListElement->SetAttribute("description", stringToChar(locomotors[i].getDescription()));
        pListElement->SetAttribute("powerConsumed", locomotors[i].powerConsumed());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store Arms
    pElement = xmlDoc.NewElement("armsList");
    for (int i = 0; i < arms.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("arms");
        pListElement->SetAttribute("name", stringToChar(arms[i].getName()));
        pListElement->SetAttribute("partNumber", arms[i].getPartNumber());
        pListElement->SetAttribute("weight", arms[i].getWeight());
        pListElement->SetAttribute("cost", arms[i].getCost());
        pListElement->SetAttribute("description", stringToChar(arms[i].getDescription()));
        pListElement->SetAttribute("powerConsumed", arms[i].powerConsumed());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store batteries
    pElement = xmlDoc.NewElement("batteriesList");
    for (int i = 0; i < batteries.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("batteries");
        pListElement->SetAttribute("name", stringToChar(batteries[i].getName()));
        pListElement->SetAttribute("partNumber", batteries[i].getPartNumber());
        pListElement->SetAttribute("weight", batteries[i].getWeight());
        pListElement->SetAttribute("cost", batteries[i].getCost());
        pListElement->SetAttribute("description", stringToChar(batteries[i].getDescription()));
        pListElement->SetAttribute("energy", batteries[i].getEnergy());
        pListElement->SetAttribute("maxPower", batteries[i].getMaxPower());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store Torso
    pElement = xmlDoc.NewElement("torsosList");
    for (int i = 0; i < torsos.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("torsos");
        pListElement->SetAttribute("name", stringToChar(torsos[i].getName()));
        pListElement->SetAttribute("partNumber", torsos[i].getPartNumber());
        pListElement->SetAttribute("weight", torsos[i].getWeight());
        pListElement->SetAttribute("cost", torsos[i].getCost());
        pListElement->SetAttribute("description", stringToChar(torsos[i].getDescription()));
        pListElement->SetAttribute("maxBatteries", torsos[i].max_batteries());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store models
    pElement = xmlDoc.NewElement("modelsList");
    for (int i = 0; i < models.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("models");
        pListElement->SetAttribute("name", stringToChar(models[i].getName()));
        pListElement->SetAttribute("modelNumber", models[i].getModelNumber());
        pListElement->SetAttribute("weight", models[i].getWeight());
        pListElement->SetAttribute("partsCost", models[i].getPartsCost());
        pListElement->SetAttribute("price", models[i].getPrice());
        pListElement->SetAttribute("description", stringToChar(models[i].getDescription()));
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    //<!!!!!!!!!!!!!!!!!!!!!! Add Vector
    // Store customers
    pElement = xmlDoc.NewElement("customersList");
    for (int i = 0; i < customers.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("customers");
        pListElement->SetAttribute("name", stringToChar(customers[i].getName()));
        pListElement->SetAttribute("customerNumber", customers[i].getCustomerNumber());
        pListElement->SetAttribute("wallet", customers[i].getWallet());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    //<!!!!!!!!!!!!!!!!!!!!!! Add Vector
    // Store associates
    pElement = xmlDoc.NewElement("associatesList");
    for (int i = 0; i < associates.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("associates");
        pListElement->SetAttribute("name", stringToChar(associates[i].getName()));
        pListElement->SetAttribute("employeeNumber", associates[i].getEmployeeNumber());
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // !!!!!!!!!!!!!
    // Add orders once get methods have been created
    
    
    // Save Data
    // !!!!!!!!!!!!!!!!!!check for errors
    xmlDoc.SaveFile("SavedData.xml");
//    XMLCheckResult(eResult);
}

void Shop::load() {
    
    
    
}


char* Shop::stringToChar(string str) {
    char charArr[10000] = "";
    strcpy(charArr, str.c_str());
}
