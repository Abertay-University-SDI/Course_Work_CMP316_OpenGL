#pragma once
#include <Windows.h>

class Window
{
public:
	Window();
	~Window();

	void on_destroy();
	bool is_terminated();
private:
	void* handle_ptr = nullptr;
};

