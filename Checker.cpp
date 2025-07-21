#include <assert.h>
#include <iostream>
using namespace std;

// Pure functions - no I/O
bool TemperatureIsOk(float temperature) 
{
  return (temperature >= 0 && temperature <= 45);
}

bool SocIsOk(float soc) 
{
  return (soc >= 20 && soc <= 80);
}

bool ChargeRateIsOk(float chargeRate) 
{
    return (chargeRate <= 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) 
{
  return TemperatureIsOk(temperature) && SocIsOk(soc) && ChargeRateIsOk(chargeRate);
}

// Output function

bool batteryout(float temperature, float soc, float chargeRate) 
{
  bool isOk = true;//default value

  if (!TemperatureIsOk(temperature)) 
  {
    cout << "Temperature out of range!\n";
    isOk = false;
  }
  if (!SocIsOk(soc)) 
  {
    cout << "State of Charge out of range!\n";
    isOk = false;
  }
  if (!ChargeRateIsOk(chargeRate)) 
  {
    cout << "Charge Rate out of range!\n";
    isOk = false;
  }

  return isOk;
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);

 
  batteryout(25, 70, 0.7); 
  batteryout(50, 85, 0);
}
