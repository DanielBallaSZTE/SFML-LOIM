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
 * Returns the desired font.
 * @name Identifier name of the font.
 */
sf::Font TextManager::getFont(std::string name)
{
	for (int i = 0; i < MAX_FONTS; i++)
	{
		if (fonts[i]->name == name)
		{
			return fonts[i]->font;
		}
	}
} /* getFont */


/**
 * Draws the text on the given window, identified by the name.
 * @window An sf::RenderWindow identifier.
 * @name Identifier name of the text.
 */
void TextManager::displayText(sf::RenderWindow window, std::string name)
{
	for (int i = 0; i < MAX_TEXTS; i++)
	{
		if (texts[i]->name == name)
		{
			window.draw(texts[i]->text);
			break;
		}
	}
} /* displayText */

/**
 * Sets the font of the desired text.
 * @font An sf::Font to set the text to.
 * @name Identifier name of the text.
 */
void setTextFont(sf::Font font, std::string name)
{

} /* setTextFont */