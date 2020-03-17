/*
*Tiffany Wiebe
*
*/


#include "GameUnit.h"


void introduction(const int amountOfMonsters, const int amountOfPartyMembers); //introduction to the program
void optionMenu();															   //option menu
void iChooseYouMonster(gameUnit monsterArray[], int monsterSize);			   //Monster selection screen
void iChooseYouPartyMember(gameUnit partyArray[], int partySize);              //Party Member selection screen

//Setting Functions for each variable in each index of the array
void monsters(gameUnit monsterArray[], const int amountOfMonsters);			   //Setting all monster variables in the monster array
void partyMembers(gameUnit partyArray[], const int amountOfPartyMembers);	   //Setting all party member variables in the party member array

void printInfo(int userChoice, gameUnit monsterArray[], gameUnit partyArray[], int monsterSize, int partySize);						//Gets the info in the monster and PM arrays and prints them to the console
int itsTimeToDuel(gameUnit monsterArray[], gameUnit partyArray[], int monsterSize, int partySize);									//Allows the user to pick a monster and PM and have the two fight
void changeStats(int unitChoice, int unitIndex, gameUnit monsterArray[], gameUnit partyArray[], int monsterSize, int partySize);	//Allows the user to specifically change the stats of either the monster or PM stats at a certain index

int main() {

	int option = 0;
	int printOption = 0;
	int unitChoice = 0;
	int unitIndex = 0;
	int unitNum = 1;
	bool running = true;

	const int amountOfMonsters = 3;
	const int amountOfPartyMembers = 3;

	gameUnit Monsters[amountOfMonsters];
	gameUnit Party[amountOfPartyMembers];

	introduction(amountOfMonsters, amountOfPartyMembers);

	system("pause");
	system("CLS");

	monsters(Monsters, amountOfMonsters);
	partyMembers(Party, amountOfPartyMembers);

	while (running) {
		optionMenu();
		cin >> option;

		switch (option) {
		case 1:
			system("CLS");
			cout << "Whose info do you want displayed?" << endl;
			cout << "1 - The Monsters" << endl;
			cout << "2 - The Party Members" << endl;
			cout << "3 - Both" << endl;

			cin >> printOption;

			printInfo(printOption, Monsters, Party, amountOfMonsters, amountOfPartyMembers);
			system("pause");
			break;
		//Option 2 is the dueling function
		case 2:
			//calling the dueling function
			itsTimeToDuel(Monsters, Party, amountOfMonsters, amountOfPartyMembers);
			break;
		case 3:
			//using a do while loop to error check for the unit choice
			do {
				system("CLS");
				//a suboption menu to ask the user whether they want to change the monster or pm stats
				cout << "Whose stats do you want to change?" << endl;
				cout << "1 - The Monsters" << endl;
				cout << "2 - The Party Members" << endl;
				//prompt the user to enter their 
				cin >> unitChoice;
				//if the user enters a number that isn't option display this 
				if (unitChoice != 1 && unitChoice != 2) {
					cout << "You were the type who coloured outside the lines, weren't you?" << endl;
					system("pause");
					system("CLS");
				}
			} while (unitChoice != 1 && unitChoice != 2); // do while loop will break if the user enters a number that is an option

			//using another do while loop to check the user's next choice
			do {
				system("CLS");
				//asking the user which stats to change (asking the user which index in the array they want to change)
				cout << "Which unit's stats do you want to change?" << endl;

				//menu to show which object in the specified array (dictated by the first user input) do they want to change
				switch (unitChoice) {
				case 1:
					for (int i = 0; i < amountOfMonsters; i++) {
						cout << unitNum << "- " << Monsters[i].GetName() << endl;
						unitNum++;
					}
					unitNum = 1;
					break;
				case 2:
					for (int i = 0; i < amountOfPartyMembers; i++) {
						cout << unitNum << "- " << Party[i].GetName() << endl;
						unitNum++;
					}
					unitNum = 1;
					break;
				}
				cin >> unitIndex;

				//if the user enters a number that isn't option display this
				if (unitIndex != 1 && unitIndex != 2 && unitIndex != 3) {
					cout << "You do realize that it is cool to follow the rules." << endl;
					system("pause");
					system("CLS");
				}

			} while (unitIndex != 1 && unitIndex != 2 && unitIndex != 3); // do while loop will break if the user enters a number that is an option

			//calling the change stats function
			changeStats(unitChoice, unitIndex, Monsters, Party, amountOfMonsters, amountOfPartyMembers);
			system("pause");
			break;
		//Option 4 sets the boolean variable running the loop to false
		case 4:
			running = false;
			cout << "Good Bye!" << endl;
			system("pause");
			break;
		//If the user enters a number that isn't an option
		default:
			cout << "You and I both know that that is not an option! " << endl;
			system("pause");
		}
	}
	return 0;
}

