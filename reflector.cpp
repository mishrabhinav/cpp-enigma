#include "reflector.hpp"

/*
 * Reflector constructor.
 * Generate the static reflector char map array.
 */
Reflector::Reflector() {
	for(int i = 0; i < TOTAL_LETTERS; i++) {
		map[i] = (i + TOTAL_LETTERS/2) % TOTAL_LETTERS;
	}
}
