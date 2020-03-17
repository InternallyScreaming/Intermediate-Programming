///////////////////////////////////FACTORY///////////////////////////////////
#pragma once
#include "GameUnit.h"
#include "SwordUnit.h"
#include "LanceUnit.h"
#include "AxeUnit.h"

enum class UnitTypes { Sword, Lance, Axe };

class UnitFactory {
public: 
	static UnitFactory* getInstance();
	gameUnit* createUnit(UnitTypes type);

private:
	UnitFactory();
	static UnitFactory* m_UnitFactory;
};