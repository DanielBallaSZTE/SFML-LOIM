#ifndef _FONTMANAGER
#define _FONTMANAGER

#include <SFML/Graphics.hpp>
#include <iostream>
#include "structs.h"

#define MAX_FONTS 1
#define MAX_TEXTS 5

class TextManager {

private:
	int			totalFonts;
	int			totalTexts;

public:
	Fonts		*fonts[MAX_FONTS];
	Texts		*texts[MAX_TEXTS];
	TextManager();
	~TextManager();
	int			getFontId(std::string name);
	int			getTextId(std::string name);
	void		setTextFont(sf::Font font, std::string name);
	void		loadFont(std::string filename, std::string name);
	void		loadAllFonts();
	void		createText(std::string text, std::string name);
	void		setTextSize(std::string name, int size);
	void		setTextColor(std::string name, sf::Color color);
	void		setTextPosition(std::string name, Position *pos);
};

#endif
