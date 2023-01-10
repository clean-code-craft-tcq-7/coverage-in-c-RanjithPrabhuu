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
TEST_CASE(" SendAlert messages to controller in high state") {
  SendAlertMessage(TO_CONTROLLER, TOO_HIGH, &printfunc);
  REQUIRE(strcmp(printStr,"feed : 0\n") == 0);
}

