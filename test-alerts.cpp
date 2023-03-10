#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "alertInfo.h"
#include "breachCheck.h"

TEST_CASE("breach inference for low limit") {
  REQUIRE(inferBreach(13, 20, 30) == TOO_LOW);
}
TEST_CASE("breach inference for high limit") {
  REQUIRE(inferBreach(31, 10, 20) == TOO_HIGH);
}
TEST_CASE("breach inference for normal limit") {
  REQUIRE(inferBreach(21, 10, 40) == NORMAL);
}
TEST_CASE("temperature breach classification for passive cooling normal") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("temperature breach classification for acive cooling normal") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("temperature breach classification for med active cooling normal") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("temperature breach classification for passive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 52) == TOO_HIGH);
}
TEST_CASE("temperature breach classification for acive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 49) == TOO_HIGH);
}
TEST_CASE("temperature breach classification for med active cooling Too high") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 65) == TOO_HIGH);
}  
TEST_CASE("temperature breach classification for passive cooling Too low") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
}
TEST_CASE("temperature breach classification for acive cooling Too low") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -2) == TOO_LOW);
}
TEST_CASE("temperature breach classification for med active cooling Too low") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -3) == TOO_LOW);
}  

char buf[100];

TEST_CASE("send email alert high") 
{
  const char* src ="Hi, the temperature is too high\n";
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  checkAndAlert(TO_EMAIL,batteryChar,50,&buf[0]);
  REQUIRE(strcmp(buf,src)!=0);
}

TEST_CASE("send controller alert high") 
{
  const char* src = "0xfeed : TOO_HIGH";
  BatteryCharacter batteryChar;
  batteryChar.coolingType = HI_ACTIVE_COOLING;
  checkAndAlert(TO_CONTROLLER,batteryChar,60,&buf[0]);
  REQUIRE(strcmp(buf,src)!=0);
}

