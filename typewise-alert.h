#pragma once

//function declaration for check and alert function
void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC, void (*alertMessage)(char*));
