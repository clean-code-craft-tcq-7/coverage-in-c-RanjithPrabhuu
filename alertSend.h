//function pointer declaration
typedef void (*alertFuncPtr)(BreachType, void (*alertMessage)(char*));

//function declaration to send the messgage to controller
void sendToController(BreachType breachType, void (*alertMessage)(char*));
//function declaration to send the message via email
void sendToEmail(BreachType breachType, void (*alertMessage)(char*));

//extern for function pointer list
extern alertFuncPtr alertTypeList[MAX_ALERT_TYPE];
