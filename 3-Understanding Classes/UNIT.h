#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class gameUnit{

private:
	//member variables
	string m_Name;
	int m_Attack;
	int m_Defense;
	int m_Speed;
	int m_Health;

public:
	//Setters
	void SetName(string name);
	void SetAttack(int attack);
	void SetDefense(int defense);
	void SetSpeed(int speed);
	void SetHealth(int health);

	//Getters
	string GetName();
	int GetAttack();
	int GetDefense();
	int GetSpeed();
	int GetHealth();

	//The Unique Method
	void monsterCry();
	void partyCry();

};