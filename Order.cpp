
#include "Order.h"
#include "SalesAssociate.h"
#include "Customer.h"
#include <ctime>

 using namespace std;

     void Order::set_date()
     {

        time_t now = time(0);
        tm * ltm = localtime(&now);
        //Format month correctly
        if (ltm->tm_mon < 10) {
            date = "0" + ltm->tm_mon;
        } else {
            date = ltm->tm_mon;
        }
        // Format day correctly
        if (ltm->tm_mday < 10) {
            date += "/0" + ltm->tm_mday;
        } else {
            date += "/" + ltm->tm_mday;
        }
        // Add year
        date += "/" + ltm->tm_year;
        
        
     }
string Order::getDate()
 	{
		 return date;
	 }

double Order::getShipping()
	 {
		 return shipping;
	 }

double Order::getSubtotal()
	 {
		 return subtotal;
	 }

double Order::getTax()
	 {
		 return tax;
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


