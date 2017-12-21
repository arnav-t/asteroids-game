#include "asteroid.hpp"
#include <ctime>

#define W 512
#define H 512
#define grey 50

char winTitle[] = "Test";

int main(int argc, char *argv[])
{
	srand(std::time(NULL));
	Window mainWin(winTitle, W, H);
	mainWin.clearScreen(grey,grey,grey);
	Asteroid a(W/2, H/2, 4 + rand()%16);
	a.draw(mainWin);
	mainWin.updateScreen();
	SDL_Delay(2000);
	SDL_Quit();
	return 0;
}
