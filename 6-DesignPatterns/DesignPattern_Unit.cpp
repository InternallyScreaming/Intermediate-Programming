#include "GameUnit.h"


//Setter Functions
void gameUnit::SetName(string name) {
	m_Name = name;
}
void gameUnit::SetAttack(unsigned int attack) {
	m_Attack = attack;
}
void gameUnit::SetDefense(unsigned int defense) {
	m_Defense = defense;
}
void gameUnit::SetSpeed(unsigned int speed) {
	m_Speed = speed;
}
void gameUnit::SetHealth(unsigned int health) {
	m_Health = health;
}

//Getter Functions
string gameUnit::GetName() {
	return m_Name;
}
unsigned int gameUnit::GetAttack(){
	return m_Attack;
}
unsigned int gameUnit::GetDefense(){
	return m_Defense;
}
unsigned int gameUnit::GetSpeed(){
	return m_Speed;
}
unsigned int gameUnit::GetHealth(){
	return m_Health;
}
