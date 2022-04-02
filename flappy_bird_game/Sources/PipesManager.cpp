#include "PipesManager.hpp"


PipesManager::PipesManager()
	: yDistribution(PIPE_INDENT, GROUND_Y - GAP_HEIGHT - PIPE_INDENT)
	, generatorTimer(GENERATOR_TIMER_DURATION / 2)
{}

void PipesManager::draw(sf::RenderWindow& window)
{
	for (auto& pipe : pipes)
	{
		pipe.draw(window);
	}
}

void PipesManager::reset()
{
	generatorTimer = GENERATOR_TIMER_DURATION / 2;
	pipes.clear();
}

void PipesManager::update(std::default_random_engine& randomEngine)
{
	// if time to generate new pipe
	if (generatorTimer > GENERATOR_TIMER_DURATION)
	{
		generatorTimer = 0;

		pipes.push_back(
			Pipe(SCREEN_WIDTH, yDistribution(randomEngine))
		);
	}
	generatorTimer++;

	// update every pipe
	for (auto& pipe : pipes)
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

std::vector<Pipe> PipesManager::getPipes() const
{
	return pipes;
}