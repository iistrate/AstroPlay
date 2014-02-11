#ifndef GAME_H
#define GAME_H

#include "TextureManager.h"
#include "UserInput.h"
#include <iostream>
#include "World.h"

class Game {
private:
	//sdl
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;

	//initializers
	bool m_brunning = false;
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 900; 
	enum {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		QUIT = 9
	};

	//compo
	TextureManager tmanager;
	UserInput ui;
	World* Askeron;
	std::vector < Image* > m_Images;

	//gets string command from user
	std::string m_scommand;

public:
	Game();
	//cleans up SDL
	~Game();
	//initialize SDL, create window 
	void init(const char* title, int x, int y, int w, int h, int flags);
	//start game loop
	void run();
	//exits game loop;
	void quit();
};

#endif // end Game.h