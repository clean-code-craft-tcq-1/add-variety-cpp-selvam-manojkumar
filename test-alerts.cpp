#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("check and alert through email") {
	alertToEMAIL* emailmsgobj = new alertToEMAIL;
	BatteryCharacter batteryObj = { HI_ACTIVE_COOLING , "Exide" };
	REQUIRE(checkAndAlert(emailmsgobj, batteryObj, 0) == LOW); ;
}

TEST_CASE("check and alert through controller") {
	alertToController* controllermsgobj = new alertToController;
	BatteryCharacter batteryObj = { HI_ACTIVE_COOLING , "Amaron" };
	REQUIRE(checkAndAlert(controllermsgobj, batteryObj, 60) == HIGH);
}
