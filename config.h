//enum for cooling type
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COOLING_TYPE
} CoolingType;

//enum for breach type
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  MAX_BREACH_TYPE
} BreachType;

//structure to hold lower and upper limit
typedef struct{
    int lowerLimit;
    int upperLimit;
} LimitValue;

//extern for array of structures
extern LimitValue limitValuesList[MAX_COOLING_TYPE];
