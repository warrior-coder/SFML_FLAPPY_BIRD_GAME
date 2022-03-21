#include "PipesManager.hpp"


PipesManager::PipesManager()
	: yDistribution(PIPE_INDENT, GROUND_Y - GAP_HEIGHT - PIPE_INDENT)
	, generatorTimer(GENERATOR_TIMER_DURATION / 2)
{}

void PipesManager::draw(sf::RenderWindow& window)
{
	for (Pipe& pipe : pipes)
	{
		pipe.draw(window);
	}
}

void PipesManager::reset()
{
	generatorTimer = GENERATOR_TIMER_DURATION;
	pipes.clear();
}

void PipesManager::update(std::default_random_engine& randomEngine)
{
	if (generatorTimer <= 0)
	{
		generatorTimer = GENERATOR_TIMER_DURATION;

		pipes.push_back(
			Pipe(SCREEN_WIDTH, yDistribution(randomEngine))
		);
	}
	generatorTimer--;

	for (Pipe& pipe : pipes)
	{
		pipe.update();
	}

	for (auto itPipe = pipes.begin(); itPipe != pipes.end(); itPipe++)
	{
		// when the pipe go beyond the screen we delete it
		if (itPipe->isGone())
		{
			pipes.erase(itPipe);
			break;
		}
	}
}

std::vector<Pipe> PipesManager::getPipes()
{
	return pipes;
}