//introduction to the program
void introduction(const int amountOfMonsters, const int amountOfPartyMembers) {
	cout << "**************************************************************************************" << endl;
	cout << "*                                      WELCOME!                                      *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*             To get started, please enter the stats for (" << amountOfMonsters << ") monsters," ;
	gotoXY(85, 4);
	cout << "*" << endl;
	cout << "*                              and (" << amountOfPartyMembers << ") party members!";
	gotoXY(85, 5);
	cout << "*" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
}

//option menu
void optionMenu() {
	system("CLS");
	cout << "**************************************************************************************" << endl;
	cout << "*                                    MAIN MENU                                       *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                              PLEASE SELECT AN OPTION                               *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*               1)       SHOW ME THE STATS INFORMATION                               *" << endl;
	cout << "*               2)       FIGHT, FIGHT, FIGHT!                                        *" << endl;
	cout << "*               3)       CHANGE MONSTER/PARTY MEMBER'S STATS                         *" << endl;
	cout << "*               4)       EXIT THE PROGRAM                                            *" << endl;
	cout << "**************************************************************************************" << endl;
}

//Monster selection screen
void iChooseYouMonster(gameUnit monsterArray[], int monsterSize) {
	int i = 0;

	cout << "**************************************************************************************" << endl;
	cout << "*                    WELCOME TO THE BATTLE MENU!!!!!!!!!!!!!!!!!!!                   *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                        SELECT THE MONSTER YOU WISH TO FIGHT!                       *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*             1)     " << monsterArray[i].GetName() << "!";

	i++;
	gotoXY(85, 6);

	cout << "*" << endl;
	cout << "*             2)     " << monsterArray[i].GetName() << "!";

	i++;
	gotoXY(85, 7);

	cout << "*" << endl;
	cout << "*             3)     " << monsterArray[i].GetName() << "!";

	gotoXY(85, 8);

	cout << "*" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
}

//Party Member selection screen
void iChooseYouPartyMember(gameUnit partyArray[], int partySize) {
	int i = 0;

	cout << "**************************************************************************************" << endl;
	cout << "*                         AWESOME CHOICE!!!!!!!!!!!!!!!!!!!                          *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                    SELECT THE PARTY MEMBER YOU WISH TO FIGHT!                      *" << endl;
	cout << "**************************************************************************************" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "*             1)     " << partyArray[i].GetName() << "!";

	i++;
	gotoXY(85, 6);

	cout << "*" << endl;
	cout << "*             2)     " << partyArray[i].GetName() << "!";

	i++;
	gotoXY(85, 7);

	cout << "*" << endl;
	cout << "*             3)     " << partyArray[i].GetName() << "!";

	gotoXY(85, 8);

	cout << "*" << endl;
	cout << "*                                                                                    *" << endl;
	cout << "**************************************************************************************" << endl;
}

//Setting all monster variables in the monster array
void monsters(gameUnit monsterArray[], const int amountOfMonsters) {
	
	//indicate which unit's stats the user is entering
	int j = 1;

	cout << "Please enter the information for each monster" << endl;

	//for loop iterating to the length of the object array
	for (int i = 0; i < amountOfMonsters; i++) {

		string name;
		int attack;
		int defense;
		int speed;
		int health;
		
		//prompts the user to enter a name
		cout << "What is the monster (" << j << ")'s  name?: ";
		cin >> name;
		monsterArray[i].SetName(name);

		//prompts the user to enter health
		cout << "What is the health of the monster?: ";
		cin >> health;
		monsterArray[i].SetHealth(health);

		//prompts the user to enter attack
		cout << "What is the attack stat of the monster?: ";
		cin >> attack;
		monsterArray[i].SetAttack(attack);

		//prompts the user to enter defense
		cout << "What is the defense stat of the monster?: ";
		cin >> defense;
		monsterArray[i].SetDefense(defense);
		
		//prompts the user to enter speed
		cout << "What is speed stat of the monster?: ";
		cin >> speed;
		monsterArray[i].SetSpeed(speed);

		//clear the console for then next iteration
		system("CLS");
		j++;
	}
	j = 1;
}

