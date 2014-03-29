#ifndef GAME_H
#define GAME_H

#include "TextureManager.h"
#include "UserInput.h"
#include <iostream>
#include "World.h"
#include "GUI.h"

class Game {
private:
	//sdl
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	//fps thingy
	Uint32 m_fps;
	Uint32 m_fpsCap;

	int m_turn;

	//initializers
	bool m_brunning;
	bool m_bdebugMode;
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT; 

	//controls
	enum {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON,
		QUIT = 9,
		DEBUG_MODE
	};

	//compo
	TextureManager tmanager;
	UserInput ui;
	World* Askeron;
	GUI gameGUI;
	std::vector < Image* > m_Images;
	std::vector < Image* > m_DebugImages;

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
	//fps
	void fpsCap();
};

#endif // end Game.h