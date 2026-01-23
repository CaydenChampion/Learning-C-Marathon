#pragma once

#include <string>
#include <vector>

using namespace std;

class Wordle
{
private:
	string word;
	vector<string> guesses;

public:
	Wordle(const string& secret) : word(secret) {}
	void guess(const string& guess);
	void display() const;
	bool win() const;
}; 
