#include <stdio.h>
#include <assert.h>

#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F

int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold);


int batteryIsOk(float temperature, float soc, float chargeRate) {

  int Validity = CheckAttributeRange(temperature,MINTEMP,MAXTEMP) & CheckAttributeRange(soc,MINSOC,MAXSOC) & CheckAttributeRange(chargeRate,0.0,CHARGERATETHRESHOLD);
  
  return Validity;
  
}



int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold)
{
  int AttributeRangevalidator = attribute < lowerthreshold || attribute > higherthreshold;
  if(AttributeRangevalidator)
    return 0;
  else 
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
