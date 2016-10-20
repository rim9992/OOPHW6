#include "Shop.h"


void Shop::cli()
{
	int choice = -1;
	string value;

	while (choice != 0)
	{
		view.printMenu();


		while (choice == -1)
		{

			cin >> value;
			choice = checkInt(value);
			if ((choice > 2 || choice < 0)&&choice!=-1)
			{
				cout << "The number you have enter is not one of the options\nTry Again:";
				choice = -1;
			}
		}

		if (choice == 1)
		{
			
			while (choice != 0)
			{

				view.printCreateMenu();
				choice = -1;
				while (choice == -1)
				{

					cin >> value;
					choice = checkInt(value);
					if ((choice > 5 || choice < 0) && choice != -1)
					{
						cout << "The number you have enter is not one of the options\nTry Again:";
						choice = -1;
					}
				}

				if (choice == 1)
					createOrder();
				else if (choice == 2)
					createCustomer();
				else if (choice == 3)
					createAssociate();
				else if (choice == 4)
					createNewModel();
				else if (choice == 5)
					createNewPart();

			}
			choice = -1;

		}
		else if (choice == 2)
		{
			while (choice != 0)
			{

				view.printReportMenu();
				choice = -1;
				while (choice == -1)
				{

					cin >> value;
					choice = checkInt(value);
					if ((choice > 4 || choice < 0) && choice != -1)
					{
						cout << "The number you have enter is not one of the options\nTry Again:";
						choice = -1;
					}
				}
				if (choice == 1)
				{
					cout << "Orders by Associate (1)"
						<< "\nOrders by Customer(2)"
						<< "\nAll(3)" << endl;

					choice = -1;
					while (choice == -1)
					{

						cin >> value;
						choice = checkInt(value);
						if ((choice > 3 || choice < 1) && choice != -1)
						{
							cout << "The number you have enter is not one of the options\nTry Again:";
							choice = -1;
						}
					}
					if (choice == 1)
					{
						view.viewAssociates(associates);
						cout << "Associate Number:";
						cin >> choice;
						try 
						{
							SalesAssociate sa = searchAssociates(choice);
							view.viewAssociateOrders(sa, orders);

						}
						catch (partNotFound& e)
						{
							cout << "The Associate Number was not found\n" << endl;
						}
						
						
					}
					else if (choice == 2)
					{
						view.viewCustomers(customers);
						cout << "Customer Number:";
						cin >> choice;
						try 
						{
							Customer cust = searchCustomers(choice);
							view.viewCustomerOrders(cust, orders);

						}
						catch (partNotFound& e)
						{
							cout << "The Customer Number was not found\n" << endl;
						}
						

					}
					else
					{
						view.viewOrders(orders);
					}
					 
				}
					
				else if (choice == 2)
					view.viewCustomers(customers);
				else if (choice == 3)
					view.viewAssociates(associates);
				else if (choice == 4)
					view.viewModels(models);
			}
			choice = -1;
			
		}
		

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

Customer Shop::searchCustomers(int num) 
{

	int length = customers.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (customers[i].getCustomerNumber() == num)
			return customers[i];
	}

	throw partNotFound();
}

SalesAssociate Shop::searchAssociates(int num)
{
	int length = associates.size();
	int i;
	for (i = 0; i < length; i++)
	{
		if (associates[i].getEmployeeNumber() == num)
			return associates[i];
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
	int partNumber=-1;
	ComponentType componentType;
	int type = -1;
	double weight=-1;
	double cost=-1;
	string description;
	cout << "Creating a New Part\n___________________\nEnter the Name: ";

	cin.ignore();
	getline(cin, name);
	
	//Gets and validates input from the user to create a new Robot part
	
	while(partNumber==-1)
	{
		cout << "Part Number: ";
		cin >> value;
		partNumber = checkInt(value);		
	 }


	while (weight == -1)
	{
		cout << "Weight: ";
		cin >> value;
		weight = checkDub(value);

	}


	while (cost == -1)
	{
		cout << "Cost: ";
		cin >> value;
		cost = checkDub(value);


	}

	//determines the type of part and gets more input accordingly

	cout << "Description: ";
	cin.ignore();
	getline(cin, description);

	cout << "Head(1)\nArm(2)\nLocomotor(3)\nTorso(4)\nBattery(5)\nComponent Type: ";


	while (type == -1)
	{
		cin >> value;
		type = checkInt(value);
		
		if (type > 5 || type < 1)
		{
			cout << "Integer must be between 1 and 5\n";
			type = -1;
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
		int speed =-1;
		while (speed ==-1)
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
		
		int speed =-1;
		while (speed == -1)
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
		int battery = -1;
		while (battery == -1)
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
		double energy = -1;
		while (energy ==-1)
		{
			cout << "Energy: ";
			cin >> value;
			energy = checkDub(value);
			
		}

		double power = -1;
		while (power == -1)
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

	double price = -1;
	int partNumber = -1;
	int num = -1;
	cout << "Enter Name:";
	cin.ignore();
	getline(cin, name);

	while (num == -1)
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
	int armNum = -1;
		

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
	while (price == -1)
	{
		cout << "Enter Model Price:";
		cin >> value;
		price = checkDub(value);
	}
	newModel.updatePrice(price);

	cout << "Enter Description:";
	cin.ignore();
	getline(cin, value);
	newModel.setDescription(value);

	models.push_back(newModel);
        
        
        save();
}

void Shop::createOrder()
{	
	if (models.size() == 0)
	{
		cout << "There are no Robot Models. Create a robot Model to create an Order.\n";
			return;
	}
	
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
	
	od.set_date();

	orders.push_back(od);
	
	save();

}

void Shop::createCustomer() {

	string name;
	int num;
	num = customers.size()+1;

	printf("Enter Customer name: ");
	cin.ignore();
	getline(cin, name);
	Customer cust(name, num);
	customers.push_back(cust);
        
        save();
	
}

void Shop::createAssociate() {

	string name;
	int num;
	num = associates.size() + 1;

	printf("Enter Associate name: ");
	cin.ignore();
	getline(cin, name);
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
        pListElement->SetAttribute("torso", models[i].getTorso());
        pListElement->SetAttribute("head", models[i].getHead());
        pListElement->SetAttribute("locomotor", models[i].getLocomotor());
        pListElement->SetAttribute("battery", models[i].getBattery());
        pListElement->SetAttribute("maxBatteries", models[i].getMaxBatteries());
        pListElement->SetAttribute("numOfArms", models[i].getnumOfArms());
        
        //get the vector of int
        for (int j = 0; j < models[i].arms.size(); j++) {
            XMLElement * pListElementVec = xmlDoc.NewElement("arms");
            pListElementVec->SetText(models[i].arms[j]);
            
            pListElement->InsertEndChild(pListElementVec);
        }
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store customers
    pElement = xmlDoc.NewElement("customersList");
    for (int i = 0; i < customers.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("customers");
        pListElement->SetAttribute("name", stringToChar(customers[i].getName()));
        pListElement->SetAttribute("customerNumber", customers[i].getCustomerNumber());
        pListElement->SetAttribute("wallet", customers[i].getWallet());
        //get the vector of int
        for (int j = 0; j < customers[i].orders.size(); j++) {
            XMLElement * pListElementVec = xmlDoc.NewElement("orders");
            pListElementVec->SetText(customers[i].orders[j]);
            
            pListElement->InsertEndChild(pListElementVec);
        }
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store associates
    pElement = xmlDoc.NewElement("associatesList");
    for (int i = 0; i < associates.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("associates");
        pListElement->SetAttribute("name", stringToChar(associates[i].getName()));
        pListElement->SetAttribute("employeeNumber", associates[i].getEmployeeNumber());
        //get the vector of int
        for (int j = 0; j < associates[i].orders.size(); j++) {
            XMLElement * pListElementVec = xmlDoc.NewElement("orders");
            pListElementVec->SetText(associates[i].orders[j]);
            
            pListElement->InsertEndChild(pListElementVec);
        }
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Store orders
    pElement = xmlDoc.NewElement("ordersList");
    for (int i = 0; i < orders.size(); i++) {
        XMLElement * pListElement = xmlDoc.NewElement("orders");
        pListElement->SetAttribute("salesassocs", orders[i].getAssociate());
        pListElement->SetAttribute("customers", orders[i].getCustomer());
        pListElement->SetAttribute("date", stringToChar(orders[i].getDate()));
        pListElement->SetAttribute("shipping", orders[i].getShipping());
        pListElement->SetAttribute("subtotal", orders[i].getSubtotal());
        pListElement->SetAttribute("tax", orders[i].getTax());
        pListElement->SetAttribute("weight", orders[i].getWeight());
        pListElement->SetAttribute("OrderNumber", orders[i].get_num());
        pListElement->SetAttribute("total", orders[i].totalPrice());
        
        //get the vector of int
        for (int j = 0; j < orders[i].robotmodels.size(); j++) {
            XMLElement * pListElementVec = xmlDoc.NewElement("robotmodels");
            pListElementVec->SetText(orders[i].robotmodels[j]);
            
            pListElement->InsertEndChild(pListElementVec);
        }
        
        pElement->InsertEndChild(pListElement);
    }
    pRoot->InsertEndChild(pElement);
    
    
    // Save Data
    XMLError eResult = xmlDoc.SaveFile("SavedData.xml");
    XMLCheckResult(eResult);
}

// Load the XML "SavedData.xml" file
void Shop::load() {
    
    string name, description;
    int partNumber, weight, cost, speed, battery;
    const char * attributeText = nullptr;
    double energy, power, wallet;
    
    XMLDocument xmlDoc;
    
    XMLError eResult = xmlDoc.LoadFile("SavedData.xml");
    XMLCheckResult(eResult);
    
    XMLNode * pRoot = xmlDoc.FirstChild();
    if (pRoot == nullptr) cerr<<"Error loading root in XML file";
    
    
    
    // Load Head
    XMLElement * pElement = pRoot->FirstChildElement("headList");
    if (pElement == nullptr) cerr<<"ERROR parsing head in XML file"<<endl;
    
    XMLElement * pListElement = pElement->FirstChildElement("head");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading head text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("partNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("weight", &weight);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("cost", &cost);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading head text from XML file";
        description = attributeText;

        Head head(name, partNumber, ComponentType::head, weight, cost, description);
        heads.push_back(head);
        
        pListElement = pListElement->NextSiblingElement("head");
    }
    
    
    
    // Load locomotors
    pElement = pRoot->FirstChildElement("locomotorsList");
    if (pElement == nullptr) cerr<<"ERROR parsing head in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("locomotors");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading locomotors text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("partNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("weight", &weight);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("cost", &cost);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading locomotors text from XML file";
        description = attributeText;
        eResult = pListElement->QueryIntAttribute("powerConsumed", &speed);
        XMLCheckResult(eResult);

        Locomotor loco(name, partNumber, ComponentType::locomotor, weight, cost, description, speed);
	locomotors.push_back(loco);
        
        pListElement = pListElement->NextSiblingElement("locomotors");
    }
    
    
    
    // Load arms
    pElement = pRoot->FirstChildElement("armsList");
    if (pElement == nullptr) cerr<<"ERROR parsing head in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("arms");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading arms text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("partNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("weight", &weight);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("cost", &cost);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading arms text from XML file";
        description = attributeText;
        eResult = pListElement->QueryIntAttribute("powerConsumed", &speed);
        XMLCheckResult(eResult);

        Arm arm(name, partNumber, ComponentType::arm, weight, cost, description, speed);
	arms.push_back(arm);
        
        pListElement = pListElement->NextSiblingElement("arms");
    }
    
    
    
    // Load batteries
    pElement = pRoot->FirstChildElement("batteriesList");
    if (pElement == nullptr) cerr<<"ERROR parsing head in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("batteries");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading batteries text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("partNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("weight", &weight);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("cost", &cost);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading batteries text from XML file";
        description = attributeText;
        eResult = pListElement->QueryDoubleAttribute("energy", &energy);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("maxPower", &power);
        XMLCheckResult(eResult);

        Battery batt(name, partNumber, ComponentType::battery, weight, cost, description, energy, power);
	batteries.push_back(batt);
        
        pListElement = pListElement->NextSiblingElement("batteries");
    }
    
    
    // Load torsos
    pElement = pRoot->FirstChildElement("torsosList");
    if (pElement == nullptr) cerr<<"ERROR parsing head in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("torsos");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading torsos text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("partNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("weight", &weight);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("cost", &cost);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading torsos text from XML file";
        description = attributeText;
        eResult = pListElement->QueryIntAttribute("maxBatteries", &battery);
        XMLCheckResult(eResult);

        Torso torso(name, partNumber, ComponentType::torso, weight, cost, description, battery);
        torsos.push_back(torso);
        
        pListElement = pListElement->NextSiblingElement("torsos");
    }
    
    
    
    // Load models
    pElement = pRoot->FirstChildElement("modelsList");
    if (pElement == nullptr) cerr<<"ERROR parsing customers in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("models");
    
    while (pListElement != nullptr) {
        int torso, head, locomotor, battery, modelNumber, maxBatteries, numOfArms;
        double price, partsCost, totalWeight;
        
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading models text from XML file";
        name = attributeText;
        attributeText = pListElement->Attribute("description");
        if (attributeText == nullptr) cerr<<"Error loading models text from XML file";
        description = attributeText;
        eResult = pListElement->QueryIntAttribute("torso", &torso);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("head", &head);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("locomotor", &locomotor);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("battery", &battery);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("modelNumber", &modelNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("maxBatteries", &maxBatteries);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("numOfArms", &numOfArms);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("price", &price);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("partsCost", &partsCost);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("weight", &totalWeight);
        XMLCheckResult(eResult);
        
        // Recycling partNumber 
        RobotModel model(name, modelNumber);
        model.restoreValues(torso, head, locomotor, battery, name, description, modelNumber, price, maxBatteries, numOfArms, partsCost, totalWeight);
        
        // Import vector of ints
        XMLElement * pListElementVec = pListElement->FirstChildElement("arms");
        while (pListElementVec != nullptr) {
            int temp;
            eResult = pListElementVec->QueryIntText(&temp);
            XMLCheckResult(eResult);
            model.arms.push_back(temp);
            
            pListElementVec = pListElementVec->NextSiblingElement("arms");
        }
        
        models.push_back(model);
        
        pListElement = pListElement->NextSiblingElement("customers");
    }
    
    
    
    
    // Load customers
    pElement = pRoot->FirstChildElement("customersList");
    if (pElement == nullptr) cerr<<"ERROR parsing customers in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("customers");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading customers text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("customerNumber", &partNumber);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("wallet", &wallet);
        XMLCheckResult(eResult);
        
        // Recycling partNumber 
        Customer customer(name, partNumber);
        customer.setWallet(wallet);
        
        // Import vector of ints
        XMLElement * pListElementVec = pListElement->FirstChildElement("orders");
        while (pListElementVec != nullptr) {
            int temp;
            eResult = pListElementVec->QueryIntText(&temp);
            XMLCheckResult(eResult);
            customer.orders.push_back(temp);
            
            pListElementVec = pListElementVec->NextSiblingElement("orders");
        }
        
        customers.push_back(customer);
        
        pListElement = pListElement->NextSiblingElement("customers");
    }
    
    
    
    // Load associates
    pElement = pRoot->FirstChildElement("associatesList");
    if (pElement == nullptr) cerr<<"ERROR parsing associates in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("associates");
    
    while (pListElement != nullptr) {
        attributeText = pListElement->Attribute("name");
        if (attributeText == nullptr) cerr<<"Error loading associates text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("employeeNumber", &partNumber);
        XMLCheckResult(eResult);
        
        // Recycling partNumber 
        SalesAssociate associate(name, partNumber);
        
        // Import vector of ints
        XMLElement * pListElementVec = pListElement->FirstChildElement("orders");
        while (pListElementVec != nullptr) {
            int temp;
            eResult = pListElementVec->QueryIntText(&temp);
            XMLCheckResult(eResult);
            associate.orders.push_back(temp);
            
            pListElementVec = pListElementVec->NextSiblingElement("orders");
        }
        
        associates.push_back(associate);
        
        pListElement = pListElement->NextSiblingElement("customers");
    }
    
    
    // Load orders
    pElement = pRoot->FirstChildElement("ordersList");
    if (pElement == nullptr) cerr<<"ERROR parsing orders in XML file"<<endl;
    
    pListElement = pElement->FirstChildElement("orders");
    
    int customer, salesAsso, orderNum;
    double weight1, shipping, subtotal, tax, total;
    
    while (pListElement != nullptr) {
        eResult = pListElement->QueryIntAttribute("salesassocs", &salesAsso);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryIntAttribute("customers", &customer);
        XMLCheckResult(eResult);
        attributeText = pListElement->Attribute("date");
        if (attributeText == nullptr) cerr<<"Error loading orders text from XML file";
        name = attributeText;
        eResult = pListElement->QueryIntAttribute("OrderNumber", &orderNum);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("shipping", &shipping);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("subtotal", &subtotal);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("tax", &tax);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("weight", &weight1);
        XMLCheckResult(eResult);
        eResult = pListElement->QueryDoubleAttribute("total", &total);
        XMLCheckResult(eResult);
        
        // Recycling partNumber 
        Order order(orderNum);
        order.restoreOrder(name, customer, salesAsso, weight1, shipping, subtotal, tax, total);
        
        // Import vector of ints
        XMLElement * pListElementVec = pListElement->FirstChildElement("robotmodels");
        while (pListElementVec != nullptr) {
            int temp;
            eResult = pListElementVec->QueryIntText(&temp);
            XMLCheckResult(eResult);
            order.robotmodels.push_back(temp);
        }
        
        orders.push_back(order);
        
        pListElement = pListElement->NextSiblingElement("customers");
    }
    
    
}


char* Shop::stringToChar(string str) {
    char charArr[10000] = "";
    strcpy(charArr, str.c_str());
}

void Shop::XMLCheckResult(XMLError a_eResult) {
    if (a_eResult != XML_SUCCESS) {
        cerr<<"Error: "<< a_eResult;
    }
}
