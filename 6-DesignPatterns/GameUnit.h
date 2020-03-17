///////////////////////////////////FACTORY///////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>

using namespace std;

class gameUnit{
protected:
	//member variables
	string m_Name;
	unsigned int m_Attack;
	unsigned int m_Defense;
	unsigned int m_Speed;
	unsigned int m_Health;

public:
	gameUnit(){};

	virtual string getName() = 0;
	virtual unsigned int getAttack() = 0;
	virtual unsigned int getDefense() = 0;
	virtual unsigned int getSpeed() = 0;
	virtual int getHealth() = 0;

	virtual void setName(string name) = 0;
	virtual void setAttack(int attack) = 0;
	virtual void setDefense(int defense) = 0;
	virtual void setSpeed(int speed) = 0;
	virtual void setHealth(int health) = 0;

};