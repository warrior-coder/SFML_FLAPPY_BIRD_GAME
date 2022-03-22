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

	sf::SoundBuffer hitSoundBuffer;
	sf::Sound hitSound;

	sf::SoundBuffer wingSoundBuffer;
	sf::Sound wingSound;

	sf::SoundBuffer pointSoundBuffer;
	sf::Sound pointSound;

public:
	Bird();

	bool isDead() const;
	
	float getY() const;
	unsigned short getScore() const;
	
	void draw(sf::RenderWindow& window);
	void reset();
	void update(std::vector<Pipe> pipes);
};