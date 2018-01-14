#ifndef _STRUCTS
#define _STRUCTS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

typedef struct Position {
	float x;
	float y;
	Position(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
} Position; /* Position */

typedef struct Fonts {
	sf::Font	font;
	std::string name;
} Fonts; /* Fonts */

typedef struct Texts {
	sf::Text	text;
	std::string name;
} Texts; /* Texts */

typedef struct node {
	struct Question *q;
	node			*next;
} node; /* Node */

typedef struct musicStruct {
	std::string name;
	sf::Music	musicFile;
} musicStruct; /* musicStruct */

typedef struct Question {
	std::string	question;

	// Answers
	std::string	a1;
	std::string	a2;
	std::string	a3;
	std::string	a4;

	int		correct;
	int		difficulty;
} Question; /* Question */

#endif