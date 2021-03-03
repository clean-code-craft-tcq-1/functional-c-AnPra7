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

void FaultyMessageTemperature(int TemperatureStatus)
{
  if(TemperatureStatus)
  {
  printf("Temperature out of range");
  }
}
void FaultyMessageSOC(int SOCStatus)
{
  if(SOCStatus)
  {
  printf("SOC out of range");
  }
}
void FaultyMessageChargeRate(int ChargeRateStatus)
{
  if(ChargeRateStatus)
  {
  printf("ChargeRate out of range");
  }
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  int TemperatureLowerRange,TemperatureHigherRange,TemperatureStatus,SOCLowerRange,SOCHigherRange,SOCStatus,ChargeRateStatus,ValidityofBattery;

  TemperatureLowerRange  = LowerThresholdChecker(temperature,MINTEMP);
  TemperatureHigherRange = UpperThresholdChecker(temperature,MAXTEMP) ;
  TemperatureStatus      = TemperatureLowerRange&TemperatureHigherRange;
  FaultyMessageTemperature(TemperatureStatus);
  
  SOCLowerRange          = LowerThresholdChecker(soc,MINSOC) ;
  SOCHigherRange         = UpperThresholdChecker(soc,MAXSOC); 
  SOCStatus              = SOCLowerRange&SOCHigherRange;
  FaultyMessageSOC(SOCStatus);
  
  ChargeRateStatus       = UpperThresholdChecker(chargeRate,CHARGERATETHRESHOLD);
  FaultyMessageChargeRate(ChargeRateStatus);

  ValidityofBattery = (TemperatureStatus)&(SOCStatus)&ChargeRateStatus;
  
  if(ValidityofBattery)
    printf("Battery is fine");
  
 return ValidityofBattery;
  
}







int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
