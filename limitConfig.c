#include <stdio.h>
#include "config.h"

//array which holds limit config list 
const CoolingInfo CoolingInfoTable[]= {
    {PASSIVE_COOLING , PASSIVE_COOLING_LOWERLIMIT,PASSIVE_COOLING_UPPERLIMIT},
    {HI_ACTIVE_COOLING,HI_ACTIVE_COOLING_LOWERLIMIT,HI_ACTIVE_COOLING_UPPERLIMIT},
    {MED_ACTIVE_COOLING,MED_ACTIVE_COOLING_LOWERLIMIT,MED_ACTIVE_COOLING_UPPERLIMIT},
};

