#include "Window.h"

bool Window::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	if (!this->window.Initialize(this, hInstance, window_title, window_class, width, height))
		return false;

	if (!gfx.Initialize(this->window.GetHWND(), width, height))
		return false;

	return true;
}

bool Window::ProcessMessages()
{
	return this->window.ProcessMessages();
}

KeyboardClass& Window::GetKeyboard()
{
	return keyboard;
}

void Window::Update()
{
	while (!keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = keyboard.ReadChar();
	}

	while (!keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
		KeyboardCallback(kbe);
	}

	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();
		MouseCallback(me);
		//TODO: Add A function like: SetKeyCallback or SetMouseCallback BEFORE using directx
	}
}

void Window::SetMouseCallback(void(*Callback)(MouseEvent& me))
{
	MouseCallback = Callback;
}

void Window::SetKeyCallback(void(*Callback)(KeyboardEvent& kbe))
{
	KeyboardCallback = Callback;
}

void Window::SwapBuffers()
{
	this->GetGraphics().GetSwapChain()->Present(1, NULL);
}