//Setting all party member variables in the party member array
void partyMembers(gameUnit partyArray[], const int amountOfPartyMembers) {

	//indicate which unit's stats the user is entering
	int j = 1;

	cout << "Please enter the information for each party member" << endl;

	//for loop iterating to the length of the object array
	for (int i = 0; i < amountOfPartyMembers; i++) {

		string name;
		int attack;
		int defense;
		int speed;
		int health;

		//prompts the user to enter a name
		cout << "What is the party member(" << j << ")'s  name?: ";
		cin >> name;
		partyArray[i].SetName(name);

		//prompts the user to enter health
		cout << "What is the health of the party member?: ";
		cin >> health;
		partyArray[i].SetHealth(health);

		//prompts the user to enter attack
		cout << "What is the attack stat of the party member?: ";
		cin >> attack;
		partyArray[i].SetAttack(attack);

		//prompts the user to enter defense
		cout << "What is the defense stat of the party member?: ";
		cin >> defense;
		partyArray[i].SetDefense(defense);

		//prompts the user to enter speed
		cout << "What is speed stat of the party member?: ";
		cin >> speed;
		partyArray[i].SetSpeed(speed);

		//clear the console for then next iteration
		system("CLS");
		j++;
	}
	j = 1;
}

//Gets the info in the monster and PM arrays and prints them to the console
void printInfo(int userChoice, gameUnit monsterArray[], gameUnit partyArray[],int monsterSize, int partySize) {
	int yOffset = 1;
	system("CLS");

	//prints the information that the user has specified in the main
	switch (userChoice) {

	//Prints only the monster array objects
	case 1:
		cout << "Monsters" << endl;
		for (int i = 0; i < monsterSize; i++) {
			cout << "Name: " << monsterArray[i].GetName() << endl;
			cout << "Health: " << monsterArray[i].GetHealth() << endl;
			cout << "Attack: " << monsterArray[i].GetAttack() << endl;
			cout << "Defense: " << monsterArray[i].GetDefense() << endl;
			cout << "Speed: " << monsterArray[i].GetSpeed() << endl;
			cout << endl;
		}
		break;

	//Prints only the PM array objects
	case 2:
		cout << "Party Members" << endl;
		for (int i = 0; i < partySize; i++) {
			cout << "Name: " << partyArray[i].GetName() << endl;
			cout << "Health: " << partyArray[i].GetHealth() << endl;
			cout << "Attack: " << partyArray[i].GetAttack() << endl;
			cout << "Defense: " << partyArray[i].GetDefense() << endl;
			cout << "Speed: " << partyArray[i].GetSpeed() << endl;
			cout << endl;
		}
		break;

	//Prints Both arrays
	case 3:
		//Prints the Monster array to the default side (left side) of the console 
		cout << "Monsters" << endl;
		for (int i = 0; i < monsterSize; i++) {
			cout << "Name: " << monsterArray[i].GetName() << endl;
			cout << "Health: " << monsterArray[i].GetHealth() << endl;
			cout << "Attack: " << monsterArray[i].GetAttack() << endl;
			cout << "Defense: " << monsterArray[i].GetDefense() << endl;
			cout << "Speed: " << monsterArray[i].GetSpeed() << endl;
			cout << endl;
		}

		//Prints the PM array 30 spaces from the left of the console
		gotoXY(30, 0);
		cout << "Party Members" << endl;
		for (int i = 0; i < partySize; i++) {
			gotoXY(30, yOffset);
			cout << "Name: " << partyArray[i].GetName() << endl;
			yOffset++;
			gotoXY(30, yOffset);
			cout << "Health: " << partyArray[i].GetHealth() << endl;
			yOffset++;
			gotoXY(30, yOffset);
			cout << "Attack: " << partyArray[i].GetAttack() << endl;
			yOffset++;
			gotoXY(30, yOffset);
			cout << "Defense: " << partyArray[i].GetDefense() << endl;
			yOffset++;
			gotoXY(30, yOffset);
			cout << "Speed: " << partyArray[i].GetSpeed() << endl;
			yOffset+=2;
			gotoXY(30, yOffset);
			cout << endl;
		}
		break;
	//Shows if the user entered a number that wasn't an option
	default: cout << "You entered something that wasn't an option >:(" << endl;
	}
}

