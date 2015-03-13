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
	//sdl vars
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//in game vars
	int m_turn;
	int m_commandCursor;
	std::vector < std::string > m_shelpers;
	std::vector < int > m_icommands;

	//switches
	bool m_brunning;
	bool m_bdebugMode;
	bool m_bexecute;
	bool m_bcameraMode;
	bool m_showCommandPrompt;

	//screen settings
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT; 
	//fps thingy
	Uint32 m_fps;
	Uint32 m_fpsCap;

	//composition
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

	//holds string command
	std::string m_scommand;
	//holds translated commands
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