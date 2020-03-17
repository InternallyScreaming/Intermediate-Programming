/*
*Assignment_02
*
*Tiffany Wiebe
*
*Objective:	To create a program that gives the user the option to play an ASCII dice game
*and if they want to continue rolling without going to the menu.Also to go above and beyond 
*the initial guidlines of the assignment for an extra 5%.
*
*
*Algorithm:
*-Include all necessary libraries
*-Include standard namespace
*-Declare void prototype for menu function
*-Declare void prototype for rollDie function
*-Declare void prototype for surprisePartOne function
*-Declare void prototype for surprisePartTwo function
*-Declare void prototype for credits function
*-Declare void prototype for gotoYX function
*-Declare enum for menu states and set the first type to 1
*-Declare all needed variables in the main function
*-Create an infinite loop using a boolean variable set to true as a parameter
*-Call up menu
*-User inputs choice
*-Checks the user input and outputs the appropriate response
*	-If user presses 1
*		-rollDie function is called (Please refer to rollDie pseudocode later in the comments)
*		-Leave option 1
*	-If user presses 2
*		-surprisePartOne funciton is called (Please refer to surprisePartOne pseudocode later in the comments)
*		-program sleeps for 500 milliseconds
*		-surprisePartTwo funciton is called (Please refer to surprisePartTwo pseudocode later in the comments)
*		-program sleeps for 500 milliseconds (1/2 a second)
*		-These two functions are nested in a for loop that will iterate after 50 cycles
*		-The for loop is nested in a do while loop that will ask the user after the for loop if they want to repeat the animation
*		-If yes the animation will play again, if not....
*       -Leave option 2
*    -If user presses 3
*		-credits function is called (Please refer to credits pseudocode later in the comments)
*		-System pauses, user must press enter to continue
*       -Leave option 3
*    -If user presses 4
*        -Set the boolean value running the infinite loop to false which will
*         stop the infinite loop
*		 -Print out "Good Bye" to the user
*        -Leave option 4
*    -If user presses any other value
*        -Tell the user that they entered an invalid input
*        -System pauses
*        -Leave default
*-Return the value of the main function
*
**************************************************************************************************************************
*													MENU FUNCTION
**************************************************************************************************************************
*-Clear the console screen
*-Print three lines of the menu title
*-Program sleeps for 200 milliseconds
*-Print another line of text
*-Program sleeps for 200 milliseconds
*-Print out welcome line
*-Program sleeps for 200 milliseconds
*-Print out Select an option prompt line
*-Print out star line
*-Program sleeps for 200 milliseconds
*-Print out option 1 line
*-Program sleeps for 200 milliseconds
*-Print out option 2 line
*-Program sleeps for 200 milliseconds
*-Print out option 3 line
*-Program sleeps for 200 milliseconds
*-Print out option 4 line
*-Program sleeps for 200 milliseconds
*-Print out star line
**************************************************************************************************************************
*													SURPRISE PART ONE FUNCTION
**************************************************************************************************************************
*-Clear console window
*-Set x variable to ASCII number 255
*-Set o variable to ASCII number 219
*-Print 17 lines of ASCII text to make an image
**************************************************************************************************************************
*													SURPRISE PART TWO FUNCTION
**************************************************************************************************************************
*-Clear console window
*-Set x variable to ASCII number 255
*-Set o variable to ASCII number 219
*-Print 17 lines of ASCII text to make an image
**************************************************************************************************************************
*													ROLL DIE FUNCTION
**************************************************************************************************************************
*-Seed the random number generator
*-Declare all necessary variables
*-Start a do while loop
*-Clear console window
*-Start a for loop that will iterate twice
*-Randomize dice number between 1 and 6
*-Switch statement for each case of Dice faces
*-call gotofunction using offset (initially set to 0) and 1 as the arguments
*-Print out ASCII line of characters
*-call gotofunction using offset (initially set to 0) and 2 as the arguments
*-Print out ASCII line of characters
*-call gotofunction using offset (initially set to 0) and 3 as the arguments
*-Print out ASCII line of characters
*-call gotofunction using offset (initially set to 0) and 4 as the arguments
*-Print out ASCII line of characters
*-call gotofunction using offset (initially set to 0) and 5 as the arguments
*-Print out ASCII line of characters
*-call gotofunction using offset (initially set to 0) and 6 as the arguments
*-Print out ASCII line of characters
*-NOTE: ALL CASES IN THE SWITCH STATEMENT FOLLOW THIS STRUCTURE
*-Offset variable is incremented up by 10
*-For loop iterates for the second time with the new offset value to give the look of the dice right beside each other
*-After the for loop the offset variable is reset to 0
*-User is asked if they want to reroll
*-If y or Y the do while loop will iterate once more, if not the function ends
**************************************************************************************************************************
*													CREDITS FUNCTION
**************************************************************************************************************************
*-Clear console window
*-Print three lines of the credits title
*-Program sleeps for 200 milliseconds
*-Print project title line
*-Program sleeps for 200 milliseconds
*-Print created by line
*-Program sleeps for 200 milliseconds
*-Print Publish date line
*-Program sleeps for 200 milliseconds
*-Print special thanks line
*-Program sleeps for 200 milliseconds
*-Print first line of Toby Fox line
*-Program sleeps for 200 milliseconds
*-Print second line of Toby Fox line
*-Print star line
**************************************************************************************************************************
*													GOTO XY FUNCTION
**************************************************************************************************************************
*-Sets cursor to x and y coordinates
*/
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
//Plays the menu to the user
void menu(); 
//rolls two dice and asks if the user wants to play again
void rollDie();
//Frame one of the animation
void surprisePartOne();
//Frame two of the animation
void surprisePartTwo();
//plays the credits to the user
void credits();
//Provided by our wonderful and awesome professor, Chris Ziraldo
void gotoXY(int x, int y);

