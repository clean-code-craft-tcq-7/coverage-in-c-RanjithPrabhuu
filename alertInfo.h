#include "config.h"

#define MAXALERTTYPE 2

typedef struct
{
	AlertTarget Target ;
	void (*AlertCallback)(BreachType);
}AlertTable;

typedef struct
{
   BreachType breachtype;
   const char*FirstMessage;
   const char*SecondMessage;
}sendToEmailMessage;

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
void SendAlertMessage(AlertTarget alertTarget,BreachType breachType);
