#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F

int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold);
int LowerThresholdChecker(float attribute, float lowerthreshold);
int UpperThresholdChecker(float attribute, float upperthreshold);

int batteryIsOk(float temperature, float soc, float chargeRate) {
  
int TemperatureLowerRange,TemperatureHigherRange,SOCLowerRange,SOCHigherRange,ChargeRateRange,Validity;
  
TemperatureLowerRange  = LowerThresholdChecker(temperature,MINTEMP);
TemperatureHigherRange = UpperThresholdChecker(temperature,MAXTEMP) ;
SOCLowerRange          = LowerThresholdChecker(soc,MINSOC) ;
SOCHigherRange         = UpperThresholdChecker(soc,MAXSOC); 
ChargeRateRange        = UpperThresholdChecker(chargeRate,CHARGERATETHRESHOLD);
  
Validity = (TemperatureLowerRange&TemperatureHigherRange)&(SOCLowerRange&SOCHigherRange)&ChargeRateRange;
  
 return Validity;
  
}



int LowerThresholdChecker(float attribute, float lowerthreshold)
{
  bool isValid = attribute < lowerthreshold;
  if(isValid)
    return 0;
  else return 1;
}

int UpperThresholdChecker(float attribute, float upperthreshold)
{
  bool isValid = attribute > upperthreshold;
  if(isValid)
    return 0;
  else return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
