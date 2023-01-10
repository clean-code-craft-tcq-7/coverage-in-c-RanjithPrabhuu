#include <stdio.h>
#include "config.h"
#include "alertInfo.h"
#include "alertSend.h"

void sendToController(BreachType breachType, void (*alertMessage)(char*)) {
  const unsigned short header = 0xfeed;
  char msgBuf[50];
  sprintf(msgBuf,"%x : %x\n", header, breachType);
  alertMessage(msgBuf);
}

void sendToEmail(BreachType breachType, void (*alertMessage)(char*)) {

  char msgBuf[100];
  if(breachType != NORMAL)
  {
      sprintf(msgBuf,"To: %s\n%s", recepient, emailAlertMessageInEng[breachType]);
      alertMessage(msgBuf);
  }
}

alertFuncPtr alertTypeList[MAX_ALERT_TYPE] = {
                &sendToController,
                &sendToEmail
};