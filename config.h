#pragma once

#define PASSIVE_COOLING_LOWERLIMIT 0
#define PASSIVE_COOLING_UPPERLIMIT 35
#define HI_ACTIVE_COOLING_LOWERLIMIT 0
#define HI_ACTIVE_COOLING_UPPERLIMIT 45
#define MED_ACTIVE_COOLING_LOWERLIMIT 0
#define MED_ACTIVE_COOLING_UPPERLIMIT 40

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAXIMUM_COOLING_TYPE
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct
{
	CoolingType coolingtype;
	int LowerLimit;
	int UpperLimit;
}CoolingInfo;

extern const CoolingInfo CoolingInfoTable[];
