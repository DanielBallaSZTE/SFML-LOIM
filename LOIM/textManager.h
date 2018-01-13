#ifndef _FONTMANAGER
#define _FONTMANAGER

#include <SFML/Graphics.hpp>
#include <iostream>

#define MAX_FONTS 1
#define MAX_TEXTS 5

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
	Fonts		*fonts[MAX_FONTS];
	Texts		*texts[MAX_TEXTS];

public:
	TextManager();
	~TextManager();
	sf::Font	getFont(std::string name);
	void		displayText(sf::RenderWindow window, std::string name);
	void		setTextFont(sf::Font, std::string name);
};

#endif
