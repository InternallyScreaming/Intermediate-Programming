/*
Name:		Tiffany Wiebe
Objective:	Use an abstract class to have 5 boat classes inherit from to create battleship
*/
#include"WiebeTiff_Assign04.h"

#define WHITE 15

void menu();																						//menu
void credits();																						//credits
int randomizeXY();																					//randomizes ships' initial xy position
int randomizeDirection();																			//randomizes ships' direction
void Board(char playArea[10][10], int offsetX, int offsetY, int hits[10][10]);						//draw play areas above boats
void draw(Boat * ship, int ascii, int offsetX, int offsetY);										//draw boats
void hitsAndMisses(int hits[10][10]);																//assigns a value of 1 to a 2d array, is needed in determining the play area tiles
void attack(int HM[10][10], char playArea[10][10], vector<Boat*>&boats, int offsetX, int offsetY);  //playable part of the game



void main() {
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));

	int menuOption;
	char player1Board[10][10];
	char player2Board[10][10];
	int player1hits[10][10];
	int player2hits[10][10];
	bool running = true;
	bool menuRunning = true;

	string playerOnePlaying = "Player 1 ";
	string playerTwoPlaying = "Player 2 ";

	hitsAndMisses(player1hits);
	hitsAndMisses(player2hits);

	while (menuRunning) {
		menu();
		do {
			cin >> menuOption;
		} while (menuOption != 1 && menuOption != 2 && menuOption != 3);

		system("pause");

		if (menuOption == 1) {

			system("CLS");
//player 1 ships

#pragma region Creating&Player1Boats
			vector<Boat*> e_boats;

			SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_RED);

			//create a boat pointer and initialize it to a derived class
			//the while loops will break when the newly created boat is not hitting another boat nor going over the boarders
			Boat * e_AircraftCarrier = new AirCraftCarrier(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 5);
			while (checkForCollision(e_boats, *e_AircraftCarrier) || edgeCollision(*e_AircraftCarrier))
			{
				e_AircraftCarrier = new AirCraftCarrier(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 5);
			}
			e_boats.push_back(e_AircraftCarrier);


			Boat * e_BattleShip = new Battleship(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 4);
			while (checkForCollision(e_boats, *e_BattleShip) || edgeCollision(*e_BattleShip))
			{
				e_BattleShip = new Battleship(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 4);
			}
			e_boats.push_back(e_BattleShip);


			Boat * e_Sub = new Submarine(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			while (checkForCollision(e_boats, *e_Sub) || edgeCollision(*e_Sub))
			{
				e_Sub = new Submarine(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			}
			e_boats.push_back(e_Sub);


			Boat * e_Cruise = new Cruiser(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			while (checkForCollision(e_boats, *e_Cruise) || edgeCollision(*e_Cruise))
			{
				e_Cruise = new Cruiser(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			}
			e_boats.push_back(e_Cruise);

			Boat * e_Destroy = new Destroyer(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 2);
			while (checkForCollision(e_boats, *e_Destroy) || edgeCollision(*e_Destroy))
			{
				e_Destroy = new Destroyer(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 2);
			}
			e_boats.push_back(e_Destroy);

			draw(e_AircraftCarrier, 219, 51, 4);
			draw(e_BattleShip, 219, 51, 4);
			draw(e_Sub, 219, 51, 4);
			draw(e_Cruise, 219, 51, 4);
			draw(e_Destroy, 219, 51, 4);

#pragma endregion Creating&DrawingPlayer1Boats

			SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);
			gotoXY(50, 2);
			cout << " Player 1: " << endl;
			Board(player1Board, 50, 3, player1hits);

			SetConsoleTextAttribute(ConsoleHandle, WHITE); //removes colour from the next line of text
			cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;

//player 2 ships
#pragma region Creating&DrawingPlayer2Boats
			vector<Boat*> p_boats;

			//create a boat pointer and initialize it to a derived class
			//the while loops will break when the newly created boat is not hitting another boat nor going over the boarders
			SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_RED);
			Boat * p_AircraftCarrier = new AirCraftCarrier(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 5);
			while (checkForCollision(p_boats, *p_AircraftCarrier) || edgeCollision(*p_AircraftCarrier))
			{
				p_AircraftCarrier = new AirCraftCarrier(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 5);
			}
			p_boats.push_back(p_AircraftCarrier);


			Boat * p_BattleShip = new Battleship(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 4);
			while (checkForCollision(p_boats, *p_BattleShip) || edgeCollision(*p_BattleShip))
			{
				p_BattleShip = new Battleship(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 4);
			}
			p_boats.push_back(p_BattleShip);

			Boat * p_Sub = new Submarine(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			while (checkForCollision(p_boats, *p_Sub) || edgeCollision(*p_Sub))
			{
				p_Sub = new Submarine(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			}
			p_boats.push_back(p_Sub);

			Boat * p_Cruise = new Cruiser(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			while (checkForCollision(p_boats, *p_Cruise) || edgeCollision(*p_Cruise))
			{
				p_Cruise = new Cruiser(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 3);
			}
			p_boats.push_back(p_Cruise);

			Boat * p_Destroy = new Destroyer(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 2);
			while (checkForCollision(p_boats, *p_Destroy) || edgeCollision(*p_Destroy))
			{
				p_Destroy = new Destroyer(vector2(randomizeXY(), randomizeXY()), randomizeDirection(), 2);
			}
			p_boats.push_back(p_Destroy);

			draw(p_AircraftCarrier, 219, 51, 18);
			draw(p_BattleShip, 219, 51, 18);
			draw(p_Sub, 219, 51, 18);
			draw(p_Cruise, 219, 51, 18);
			draw(p_Destroy, 219, 51, 18);
#pragma endregion Creating&Drawing2PlayerBoats

			SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);
			gotoXY(50, 16);
			cout << " Player 2: " << endl;
			Board(player2Board, 50, 17, player1hits);

			//SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_INTENSITY); //removes colour from text

			while (running) {
				//player 1's turn
				SetConsoleTextAttribute(ConsoleHandle, WHITE);
				gotoXY(75, 19);
				cout << "Player 1's turn" << endl;
				attack(player1hits, player2Board, p_boats, 50, 17);
				
				//Will declare when a single boat is sunk
				if (boatSinks(*p_AircraftCarrier)) {
					gotoXY(5, 18);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 2's ";
					p_AircraftCarrier->sinking();
				}
				if (boatSinks(*p_BattleShip)) {
					gotoXY(5, 19);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 2's ";
					p_BattleShip->sinking();
				}
				if (boatSinks(*p_Sub)) {
					gotoXY(5, 20);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 2's ";
					p_Sub->sinking();
				}
				if (boatSinks(*p_Cruise)) {
					gotoXY(5, 21);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 2's ";
					p_Cruise->sinking();
				}
				if (boatSinks(*p_Destroy)) {
					gotoXY(5, 22);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 2's ";
					p_Destroy->sinking();
				}
				//player 2's turn
				SetConsoleTextAttribute(ConsoleHandle, WHITE);
				gotoXY(75, 19);
				cout << "Player 2's turn" << endl;
				attack(player2hits, player1Board, e_boats, 50, 3);

				//will declare when a single boat is sunk
				if (boatSinks(*e_AircraftCarrier)) {
					gotoXY(75, 0);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 1's ";
					e_AircraftCarrier->sinking();
				}
				if (boatSinks(*e_BattleShip)) {
					gotoXY(75, 1);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 1's ";
					e_BattleShip->sinking();
				}
				if (boatSinks(*e_Sub)) {
					gotoXY(75, 2);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 1's ";
					e_Sub->sinking();
				}
				if (boatSinks(*e_Cruise)) {
					gotoXY(75, 3);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 1's ";
					e_Cruise->sinking();
				}
				if (boatSinks(*e_Destroy)) {
					gotoXY(75, 4);
					SetConsoleTextAttribute(ConsoleHandle, WHITE);
					cout << "Player 1's ";
					e_Destroy->sinking();
				}

				if (sinkAllShips(e_boats)) {
					cout << "Player 2 wins the game!" << endl;
					system("pause");

					e_AircraftCarrier = NULL;
					e_BattleShip = NULL;
					e_Sub = NULL;
					e_Cruise = NULL;
					e_Destroy = NULL;

					p_AircraftCarrier = NULL;
					p_BattleShip = NULL;
					p_Sub = NULL;
					p_Cruise = NULL;
					p_Destroy = NULL;

					delete e_AircraftCarrier;
					delete e_BattleShip;
					delete e_Sub;
					delete e_Cruise;
					delete e_Destroy;

					delete p_AircraftCarrier;
					delete p_BattleShip;
					delete p_Sub;
					delete p_Cruise;
					delete p_Destroy;

					running = false;
				}
				if (sinkAllShips(p_boats)) {
					cout << "Player 1 wins the game!" << endl;
					system("pause");

					e_AircraftCarrier = NULL;
					e_BattleShip = NULL;
					e_Sub = NULL;
					e_Cruise = NULL;
					e_Destroy = NULL;

					p_AircraftCarrier = NULL;
					p_BattleShip = NULL;
					p_Sub = NULL;
					p_Cruise = NULL;
					p_Destroy = NULL;

					delete e_AircraftCarrier;
					delete e_BattleShip;
					delete e_Sub;
					delete e_Cruise;
					delete e_Destroy;

					delete p_AircraftCarrier;
					delete p_BattleShip;
					delete p_Sub;
					delete p_Cruise;
					delete p_Destroy;


					running = false;
				}
			}
		}
		else if (menuOption == 2) {
			credits();
			system("pause");
		}
		else if (menuOption == 3)
		{
			cout << "Good Bye!" << endl;
			menuRunning = false;
			system("pause");
		}
	}
}

void menu(){
	system("CLS");
	gotoXY(30, 0);
	cout << "||     *                            *                    ((   *  ||" << endl; 
	gotoXY(30, 1);
	cout << "||        *                 *                *            ~      ||" << endl; 
	gotoXY(30, 2);
	cout << "||                ___.                          *          *     ||" << endl; 
	gotoXY(30, 3);
	cout << "||       *    ___.\\__|.__.           *                           ||" << endl; 
	gotoXY(30, 4);
	cout << "||            \\__|. .| \\_|.                                      ||" << endl; 
	gotoXY(30, 5);
	cout << "||            . X|___|___| .                         *           ||" << endl; 
	gotoXY(30, 6);
	cout << "||          .__/_||____ ||__.            *                /\\     ||" << endl; 
	gotoXY(30, 7);
	cout << "||  *     .  |/|____ |_\\|_ |/ _                          /  \\    ||" << endl; 
	gotoXY(30, 8);
	cout << "||        \\ _/ |_X__\\|_  |\\||~,~{                       /    \\   ||" << endl; 
	gotoXY(30, 9);
	cout << "||         \\/\\ |/|    |_ |/:|`X'{                   _ _/      \\__||" << endl; 
	gotoXY(30, 10);
	cout << "||          \\ \\/ |___ |_\\|_.|~~~                   /    . .. . ..||" << endl; 
	gotoXY(30, 11);
	cout << "||         _|X/\\ |___\\|_ :| |_.                  - .......... . .||" << endl; 
	gotoXY(30, 12);
	cout << "||         | __\\_:____ |  ||o-|            ___/........ . . .. ..||" << endl; 
	gotoXY(30, 13);
	cout << "||         |/_-|-_|__ \\|_ |/--|       ____/  . . .. . . .. ... . ||" << endl; 
	gotoXY(30, 14);
	cout << "|| ........:| -|- o-o\\_:_\\|o-/:....../...........................||" << endl; 
	gotoXY(30, 15);
	cout << "|| ._._._._._\\=\\====o==o==o=/:.._._._._._._._._._._._._._._._._._||" << endl; 
	gotoXY(30, 16);
	cout << "|| _._._._._._\\_\\ ._._._._.:._._._._._._._._._._._._._.P_._._._._||" << endl; 
	gotoXY(30, 17);
	cout << "|| ._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._||" << endl; 
	gotoXY(30, 18);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 19);
	cout << "||                   WELCOME TO BATTLESHIP!                      ||" << endl; 
	gotoXY(30, 20);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 21);
	cout << "||                   1-PLAY GAME                                 ||" << endl;
	gotoXY(30, 22);
	cout << "||                   2-CREDITS                                   ||" << endl; 
	gotoXY(30, 23);
	cout << "||                   3-EXIT                                      ||" << endl; 
	gotoXY(30, 24);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 25);
}
void credits(){
	system("CLS");
	gotoXY(30, 0);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 1);
	cout << "||                          CREDITS                              ||" << endl; 
	gotoXY(30, 2);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 3);
	cout << "||CODING............................................TIFFANY WIEBE||" << endl; 
	gotoXY(30, 4);
	cout << "||WITH ASSISTANCE OF.........................ETIENNE DOUCET-LEGER||" << endl; 
	gotoXY(30, 5);
	cout << "||	                              (FOR GIVING ME HIS NOTES)||" << endl; 
	gotoXY(30, 6);
	cout << "||ASCII ART............................................MANOJ JAIN||" << endl; 
	gotoXY(30, 7);
	cout << "||		                               (FROM CHRIS.COM)||" << endl; 
	gotoXY(30, 8);
	cout << "||---------------------------------------------------------------||" << endl; 
	gotoXY(30, 9);
}
int randomizeXY(){
	int num = rand() % 10;
	Sleep(1);
	return num;
}
int randomizeDirection(){
	int num = rand() % 4 + 1;
	Sleep(1);
	return num;
}
void draw(Boat * ship, int ascii, int offsetX, int offsetY) {
	for (int i = 0; i < ship->getSize(); i++) {
		gotoXY(ship->positions[i].X + offsetX, ship->positions[i].Y + offsetY);
		cout << (char)ascii;
	}
}
void Board(char playArea[10][10], int offsetX, int offsetY, int hits[10][10]) {
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);

	gotoXY(offsetX, offsetY);
	cout << " 0123456789" << endl;
	offsetY++;
	for (int i = 0; i < 10; i++) {
		SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_GREEN);
		gotoXY(offsetX, offsetY);
		cout << i;
		for (int j = 0; j < 10; j++) {
			//default blue board
			if (hits[i][j] == 1) {
				SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_BLUE);
				playArea[i][j] = (char)219;
				cout << playArea[i][j];
			}
			//if player misses
			if (hits[i][j] == 2) {
				SetConsoleTextAttribute(ConsoleHandle, WHITE);
				playArea[i][j] = (char)88;
				cout << playArea[i][j];
			}
			//if player hits
			if (hits[i][j] == 3) {
				SetConsoleTextAttribute(ConsoleHandle, FOREGROUND_RED);
				playArea[i][j] = (char)219;
				cout << playArea[i][j];
			}
		}
		cout << endl;
		offsetY++;
	}
}
void hitsAndMisses(int hits[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			hits[i][j] = 1;
		}
	}
}
void attack(int HM [10][10], char playArea[10][10], vector<Boat*>&boats, int offsetX, int offsetY) {
	
	int X = 0;
	int Y = 0;
	gotoXY(75, 20);
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << endl;
	gotoXY(75, 21);
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << endl;
	gotoXY(75, 22);
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << endl;
	gotoXY(75, 23);
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << endl;
	gotoXY(75, 24);
	cout << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << endl;
	gotoXY(75, 20);
	cout << "Enter in the Coordinates:" << endl;
	gotoXY(75, 21);
	cout << "X: ";
	do { //continue to ask player for a valid X answer
		gotoXY(79, 21);
		cin >> X;
	} while (X != 1 && X != 2 && X != 3 && X != 4 && X != 5 && X != 6 && X != 7 && X != 8 && X != 9 && X != 0);
	gotoXY(75, 22);
	cout << "Y: ";
	do { //continue to ask player for a valid Y answer
		gotoXY(79, 22);
		cin >> Y;
	} while (Y != 1 && Y != 2 && Y != 3 && Y != 4 && Y != 5 && Y != 6 && Y != 7 && Y != 8 && Y != 9 && Y != 0);

	if (hitCollision(boats, X, Y)) {
		gotoXY(79, 23);
		cout << "hit" << endl;
		HM[Y][X] = 3;
		Sleep(500);
	}
	else {
		gotoXY(79, 23);
		cout << "miss" << endl;
		HM[Y][X] = 2;
		Sleep(500);
	}
	Board(playArea, offsetX, offsetY, HM);//redraws the board
}
