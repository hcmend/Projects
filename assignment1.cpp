/******************************************************
** Program: hooping.cpp
** Author: Hailey Mendenhall
** Date: 1/28/2024
** Description: This code is a simulation of a basketball shooting contest. It is a two player game where each player has five racks of five balls each to try and make. 
** Input: Moneyball Rack, Shooting Ability, If They Want to PLay Again
** Output: Rack Scores, Total Scores, Winner
******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// This get_input function is where I receive user input and store them in variables to be used later. 
void get_input(int *ability, int *mbrack){ // since these are pointers, I can directly influence the variables from this function. 
    do {
        cout << "Please enter the rack you would like to be your moneyball rack in the form of an integer from 1-5: ";
        cin >> *mbrack; // this cout and cin statement gets their answer for what rack should be all moneyballs and stores it in mbrack.
        if (*mbrack < 1 || *mbrack > 5){ 
            cout << "Sorry, that is not a valid input." << endl;
        }       
    }while( *mbrack < 1 || *mbrack > 5); // error handling
    do {
        cout << "Please enter your shooting ability as an integer from 1-99: ";
        cin >> *ability;  // this cout and cin takes their shooting ability and puts it in ability. 
        if (*ability < 1 || *ability > 99){
            cout << "Sorry, that is not a valid input." << endl;
        }
        cout << endl;      
    } while(*ability < 1 || *ability > 99); // error handling
}

// This function create_array is where I make the array of missed and made shots.
void create_array(int a [5][5], int ability, int mbrack){   
    srand(time(NULL)); 
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (rand() % 100 + 1  <= ability){ // compares a random number from 1-100 to the user's inputted shooting ability. if ability is greater than random they made shot. if not, they missed it. 
                if (i+1 == mbrack || j == 4){ // checking if it was a moneyball or not
                    a[i][j] = 2;                 
                }else{
                    a[i][j] = 1;
                }
            }else{
                a[i][j] = 0;
            }
        }                            
    }
}

// this function print_out outputs the results of each shot as well as the total for each rack.
void print_out(int array [5][5]){
    int rack_score;
    for (int h = 0; h < 5; h++){  
        cout << "Rack " << h << ": "; 
        rack_score = 0;
        for (int i = 0; i < 5; i++){
            if (array[h][i] == 2){
                rack_score += 2;
                cout << "M ";
            } else if (array[h][i] == 1){
                rack_score += 1;
                cout << "O ";
            } else {
                rack_score += 0;
                cout << "X ";
            }
        }
        cout << " | " << rack_score << " pts" << endl;
    }
}

//this function calucate-score outputs the final score of a player's shooting. 
int calculate_score(int array[5][5]){
    int total_score = 0;
    for (int h = 0; h < 5; h++){ // runs through every rack
        for (int i = 0; i < 5; i++){ // runs through each shot on that rack
            total_score += array[h][i]; 
        }          
    }
    cout << "The total score is: " << total_score << endl << endl;
    return total_score;
}

//this function compares the final scores of each player and says who won the game. 
void declare_winner(int score1, int score2){
    if (score1 > score2){
        cout << "Player 1 is the winner!" << endl;
    }else if (score1 < score2){
        cout << "PLayer 2 is the winner!" << endl;
    }else{
        cout << "There was a tie!" << endl;
    }
}

// this function player_1 calls all other functions for the first player, letting them play the game.
int player_1(int *ability, int *mbrack){
    cout << "Player 1: " << endl;
    get_input (ability, mbrack);
    int array [5][5];
    create_array(array, *ability, *mbrack);
    print_out(array);
    return calculate_score(array);    
}

// this function lets player 2 go through the game. The only difference is it stores their final score in a different space than the first player. 
int player_2(int *ability, int *mbrack){
    cout << "Player 2: " << endl;
    get_input (ability, mbrack);
    int array [5][5];
    create_array(array, *ability, *mbrack);
    print_out(array);
    return calculate_score(array);
}

// mains function in this program is to initialize variables, call player functions, and let user play again if they want
int main(){
    int again = 0;
    do{
        int mbrack = 0; int ability = 0;         
        cout << "Welcome to the basketball shooting simulation! In this game you will have five racks with five balls each. The last ball of each rack is a moneyball which earns you two points. You also get to select a rack that is all moneyballs. Good luck and have fun!" << endl << endl;
        int score1 = player_1(&ability, &mbrack);
        int score2 = player_2(&ability, &mbrack);
        declare_winner(score1, score2);
        cout << "Would you like to play again? Please enter 1 if you do. Otherwise enter anything else: ";  
        cin >> again;
    } while (again == 1);
    return 0;    
}