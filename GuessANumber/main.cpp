#include <iostream>
#include <random>

int random(int min, int max) {
	// create generator
	std::random_device rng;
	std::mt19937 engine(rng());
	std::uniform_int_distribution<> distribution(min, max);

	// generate number
	return distribution(engine);
}

int main(int argc, char* argv[]) {
	
	// pick a random number between 1 and 100
	int target = random(1, 100);
	std::cout << target << std::endl;

	// terminate after ENTER key press
	std::cout << "Press ENTER to exit...";
	std::cin.ignore();
}