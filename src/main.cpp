/*
file	main.cpp
author	Vicente Rizzi
version	1.0
date	03/05/2022

*/

#include <SFML/Graphics.hpp>

#define SPRITE_SPEED 5

int main()
{
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(desktopMode.width, desktopMode.height, desktopMode.bitsPerPixel), "SFML works!", sf::Style::Fullscreen);

	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	// create a red triangule
	sf::Texture texture;
	if (!texture.loadFromFile("content/character.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(0.3, 0.3);

	sf::Texture background;
	if (!background.loadFromFile("content/bg_green.png"))
	{
		return EXIT_FAILURE;
	}
	sf::Sprite backgroundSprite(background);

	int x = window.getSize().x / 2.;
	int y = window.getSize().y / 2.;

	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	sf::Clock timer;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						upFlag = true;
						break;
					case sf::Keyboard::Down:
						downFlag = true;
						break;

					case sf::Keyboard::Left:
						leftFlag = true;
						break;

					case sf::Keyboard::Right:
						rightFlag = true;
						break;

					default:
						break;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						upFlag = false;
						break;
					case sf::Keyboard::Down:
						downFlag = false;
						break;

					case sf::Keyboard::Left:
						leftFlag = false;
						break;

					case sf::Keyboard::Right:
						rightFlag = false;
						break;

					default:
						break;
				}
			}
		}

		if (upFlag)
			y -= SPRITE_SPEED;
		if (downFlag)
			y += SPRITE_SPEED;
		if (leftFlag)
			x -= SPRITE_SPEED;
		if (rightFlag)
			x += SPRITE_SPEED;

		if (x < 0)
			x = 0;
		if (x > (int)window.getSize().x)
			x = window.getSize().x;

		if (y < 0)
			y = 0;

		if (y > (int)window.getSize().y)
			y = window.getSize().y;

		window.clear();

		sprite.setPosition(x, y);
		window.draw(backgroundSprite);
		window.draw(sprite);

		window.display();
	}

	return 0;
}