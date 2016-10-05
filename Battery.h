#ifndef _BATTERY_H_
#define _BATTERY_H_
#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Battery{

public: 
    
      Battery(double Energy, double MaxPower) : energy(Energy), maxPower(MaxPower){}
      
      double getEnergy();
      double getMaxPower();
      
private:
       
       double energy;
       double maxPower;
       
};

#endif
