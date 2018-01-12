#ifndef _FONTMANAGER
#define _FONTMANAGER

#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_FONTS

typedef struct Fonts {
	sf::Font	font;
	std::string name;
} Fonts;

typedef struct Texts {
	sf::Text	text;
	std::string name;
} Texts;

class TextManager {

private:
	Fonts		*fonts[1];
	Texts		*texts[5];

public:
	sf::Font	getFont(std::string name);
	void		displayText(sf::RenderWindow window, std::string name);
	void		setTextFont(sf::Font, std::string name);


};

#endif
