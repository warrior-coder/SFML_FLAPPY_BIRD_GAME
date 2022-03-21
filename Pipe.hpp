#pragma once

#include <chrono>
#include <SFML/Graphics.hpp>

#include "Global.hpp"

class Pipe
{
	float x;
	int y;

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Pipe(float x, int y);

	bool isGone();

	float getX();
	int getY();

	void draw(sf::RenderWindow& window);
	void update();
};