#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Goto these coordinates
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}		

//Holds X and Y coordinates
struct vector2 {
	vector2() { X = 0; Y = 0; }
	vector2(int x, int y) { X = x; Y = y; }

	int X;
	int Y;

	vector2 operator=(vector2 value) {
		X = value.X;
		Y = value.Y;
		return *this;
	}

	bool operator==(vector2 value) {
		if (X == value.X && Y == value.Y) {
			return true;
		}
		return false;
	}
};

//Base class for ships
class Boat {
protected:
	string m_name;			//name of ship
	int m_size;				//size of ship
	int m_health;			//health of ship
	int m_X;				//intial X position
	int m_Y;				//initial Y position
public:

	string getName() { return m_name; }
	int getSize() { return m_size; }
	int getHealth() { return m_health; }

	void setHealth(int health) { m_health = health; }
	vector<vector2> positions;				//vector to hold the boat

	Boat(){}; //Default Constructor.  The code will break without a default constructor

	//Creating a boat contructor
	Boat(vector2 initialPosition, int direction, int size) {
		positions.push_back(initialPosition);			//puts the first position of the boat
		m_size = size;
		m_health = m_size;
		
		for (int i = 1; i < size; i++) {	//puts the rest of the boat spaces into a vector based on the orientation of the boat
			switch (direction) {
			case 1://North
				positions.push_back(vector2((positions[i - 1].X), (positions[i - 1].Y - 1)));	
				break;
			case 2://South
				positions.push_back(vector2((positions[i - 1].X), (positions[i - 1].Y + 1)));
				break;
			case 3://East
				positions.push_back(vector2((positions[i - 1].X + 1), (positions[i - 1].Y)));
				break;
			case 4://West
				positions.push_back(vector2((positions[i - 1].X - 1), (positions[i - 1].Y)));
				break;
			}
		}
	}
	virtual void sinking() = 0;
};

//Derived classes from base class "Boat"
#pragma region Derived_Classes
class AirCraftCarrier : public Boat{
public: 
	AirCraftCarrier() {m_name = "Aircraft Carrier"; m_size = 5;}
	AirCraftCarrier(vector2 initialPosition, int direction, int size) : Boat(initialPosition, direction, size) {}
	void sinking() override {cout << "Aircraft Carrier has sunk"; }
};

class Battleship : public Boat{
public:
	Battleship() {m_name = "Battleship"; m_size = 4;}
	Battleship(vector2 initialPosition, int direction, int size) : Boat(initialPosition, direction, size) {}
	void sinking() override { cout <<"Battleship has sunk"; }
};

class Submarine : public Boat {
public:
	Submarine() {m_name = "Submarine"; m_size = 3;}
	Submarine(vector2 initialPosition, int direction, int size) : Boat(initialPosition, direction, size) {}
	void sinking() override { cout << "Submarine has sunk"; }
};

class Cruiser : public Boat {
public:
	Cruiser() {m_name = "Cruiser"; m_size = 3;}
	Cruiser(vector2 initialPosition, int direction, int size) : Boat(initialPosition, direction, size) {}
	void sinking() override { cout << "Cruiser has sunk"; }
};

class Destroyer : public Boat {
public:
	Destroyer() {m_name = "Destroyer"; m_size = 2;}
	Destroyer(vector2 initialPosition, int direction, int size) : Boat(initialPosition, direction, size) {}
	void sinking() override { cout << "Destroyer has sunk"; }
};
#pragma endregion Derived_Classes

//checks a single boat against another
bool collision(Boat * firstBoat, Boat * secondBoat, vector2 &collision) {
	for (int i = 0; i < firstBoat->getSize(); i++) {
		for (int j = 0; j < secondBoat->getSize(); j++) {
			if (firstBoat->positions[i] == secondBoat->positions[j]) {
				collision = firstBoat->positions[i];
				return true;
			}
		}
	}
	return false;
}
//checks a boat against all newly created boats for a single player
bool checkForCollision(vector<Boat*>& boats, Boat & boat){
	vector2 collisionlocation;
	for (int i = 0; i < boats.size(); i++){
		if (collision(boats[i], &boat, collisionlocation)){
			return true;
		}
	}
	return false;
}
//checks if a boat is going over the edge
bool edgeCollision(Boat &Boat) {
	for (int i = 0; i < Boat.getSize(); i++) {
		if (Boat.positions[i].X < 0 || Boat.positions[i].Y < 0 || Boat.positions[i].X > 9 || Boat.positions[i].Y > 9){
			return true;
		}
	}
	return false;
}
//checks if a singular boat was hit
bool attackLocation(Boat & Boat, int xCoor, int yCoor) {
	int currentHealth = Boat.getHealth();
	for (int i = 0; i < Boat.getSize(); i++) {
		if (Boat.positions[i].X == xCoor && Boat.positions[i].Y == yCoor) {
			currentHealth--;
			Boat.setHealth(currentHealth);
			return true;
		}
	}
	return false;
}
//checks if any boats were hit
bool hitCollision(vector<Boat*>& boats, int xCoor, int yCoor) {
	for (int i = 0; i < boats.size(); i++) {
		if (attackLocation(*boats[i], xCoor, yCoor)) {
			return true;
		}
	}
	return false;
}
//checks if a singular boat was sunk
bool boatSinks(Boat & boat)  {
	if (boat.getHealth() <= 0) {

		return true;
	}
	return false;
}
//checks if all boats were sunk
bool sinkAllShips(vector<Boat*> & boats) {
	for (int i = 0; i < boats.size(); i++) {
		if (boatSinks(*boats[i]) == false) {
			return false;
		}
	}
	return true;
}
