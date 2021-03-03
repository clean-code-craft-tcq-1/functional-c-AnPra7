#include "BatteryHealthChecker.h"

/*=============================================================================
=======                                MACROS                           =======
=============================================================================*/
#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F

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

void FaultyMessage(int TemperatureStatus, int SOCStatus, int ChargeRateStatus)
{
  if(TemperatureStatus==0)
   printf("Temperature our of range");
  if(SOCStatus==0)
   printf("SOCStatus our of range");
  if(ChargeRateStatus==0)
   printf("ChargeRateStatus our of range");
  
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  int TemperatureLowerRange,TemperatureHigherRange,TemperatureStatus,SOCLowerRange,SOCHigherRange,SOCStatus,ChargeRateStatus,Validity;

  TemperatureLowerRange  = LowerThresholdChecker(temperature,MINTEMP);
  TemperatureHigherRange = UpperThresholdChecker(temperature,MAXTEMP) ;
  TemperatureStatus      = TemperatureLowerRange&TemperatureHigherRange;
  SOCLowerRange          = LowerThresholdChecker(soc,MINSOC) ;
  SOCHigherRange         = UpperThresholdChecker(soc,MAXSOC); 
  SOCStatus              = SOCLowerRange&SOCHigherRange
  ChargeRateStatus       = UpperThresholdChecker(chargeRate,CHARGERATETHRESHOLD);

  ValidityofBattery = (TemperatureStatus)&(SOCStatus)&ChargeRateRange;
  FaultyMessage(TemperatureStatus,SOCStatus,ChargeRateStatus);
  
 return ValidityofBattery;
  
}







int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
