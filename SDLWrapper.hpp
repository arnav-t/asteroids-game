#include <SDL2/SDL.h>

class Window
{
	private:
		SDL_Window *win;
		SDL_Renderer *ren;
	public:
		Window(char title[], int w, int h)
		{
			win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, 
								   SDL_WINDOWPOS_CENTERED, w, h, 
							       SDL_WINDOW_BORDERLESS);
			ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
		}
		~Window()
		{
			SDL_DestroyRenderer(ren);
			SDL_DestroyWindow(win);
		}
		void clearScreen(int r, int g, int b)
		{
			SDL_SetRenderDrawColor(ren, r, g, b, 255);
			SDL_RenderClear(ren);
		}
		void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b)
		{
			SDL_SetRenderDrawColor(ren, r, g, b, 255);
			SDL_RenderDrawLine(ren, x1, y1, x2, y2);
		}
		void updateScreen()
		{
			SDL_RenderPresent(ren);
		}
};
