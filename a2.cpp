#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Include <limits> for std::numeric_limits

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int secretNumber = rand() % 5 + 1; // Generate a random number between 1 and 5

    std::cout << "Welcome to the guessing game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 5." << std::endl;

    int userGuess;
    while (true) {
        std::cout << "Guess a number: ";
        if (!(std::cin >> userGuess)) { // Check if input is valid
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input up to newline
            continue;
        }

        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    return 0;
}
