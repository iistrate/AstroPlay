#ifndef GAME_H
#define GAME_H

#include "TextureManager.h"
#include "UserInput.h"

class Game {
private:
	//sdl
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	//font
	TTF_Font* m_pfont = 0;

	//initializers
	bool m_brunning = false;
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 900; 
	enum m_Keys {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		QUIT = 9
	};

	//compo
	TextureManager tmanager;
	UserInput ui;


public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int w, int h, int flags);
	void run();
	void quit();
};

#endif // end Game.h