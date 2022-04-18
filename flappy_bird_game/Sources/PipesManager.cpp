#include "PipesManager.hpp"


PipesManager::PipesManager()
	: _generatorTimer(GENERATOR_TIMER_DURATION / 2)
	, _yDistribution(PIPE_INDENT, GROUND_Y - GAP_HEIGHT - PIPE_INDENT)
{}

void PipesManager::Draw(sf::RenderWindow& window)
{
	for (auto& pipe : _pipes)
	{
		pipe.Draw(window);
	}
}

void PipesManager::Reset()
{
	_generatorTimer = GENERATOR_TIMER_DURATION / 2;
	_pipes.clear();
}

void PipesManager::Update(std::default_random_engine& randomEngine)
{
	// if time to generate new pipe
	if (_generatorTimer > GENERATOR_TIMER_DURATION)
	{
		_generatorTimer = 0;

		_pipes.emplace_back(Pipe(SCREEN_WIDTH, _yDistribution(randomEngine)));
	}
	_generatorTimer++;

	// update every pipe
	for (auto& pipe : _pipes)
	{
		pipe.Update();
	}

	for (auto itPipe = _pipes.begin(); itPipe != _pipes.end(); ++itPipe)
	{
		// when the pipe go beyond the screen we delete it
		if (itPipe->IsGone())
		{
			_pipes.erase(itPipe);

			break;
		}
	}
}

std::vector<Pipe> PipesManager::GetPipes() const
{
	return _pipes;
}