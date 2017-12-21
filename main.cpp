#include "asteroid.hpp"
#include <ctime>

using namespace std;

#define W 512
#define H 512
#define grey 50
#define astNum 10
#define framerate 60

char winTitle[] = "Test";

int main(int argc, char *argv[])
{
	srand(time(NULL));
	Window mainWin(winTitle, W, H);
	vector<Asteroid> astList;
	for(int i=0;i<astNum;++i)
		astList.push_back(Asteroid(rand()%W, rand()%H, 4 + rand()%16));
	bool quit = false;
	clock_t prevFrame = clock();
	while(!quit)
	{
		mainWin.clearScreen(grey,grey,grey);
		for(int i=0;i<astNum;++i)
			astList[i].update(mainWin);
		mainWin.updateScreen();
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_KEYDOWN)
			{
				if(e.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
			}
		}
		double delay = 1000/framerate - ((double)(clock() - prevFrame)*1000/CLOCKS_PER_SEC);
		SDL_Delay(delay>0 ? delay : 0);
		prevFrame = clock();
	}
	SDL_Quit();
	return 0;
}
