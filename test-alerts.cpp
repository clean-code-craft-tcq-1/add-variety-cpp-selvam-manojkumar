#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"


TEST_CASE("check and alert through email") {
	alertToEMAIL* emailmsgobj = new alertToEMAIL;
	BatteryCharacter batteryObj = { HI_ACTIVE_COOLING , "Exide" };
	REQUIRE(checkAndAlert(emailmsgobj, batteryObj, -5) == TOO_LOW);
	REQUIRE(checkAndAlert(emailmsgobj, batteryObj, 2) == NORMAL);
}

TEST_CASE("check and alert through controller") {
	alertToController* controllermsgobj = new alertToController;
	BatteryCharacter batteryObj = { MED_ACTIVE_COOLING , "Amaron" };
	REQUIRE(checkAndAlert(controllermsgobj, batteryObj, 60) == TOO_HIGH);
	batteryObj = { PASSIVE_COOLING , "Amara raja" };
	REQUIRE(checkAndAlert(controllermsgobj, batteryObj, 10) == NORMAL);
}

