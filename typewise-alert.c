#include <stdio.h>
#include "config.h"
#include "breachCheck.h"
#include "alertSend.h"
#include "typewise-alert.h"

//function definition for check and alert function
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC, void (*alertMessage)(char*))
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
    alertTypeList[alertTarget](breachType, alertMessage);
}
 
