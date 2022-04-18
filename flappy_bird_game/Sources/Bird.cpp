#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Pipe.hpp"
#include "Bird.hpp"


Bird::Bird()
	: _isDead(false)
	, _x(BIRD_START_X)
	, _y((GROUND_Y - BIRD_SIZE) / 2.0f)
	, _ySpeed(0.0f)
	, _score(0)
{
	// load image
	_texture.loadFromFile("Resources/Images/Bird.png");
	_sprite.setTexture(_texture);

	// load sound
	_hitSoundBuffer.loadFromFile("Resources/Sounds/Hit.wav");
	_hitSound.setBuffer(_hitSoundBuffer);

	_pointSoundBuffer.loadFromFile("Resources/Sounds/Point.wav");
	_pointSound.setBuffer(_pointSoundBuffer);

	_wingSoundBuffer.loadFromFile("Resources/Sounds/Wing.wav");
	_wingSound.setBuffer(_wingSoundBuffer);
}

bool Bird::IsDead() const
{
	return _isDead;
}

float Bird::GetY() const
{
	return _y;
}

unsigned short Bird::GetScore() const
{
	return _score;
}

void Bird::Draw(sf::RenderWindow& window)
{
	_sprite.setPosition(static_cast<float>(_x), _y);
	_sprite.setTextureRect(sf::IntRect(
		BIRD_SIZE * (_ySpeed <= 0.0f),
		BIRD_SIZE * (_isDead == true),
		BIRD_SIZE,
		BIRD_SIZE
	));
	window.draw(_sprite);
}

void Bird::Reset()
{
	_isDead = false;
	_x = BIRD_START_X;
	_y = (GROUND_Y - BIRD_SIZE) / 2.0f;
	_ySpeed = 0.0f;
	_score = 0;
}

void Bird::Update(std::vector<Pipe> pipes)
{
	_y += _ySpeed;
	_ySpeed += GRAVITY;

	if (!_isDead)
	{
		if (_ySpeed >= 0.0f && _y >= 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_ySpeed = FLAP_SPEED;

			_wingSound.play();
		}

		for (const auto& pipe : pipes)
		{
			if (_x > pipe.GetX() - BIRD_SIZE && _x < pipe.GetX() + PIPE_WIDTH)
			{
				if (_y > GAP_HEIGHT + pipe.GetY() - BIRD_SIZE || _y < pipe.GetY())
				{
					if (!_isDead) _hitSound.play();

					_isDead = true;
					_ySpeed = 0.0f;
				}
			}
			else if (_x == pipe.GetX() + 2 * BIRD_SIZE)
			{
				_score++;

				_pointSound.play();
			}
		}
	}

	if (_y >= GROUND_Y - BIRD_SIZE)
	{
		if (!_isDead) _hitSound.play();

		_isDead = true;
		_ySpeed = 0.0f;
		_y = GROUND_Y - BIRD_SIZE;
	}
}