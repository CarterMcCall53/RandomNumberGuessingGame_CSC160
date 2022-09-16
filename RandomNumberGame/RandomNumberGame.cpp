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
	srand(time(0));
	do
	{
		int guesses = 0;
		correctNumber = rand() % 100; 
		for (int i = 0; i < 1;)
		{
			cout << "Please Guess a number (0-100): ";
			cin >> playerGuess;
			diff = playerGuess - correctNumber;
			absDiff = abs(diff);
			if (absDiff > 50)
			{
				cout << "Frozen" << endl;
			}
			else if (absDiff > 25)
			{
				cout << "Cold" << endl;
			}
			else if (absDiff > 15)
			{
				cout << "Lukewarm" << endl;
			}
			else if (absDiff > 10)
			{
				cout << "Warm" << endl;
			}
			else if (absDiff > 5)
			{
				cout << "Hot" << endl;
			}
			else if (absDiff > 0)
			{
				cout << "Boiling" << endl;
			}
			else
			{
				guesses++;
				cout << "CORRECT! You guessed the number in " << guesses << " guesses!" << endl;
				i++;
				continue;
			}
			guesses++;
		}
		do {
			cout << "Do you want to play again? (Y|N): ";
			cin >> input;
			repChar = tolower(input[0]);
		} while (repChar != 'y' && repChar != 'n');
	} while (repChar == 'y');
}