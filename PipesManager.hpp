#pragma once

#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>

#include "Global.hpp"
#include "Pipe.hpp"


class PipesManager
{
	int generatorTimer;

	std::uniform_int_distribution<int> yDistribution;
	std::vector<Pipe> pipes;

public:
	PipesManager();
	
	std::vector<Pipe> getPipes();
	
	void draw(sf::RenderWindow& window);
	void reset();
	void update(std::default_random_engine& randomEngine);
};