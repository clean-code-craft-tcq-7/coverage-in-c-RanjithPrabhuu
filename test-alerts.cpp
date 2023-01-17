#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "alertInfo.h"
#include "breachCheck.h"

char printStr[100];

void printfunc(char* buff)
{
    strcpy(printStr, buff);
    printf(buff);
}

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to High") {
  REQUIRE(inferBreach(30, 10, 20) == TOO_HIGH);
}
TEST_CASE("infers the breach according to Normal") {
  REQUIRE(inferBreach(20, 10, 40) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach passive cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach acive cooling cooling") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach medactive cooling") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 30) == NORMAL);
}
TEST_CASE("classifyTemperatureBreach passive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 50) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach acive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
}
TEST_CASE("classifyTemperatureBreach medactive cooling Too high") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 60) == TOO_HIGH);

