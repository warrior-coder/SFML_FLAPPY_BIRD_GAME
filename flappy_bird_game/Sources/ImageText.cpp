#include "ImageText.hpp"


ImageText::ImageText()
{
	fontTexture.loadFromFile("Resources/Images/Font.png");
}

void ImageText::setColor(const sf::Color& color)
{
	this->color = color;
}

void ImageText::setText(const std::string& text)
{
	this->text = text;
}

void ImageText::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void ImageText::draw(sf::RenderWindow& window)
{
	int characterX = x;
	int characterY = y;
	int characterWidth;
	int characterHeight;

	characterWidth = fontTexture.getSize().x / FONT_CHARACTERS_COUNT;
	characterHeight = fontTexture.getSize().y;
	characterSprite.setTexture(fontTexture);
	characterSprite.setColor(color);

	for (std::string::const_iterator itText = text.cbegin(); itText != text.cend(); itText++)
	{
		// set character position
		characterSprite.setPosition(
			static_cast<float>(characterX),
			static_cast<float>(characterY)
		);

		// cut current character sprite from Font.png image using ASCII table codes
		characterSprite.setTextureRect(
			sf::IntRect(
				characterWidth * static_cast<int>(*itText - ' '),
				0,
				characterWidth,
				characterHeight
			)
		);

		// move carriage horisontaly
		characterX += characterWidth;

		window.draw(characterSprite);
	}
}

int ImageText::getWidth()
{
	return fontTexture.getSize().x / FONT_CHARACTERS_COUNT * text.length();
}

int ImageText::getHeight()
{
	return fontTexture.getSize().y;
}
