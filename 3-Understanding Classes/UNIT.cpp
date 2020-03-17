#include "TiffanyWiebe_Assignment_03_UNIT.h"


//Setter Functions
void gameUnit::SetName(string name) {
	m_Name = name;
}
void gameUnit::SetAttack(int attack) {
	m_Attack = attack;
}
void gameUnit::SetDefense(int defense) {
	m_Defense = defense;
}
void gameUnit::SetSpeed(int speed) {
	m_Speed = speed;
}
void gameUnit::SetHealth(int health) {
	m_Health = health;
}

//Getter Functions
string gameUnit::GetName() {
	return m_Name;
}
int gameUnit::GetAttack(){
	return m_Attack;
}
int gameUnit::GetDefense(){
	return m_Defense;
}
int gameUnit::GetSpeed(){
	return m_Speed;
}
int gameUnit::GetHealth(){
	return m_Health;
}

//The Unique Method Functions
void gameUnit::monsterCry() {
	cout << "rrrrrrrrRAAAAAAAAAAAAAAAAAAAAAAAAWWWWWWWWWWWRRRRRRRR" << endl;
}
void gameUnit::partyCry() {
	cout << "GrrrrrrrrrrrrrrrrrrrrrrrrrrrrrUuUUrrrr!!!!!!!!!!" << endl;
}