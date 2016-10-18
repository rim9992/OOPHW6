#ifndef _ORDER_H
#define _ORDER_H
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <time.h>

using namespace std;

#include "RobotModel.h"

class SalesAssociate;
class Customer;


 class Order{
   public:

	   Order(int number)
		   : OrderNumber(number){};

	   
    void choose_customer(int cust);
    void choose_salesAssoc(int salesAssoc);
    void choose_RobotModel(RobotModel robo);
    void set_date();
    int get_num();
	 
    double getShipping();
    double getSubtotal();
    double getTax();
    string getDate();
    int getCustomer();
    int getAssociate();
    double getWeight();

    void calculateShipping();
    void calculateTax();
    double totalPrice();

    vector<int> robotmodels;

   private:
    string date;
    int customers;
    int salesassocs;
    double weight = 0;
   
    int OrderNumber;

    double shipping = 0;
    double subtotal=0;
    double tax=0;
    double total = 0;

 };


 #endif
