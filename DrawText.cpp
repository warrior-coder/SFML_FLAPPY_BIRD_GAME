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

	sf::Texture fontTexture;
	sf::Sprite characterSprite;
	
	fontTexture.loadFromFile("Resources/Images/Font.png");

	// 96 characters in the texture
	characterWidth = fontTexture.getSize().x / 96;
	characterSprite.setTexture(fontTexture);
	characterSprite.setColor(textColor);

	// calculate text position if center alignment was specified
	if (isHorizontalAlignCenter)
	{
		characterX += static_cast<int>(
			round((SCREEN_WIDTH - characterWidth * text.substr(0, text.find_first_of('\n')).size()) / 2.0f)
		);
	}
	if (isVerticalAlignCenter)
	{
		characterY += static_cast<int>(
			round((SCREEN_HEIGHT - FONT_HEIGHT * (1 + std::count(text.begin(), text.end(), '\n'))) / 2.0f)
		);
	}

	for (std::string::const_iterator itText = text.cbegin(); itText != text.cend(); itText++)
	{
		// move carriage verticaly if '\n' detected
		if (*itText == '\n')
		{
			if (isHorizontalAlignCenter)
			{
				characterX = x + static_cast<int>(
					round((SCREEN_WIDTH - characterWidth * text.substr(1 + itText - text.begin(), text.find_first_of('\n', 1 + itText - text.begin()) - (1 + itText - text.begin())).size()) / 2.0f)
				);
			}
			else
			{
				characterX = x;
			}

			characterY += FONT_HEIGHT;

			// skip drawing character
			continue;
		}

		// set character[i] position
		characterSprite.setPosition(
			static_cast<float>(characterX),
			static_cast<float>(characterY)
		);

		// cut current character[i] sprite from Font.png
		characterSprite.setTextureRect(
			sf::IntRect(
				characterWidth * static_cast<int>(*itText - ' '),
				0,
				characterWidth,
				FONT_HEIGHT
			)
		);

		// move carriage horisontaly
		characterX += characterWidth;

		window.draw(characterSprite);
	}
}