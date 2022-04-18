#pragma once

#include <SFML/Graphics.hpp>

#include "Global.hpp"


class Pipe
{
	float _x;
	int _y;

	sf::Texture _texture;
	sf::Sprite _sprite;

public:
	Pipe(float x, int y);

	bool IsGone() const;
	float GetX() const;
	int GetY() const;

	void Draw(sf::RenderWindow& window);
	void Update();
};