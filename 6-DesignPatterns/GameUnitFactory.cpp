///////////////////////////////////FACTORY///////////////////////////////////

#pragma once
#include "GameUnitFactory.h"

UnitFactory* UnitFactory::m_UnitFactory = 0;

UnitFactory* UnitFactory::getInstance()
{
	if (m_UnitFactory == 0)
		m_UnitFactory = new UnitFactory();
	return m_UnitFactory;
}

UnitFactory::UnitFactory(){}

gameUnit* UnitFactory::createUnit(UnitTypes type)
{
	switch (type)
	{
	case UnitTypes::Sword:
		return new SwordUnit();
		break;
	case UnitTypes::Lance:
		return new LanceUnit();
		break;
	case UnitTypes::Axe:
		return new AxeUnit();
		break;
	default:
		break;
	}
}