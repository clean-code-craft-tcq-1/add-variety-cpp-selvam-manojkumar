#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"


TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(22, 20, 30) == NORMAL);
}

TEST_CASE("check and alert through email") {
	alertToEMAIL* emailmsgobj = new alertToEMAIL;
	BatteryCharacter batteryObj = { HI_ACTIVE_COOLING , "Exide" };
	REQUIRE(checkAndAlert(emailmsgobj, batteryObj, -5) == TOO_LOW); ;
}

TEST_CASE("check and alert through controller") {
	alertToController* controllermsgobj = new alertToController;
	BatteryCharacter batteryObj = { MED_ACTIVE_COOLING , "Amaron" };
	REQUIRE(checkAndAlert(controllermsgobj, batteryObj, 60) == TOO_HIGH);
}
