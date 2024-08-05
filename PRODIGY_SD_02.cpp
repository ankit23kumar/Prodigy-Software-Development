/*  Coder : Ankit Kumar 
 Task 2 - Build a c++ user driven program of Number Guessing Game . 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "Guess the Number Game\n";
    cout << "I have generated a random number between 1 and 100.\n";
    cout << "Try to guess it!\n";

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the correct number: " << randomNumber << endl;
            cout << "It took you " << attempts << " attempts to guess the number.\n";
        }
    }

    return 0;
}
