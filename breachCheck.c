#include "config.h"
#include "breachCheck.h"

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

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
   int lowerLimit = 0;
   int upperLimit = 0;
   for ( int CoolingInfoTableIndex = 0; CoolingInfoTableIndex < MAXIMUM_COOLING_TYPE;CoolingInfoTableIndex++)
   {
      if(CoolingInfoTable[CoolingInfoTableIndex].coolingtype == coolingType)
      {
         lowerLimit = CoolingInfoTable[CoolingInfoTableIndex].LowerLimit;
         upperLimit = CoolingInfoTable[CoolingInfoTableIndex].UpperLimit; 
         break;
      }
   } 
   return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

