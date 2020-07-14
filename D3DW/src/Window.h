#pragma once
#include "WindowContainer.h"
class Window : public WindowContainer
{
private:
	void (*MouseCallback)(MouseEvent& me);
	void (*KeyboardCallback)(KeyboardEvent& kbe);
public:
	KeyboardEvent kbe;
	bool Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	bool ProcessMessages();
	KeyboardClass& GetKeyboard();
	void Update();
	void SetMouseCallback(void (*Callback)(MouseEvent& me));
	void SetKeyCallback(void (*Callback)(KeyboardEvent& kbe));
	void SwapBuffers();
};