#ifndef GAME_H
#define GAME_H

#include "GLOBALS.h"

#include "TextureManager.h"
#include "UserInput.h"
#include <iostream>
#include "World.h"
#include "GUI.h"
#include "StringParser.h"

class Game {
private:
	//sdl
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	//fps thingy
	Uint32 m_fps;
	Uint32 m_fpsCap;

	int m_turn;
	bool m_bcameraMode; 
	int m_commandCursor;
	std::vector < int > m_icommands;

	//initializers
	bool m_brunning;
	bool m_bdebugMode;
	bool m_bexecute;

	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT; 

	//compo
	TextureManager Tmanager;
	UserInput Ui;
	World* Askeron;
	GUI GameGUI;
	StringParser Parser;
	//image sets
	std::vector < Image* > m_Images_WORLD;
	std::vector < Image* > m_Images_GUI;
	std::vector < Image* > m_Images_MOVING;
	std::vector < Image* > m_DebugImages;

	//gets string command from user
	std::string m_scommand;
	//has commands
	std::vector < int > m_icommand;

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