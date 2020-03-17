///////////////////////////////////SINGLETON///////////////////////////////////
#include "Console.h"

Console* Console::m_changeColour = 0;

Console* Console::getInstance()
{
	if (m_changeColour == 0) { m_changeColour = new Console(); }
	return m_changeColour;
}

Console::Console(){}

void Console::changeConsoleColour(){
	system("color F3");
}

