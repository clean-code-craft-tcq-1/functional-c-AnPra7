/******************************************************************************/
/***    \file        EventCountColorCode.h
***     \author      Pratik Jaiswal               
***
***     \brief       Header for BatteryHealthChecker.h
***/       
/*****************************************************************************/

#ifndef BatteryHealthChecker_h
#define BatteryHealthChecker_h

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/*=============================================================================
=======                      COMMON FUNCTIONS                            =======
=============================================================================*/
extern int CheckAttributeRange(float attribute, float lowerthreshold, float higherthreshold);
extern int LowerThresholdChecker(float attribute, float lowerthreshold);
extern int UpperThresholdChecker(float attribute, float upperthreshold);

#endif
