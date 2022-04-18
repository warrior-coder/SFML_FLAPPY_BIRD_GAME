#include "Pipe.hpp"


Pipe::Pipe(const float x, const int y)
	: _x(x)
	, _y(y)
{
	_texture.loadFromFile("Resources/Images/Pipe.png");
	_sprite.setTexture(_texture); // using 1 sprite to draw 2 pipes
}

bool Pipe::IsGone() const
{
	return (_x <= -PIPE_WIDTH);
}

float Pipe::GetX() const
{
	return _x;
}

int Pipe::GetY() const
{
	return _y;
}

void Pipe::Draw(sf::RenderWindow& window)
{
	// top pipe
	_sprite.setTextureRect(sf::IntRect(PIPE_WIDTH, 0, PIPE_WIDTH, SCREEN_HEIGHT));
	_sprite.setPosition(_x, static_cast<float>(_y - SCREEN_HEIGHT));
	window.draw(_sprite);

	// bottom pipe
	_sprite.setTextureRect(sf::IntRect(0, 0, PIPE_WIDTH, SCREEN_HEIGHT));
	_sprite.setPosition(_x, static_cast<float>(_y + GAP_HEIGHT));
	window.draw(_sprite);
}

void Pipe::Update()
{
	_x -= BIRD_SPEED;
}