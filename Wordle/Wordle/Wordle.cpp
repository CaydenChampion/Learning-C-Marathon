#include <string>
#include "Wordle.h"

using namespace std;

void Wordle::guess(const string& guess)
{
	guesses.push_back(guess);
}
void Wordle::display() const
{

}
bool Wordle::win() const
{
	if (guesses.empty())
	{
		return false;
	}
	return word == guesses[guesses.size() - 1];
} 