///////////////////////////////////FACTORY///////////////////////////////////
#pragma once
#include "GameUnit.h"

class LanceUnit : public gameUnit {
public:
	LanceUnit() {
		m_Name = "Cordelia";
		m_Attack = rand() % 30 + 70;
		m_Defense = rand() % 30 + 70;
		m_Speed = rand() % 30 + 70;
		m_Health = rand() % 30 + 70;
	};
	LanceUnit(string name, unsigned int attack, unsigned int defense, unsigned int speed, unsigned int health) {
		m_Name = name;
		m_Attack = attack;
		m_Defense = defense;
		m_Speed = speed;
		m_Health = health;
	}

	string gameUnit::getName() { return m_Name; }
	unsigned int gameUnit::getAttack() { return m_Attack; }
	unsigned int gameUnit::getDefense() { return m_Defense; }
	unsigned int gameUnit::getSpeed() { return m_Speed; }
	int gameUnit::getHealth() { return m_Health; }

	void setName(string name) { m_Name = name; }
	void setAttack(int attack) { m_Attack = attack; }
	void setDefense(int defense) { m_Defense = defense; }
	void setSpeed(int speed) { m_Speed = speed; }
	void setHealth(int health) { m_Health = health; }
};