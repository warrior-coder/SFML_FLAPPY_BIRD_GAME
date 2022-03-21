#include "Pipe.hpp"


Pipe::Pipe(float x, int y)
	: x(x)
	, y(y)
{
	image.loadFromFile("Resources/Images/Pipe.png");
}

bool Pipe::isGone()
{
	return (x <= -PIPE_WIDTH);
}

float Pipe::getX()
{
	return x;
}

int Pipe::getY()
{
	return y;
}

void Pipe::draw(sf::RenderWindow& window)
{
	// using 1 sprite to draw 2 pipes
	texture.loadFromImage(image);
	
	// top pipe
	sprite.setPosition(
		x,
		static_cast<float>(y - SCREEN_HEIGHT)
	);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(
		PIPE_WIDTH,
		0,
		PIPE_WIDTH,
		SCREEN_HEIGHT
	));
	window.draw(sprite);

	// bottom pipe
	sprite.setPosition(
		x,
		static_cast<float>(y + GAP_HEIGHT)
	);
	sprite.setTextureRect(sf::IntRect(
		0,
		0,
		PIPE_WIDTH,
		SCREEN_HEIGHT
	));
	window.draw(sprite);
}

void Pipe::update()
{
	x -= BIRD_SPEED;
}