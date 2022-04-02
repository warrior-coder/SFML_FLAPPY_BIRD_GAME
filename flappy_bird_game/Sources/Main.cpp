#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Bird.hpp"
#include "PipesManager.hpp"
#include "ImageText.hpp"


int main()
{
	// main game objects
	Bird bird;
	PipesManager pipesManager;

	// initialize random engine
	std::default_random_engine randomEngine(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

	// window event
	sf::Event event;

	// initialize window
	sf::RenderWindow window(
		sf::VideoMode(static_cast<unsigned int>(SCREEN_RESIZE * SCREEN_WIDTH), static_cast<unsigned int>(SCREEN_RESIZE * SCREEN_HEIGHT)),
		"Flappy Bird",
		sf::Style::Close
	);
	window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	// prepare backgroung and ground
	sf::Texture backgroundeltaTimeexture, groundeltaTimeexture;
	sf::Sprite backgroundSprite, groundSprite;

	backgroundeltaTimeexture.loadFromFile("Resources/Images/Background.png");
	backgroundSprite.setPosition(0.0f, 0.0f);
	backgroundSprite.setTexture(backgroundeltaTimeexture);

	groundeltaTimeexture.loadFromFile("Resources/Images/Ground.png");
	groundSprite.setPosition(0.0f, GROUND_Y);
	groundSprite.setTexture(groundeltaTimeexture);

	// set window icon
	sf::Image windowIcon;

	windowIcon.loadFromFile("Resources/Images/Icon.png");
	window.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

	// use font from image to draw text
	ImageText scoreText;

	scoreText.setColor(sf::Color::Black);

	// frame time variables
	std::chrono::steady_clock::time_point timePointEnd;
	std::chrono::steady_clock::time_point timePointBegin = std::chrono::steady_clock::now();
	std::chrono::milliseconds deltaTime;

	// main game loop
	while (window.isOpen())
	{
		// calculate frame duration
		timePointEnd = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(timePointEnd - timePointBegin);

		if (deltaTime.count() > MILLISECONDS_FRAME_DURATION)
		{
			// handle events
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						window.close();
					}
				}
			}

			// move bird and pipes
			bird.update(pipesManager.getPipes());

			if (!bird.isDead())
			{
				pipesManager.update(randomEngine);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				bird.reset();
				pipesManager.reset();
			}

			// draw the screen frame
			window.clear(sf::Color::Black);
			window.draw(backgroundSprite);

			pipesManager.draw(window);
			bird.draw(window);

			// show score
			scoreText.setText(
				std::to_string(bird.getScore())
			);
			scoreText.setPosition(
				(SCREEN_WIDTH - scoreText.getWidth()) / 2,
				SCREEN_HEIGHT / 20
			);

			scoreText.draw(window);

			// draw ground after pipes to close them
			window.draw(groundSprite);

			// display drawings
			window.display();

			// remember new time point
			timePointBegin = timePointEnd;
		}
	}

	return 0;
}