#include "plugboard.hpp"

#include <sstream>

/* 
 * Plugboard constructor.
 * Convert the plugboard config into a character map array.
 */
Plugboard::Plugboard(std::string mapping) {

	std::istringstream input(mapping);

	int number1, number2;

	for(int i = 0; i < TOTAL_LETTERS; i++) {
		map[i] = i;
	}

	while(input >> number1 >> number2) {
		map[number2] = number1;
		map[number1] = number2;
	}
}
