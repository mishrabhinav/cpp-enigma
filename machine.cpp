#include "machine.hpp"

#include <stdexcept>

/* 
 * Constructor for Enigma Machine.
 * r_map  -> rotor configs
 * pb_map -> plugboard config
 */
Enigma::Enigma(std::vector<std::string> r_map, std::string pb_map)
	:plugboard(pb_map),reflector() {
		std::vector<std::string>::iterator rotor;

		for(rotor = r_map.begin(); rotor != r_map.end(); rotor++) {
			Rotor r(*rotor);
			rotors.push_back(r);
		}
}

/*
 * Encrypt the message provided.
 * Iterate over all the characters, if valid then
 * encrypt it else throw an error.
 */
void Enigma::encrypt(std::string &message) {
	int message_len = message.length();

	for(int i = 0; i < message_len; i++) {
		if(VALID_CHAR(message[i])) {
			encrypt_char(message[i]);
		} else {
			throw std::invalid_argument(EX_INVALID_CHAR);
		}
	}
}

/*
 * Encrypt the provided character.
 * Route for encryption:
 * 1. Plugboard
 * 2. Rotors
 * 3. Reflector
 * 4. Rotors
 * 5. Plugboard
 * Rotate the rotors after this.
 */
void Enigma::encrypt_char(char &c) {
	plugboard.encrypt(c);

	std::vector<Rotor>::iterator rotor;
	for(rotor = rotors.begin(); rotor != rotors.end(); rotor++) {
		rotor->encrypt(c);
	}

	reflector.encrypt(c);

	std::vector<Rotor>::reverse_iterator rrotor;
	for(rrotor = rotors.rbegin(); rrotor != rotors.rend();
							rrotor++) {
		rrotor->reverse_encrypt(c);
	}

	plugboard.encrypt(c);

	rotate();
}

/*
 * Rotate the rotors.
 * If the current rotor has reached the notch,
 * rotate the next rotors.
 */
void Enigma::rotate(void) {
	bool rotate_it = true;
	bool rotate_next = false;

	std::vector<Rotor>::iterator rotor;
	for(rotor = rotors.begin(); rotor != rotors.end(); rotor++) {
		if(rotate_next)
			rotate_next = rotor->rotate();

		if(rotate_it) {
			rotate_next = rotor->rotate();
			rotate_it = false;
		}
	}
}
