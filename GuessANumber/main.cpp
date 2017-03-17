#include <iostream>
#include <random>

using namespace std;

enum class Result
{
	Correct,
	TooLow,
	TooHigh,
	InvalidInput
};

int random(int min, int max)
{
	// create generator
	random_device rng;
	mt19937 engine(rng());
	uniform_int_distribution<> distribution(min, max);

	// generate number
	return distribution(engine);
}

Result ask(int target)
{
	// ask the user for a number
	cout << "Guess the number (between 1 and 100):" << endl;
	
	// parse input
	int inputValue;
	if (cin >> inputValue)
	{
		// was the user correct?
		if (inputValue == target)
			return Result::Correct;

		// if not, describe why not
		return inputValue > target
			? Result::TooHigh
			: Result::TooLow;
	}
	else
	{
		// invalid value, flush the buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return Result::InvalidInput;
	}
}

int main(int argc, char* argv[])
{
	// pick a random number between 1 and 100
	int target = random(1, 100);

	// ask the user to guess the number
	int attempts = 1;
	Result result = ask(target);

	// keep asking the user until they guess correctly
	while (result != Result::Correct)
	{
		// display relevant message
		switch (result)
		{
		case Result::TooLow:
			cout << "Incorrect (too low)." << endl;
			break;
		case Result::TooHigh:
			cout << "Incorrect (too high)." << endl;
			break;
		case Result::InvalidInput:
			cout << "Invalid input." << endl;
			break;
		}

		// ask again
		attempts++;
		result = ask(target);
	}

	// correct
	cout << "Correct! You guessed the number in "
		<< attempts << " tries." << endl;

	// terminate after input
	cout << "Press Ctrl+C to exit." << endl;
	char c;
	cin >> c;
	return 0;
}