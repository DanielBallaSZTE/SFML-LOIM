#include "textManager.h"


/**
 * TextManager constructor.
 * Allocates all structures.
 */
TextManager::TextManager()
{
	for (int i = 0; i < MAX_FONTS; i++)
	{
		fonts[i] = new Fonts;
	}
	for (int i = 0; i < MAX_TEXTS; i++)
	{
		texts[i] = new Texts;
	}

	totalFonts = 0;
	totalTexts = 0;
	loadAllFonts();
} /* TextManager */


/**
 * TextManager destructor.
 * Frees all structures.
 */
TextManager::~TextManager()
{
	for (int i = 0; i < MAX_FONTS; i++)
	{
		delete(fonts[i]);
	}
	for (int i = 0; i < MAX_TEXTS; i++)
	{
		delete(fonts[i]);
	}
} /* ~TextManager */


/**
 * Returns the desired font's ID in the array, -1 if no font was found.
 * @name Identifier name of the font.
 */
int TextManager::getFontId(std::string name)
{
	for (int i = 0; i < totalFonts; i++)
	{
		if (fonts[i]->name == name)
		{
			return i;
		}
	}
	return -1;
} /* getFont */


/**
 * Returns an sf::Text's ID in the array identified by the name, -1 if no text was found.
 * @name Identifier name of the text.
 */
int TextManager::getTextId(std::string name)
{
	for (int i = 0; i < totalTexts; i++)
	{
		if (texts[i]->name == name)
		{
			return i;
		}
	}
	return -1;
} /* getText */

/**
 * Sets the font of the desired text.
 * @font An sf::Font to set the text to.
 * @name Identifier name of the text.
 */
void TextManager::setTextFont(sf::Font font, std::string name)
{
	for (int i = 0; i < totalTexts; i++)
	{
		if (texts[i]->name == name)
		{
			texts[i]->text.setFont(font);
			break;
		}
	}
} /* setTextFont */


/**
 * Loads all fonts
 */
void TextManager::loadAllFonts()
{
	loadFont("fonts/arial.ttf", "arial");
} /* loadAllFonts */


/**
 * Loads a single font
 * @filename Filename of the font.
 * @name Identifier name of the font.
 */
void TextManager::loadFont(std::string filename, std::string name)
{
	fonts[totalFonts]->name = name;
	fonts[totalFonts]->font.loadFromFile(filename);
	totalFonts++;
} /* loadFont */


/**
 * Creates a text
 * @text Text to set.
 * @name Identifier name of the text.
 */
void TextManager::createText(std::string text, std::string name)
{
	texts[totalTexts]->name = name;
	texts[totalTexts]->text.setString(text);
	totalTexts++;
} /* createText */


/**
 * Sets the size of the given text.
 * @name Identifier name of the text.
 * @size Size of the text.
 */
void TextManager::setTextSize(std::string name, int size)
{
	for (int i = 0; i < totalTexts; i++)
	{
		if (texts[i]->name == name)
		{
			texts[i]->text.setCharacterSize(size);
			break;
		}
	}
} /* setTextSize */


/**
 * Sets the color of the given text.
 * @name Identifier name of the text.
 * @color Color to set the text to.
 */
void TextManager::setTextColor(std::string name, sf::Color color)
{
	for (int i = 0; i < totalTexts; i++)
	{
		if (texts[i]->name == name)
		{
			texts[i]->text.setFillColor(color);
			break;
		}
	}
} /* setTextColor */


/**
 * Sets the position of the given text.
 * @name Identifier name of the text.
 * @position Position structure to place the text to.
 */
void TextManager::setTextPosition(std::string name, Position *position)
{
	for (int i = 0; i < totalTexts; i++)
	{
		if (texts[i]->name == name)
		{
			texts[i]->text.setPosition(position->x, position->y);
			break;
		}
	}
} /* setTextPosition */