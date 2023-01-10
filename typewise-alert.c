#include <stdio.h>
#include "config.h"
#include "breachCheck.h"
#include "typewise-alert.h"


void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC, void (*alertMessage)(char*))
{
    BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
}
 

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
