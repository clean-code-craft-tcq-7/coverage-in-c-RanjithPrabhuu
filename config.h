#pragma once

#define NORMAL_COOLING_LOWERLIMIT 0
#define NORMAL_COOLING_UPPERLIMIT 35
#define HIGH_ACTIVE_COOLING_LOWERLIMIT 0
#define HIGH_ACTIVE_COOLING_UPPERLIMIT 45
#define MEDIUM_ACTIVE_COOLING_LOWERLIMIT 0
#define MEDIUM_ACTIVE_COOLING_UPPERLIMIT 40
#define MAXIMUM_COOLING_TYPE 3

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
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
