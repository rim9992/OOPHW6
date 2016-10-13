 #ifndef __ORDER_H
 #define __ORDER_H 2016
 #include <iostream>
 #include <string>
#include <iomanip>
#include <vector>
#include<time.h>
#include "RobotModel.h"
#include "Customer.h"
#include "SalesAssociate.h"

 using namespace std;

 class Order{
   public:
    Order(int number = 1000, string stat = "Shipping")
    : OrderNumber = number, Status = stat{};

    void choose_customer(Customer cust);
    void choose_salesAssoc(SalesAssociate salesAssoc);
    void choose_RobotModel(RobotModel robo);
    void get_date();

    double robotPrice(RobotModel robo);
    double calculateShipping();
    double calculateTax();
    double totalPrice();

   private:
    string date;
    string customers;
    string salesassocs;
    string robotmodels;
    string Status;
    int OrderNumber;

    double Robot_Price;
    double Shipping;
    double Tax;
    double Total;

 };
 #endif
