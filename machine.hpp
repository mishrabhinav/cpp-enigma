#ifndef MACHINE_HPP
#define MACHINE_HPP

#include "rotor.hpp"
#include "plugboard.hpp"
#include "reflector.hpp"

#include <vector>
#include <string>

#define EX_INVALID_CHAR "ERROR: Invalid char entered."

class Enigma {
		std::vector<Rotor> rotors;
		Plugboard plugboard;
		Reflector reflector;

		void rotate(void);
	public:
		Enigma(std::vector<std::string>, std::string);	
		void encrypt(std::string&);
		void encrypt_char(char&);
};

#endif