//Allows the user to pick a monster and PM and have the two fight
int itsTimeToDuel(gameUnit monsterArray[], gameUnit partyArray[], int monsterSize, int partySize) {

	//initialize all necessary variables
	int monsterChoice = 0;
	int partyChoice = 0;
	bool duelRunning = true;
	
	//creates another variable of type gameUnit and set it to the class gameUnit
	gameUnit cries = gameUnit();
	
	
	system("CLS");
	//calling the monster selection screen
	iChooseYouMonster(monsterArray, monsterSize);
	cin >> monsterChoice;

	system("CLS"); 
	//calling the Party Member selection screen
	iChooseYouPartyMember(partyArray, partySize);
	cin >> partyChoice;

	//sets the user's choices to the actual index of the array
	int actualMonsterIndex = monsterChoice - 1;
	int actualPartyIndex = partyChoice - 1;

	//initialize monster variables and set them to the array at the actual index using the respective getter function
	string monsterName = monsterArray[actualMonsterIndex].GetName();
	int monsterHealth = monsterArray[actualMonsterIndex].GetHealth();
	int monsterAttack = monsterArray[actualMonsterIndex].GetAttack();
	int monsterDefense = monsterArray[actualMonsterIndex].GetDefense();
	int monsterSpeed = monsterArray[actualMonsterIndex].GetSpeed();

	//initialize PM variables and set them to the array at the actual index using the respective getter function
	string partyName = partyArray[actualPartyIndex].GetName();
	int partyHealth = partyArray[actualPartyIndex].GetHealth();
	int partyAttack = partyArray[actualPartyIndex].GetAttack();
	int partyDefense = partyArray[actualPartyIndex].GetDefense();
	int partySpeed = partyArray[actualPartyIndex].GetSpeed();

	//damage variables
	int monsterDamageTaken;
	int partyDamageTaken;

	//unsigned ints used if the speed stats of the selected monster and PM are the same value
	unsigned int ptSpdDiff = 0;
	unsigned int mstSpdDiff = 0;

	//do while loop that will break if the boolean variable duelRunning is set to false
	do{
		//clear console
		system("CLS");
		//title
		cout << "********************************************************************************************************************" << endl;
		cout << "*                                      IT'S TIME TO DU-DU-DU-DU-DU-D-D-D-DUEL!                                     *" << endl;
		cout << "********************************************************************************************************************" << endl;

		//offset and print the monster of choice's (MoC's) stats
		gotoXY(10, 5);
		cout << "Name:    " << monsterName << endl;
		gotoXY(10, 6);
		cout << "Health:  " << monsterHealth << endl;
		gotoXY(10, 7);
		cout << "Attack:  " << monsterAttack << endl;
		gotoXY(10, 8);
		cout << "Defense: " << monsterDefense << endl;
		gotoXY(10, 9);
		cout << "Speed:   " << monsterSpeed << endl;

		//offset and print the PM of choice's (PMoC's)stats
		gotoXY(85, 5);
		cout << "Name:    " << partyName << endl;
		gotoXY(85, 6);
		cout << "Health:  " << partyHealth << endl;
		gotoXY(85, 7);
		cout << "Attack:  " << partyAttack << endl;
		gotoXY(85, 8);
		cout << "Defense: " << partyDefense << endl;
		gotoXY(85, 9);
		cout << "Speed:   " << partySpeed << endl;
		cout << "********************************************************************************************************************" << endl;
		cout << endl;
		
		//if the MoC's speed PMoC's speed equals the same a do while loop will run where two variables are randomized from 1-10
		//the do while loop will break when the values do not equal each other
		if (monsterSpeed == partySpeed) {
			do {
				srand(time(NULL));
				ptSpdDiff = rand() % 10 + 1;
				mstSpdDiff = rand() % 10 + 1;
			} while (ptSpdDiff == mstSpdDiff);
		}

		// if monster speed is greater or if the monster speed difference speed is greater
		if (monsterSpeed > partySpeed || mstSpdDiff > ptSpdDiff) {
			cout << monsterName << " speed is higher! He/She/It attacks first!" << endl;
			
			//calls the monster cry function found in the header file
			cries.monsterCry();
			system("pause");

			//calculate partyDamage
			partyDamageTaken = monsterAttack - partyDefense;

			//if the party Damage is greater than zero
			if (partyDamageTaken > 0) {
				//set health to equal itself minus the damage
				partyHealth = partyHealth - partyDamageTaken;
				cout << partyName << " took " << partyDamageTaken << " point(s) of damage!" << endl;

				//calls the PM cry function found in the header
				cries.partyCry();
			}
			//if the party damage is not greater than zero
			else {
				cout << partyName << " took no points of damage!" << endl;
			}
			system("pause");

			//if the PM's health reaches zero
			if (partyHealth <= 0) {
				cout << partyName << " has lost all of his/her/its health and no longer able to fight!" << endl;

				//call the party cry
				cries.partyCry();
				system("pause");
				cout << monsterName << " wins the duel!" << endl;
				
				//set the boolean variable to false to break the do while loop
				duelRunning = false;
				system("pause");
			}
			else {
				cout << partyName << " attacks!" << endl;

				//call the party cry
				cries.partyCry();
				system("pause");

				//calculate the monsterDamage
				monsterDamageTaken = partyAttack - monsterDefense;

				//if the monster Damage is greater than zero
				if (monsterDamageTaken > 0) {
					//set health to equal itself minus the damage
					monsterHealth = monsterHealth - monsterDamageTaken;
					cout << monsterName << " took " << monsterDamageTaken << " point(s) of damage!" << endl;

					//call monster cry
					cries.monsterCry();
				}

				//if the monster damage is not greater than zero
				else {
					cout << monsterName << " took no points of damage!" << endl;
				}

				system("pause");
				//if the monster's health reaches zero
				if (monsterHealth <= 0) {
					cout << monsterName << " has lost all of his/her/its health and no longer able to fight!" << endl;

					//call monster cry
					cries.monsterCry();
					system("pause");
					cout << partyName << " wins the duel!" << endl;

					//set boolean variable to false
					duelRunning = false;
					system("pause");
				}
			}
		}

		// if party speed is greater or if the party speed difference is greater
		if (partySpeed > monsterSpeed || ptSpdDiff > mstSpdDiff) {
			cout << partyName << " speed is higher! He/She/It attacks first!" << endl;

			//calls party cry
			cries.partyCry();
			system("pause");

			//calculates monster damage
			monsterDamageTaken = partyAttack - monsterDefense;

			//if monster damage is greater than zero
			if (monsterDamageTaken > 0) {
				//set health to equal itself minus the damage
				monsterHealth = monsterHealth - monsterDamageTaken;
				cout << monsterName << " took " << monsterDamageTaken << " point(s) of damage!" << endl;

				//calls monster cry
				cries.monsterCry();
			}
			// if the monster damage is not greater than zero
			else {
				cout << monsterName << " took no points of damage!" << endl;
			}

			system("pause");
			//if the monster's health reaches zero
			if (monsterHealth <= 0) {
				cout << monsterName << " has lost all of his/her/its health and no longer able to fight!" << endl;

				//calls monster cry
				cries.monsterCry();
				system("pause");
				cout << partyName << " wins the duel!" << endl;

				//set boolean variable to false
				duelRunning = false;
				system("pause");
			}
			else {
				cout << monsterName << " attacks!" << endl;

				//calls monster cry
				cries.monsterCry();
				system("pause");

				//calculate party damage
				partyDamageTaken = monsterAttack - partyDefense;

				// if party damage is greater than zero
				if (partyDamageTaken > 0) {

					//set health to equal itself minus the damage
					partyHealth = partyHealth - partyDamageTaken;
					cout << partyName << " took " << partyDamageTaken << " point(s) of damage!" << endl;

					//calls party cry
					cries.partyCry();
				}

				// if party damage is not greater than zero
				else {
					cout << partyName << " took no points of damage!" << endl;
				}
				system("pause");

				//if PM's health reaches zero
				if (partyHealth <= 0) {
					cout << partyName << " has lost all of his/her/its health and no longer able to fight!" << endl;
					system("pause");

					// calls party cry
					cries.partyCry();
					cout << monsterName << " wins the duel!" << endl;

					//set boolean variable to false
					duelRunning = false;
					system("pause");
				}
			}
		}

		// to prevent a standoff where no one is taking damage
		if (monsterAttack < partyDefense && partyAttack < monsterDefense) {
			//Tell the user that no one is taking damage
			cout << "Both " << monsterName << " and " << partyName << " are unable to defeat the other" << endl;
			cout << "It is a draw!" << endl;
			system("pause");

			//set boolean variable to false
			duelRunning = false;
		}

	} while (duelRunning);

	return 0;

}

