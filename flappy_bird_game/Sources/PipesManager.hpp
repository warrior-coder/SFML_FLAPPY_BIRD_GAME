#pragma once

#include <random>

#include "Global.hpp"
#include "Pipe.hpp"


class PipesManager
{
	int _generatorTimer;

	std::uniform_int_distribution<int> _yDistribution;
	std::vector<Pipe> _pipes;

public:
	PipesManager();
	
	std::vector<Pipe> GetPipes() const;
	
	void Draw(sf::RenderWindow& window);
	void Reset();
	void Update(std::default_random_engine& randomEngine);
};