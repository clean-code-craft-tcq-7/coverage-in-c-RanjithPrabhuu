#include <stdio.h>
#include "config.h"

//array which holds limit config list 
LimitValue limitConfigList[MAX_COOLING_TYPE] =
{
      {.lowerLimit = 0, .upperLimit = 35},
      {.lowerLimit = 0, .upperLimit = 45},
      {.lowerLimit = 0, .upperLimit = 40},
};
