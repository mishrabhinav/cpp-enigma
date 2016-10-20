#include "component.hpp"

#include <sstream>
#include <string>

// Encrypt the char for the current component.
void Component::encrypt(char& c) {
	c = CHAR(map[INT(c)]);
}