//Enum for the user choices in the menu
enum choices {
	Dice = 1,
	Animation,
	Credits,
	Exit
};

//MAIN FUNCTION
int main() {

	bool running = true;
	int playerChoice = 0;
	char playAgain;

	while (running) {
		menu();
		cin >> playerChoice;
		switch (playerChoice) {
		case Dice:
			rollDie();
			break;
		case Animation:
			//The dog in the animation was based on annoying dog created by Toby Fox all rights are reserved to him
			do{
				for (int i = 0; i < 50; i++) {
					surprisePartOne();
					Sleep(500);
					surprisePartTwo();
					Sleep(500);
				}
				cout << "Do you want to play the animation again? (y/n): ";
				cin >> playAgain;
			}while (playAgain == 'y' || playAgain == 'Y');
			break;
		case Credits:
			credits();
			system("pause");
			break;
		case Exit:
			running = false;
			cout << "Good Bye!" << endl;
			break;
		default:
			cout << "That is an invalid input." << endl;
            system("pause");
			break;
		}
	}
	return 0;
}
//Plays the menu to the user
void menu() {
	system("CLS");
	cout << "**************************************************************************************" << endl;
	cout << "*                                    MAIN MENU                                       *" << endl;
	cout << "**************************************************************************************" << endl;
	Sleep(200);
	cout << "*                                     WELCOME                                        *" << endl;
	Sleep(200);
	cout << "*                              PLEASE SELECT AN OPTION                               *" << endl;
	cout << "**************************************************************************************" << endl;
	Sleep(200);
	cout << "*               1)       ROLL TWO DICE                                               *" << endl;
	Sleep(200);
	cout << "*               2)       PLAY AN ANIMATION                                           *" << endl;
	Sleep(200);
	cout << "*               3)       CREDITS                                                     *" << endl;
	Sleep(200);
	cout << "*               4)       EXIT                                                        *" << endl;
	Sleep(200);
	cout << "**************************************************************************************" << endl;
}

