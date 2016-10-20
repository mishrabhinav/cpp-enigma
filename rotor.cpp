#include "rotor.hpp"

#include <sstream>

/* 
 * Rotor constructor.
 * Convert the rotor configs into a character map array.
 */
Rotor::Rotor(std::string mapping) {
	std::istringstream input(mapping);
	offset = 0;

	int number, i = 0;

	while(input >> number) {
		map[i] = number;
		reverse_map[number] = i;	
		i++;
	}
}

// Encrypt the char for the current rotor.
void Rotor::encrypt(char &c) {
	c = SHIFT_CHAR(map[SHIFT_INT(c)]);
}

// Encrypt the char after hitting reflector.
void Rotor::reverse_encrypt(char &c) {
	c = SHIFT_CHAR(reverse_map[SHIFT_INT(c)]);
}

// Rotate the rotor.
bool Rotor::rotate(void) {
	offset = (offset + 1) % TOTAL_LETTERS;
	return !offset;
}
