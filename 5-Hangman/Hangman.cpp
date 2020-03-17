/*
Tiffany Wiebe
101005848
Objective: Using in and out streams, create hangman.
*/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

void menu();																										//Game Menu
void rules();																										//Print out the rules
void printGallows();																								//Prints the gallows to the console
void createDictionary(vector<string> &WordBank);																	//Opens Dictionary file, imports it into a string vector, then closes it
void clearPartOfScreen();																							//Clears a portion of the screen
void printResults(int attempts, int incorrectGuesses, vector<string> wordBank, int generate);						//Prints the results to a separate .txt file
void credits();																										//Game's Credits
void gotoXY(int x, int y);																							//Go to "these" coordinates

bool charCheck(vector<string> &WordBank, int generate, char playerChoice);											//Checks if the user's input is in a word 
bool lowerCase(char playerChoice);																					//Checks if the user's input is a lowercase letter
bool alreadyChosen(vector<char> prevChoices, char playerChoice);													//Checks if the user's input has already been chosen
bool didUserWin(vector<string> Wordbank, int generate, vector<string> activeWord);									//Checks if the user has won the game


int main() {

	int X = 70;
	int Y = 1;

	
	int menuOption;
	int chosenWord;
	int wrongs = 0;
	int tries = 0;
	char playerChoice;
	char goBack;
	bool running = true;

	vector<string> wordbank;
	vector<char> choiceHistory;
	vector<string> activeWord;

	srand(time(NULL));

	do {
		menu();
		do {
			gotoXY(15, 15);
			cout << "Please Choose An Option: ";
			cin >> menuOption;
		} while (menuOption != 1 && menuOption != 2 && menuOption != 3);

		system("CLS");

		switch (menuOption) {
		case 1:

			createDictionary(wordbank);
			chosenWord = rand() % wordbank.size();

			for (int i = 0; i < wordbank[chosenWord].length(); i++) {
				activeWord.push_back("-");
			}

			//prints the placeholder for the player
			gotoXY(40, 13);
			cout << "This is your word: ";
			for (int i = 0; i < wordbank[chosenWord].length(); i++) {
				cout << activeWord[i];
			}

			gotoXY(X, 0);
			cout << "Chosen Letters" << endl;

			//print the gallows to the screen
			printGallows();


			while (running) {

				//Ensures that the player inputs a letter that they haven't used before and is a lowercase letter
				do {
					gotoXY(0, 13);
					cout << "Please Enter A Lowercase Letter" << endl;
					cin >> playerChoice;

					if (!lowerCase(playerChoice)) {
						cout << "That was not a lowercase letter." << endl;
						clearPartOfScreen();
					}
					if (alreadyChosen(choiceHistory, playerChoice)) {
						cout << "You already chose that." << endl;
						clearPartOfScreen();
					}
				} while (!lowerCase(playerChoice) || alreadyChosen(choiceHistory, playerChoice));

				//push in the player input
				choiceHistory.push_back(playerChoice);

				//print out chosen letters 
				tries++;
				gotoXY(X, Y);
				cout << choiceHistory[tries - 1];
				X += 2;
				if (tries % 5 == 0) {
					X = 70;
					Y++;
				}

				/*if the user has inputed a letter that was not in the word, increment the wrong guesses counter and print out the corresponding body part to the console
				if the user gets 6 wrong guesses, they lose.  Print out the results of the game and set the infinite loop variable to false*/
				if (!charCheck(wordbank, chosenWord, playerChoice)) {
					gotoXY(0, 15);
					cout << "Wrong" << endl;
					wrongs++;

					switch (wrongs) {
					case 1:
						gotoXY(59, 2);
						cout << "O";
						break;
					case 2:
						gotoXY(59, 3);
						cout << "|";
						break;
					case 3:
						gotoXY(58, 4);
						cout << "/";
						break;
					case 4:
						gotoXY(60, 4);
						cout << "\\";
						break;
					case 5:
						gotoXY(58, 3);
						cout << "/";
						break;
					case 6:
						gotoXY(60, 3);
						cout << "\\";

						gotoXY(65, 0);
						//cout << "Well, you killed him. I hope you are happy";
						printResults(tries, wrongs, wordbank, chosenWord);
						system("results.txt");
						running = false;
						break;
					}
					clearPartOfScreen();
					
				}

				//if user has inputed a letter that is in the word, indicate that they were correct and set the indexes in the active word vector (where the inputed letter is equal to) to the player's inputed letter
				if (charCheck(wordbank, chosenWord, playerChoice)) {
					gotoXY(0, 15);
					cout << "Correct" << endl;
					for (int i = 0; i < wordbank[chosenWord].length(); i++) {
						if (wordbank[chosenWord][i] == playerChoice) {
							activeWord[i] = wordbank[chosenWord][i];
						}
					}

					gotoXY(59, 13);
					for (int i = 0; i < wordbank[chosenWord].length(); i++) {
						cout << activeWord[i];
					}
				}

				clearPartOfScreen();

				//If user has won the game, print results to .txt file and set the infinite loop variable to false
				if (didUserWin(wordbank, chosenWord, activeWord)) {
					gotoXY(65, 0);
					printResults(tries, wrongs, wordbank, chosenWord);
					system("results.txt");
					running = false;
				}

				
			}
			break;
		case 2:
			rules();
			break;
		case 3:
			credits();
			break;
		case 4:
			return 0;
			break;
		}

		//Ask the user if they want to return to the main menu
		do {
			gotoXY(33, 21);
			cout << "Would you like to go back to the menu? (y/n): ";
			cin >> goBack;

			if (goBack != 'y' && goBack != 'Y' && goBack != 'n' && goBack != 'N') {
				gotoXY(33, 22);
				cout << "Please choose a valid input" << endl;
			}

		} while (goBack != 'y' && goBack != 'Y' && goBack != 'n' && goBack != 'N');

	}while (goBack == 'y' || goBack == 'Y');

	return 0;
}

