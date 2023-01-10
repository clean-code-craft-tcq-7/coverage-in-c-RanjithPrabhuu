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

//enum for alert mode 
typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  MAX_ALERT_TYPE,
} AlertTarget;

//structure to hold coolingType and brand
typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

//extern array to hold the limit
extern LimitValue limitValuesList[MAX_COOLING_TYPE];
//extern variable to hold the receipent
extern const char* recepient;

