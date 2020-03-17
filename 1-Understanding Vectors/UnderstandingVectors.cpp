/*
*Assignment_01
*
*Tiffany Wiebe
*
*Objective: To use a vector to allow for the user to store player scores,
*to print the entered scores to the console, and to find the greatest value.
*
*
*Algorithm:
*-Include libraries for the input/out and vectors and pre-programmed vector functions
*-Include standard namespace
*-Declare an integer function prototype called GameScore
*-Declare needed variables in the main
*-Create an integer vector called playerScore
*-Call the GameScore function in the main
*-Create an infinite loop using a boolean variable set to true as a parameter
*-Print the instructions to the user
*-User inputs the option
*-Checks the user input and outputs the appropriate response
*    -If user presses 1
*        -Instruct user to input score
*        -User inputs score
*        -Push back the vector to include the score value
*        -Leave option 1
*    -If user presses 2
*        -Create a for loop that will end when the iterator is less than the 
*         size of the vector playerScore
*        -Print the number in the vector at index i
*        -Leave option 2
*    -If user presses 3
*        -Create a for loop that will end when the iterator is less or equal to the 
*         size of the vector playerScore
*        -Logic statement with the condition that if max (initially set to 0) is
*         less than the value of the playerScore, the max variable is now assigned
*         the value of playerScore at index i
*        -Print the highscore to the user
*        -Set max back to zero 
*        -Leave option 3
*    -If user presses 4
*        -Set the boolean value running the infinite loop to false which will
*         stop the infinite loop
*        -Leave option 4
*    -If user presses any other value
*        -Tell the user that they entered an invalid input
*        -Leave default
*-Return the value of the main function
*
*GameScore function:
*-Declare a variable to hold the number of players
*-Asks the user how many players there are
*-User inputs number of players
*-Return the value that the user entered for the amount of players
*
*/

//All libraries necessary for the program
#include <iostream>
#include <vector>

using namespace std;

//Asks the user how many players there are
int GameScore();

int main(){
    
    int option;             //Holds the option the user chooses
    int score;              //Holds the score the user enters
    int max = 0;            //Holds the initial value to test for the max number in the vector
    bool running = true;    //A boolean value to run an infinite loop but also allow to be easily switched
    
    //Using a vector to dynamically hold all the values the user wishes to enter
    vector<int> playerScore;
    
    //calling up the game score function
    GameScore();
    
    //An infinite to constantly ask the user what option they want to execute
    while(running){
        cout << endl <<"Please enter number for the option you wish to use." << endl;
        cout <<"1: Enter a new player score" << endl;
        cout <<"2: See the full list of entered score" << endl;
        cout <<"3: Show the high score" << endl;
        cout <<"4: Exit" << endl;
        cin >> option;
        cout << endl;
        switch(option){
            case 1: //Enter a player score
            cout << "Please enter the score: ";
            cin >> score;
            playerScore.push_back(score);
            break;
            case 2: //Print all player scores
            cout << "Here are the scores so far \n";
            for (int i = 0; i <  playerScore.size(); i++){
                cout << playerScore[i] << endl;
            }
            break;
            case 3: //Find and print the highscore
            for (int i = 0; i <=playerScore.size(); i++){
                if(max < playerScore[i]){
                    max = playerScore[i];
                }
            }
            cout << "The high score is: "<< max << endl;
            max = 0;
            break;
            case 4: //Exit the program
            running = false;
            break;
            default: cout << "That is an invalid input \n";
            break;
        }
    }
    return 0;
}
//Asks the user how many players there are
//User inputs number of players
int GameScore(){
    int players = 0;
    cout << "Welcome \n";
    cout << "Please enter the number of players: ";
    cin >> players;
    return players;
}
