
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
        total = tax + shipping + subtotal;
		return total;
    }
   int Order::get_num()
   {
	   return OrderNumber;
   }

int Order::getCustomer()
   {
	   return customers;
   }

   int Order::getAssociate()
   {
	   return salesassocs;
   }

   double Order::getWeight()
   {
	   return weight;
   }

void Order::printOrder()
   {
	   cout << "Order Number:" << OrderNumber
		   << "\nDate of sale:" << date
		   << "\nCustomer Number: " << setfill('0') << setw(5) << customers
		   << "\nAssociate Number:" << setfill('0') << setw(5) << salesassocs
		   << "\nRobot Models Purchased:" << endl;

	   int bots = robotmodels.size();
	   for (int i = 0; i < bots; i++)
	   {
		   cout << "\t" << setfill('0') << setw(5) << robotmodels[i] << endl;
	   }
	   cout << "subtotal:$"  << subtotal
		   << "\nShipping:$" << shipping
		   << "\nTaxes:$" << tax
		   << "\nTotal:$" << total << "\n" << endl;
   }

   void Order::restoreOrder(string inDate, int inCustomers, int inSalesassoc, double inWeight, double inShipping, double inSubtotal, double inTax, double inTotal){
       
    date = inDate;
    customers = inCustomers;
    salesassocs = inSalesassoc;
    weight = inWeight;
    shipping = inShipping;
    subtotal = inSubtotal;
    tax = inTax;
    total = inTotal; 
   }

