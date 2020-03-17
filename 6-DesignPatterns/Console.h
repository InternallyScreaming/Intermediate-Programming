///////////////////////////////////SINGLETON///////////////////////////////////
#pragma once
#include <Windows.h>

class Console {
private:
	static Console * m_changeColour;
	Console();
public:
	static Console * getInstance();
	void changeConsoleColour();
};