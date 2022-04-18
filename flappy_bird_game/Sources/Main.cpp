#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Bird.hpp"
#include "PipesManager.hpp"
#include "ImageText.hpp"


/*
SFML (Simple and Fast Multimedia Library) – cross-platform object-oriented multimedia API, which provides access to windowing, graphics, audio, network
*/


int main()
{
	// main game objects
	Bird bird;
	PipesManager pipesManager;

	// initialize random engine
	std::default_random_engine randomEngine(
		static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count())
	);

	// window event
	sf::Event event{};

	// initialize window
	sf::RenderWindow window(
		sf::VideoMode(static_cast<unsigned int>(SCREEN_RESIZE * SCREEN_WIDTH), static_cast<unsigned int>(SCREEN_RESIZE * SCREEN_HEIGHT)),
		"Flappy Bird",
		sf::Style::Close
	);
	window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

	// prepare background
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	backgroundTexture.loadFromFile("Resources/Images/Background.png");
	backgroundSprite.setPosition(0.0f, 0.0f);
	backgroundSprite.setTexture(backgroundTexture);

	// prepare ground
	sf::Texture groundTexture;
	sf::Sprite groundSprite;

	groundTexture.loadFromFile("Resources/Images/Ground.png");
	groundSprite.setPosition(0.0f, GROUND_Y);
	groundSprite.setTexture(groundTexture);

	// set window icon
	sf::Image windowIcon;

	windowIcon.loadFromFile("Resources/Images/Icon.png");
	window.setIcon(windowIcon.getSize().x, windowIcon.getSize().y, windowIcon.getPixelsPtr());

	// use font from image to draw text
	ImageText scoreText;

	scoreText.SetColor(sf::Color::Black);

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
			bird.Update(pipesManager.GetPipes());

			if (!bird.IsDead())
			{
				pipesManager.Update(randomEngine);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				bird.Reset();
				pipesManager.Reset();
			}

			// draw the screen frame
			window.clear(sf::Color::Black);
			window.draw(backgroundSprite);

			pipesManager.Draw(window);
			bird.Draw(window);

			// show score text
			scoreText.SetText(std::to_string(bird.GetScore()));
			scoreText.SetPosition((SCREEN_WIDTH - scoreText.GetWidth()) / 2,SCREEN_HEIGHT / 20);
			scoreText.Draw(window);

			// draw ground over pipes
			window.draw(groundSprite);

			// display drawings
			window.display();

			// remember new time point
			timePointBegin = timePointEnd;
		}
	}

	return 0;
}