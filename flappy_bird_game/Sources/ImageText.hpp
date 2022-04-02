#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "Global.hpp"


class ImageText
{
	int x, y;

	std::string text;
	sf::Color color;

	sf::Texture fontTexture;
	sf::Sprite characterSprite;

public:
	ImageText();

	int getWidth();
	int getHeight();

	void setText(const std::string& text);
	void setColor(const sf::Color& color);
	void setPosition(int x, int y);

	void draw(sf::RenderWindow& window);
};