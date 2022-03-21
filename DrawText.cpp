#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "DrawText.hpp"


void drawText(
	const sf::Color& textColor,
	bool isHorizontalAlignCenter,
	bool isVerticalAlignCenter,
	int x,
	int y,
	const std::string& text,
	sf::RenderWindow& window
)
{
	int characterX = x;
	int characterY = y;

	int characterWidth;

	sf::Sprite characterSprite;
	sf::Texture fontTexture;
	
	fontTexture.loadFromFile("Resources/Images/Font.png");

	// 96 characters in the texture
	characterWidth = fontTexture.getSize().x / 96;
	characterSprite.setTexture(fontTexture);
	characterSprite.setColor(textColor);

	if (isHorizontalAlignCenter)
	{
		characterX += static_cast<int>(round(0.5f * (SCREEN_WIDTH - characterWidth * text.substr(0, text.find_first_of('\n')).size())));
	}

	if (isVerticalAlignCenter)
	{
		characterY += static_cast<int>(round(0.5f * (SCREEN_HEIGHT - FONT_SIZE * (1 + std::count(text.begin(), text.end(), '\n')))));
	}

	for (std::string::const_iterator itText = text.cbegin(); itText != text.cend(); itText++)
	{
		if (*itText == '\n')
		{
			if (isHorizontalAlignCenter)
			{
				characterX = x + static_cast<int>(round(0.5f * (SCREEN_WIDTH - characterWidth * text.substr(1 + itText - text.begin(), text.find_first_of('\n', 1 + itText - text.begin()) - (1 + itText - text.begin())).size())));
			}
			else
			{
				characterX = x;
			}

			characterY += FONT_SIZE;

			continue;
		}

		characterSprite.setPosition(
			static_cast<float>(characterX),
			static_cast<float>(characterY)
		);
		characterSprite.setTextureRect(sf::IntRect(characterWidth * (*itText - 32), 0, characterWidth, FONT_SIZE));

		characterX += characterWidth;

		window.draw(characterSprite);
	}
}