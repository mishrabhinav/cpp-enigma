#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "component.hpp"

#include <string>

#define SHIFT_INT(c)	((INT(c) + offset) % TOTAL_LETTERS)
#define SHIFT_CHAR(i)	CHAR((i - offset + TOTAL_LETTERS) % TOTAL_LETTERS)

class Rotor: public Component {
		int reverse_map[TOTAL_LETTERS];
		int offset;
	public:
		Rotor(std::string);
		void encrypt(char&);
		void reverse_encrypt(char&);
		bool rotate(void);
};

#endif
