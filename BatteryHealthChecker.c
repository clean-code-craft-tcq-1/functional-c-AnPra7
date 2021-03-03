#include <stdio.h>
#include <assert.h>

#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F




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
  int Validity = CheckAttributeRange(temperature,MINTEMP,MAXTEMP) & CheckAttributeRange(soc,MINSOC,MAXSOC) & CheckAttributeRange(chargeRate,0.0,CHARGERATETHRESHOLD);
  
   return Validity;
  
}



int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold)
{
  if(attribute < lowerthreshold || attribute > higherthreshold)
    return 0;
  else 
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
