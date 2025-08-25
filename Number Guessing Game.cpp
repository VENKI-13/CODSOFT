#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;  // Random number between 1 and 100
    int guess, attempts = 0;

    cout << "\n===============================" << endl;
    cout << " Welcome to the Guessing Game!" << endl;
    cout << " I've chosen a secret number between 1 and 100." << endl;
    cout << " Can you crack the code?" << endl;
    cout << "===============================\n" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try a smaller number." << endl;
        } else if (guess < number) {
            cout << "Too low! Try a bigger number." << endl;
        } else {
            cout << "\n BOOM! You nailed it in " << attempts << " tries! " << endl;
            if (attempts <= 3)
                cout << "Wow! You're a mind reader!" << endl;
            else if (attempts <= 7)
                cout << "Good job, solid guessing!" << endl;
            else
                cout << "That was tough, but you made it!" << endl;
        }

    } while (guess != number);

    cout << "\nThanks for playing!" << endl;
    cout << "===============================" << endl;

    return 0;
}