//Allows the user to specifically change the stats of either the monster or PM stats at a certain index
void changeStats(int unitChoice, int unitIndex, gameUnit monsterArray[], gameUnit partyArray[], int monsterSize, int partySize) {

	//declare a variable initialized to the value of the index that the user chose to the value that is actually the value of the array
	int actualIndex = unitIndex - 1;

	string name;
	int attack;
	int defense;
	int speed;
	int health;
	
	cout << "Here are the original stats of the unit." << endl;

	//prints the information of the specific unit the user wants to change
	switch (unitChoice) {
	case 1:
		cout << "Name: " << monsterArray[actualIndex].GetName() << endl;
		cout << "Health: " << monsterArray[actualIndex].GetHealth() << endl;
		cout << "Attack: " << monsterArray[actualIndex].GetAttack() << endl;
		cout << "Defense: " << monsterArray[actualIndex].GetDefense() << endl;
		cout << "Speed: " << monsterArray[actualIndex].GetSpeed() << endl;
		cout << endl;
		break;
	case 2:
		cout << "Name: " << partyArray[actualIndex].GetName() << endl;
		cout << "Health: " << partyArray[actualIndex].GetHealth() << endl;
		cout << "Attack: " << partyArray[actualIndex].GetAttack() << endl;
		cout << "Defense: " << partyArray[actualIndex].GetDefense() << endl;
		cout << "Speed: " << partyArray[actualIndex].GetSpeed() << endl;
		cout << endl;
		break;
	}

	cout << "Please Enter the new stats" << endl;

	//Overwritting the original values
	switch (unitChoice) {

	//If the user enter's 1, changes a monster array index
	case 1:

		//Overwritting the monster's name at the actual index
		cout << "What is the monster's name?: ";
		cin >> name;
		monsterArray[actualIndex].SetName(name);

		//Overwritting the monster's health at the actual index
		cout << "What is the health of the monster?: ";
		cin >> health;
		monsterArray[actualIndex].SetHealth(health);

		//Overwritting the monster's attack at the actual index
		cout << "What is the attack stat of the monster?: ";
		cin >> attack;
		monsterArray[actualIndex].SetAttack(attack);

		//Overwritting the monster's defense at the actual index
		cout << "What is the defense stat of the monster?: ";
		cin >> defense;
		monsterArray[actualIndex].SetDefense(defense);

		//Overwritting the monster's speed at the actual index
		cout << "What is speed stat of the monster?: ";
		cin >> speed;
		monsterArray[actualIndex].SetSpeed(speed);
		break;

	//If the user enter's 1, changes a monster array index
	case 2:
		//Overwritting the pm's name at the actual index
		cout << "What is the party member's  name?: ";
		cin >> name;
		partyArray[actualIndex].SetName(name);

		//Overwritting the pm's health at the actual index
		cout << "What is the health of the party member?: ";
		cin >> health;
		partyArray[actualIndex].SetHealth(health);

		//Overwritting the pm's attack at the actual index
		cout << "What is the attack stat of the party member?: ";
		cin >> attack;
		partyArray[actualIndex].SetAttack(attack);

		//Overwritting the pm's defense at the actual index
		cout << "What is the defense stat of the party member?: ";
		cin >> defense;
		partyArray[actualIndex].SetDefense(defense);

		//Overwritting the pm's speed at the actual index
		cout << "What is speed stat of the party member?: ";
		cin >> speed;
		partyArray[actualIndex].SetSpeed(speed);
		break;
	}
}