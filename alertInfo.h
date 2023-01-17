#include "config.h"

#define MAXALERTTYPE 2

typedef struct
{
	AlertTarget Target ;
	void (*AlertCallback)(BreachType,char*);
}AlertTable;

typedef struct
{
   BreachType breachtype;
   const char*FirstMessage;
   const char*SecondMessage;
}sendToEmailMessage;

void sendToController(BreachType breachType,char* msgBuf);
void sendToEmail(BreachType breachType,char* msgBuf);
void SendAlertMessage(AlertTarget alertTarget,BreachType breachType,char* msgBuf);
