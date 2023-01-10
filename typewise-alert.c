#include "typewise-alert.h"
#include "config.h"
#include "breachCheck.h"
#include "AlertInfo.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  SendAlertMessage(alertTarget, breachType);
}
