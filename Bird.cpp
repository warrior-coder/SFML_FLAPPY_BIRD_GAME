#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Pipe.hpp"
#include "Bird.hpp"


Bird::Bird() 
{
	image.loadFromFile("Resources/Images/Bird.png");
	reset();
}

bool Bird::isDead() const
{
	return dead;
}

float Bird::getY() const
{
	return y;
}

unsigned short Bird::getScore() const
{
	return score;
}

void Bird::draw(sf::RenderWindow& window)
{
	texture.loadFromImage(image);

	sprite.setPosition(
		static_cast<float>(x),
		y
	);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(
		BIRD_SIZE * (ySpeed <= 0.0f),
		BIRD_SIZE * (dead == true),
		BIRD_SIZE,
		BIRD_SIZE
	));

	window.draw(sprite);
}

void Bird::reset()
{
	dead = false;

	x = BIRD_START_X;
	y = (GROUND_Y - BIRD_SIZE) / 2.0f;

	ySpeed = 0.0f;

	score = 0;
}

void Bird::update(std::vector<Pipe> pipes)
{
	y += ySpeed;
	ySpeed += GRAVITY;

	if (!dead)
	{
		if (ySpeed >= 0.0f && y >= 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			ySpeed = FLAP_SPEED;
		}

		for (auto& pipe : pipes)
		{
			if (x > pipe.getX() - BIRD_SIZE && x < pipe.getX() + PIPE_WIDTH)
			{
				if (y > GAP_HEIGHT + pipe.getY() - BIRD_SIZE || y < pipe.getY())
				{
					dead = true;
					ySpeed = 0.0f;
				}
			}
			else if (x == pipe.getX() + 2 * BIRD_SIZE)
			{
				score++;
			}
		}
	}

	if (y >= GROUND_Y - BIRD_SIZE)
	{
		dead = true;
		ySpeed = 0.0f;
		y = GROUND_Y - BIRD_SIZE;
	}
}