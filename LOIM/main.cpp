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
		std::cout << "\nSpriteManager::Successfuly loaded logo.jpeg";
	}
	sf::Sprite sprite_bg;
	sprite_bg.setTexture(texture_bg);

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
		window.display();
	}


	questions->freeQuestions();
	delete(musicPlayer);
	delete(questions);

	return 0;
}