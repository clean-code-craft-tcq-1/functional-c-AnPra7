#ifndef BatteryHealthChecker_h
#define BatteryHealthChecker_h

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

extern int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold);
extern int LowerThresholdChecker(float attribute, float lowerthreshold);
extern int UpperThresholdChecker(float attribute, float upperthreshold);

#endif
