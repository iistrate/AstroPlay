#ifndef GAME_H
#define GAME_H

#include <SDL.h>

//globals
SDL_Window* g_pWindow;
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 480;

class Game {
private:
	bool m_brunning = false;
public:
	Game();
	~Game();

	void init();
	void run();
	void quit();
};

#endif // end Game.h