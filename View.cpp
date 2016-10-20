#include "View.h"


void View::viewHeads(vector<Head> list)
{
	int length = list.size();

	cout << "Heads\n_____\n\n";
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName()
			<< "\nPart Number: " << setfill('0') << setw(5) << list[i].getPartNumber()
			<< "\nCost:$" << list[i].getCost()
			<< "\nWeight:"  << list[i].getWeight()
			<< "\nDescription:" << list[i].getDescription() << "\n" << endl;

	}
}

void View::viewArms(vector<Arm> list)
{
	cout << "Arms\n_____\n\n";
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName()
			<< "\nPart Number: " << setfill('0') << setw(5) << list[i].getPartNumber()
			<< "\nCost:$" << list[i].getCost()
			<< "\nWeight: " << list[i].getWeight()
			<< "\nDescription:" << list[i].getDescription() 
			<<"\nSpeed: " <<list[i].powerConsumed()
			<< "\n" << endl;
	}
}
void View::viewLocomotors(vector<Locomotor> list)
{
	cout << "Locomotors\n_____\n\n";
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName()
			<< "\nPart Number: " << setfill('0') << setw(5) << list[i].getPartNumber()
			<< "\nCost:$" << list[i].getCost()
			<< "\nWeight:" << list[i].getWeight()
			<< "\nDescription:" << list[i].getDescription() 
			<<"\nMax Speed: " << list[i].powerConsumed()
			<< "\n" << endl;
	}
}
void View::viewTorsos(vector<Torso> list)
{

	cout << "Torsos\n______\n\n";
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName()
			<< "\nPart Number: " << setfill('0') << setw(5) << list[i].getPartNumber()
			<< "\nCost:$" << list[i].getCost()
			<< "\nWeight"  << list[i].getWeight()
			<< "\nDescription:" << list[i].getDescription() 
			<<"\nMax Batteries: "<<list[i].max_batteries()
			<< "\n" << endl;

	}
}
void View::viewBatteries(vector<Battery> list)
{
	cout << "Batteries\n________\n\n";
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name :" << list[i].getName()
			<< "\nPart Number: " << setfill('0') << setw(5) << list[i].getPartNumber()
			<< "\nCost: " << list[i].getCost()
			<< "\nWeight:" << list[i].getWeight()
			<< "\nDescription:" << list[i].getDescription() 
			<< "\nEnergy: "<< list[i].getEnergy()
			<<"\nMax Power: "<<list[i].getMaxPower()
			<< "\n" << endl;
	}
}

void View::viewModels(vector<RobotModel> list)
{
	cout << "Models:" << endl;
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << list[i].getName() 
			 << "\nPrice:$" << list[i].getPrice() 
			 << "\nDescription:" << list[i].getDescription() 
		     <<"\nModel Number: "<< list[i].getModelNumber() 
			 <<"\n"<< endl;
	}
}

void View::viewCustomers(vector<Customer> list)
{

	int i;
	int length = list.size();
	cout << "Customers:" << endl;
	for (i = 0; i < length; i++)
	{

		cout << list[i].cust_to_string();
	}
	cout << endl;
}

void View::viewAssociates(vector<SalesAssociate> list)
{
	int length = list.size();

	cout << "Sales Associates:" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << list[i].assoc_to_string();
	}
	cout << endl;
}

void View::viewOrders(vector<Order> list)
{
	
	int length = list.size();
	cout << "Orders:" << endl;
	for (int i = 0; i < length; i++)
	{
		
		list[i].printOrder();
	}
	cout << endl;
}

void View::viewCustomerOrders(Customer cust, vector<Order> list)
{
	int length = cust.orders.size();
	cout << "Customer " <<cust.cust_to_string() <<" Orders:" << endl;
	for (int i = 0; i < length; i++)
	{

		int order = cust.orders[i];
		for (int j = 0; j < list.size(); j++)
		{
			if (list[j].get_num() == order)
				list[j].printOrder();
		}
	}
	cout << endl;

}

void View::viewAssociateOrders(SalesAssociate assoc, vector<Order> list)
{
	int length = assoc.orders.size();

	cout << "Associate " << assoc.assoc_to_string() << " Orders:" << endl;
	for (int i = 0; i < length; i++)
	{

		int order = assoc.orders[i];
		for (int j = 0; j < list.size(); j++)
		{
			if (list[j].get_num() == order)
				list[j].printOrder();
		}
	}
	cout << endl;

}


void View::printMenu()
{
	cout << "Main Menu\n_______\n"
		 <<"Create(1)\n"
		 <<"Report(2)\n"
		 <<"Quit(0)\n"
		 << endl;
}

void View::printCreateMenu()
{
	cout << "Create\n________\n"
		<< "Order(1)\n"
		<< "Customer(2)\n"
		<< "Sales Associate(3)\n"
		<< "Robot Model(4)\n"
		<< "Robot Part(5)\n"
		<< "Quit to main menu(0)\n"
		<< endl;

}

void View::printReportMenu()
{
	cout <<"Report\n________\n"
		<< "Orders(1)\n"
		<< "Customers(2)\n"
		<< "Sales Associates(3)\n"
		<< "Robot Models(4)\n"
		<< "Quit to main menu(0)\n"
		<< endl;

}
