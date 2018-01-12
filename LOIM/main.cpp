#include <SFML/Graphics.hpp>
#include "musicPlayer.h"
#include <iostream>
#include "linkedList.h"
#include "QuestionManager.h"

int main()
{

	MusicPlayer *musicPlayer = new MusicPlayer;
	musicPlayer->playMusic("mainTheme");

	sf::RenderWindow window(sf::VideoMode(800, 600), "Legyen Ön is milliomos!");
	window.setFramerateLimit(60);

	QManager *questions = new QManager;
	questions->readQuestions("questions.txt");

	// Temporary texture
	sf::Texture texture_bg;
	if (!texture_bg.loadFromFile("img/logo.jpeg"))
	{
		std::cout << "\nSpriteManager::Error loading image logo.jpeg";
	}
	else
	{
		std::cout << "\nSpriteManager::Successfuly loaded image logo.jpeg";
	}
	sf::Font arial;
	if (!arial.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "\nFontManager::Error loading font arial.ttf";
	}
	else
	{
		std::cout << "\nFontManager::Successfuly loaded font arial.ttf";
	}
	sf::Text dballa;
	dballa.setFont(arial);
	dballa.setString("Made in Csalbi");
	dballa.setCharacterSize(24);
	dballa.setFillColor(sf::Color::White);
	dballa.setPosition(320, 561);

	sf::Sprite sprite_bg;
	sprite_bg.setTexture(texture_bg);
	float pos_x = 392;
	float pos_y = 294;
	sprite_bg.setPosition(pos_x, pos_y);
	double sScale = 0.01;
	sprite_bg.setScale(sScale, sScale);
	bool drawDaniel = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Check if music is playing
			if (!musicPlayer->getMusicStatus("mainTheme") && !musicPlayer->getMusicStatus("easyQuestions"))
			{
				musicPlayer->playMusic("easyQuestions");
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(sprite_bg);
		if (drawDaniel)
		{
			window.draw(dballa);
		}
		window.display();

		if (sScale <= 1)
		{
			sprite_bg.setScale(sScale, sScale);
			sScale += 0.001;
			pos_x -= 0.4;
			pos_y -= 0.321;
			sprite_bg.setPosition(pos_x, pos_y);
		}
		else if (!drawDaniel)
		{
			drawDaniel = true;
		}
	}


	questions->freeQuestions();
	delete(musicPlayer);
	delete(questions);

	return 0;
}