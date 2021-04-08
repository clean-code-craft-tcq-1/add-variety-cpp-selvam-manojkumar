#include "typewise-alert.h"
#include <iostream>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

void setTemperatureLimits(CoolingType coolingType, temperatureLimits * limits)
{
	limits->lowerLimit = CoolingLimitsMap[coolingType].first;
	limits->upperLimit = CoolingLimitsMap[coolingType].second;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
	temperatureLimits limits = { 0,0 };
	setTemperatureLimits(coolingType, &limits);
	return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
}

BreachType checkAndAlert(alertmode* alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  return alertTarget->notifyallert(breachType);
}

BreachType alertToController::notifyallert(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return breachType;
}


BreachType alertToEMAIL::notifyallert(BreachType breachType) {

  const char* recepient = "a.b@c.com";
  if (breachType != NORMAL)
  {
	  std::cout << "To: " << recepient << "\n" << EmailMsgMap[breachType] << std::endl;
	 
  }
   return breachType;
}
