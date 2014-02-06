#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "TextureManager.h"
class Game {
private:
	//sdl
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;

	//initializers
	bool m_brunning = false;
	const int SCREEN_WIDTH = 960;
	const int SCREEN_HEIGHT = 480; 

	//compo
	Text
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int w, int h, int flags = SDL_WINDOW_SHOWN);
	void run();
	void quit();
};

#endif // end Game.h