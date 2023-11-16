#pragma once
#include "Window.h"
#include <memory>

class Game
{
public:
	Game();
	~Game();

	void run();
	void terminate();

protected:
	bool is_running = true;
	std::unique_ptr<Window> window_ptr = nullptr;
};

