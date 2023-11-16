#include "Window.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		Window* window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->on_destroy();
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return NULL;
}

Window::Window()
{
	WNDCLASSEX window_class;
	window_class.cbSize = sizeof(WNDCLASSEX);
	window_class.lpszClassName = L"OpenGL_Window";
	window_class.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&window_class);

	//window size
	RECT window_size = { 0.0f, 0.0f, 1024.0f, 768.0f };
	AdjustWindowRect(&window_size, WS_SYSMENU, false);

	//create window
	handle_ptr = CreateWindowEx(NULL, L"OpenGL_Window", L"Nautilus Engine", WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		window_size.right, window_size.bottom, NULL, NULL, NULL, NULL);

	SetWindowLongPtr((HWND)handle_ptr, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow((HWND)handle_ptr, SW_SHOW);
	UpdateWindow((HWND)handle_ptr);
}

Window::~Window()
{
	DestroyWindow((HWND)handle_ptr);
}

void Window::on_destroy()
{
	handle_ptr = nullptr;
}

bool Window::is_terminated()
{
	return handle_ptr;
}
