#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#define TOTAL_LETTERS	26
#define VALID_CHAR(c)	(c >= 'A' && c <= 'Z')
#define CHAR(i)		(i + 'A')
#define INT(c)		(c - 'A')

class Component {
	protected:
		int map[TOTAL_LETTERS];
	public:
		virtual void encrypt(char&);
};

#endif
