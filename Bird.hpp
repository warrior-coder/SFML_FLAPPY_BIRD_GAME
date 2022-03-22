#pragma once

#include <SFML/Audio.hpp>

#include "Pipe.hpp"


class Bird
{
	bool dead;

	int x;
	float y;
	float ySpeed;

	unsigned short score;
	
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::SoundBuffer hitSoundBuffer, wingSoundBuffer, pointSoundBuffer;
	sf::Sound hitSound, wingSound, pointSound;

public:
	Bird();

	bool isDead() const;
	float getY() const;
	unsigned short getScore() const;
	
	void draw(sf::RenderWindow& window);
	void reset();
	void update(std::vector<Pipe> pipes);
};