#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "Global.hpp"


class ImageText
{
	int _x;
	int _y;

	std::string _text;
	sf::Color _color;

	sf::Texture _fontTexture;
	sf::Sprite _characterSprite;

public:
	explicit ImageText(int x = 0, int y = 0);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	void SetText(const std::string& text);
	void SetColor(const sf::Color& color);
	void SetPosition(int x, int y);

	void Draw(sf::RenderWindow& window);
};