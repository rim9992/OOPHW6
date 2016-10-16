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

	   Order(int number, string stat)
		   : OrderNumber(number), Status(stat) {};

	   Order(int number) : OrderNumber(number) { Status = "Shipping"; };

    void choose_customer(int cust);
    void choose_salesAssoc(int salesAssoc);
	void choose_RobotModel(RobotModel robo);
    void get_date();
	int get_num();

    void calculateShipping();
    void calculateTax();
	double totalPrice();


   private:
    string date;
    int customers;
    int salesassocs;
	double weight = 0;
    vector<int> robotmodels;
    string Status;
    int OrderNumber;

	double Robot_Price = 0;;
	double shipping = 0;
	double subtotal=0;
    double tax=0;
    double total = 0;

 };


 #endif
