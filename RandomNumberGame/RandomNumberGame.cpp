/* RandomNumberGame
*  Carter McCall
*  14 September 2022
*  Purpose:
*		Create a random number guessing game
*  Modified 15 September 2022:
*		Added guesses counter
*/

#include <iostream>
using namespace std;

int main() {
	string input;
	char repChar;
	int correctNumber, playerGuess, diff, absDiff;
	bool badInput, cont = false;
	srand(time(0));
	do
	{
		int guesses = 0;
		correctNumber = rand() % 100; 
		badInput = true;
		do {
			do {
				try {
					cout << "Please Guess any integer (1-100): ";
					cin >> playerGuess;
					if (cin.fail()) throw runtime_error("Must type an integer between 1 & 100");
					else if (playerGuess < 1 || playerGuess > 100) throw runtime_error("Must type an integer between 1 & 100");
					else badInput = false;
				}
				catch (exception e) {
					system("cls");
					cout << e.what() << endl;
					cin.clear();
					cin.ignore();
				}
			} while (badInput == true);
			diff = playerGuess - correctNumber;
			absDiff = abs(diff);
			system("cls");
			if (absDiff > 50)
			{
				cout << "Frozen" << endl;
				guesses++;
			}
			else if (absDiff > 25)
			{
				cout << "Cold" << endl;
				guesses++;
			}
			else if (absDiff > 15)
			{
				cout << "Lukewarm" << endl;
				guesses++;
			}
			else if (absDiff > 10)
			{
				cout << "Warm" << endl;
				guesses++;
			}
			else if (absDiff > 5)
			{
				cout << "Hot" << endl;
				guesses++;
			}
			else if (absDiff > 0)
			{
				cout << "Boiling" << endl;
				guesses++;
			}
			else
			{
				system("cls");
				guesses++;
				cout << "CORRECT! You guessed the number in " << guesses << " guesses!" << endl;
				cont = true;
			}
		} while (cont == false);
		do {
			cout << "Do you want to play again? (Y|N): ";
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}