#include "ImageText.hpp"


ImageText::ImageText(int x, int y)
	: _x(x)
	, _y(y)
{
	_fontTexture.loadFromFile("Resources/Images/Font.png");
}

void ImageText::SetColor(const sf::Color& color)
{
	_color = color;
}

void ImageText::SetText(const std::string& text)
{
	_text = text;
}

void ImageText::SetPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void ImageText::Draw(sf::RenderWindow& window)
{
	int characterX = _x;
	const int characterY = _y;
	const int characterWidth = _fontTexture.getSize().x / FONT_CHARACTERS_COUNT;
	const int characterHeight = _fontTexture.getSize().y;

	_characterSprite.setTexture(_fontTexture);
	_characterSprite.setColor(_color);

	for (std::string::const_iterator itText = _text.cbegin(); itText != _text.cend(); ++itText)
	{
		// set character position
		_characterSprite.setPosition(static_cast<float>(characterX),static_cast<float>(characterY));

		// cut current character sprite from Font.png image using ASCII table codes
		_characterSprite.setTextureRect(sf::IntRect(characterWidth * (*itText - ' '), 0, characterWidth, characterHeight));

		// move carriage horizontally
		characterX += characterWidth;

		window.draw(_characterSprite);
	}
}

unsigned int ImageText::GetWidth() const
{
	return _fontTexture.getSize().x / FONT_CHARACTERS_COUNT * _text.length();
}

unsigned int ImageText::GetHeight() const
{
	return _fontTexture.getSize().y;
}