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
	cout << "Models:" << endl;
	int length = list.size();
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << list[i].getName() << "\nPrice:$" << list[i].getPrice() << "\nDescription:" << list[i].getDescription() 
		<<"\nModel Number: "<< list[i].getModelNumber() <<"\n"<< endl;
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
