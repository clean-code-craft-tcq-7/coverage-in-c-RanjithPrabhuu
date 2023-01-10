#include <stdio.h>
#include "breachCheck.h"

//function definition to check the breach
BreachType inferBreach(double value, double lowerLimit, double upperLimit) 
{
  if(value < lowerLimit) 
  {
    return TOO_LOW;
  }
  if(value > upperLimit) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

//function definition to classify the limits
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  int lowerLimit = limitValuesList[coolingType].lowerLimit;
  int upperLimit = limitValuesList[coolingType].upperLimit;
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}
