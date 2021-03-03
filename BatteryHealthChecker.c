#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) {
  /*if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }*/
  if( TemperatureRange(temperature) || StateofCharge(soc) || chargeRatevalidity(chargeRate) )
    printf(" Faulty Battery System");
    return 0;
  else
    return 1;
}

int TemperatureRange(float temperature)
{
  if(temperature>45)
    return 0;
}

int StateofCharge(float soc)
{
  if(soc<20 || soc> 80)
    return 0;
}

int chargeRatevalidity(float chargeRate)
{
  if(chargeRate > 0.8)
    return 0;
  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
