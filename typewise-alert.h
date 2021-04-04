#pragma once
#include<map>
#include<string>

typedef std::pair<double, double> limits;

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef struct {
	double upperLimit;
	double lowerLimit;
}temperatureLimits;



static std::map<CoolingType, limits> CoolingLimitsMap =
{
	{ PASSIVE_COOLING , std::make_pair(0,35) },
	{ HI_ACTIVE_COOLING , std::make_pair(0,45) },
	{ MED_ACTIVE_COOLING , std::make_pair(0,40) }
};

static std::map<BreachType, std::string> EmailMsgMap =
{
	{ TOO_LOW , "Hi, the temperature is too low\n" },
	{ TOO_HIGH , "Hi, the temperature is too high\n" }
};

BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

class alertmode {
public:
	virtual void notifyallert(BreachType breachType) = 0;
};

class alertToController :public alertmode {
public:
	virtual void notifyallert(BreachType breachType);
};


class alertToEMAIL :public alertmode {
public:
	virtual void notifyallert(BreachType breachType);
};


typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(alertmode* alertTarget, BatteryCharacter batteryChar, double temperatureInC);
