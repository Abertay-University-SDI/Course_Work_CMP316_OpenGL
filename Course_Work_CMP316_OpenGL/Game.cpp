#include "Game.h"

Game::Game()
{
	window_ptr = std::unique_ptr<Window>(new Window());
}

Game::~Game()
{
}

void Game::run()
{
	MSG msg;
	while (is_running && !window_ptr->is_terminated())
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(1);
	}
}

void Game::terminate()
{
	is_running = false;
}
