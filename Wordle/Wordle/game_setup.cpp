#include <iostream>
#include <string>
#include "Wordle.h"

using namespace std;

int main()
{
	cout << "Welcome to Wordle!" << endl;

	string secret = "CODING";
	Wordle w(secret);

	while (!w.win())
	{

		string guess;
		cout << "Enter a guess: ";
		cin >> guess;

		w.guess(guess);

		w.display();
	}

	cout << "Congratulations! You've guessed the word!" << endl;

	return 0;
} 