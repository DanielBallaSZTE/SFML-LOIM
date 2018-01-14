#include "musicPlayer.h"
#include "QuestionManager.h"
#include "textManager.h"

int main()
{
	// Create MusicPlayer
	MusicPlayer *musicPlayer = new MusicPlayer;
	musicPlayer->setGlobalVolume(10.0f);
	musicPlayer->playMusic("mainTheme");


	// Create TextManager
	TextManager *textManager = new TextManager;
	textManager->createText("Made in Csalbi", "madeincsalbi");
	// textManager->setTextFont(textManager->fonts[textManager->getFontId("arial")]->font, "madeincsalbi");
	textManager->setTextSize("madeincsalbi", 24);
	textManager->setTextColor("madeincsalbi", sf::Color::White);
	textManager->setTextPosition("madeincsalbi", new Position(320, 561));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Legyen Ön is milliomos!", sf::Style::Titlebar | sf::Style::Close);
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

	sf::Sprite sprite_bg;
	sprite_bg.setTexture(texture_bg);
	float pos_x = 392.0f; // Center of screen
	float pos_y = 294.0f; // Center of screen
	sprite_bg.setPosition(pos_x, pos_y);
	float sScale = 0.01f;
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

			if (sf::Event::KeyPressed)
			{
				if (musicPlayer->getMusicStatus("mainTheme"))
				{
					if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Escape)
					{
						musicPlayer->stopMusic("mainTheme");
						sScale = 1.0f;
						musicPlayer->playMusic("easyQuestions");
						pos_x = 0.0f;
						pos_y = 0.0f;
					}
				}
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
			window.draw(textManager->texts[0]->text);
		}
		window.display();

		if (sScale <= 1)
		{
			sprite_bg.setScale(sScale, sScale);
			sScale += 0.001f;
			pos_x -= 0.4f;
			pos_y -= 0.321f;
			sprite_bg.setPosition(pos_x, pos_y);
		}
		else if (!drawDaniel)
		{
			drawDaniel = true;
		}
	}


	questions->freeQuestions();
	delete(textManager);
	delete(musicPlayer);
	delete(questions);

	return 0;
}