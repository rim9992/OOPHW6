
#include "Order.h"
#include "SalesAssociate.h"
#include "Customer.h"

 using namespace std;

     void Order::get_date()
     {
           	char today[9];
            _strdate_s(today);
            date = today;
     }

    void Order::choose_customer(int cust)
    {
		customers = cust;
    }
    void Order::choose_salesAssoc(int salesAssoc)
    {
		salesassocs = salesAssoc;
    }
	void Order::choose_RobotModel(RobotModel robo)
	{
		robotmodels.push_back(robo.getModelNumber());
		subtotal += robo.getPrice();
		weight += robo.getWeight();
	}

    
	void Order::calculateShipping()
    {
        double cost_per_pound = 1.5;
		shipping = weight * cost_per_pound;
    }

    void Order::calculateTax()
    {
        double taxes = .0825;
        tax = taxes*subtotal;
    }

   double Order::totalPrice()
    {
        total = tax + shipping + Robot_Price;
		return total;
    }
   int Order::get_num()
   {
	   return OrderNumber;
   }


