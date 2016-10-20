#include "machine.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#define EX_CONFIG_INVALID "ERROR: Config file(s) don't exist."
#define EX_CONFIG_MISSING "ERROR: Config files not provided."

// Get raw message from stdin.
std::string get_raw_text(void);

// Get the contents of the file.
std::string get_file_content(char *);

// Get all the rotor configs.
std::vector<std::string> get_rotor_mappings(int, char**);

// Get the plugboard config.
std::string get_plugboard_mapping(int, char**);

int main(int argc, char **argv) {

	if(argc == 1) {
		throw std::invalid_argument(EX_CONFIG_MISSING);
	}

	std::vector<std::string> rotor_maps = get_rotor_mappings(argc, argv);
	std::string plugboard_map = get_plugboard_mapping(argc, argv);
	std::string input = get_raw_text();

	Enigma enigma(rotor_maps, plugboard_map);

	enigma.encrypt(input);

	std::cout << input << std::endl;

	return 0;
}

std::string get_raw_text(void) {
	std::string raw_text, line;
	while(std::cin >> line) {
		raw_text.append(line);
	}

	return raw_text;
}

std::string get_file_content(char *filename) {
	std::ifstream file(filename, std::ios::in);
	std::string input;

	if(file.good()) {
		getline(file, input);
	} else {
		throw  std::invalid_argument(EX_CONFIG_INVALID);
	}

	file.close();

	return input;
}

std::vector<std::string> get_rotor_mappings(int argc, char **argv) {
	std::vector<std::string> rotors;

	for(int i = 1; i < argc - 1; i++) {
		rotors.push_back(get_file_content(argv[i]));
	} 

	return rotors;
}

std::string get_plugboard_mapping(int argc, char **argv) {
	return get_file_content(argv[argc - 1]);
}
