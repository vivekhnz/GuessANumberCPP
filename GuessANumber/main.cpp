#include <iostream>
#include <random>

using namespace std;

int random(int min, int max) {
	// create generator
	random_device rng;
	mt19937 engine(rng());
	uniform_int_distribution<> distribution(min, max);

	// generate number
	return distribution(engine);
}

bool ask(int target)
{
	// ask the user for a number
	cout << "Guess the number (between 1 and 100):" << endl;
	int inputValue;
	if (cin >> inputValue) {
		return inputValue == target;
	}
	else {
		// invalid value, flush the buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input." << endl;
		return false;
	}
}

int main(int argc, char* argv[]) {
	
	// pick a random number between 1 and 100
	int target = random(1, 100);

	// ask the user to guess the number
	if (ask(target))
	{
		// correct
		cout << "Correct!" << endl;
	}
	else
	{
		// incorrect
		cout << "Incorrect. The correct answer was "
			<< target << "." << endl;
	}

	// terminate after input
	cout << "Press Ctrl+C to exit." << endl;
	char c;
	cin >> c;
	return 0;
}