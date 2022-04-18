#pragma once

#include <SFML/Audio.hpp>

#include "Pipe.hpp"


class Bird
{
	bool _isDead;

	int _x;
	float _y;
	float _ySpeed;

	unsigned short _score;
	
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;

	sf::SoundBuffer _hitSoundBuffer, _wingSoundBuffer, _pointSoundBuffer;
	sf::Sound _hitSound, _wingSound, _pointSound;

public:
	Bird();

	bool IsDead() const;
	float GetY() const;
	unsigned short GetScore() const;
	
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Update(std::vector<Pipe> pipes);
};