//Frame one of the animation
void surprisePartOne() {
	system("CLS");
	char x = (char)255; //empty space
	char o = (char)219;	//white space
	
	cout << x << x << x << o << x << o << o << o << o << x << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << x << o << o << x << o << o << o << o << o << x << x << x << x << x << x << o << endl; //tail starts here
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << x << x << x << x << x << o << endl;
	//Line 5 ^^^^^
	cout << x << x << o << o << o << x << x << o << o << o << o << o << o << o << o << o << x << x << x << o << endl; //tail ends here
	cout << x << x << o << x << o << x << o << o << x << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << x << x << x << x << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	//Line 10 ^^^^^
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;//legs start here
	cout << x << x << x << o << o << x << x << o << o << x << x << x << x << o << o << x << x << o << o << endl;
	//Line 15 ^^^^^^^
	cout << x << x << x << o << x << x << x << o << o << x << x << x << x << o << o << x << x << o << endl;
	cout << x << x << x << x << x << x << x << o << x << x << x << x << x << o << endl;
}
//Frame two of the animation
void surprisePartTwo() {
	system("CLS");
	char x = (char)255; //empty space
	char o = (char)219; //white space

	cout << x << x << x << o << x << o << o << o << o << x << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << x << o << o << x << o << o << o << o << o << endl; //tail starts here
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	//Line 5 ^^^^^
	cout << x << x << o << o << o << x << x << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << x << o << x << o << o << x << o << o << o << o << o << o << o << o << o << o << o <<  o << o << o <<endl;//tail ends here
	cout << x << x << o << o << x << x << x << x << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	//Line 10 ^^^^^
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl;
	cout << x << x << x << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << o << endl; //legs start here
	cout << x << x << x << o << o << x << x << o << o << x << x << x << x << o << o << x << x << o << o << endl;
	//Line 15 ^^^^^^^
	cout << x << x << x << o << o << x << x << o <<x  << x << x << x << x << o << x << x << x << o << o << endl;
	cout << x << x << x << o << x << x << x << x << x << x << x << x << x << x << x << x << x << o << endl;
}
//rolls two dice and asks if the user wants to play again
void rollDie() {

	srand(time(NULL));

	int dieNum;
	int offset = 0;
	char playAgain;
	do {
		system("CLS");
		for (int i = 0; i < 2; i++) {
			dieNum = rand() % 6 + 1;
			switch (dieNum) {
			case 1: // Dice Face 1
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			case 2:// Dice Face 2
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			case 3:// Dice Face 3
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			case 4:// Dice Face 4
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			case 5:// Dice Face 5
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			case 6:// Dice Face 6
				gotoXY(offset, 0);
				cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
				gotoXY(offset, 1);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 2);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 3);
				cout << (char)186 << (char)255 << (char)254 << (char)255 << (char)255 << (char)255 << (char)254 << (char)255 << (char)186 << endl;
				gotoXY(offset, 4);
				cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
				break;
			}
			offset = offset + 10;
		}
		offset = 0;
		cout << "Play Again? (y/n): ";
		cin >> playAgain;
	} while (playAgain == 'y' || playAgain == 'Y');
}
//plays the credits to the user
void credits() {
		system("CLS");
		cout << "**************************************************************************************" << endl;
		cout << "*                                     CREDITS                                        *" << endl;
		cout << "**************************************************************************************" << endl;
		Sleep(200);
		cout << "*PROJECT TITLE___________________________________________________________ASSIGNMENT 2*" << endl;
		Sleep(200);
		cout << "*CREATED BY_____________________________________________________________TIFFANY WIEBE*" << endl;
		Sleep(200);
		cout << "*PUBLISH DATE______________________________________________________SEPTEMBER 26, 2017*" << endl;
		Sleep(200);
		cout << "*SPECIAL THANKS TO__________________________________________________________(char)225*" << endl;
		Sleep(200);
		cout << "        THE DOG IN THE ANIMATION WAS BASED ON ANNOYING DOG CREATED BY TOBY FOX       *" << endl;
		Sleep(200);
		cout << "                        ALL RIGHTS ARE RESERVED TO HIM                               *" << endl;
		cout << "**************************************************************************************" << endl;
}
//Provided by our wonderful and awesome professor, Chris Ziraldo
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}