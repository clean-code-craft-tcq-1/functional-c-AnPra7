#include <stdio.h>
#include <assert.h>

#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F

int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold);


int batteryIsOk(float temperature, float soc, float chargeRate) {

  int Validity = CheckAttributeDualRange(temperature,MINTEMP,MAXTEMP) & CheckAttributeDualRange(soc,MINSOC,MAXSOC) & CheckifHigherthanRange(chargeRate,CHARGERATETHRESHOLD);
  
  return Validity;
  
}



int CheckAttributeDualRange(float attribute, float lowerthreshold, float higherthreshold)
{
  int AttributeRangevalidator = attribute < lowerthreshold || attribute > higherthreshold;
  if(AttributeRangevalidator)
    return 0;
  else 
    return 1;
}

int CheckifHigherthanRange(float attribute, float threshold)
{
  int IsRangeValid = attribute > threshold;
  if(IsRangeValid)
    return 0;
  else 
    return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