void menu() {
	int X = 15;
	int Y = 0;

	system("CLS");

	gotoXY(X, Y);
	cout << (char)201;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;

	for (int i = 0; i < 3; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		if (i == 1) {
			for (int j = 0; j < 35; j++) {
				cout << (char)255;
			}

			cout << "WELCOME TO HANGMAN!!!";

			for (int j = 0; j < 34; j++) {
				cout << (char)255;
			}
		}
		else {
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
		}
			cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)204;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)185 << endl;

	for (int i = 0; i < 9; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		switch (i) {
		case 1:
			for (int j = 0; j < 35; j++) {
				cout << (char)255;
			}
			cout << "1 - Play Game";
			for (int j = 0; j < 42; j++) {
				cout << (char)255;
			}
			break;
		case 3:
			for (int j = 0; j < 35; j++) {
				cout << (char)255;
			}
			cout << "2 - How to Play";
			for (int j = 0; j < 40; j++) {
				cout << (char)255;
			}
			break;
		case 5:
			for (int j = 0; j < 35; j++) {
				cout << (char)255;
			}
			cout << "3 - Credits";
			for (int j = 0; j < 44; j++) {
				cout << (char)255;
			}
			break;
		case 7:
			for (int j = 0; j < 35; j++) {
				cout << (char)255;
			}
			cout << "4 - Exit";
			for (int j = 0; j < 47; j++) {
				cout << (char)255;
			}
			break;
		default:
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
			break;
		}
		cout << (char)186 << endl;

	}

	gotoXY(X, ++Y);
	cout << (char)200;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)188 << endl;
}
void rules() {
	int X = 15;
	int Y = 0;

	system("CLS");

	gotoXY(X, Y);
	cout << (char)201;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;

	for (int i = 0; i < 3; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		if (i == 1) {
			for (int j = 0; j < 37; j++) {
				cout << (char)255;
			}

			cout << "How to Play";

			for (int j = 0; j < 42; j++) {
				cout << (char)255;
			}
		}
		else {
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
		}
		cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)204;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)185 << endl;

	for (int i = 0; i < 15; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		switch (i) {
		case 1:
			cout << " 1) At the start of the game, you will be given a word that looks like this -> ---------  ";
			break;
		case 3:
			cout << " 2) Each hyphen represents a letter";
			for (int j = 0; j < 55; j++) {
				cout << (char)255;
			}
			break;
		case 5:
			cout << " 3) You will be prompted to enter a lowercase letter. You will only continue when you do  ";
			break;
		case 7:
			cout << " 4) Your choices will be printed to the right of the screen";
			for (int j = 0; j < 31; j++) {
				cout << (char)255;
			}
			break;
		case 9:
			cout << " 5) You are allowed 6 wrong guesses to guess your word";
			for (int j = 0; j < 36; j++) {
				cout << (char)255;
			}
			break;
		case 11:
			cout << " 6) After you win or lose, your results will open up in Notepad";
			for (int j = 0; j < 27; j++) {
				cout << (char)255;
			}
			break;
		case 13:
			cout << " 7) Close Notepad, you will be asked to go to the main menu";
			for (int j = 0; j < 31; j++) {
				cout << (char)255;
			}
			break;
		default:
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
			break;
		}
		cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)200;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)188 << endl;
}
void printGallows() {
	int X = 50;
	int Y = 0;

	gotoXY(X, Y);
	cout << (char)201;
	for (int i = 0; i < 8; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;

	gotoXY(X, ++Y);
	cout << (char)186;
	for (int i = 0; i < 8; i++) {
		cout << (char)255;
	}
	cout << (char)208 << endl;

	for (int i = 0; i < 8; i++) {
		gotoXY(X, ++Y);
		cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)204;
	for (int i = 0; i < 8; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;

	gotoXY(X, ++Y);
	cout << (char)208;
	for (int i = 0; i < 8; i++) {
		cout << (char)255;
	}
	cout << (char)208 << endl;
}
void createDictionary(vector<string> &WordBank) {
	ifstream Dictionary;
	string word;

	Dictionary.open("10000CommonMediumWords.txt");
	if (!Dictionary.fail()) {
		while (!Dictionary.eof()) {
			getline(Dictionary, word);
			WordBank.push_back(word);
		}
		Dictionary.close();
	}
}
void clearPartOfScreen() {
	Sleep(400);
	gotoXY(0, 13);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 33; j++) {
			cout << (char)255;
		}
		cout << endl;
	}
	gotoXY(0, 13);
}
void printResults(int attempts, int incorrectGuesses, vector<string> wordBank, int generate) {
	ofstream Results;
	Results.open("results.txt");
	Results << "------------------------------------------------------------------------\n";
	if (incorrectGuesses == 6) {
		Results << "You Lost \n";
		Results << "Better Luck Next Time \n";
	}
	else {
		Results << "Congratulations\n";
		Results << "You Won!\n";
	}
	Results << "------------------------------------------------------------------------\n";
	Results << "Your Word:           " << wordBank[generate] << endl;
	Results << "Guesses:             " << attempts << endl;
	Results << "Incorrect Guesses:   " << incorrectGuesses << endl;
	Results << "------------------------------------------------------------------------\n";
	Results.close();
}
void credits() {
	int X = 15;
	int Y = 0;

	system("CLS");

	gotoXY(X, Y);
	cout << (char)201;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)187 << endl;

	for (int i = 0; i < 3; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		if (i == 1) {
			for (int j = 0; j < 40; j++) {
				cout << (char)255;
			}

			cout << "Credits";

			for (int j = 0; j < 43; j++) {
				cout << (char)255;
			}
		}
		else {
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
		}
		cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)204;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)185 << endl;

	for (int i = 0; i < 3; i++) {
		gotoXY(X, ++Y);
		cout << (char)186;

		if (i == 1) {
			cout << "     Made By";

			for (int j = 0; j < 60; j++) {
				cout << ".";
			}

			cout << "Tiffany Wiebe     ";
		}
		else {
			for (int j = 0; j < 90; j++) {
				cout << (char)255;
			}
		}
		cout << (char)186 << endl;
	}

	gotoXY(X, ++Y);
	cout << (char)200;
	for (int i = 0; i < 90; i++) {
		cout << (char)205;
	}
	cout << (char)188 << endl;
}
void gotoXY(int x, int y){
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = false;
	cursorInfo.dwSize = 10;
	SetConsoleCursorInfo(hStdout, &cursorInfo);
}

bool charCheck(vector<string> &WordBank, int generate, char playerChoice) {
	for (int i = 0; i < WordBank[generate].length(); i++) {
		if (WordBank[generate][i] == playerChoice) {
			return true;
		}
	}
	return false;
}
bool lowerCase(char playerChoice) {
	int lowerCase = 97;
	int lowChar;

	for (int i = 0; i < 26; i++) {
		lowChar = (char)lowerCase;
		if (playerChoice == lowChar) {
			return true;
		}
		lowerCase++;
	}

	return false;
}
bool alreadyChosen(vector<char> prevChoices, char playerChoice) {
	for (int i = 0; i < prevChoices.size(); i++) {
		if (playerChoice == prevChoices[i]) {
			return true;
		}
	}
	return false;
}
bool didUserWin(vector<string> Wordbank, int generate, vector<string> activeWord) {
	for (int i = 0; i < Wordbank[generate].length(); i++) {
		if (activeWord[i][0] != Wordbank[generate][i]) {
			return false;
		}
	}
	return true;
}


