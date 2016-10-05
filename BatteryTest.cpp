#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Battery.h"

int main()
{
    
     Battery battery(25, 10);

     cout << "Energy in Kilo Watt Hr: " << battery.getEnergy() << endl;
     cout << "Max power consumed" << battery.getMaxPower() << endl;
     
     cin.get();


return 0;
}
