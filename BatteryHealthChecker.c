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
  int Validity = CheckAttributeRange(temperature,0,45) & CheckAttributeRange(soc,20,80) & CheckAttributeRange(chargeRate,0,0.8);
  
   return Validity;
  
}



int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold)
{
  if(attribute<lowerthreshold || attribute>higherthreshold)
    return 0;
  else 
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
