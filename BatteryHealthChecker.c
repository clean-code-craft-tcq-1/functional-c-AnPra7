#include "BatteryHealthChecker.h"

/*=============================================================================
=======                                MACROS                           =======
=============================================================================*/
#define MAXTEMP 45.0F
#define MINTEMP 0.0F
#define MAXSOC 80.0F
#define MINSOC 20.0F
#define CHARGERATETHRESHOLD 0.8F

/*********************************************************************************
 * A function that checks the lower range of the passed attribute
 * attribute can be temperature , state of charge or Charge Rate
 * Thresholds has been defined globally
 *********************************************************************************/
int LowerThresholdChecker(float attribute, float lowerthreshold)
{
  bool isValid = attribute < lowerthreshold;
  if(isValid)
    return 0;
  else return 1;
}
/*********************************************************************************
 * A function that checks the higher range of the passed attribute
 * attribute can be temperature , state of charge or Charge Rate
 * Thresholds has been defined globally
 *********************************************************************************/
int UpperThresholdChecker(float attribute, float upperthreshold)
{
  bool isValid = attribute > upperthreshold;
  if(isValid)
    return 0;
  else return 1;
}

/*********************************************************************************
 * A function that prints the temperature abnormality
 *********************************************************************************/
void FaultyMessageTemperature(int TemperatureStatus)
{
  if(TemperatureStatus)
  {
  printf("Temperature out of range");
  }
}
/*********************************************************************************
 * A function that prints the SOC abnormality
 *********************************************************************************/
void FaultyMessageSOC(int SOCStatus)
{
  if(SOCStatus)
  {
  printf("SOC out of range");
  }
}
/*********************************************************************************
 * A function that prints the Charge Rate abnormality
 *********************************************************************************/
void FaultyMessageChargeRate(int ChargeRateStatus)
{
  if(ChargeRateStatus)
  {
  printf("ChargeRate out of range");
  }
}

/*********************************************************************************
 * A function that gives the overall Status of the battery manmagement system
 *********************************************************************************/
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
