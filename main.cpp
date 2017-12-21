#include "SDLWrapper.hpp"

#define W 512
#define H 512
#define grey 50

char winTitle[] = "Test";

int main(int argc, char *argv[])
{
	Window mainWin(winTitle, W, H);
	mainWin.clearScreen(grey,grey,grey);
	mainWin.drawLine(0,0,H,W,255,255,255);
	mainWin.updateScreen();
	SDL_Delay(5000);
	SDL_Quit();
	return 0;
}
