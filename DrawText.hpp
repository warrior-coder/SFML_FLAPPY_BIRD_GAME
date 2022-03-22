#pragma once

#include <SFML/Graphics.hpp>

#include "Global.hpp"


void drawText(
	const sf::Color& color,
	bool isHorizontalAlignCenter,
	bool isVerticalAlignCenter,
	int x,
	int y,
	const std::string& text,
	sf::RenderWindow& window
);