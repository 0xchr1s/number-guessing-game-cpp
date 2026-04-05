#include <iostream>
#include <cstdlib>
#include <ctime>


int main (){

    char input;
    srand(time(0));         // initialize random number generator 
    


std::cout << "RULES: " << "\n\n" 
          << "- Guess a number in the given range" <<  "\n" 
          << "- You will get hints (higher/lower)" <<  "\n" 
          << "- You have a maximum of 5 attempts\n\n" <<

"Press ENTER to start: \n";
std::cin.get();             // when ENTER is pressed -> program continues

do {
    int number{0};
    int tries = 0; 
    int difficulty; 
    int max;
    int min;
    

do {
std::cout << "\n" 
          << "Choose your difficulty level:" << "\n\n" 
          << "[1] Easy: 1-10" << "\n" 
          << "[2] Medium: 1-50" << "\n" 
          << "[3] Hard: 1-100" << "\n\n";

std::cin >> difficulty;

} while (difficulty < 1 || difficulty > 3);

// set maximum and minimum of a specific difficulty level
if (difficulty == 1) {
    max = 10;
    min = 1;
}
else if (difficulty == 2){ 
    max = 50; 
    min = 1;
}
else if(difficulty == 3) {
    max = 100; 
    min = 1;
}

int secret = rand() % max + 1;          // calculation of difficulty areas 

while (number != secret) {

    if (difficulty == 1){
    std::cout << "Enter a number between 1-10: \n";
    }
    else if(difficulty == 2){
    std::cout << "Enter a number between 1-50: \n";
}
    else if(difficulty == 3){
    std::cout << "Enter a number between 1-100: \n";
    }

    std::cin >> number;
    ++tries;
    std::cout << "Attempt: " << tries << "\n";

    // after 5 tries the game is over 
 if(tries >= 5) {
    std::cout << "\n        GAME LOST \n";
    std::cout << "\n-------------------------\n";
    break;
    }

    // check if input is within range
if (number < min || number > max){
    std::cout << "The number is NOT within the specified range. \n";
    continue;               // program returns to the loop. 

}
if (number < secret){
    std::cout << "The correct number is higher than " << number << "\n";
}
else if (number > secret){
    std::cout << "The correct number is lower than " << number << "\n";  
}

}
 if (tries < 5){
    std::cout << "\n        GAME WON \n";

    std::cout << "\n-------------------------\n";
 } 
 

 // If the number is guessed correctly
if (number == secret){
    std::cout << "\nYou guessed correctly, the number was " << secret << "\n";
    std::cout << "Number of attempts required: " << tries << "\n";
}
    std::cout << "\nDo you want to play the game again?  (y/n) \n";
    std::cin >> input;

 // decision whether the program should be played again
}while (input == 'y' || input == 'Y');
std::cout << "THE GAME IS OVER";


   return 0; 
}
