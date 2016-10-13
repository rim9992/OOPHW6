 #include <iostream>
 #include <string>
#include <iomanip>
#include <vector>
#include<time.h>

#include "RobotModel.h"
#include "Customer.h"
#include "SalesAssociate.h"
#include "Order.h"
 using namespace std;

     void Order::get_date()
     {
           	char today[9];
            _strdate(today);
            date = today;
     }

    void Order::choose_customer(Customer cust)
    {
        customers = cust.name();

    }
    void Order::choose_salesAssoc(SalesAssociate salesAssoc)
    {
        salesassocs = salesAssoc.name();
    }
    void Order::choose_RobotModel(RobotModel robo)
    {
        robotmodels = robo.name();
    }

    double Order::robotPrice(RobotModel robo)
    {
       Robot_Price = robo.price;
       return Robot_Price;
    }
    double Order::calculateShipping()
    {
        double weight = RobotModel::totalWeight;
        double cost_per_pound = 1.5;
        double Shipping = weight * cost_per_pound;

        return Shipping;


    }
    double Order::calculateTax()
    {
        double taxes = .0825;
        Tax = taxes;
        return Tax;

    }
    double Order::totalPrice()
    {
        double total_price = Tax + Shipping + Robot_Price;
        Total = total_price;
        return Total;
    }


