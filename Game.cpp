#include "Game.h"
#include <iostream>


//my little helper
#define P(x) std::cout << #x << "'s value is " << x << std::endl;

void Game::init(const char* title, int x, int y, int w, int h, int flags) {
	//game loop condition
	m_brunning = true;

	//initialize font
	if (TTF_Init() == -1) {
		std::cout << "FOnts failed to initialize" << std::endl;
	}
	else {
		m_pfont = TTF_OpenFont("ARLRDBD.TTF", 14);
	}
	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		if (m_pWindow) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			SDL_StartTextInput();
		}
		else {
			std::cout << "Window failed to load" << std::endl;
		}
	}
	else {
		std::cout << "SDL failed to initialize" << std::endl;
	}
}
void Game::run() {
	int input = 0;
	init("Practicum", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	do {
		input = ui.getInput();
		if (input == QUIT) {
			quit();
		}
		else {
			P(ui.getCommand()); //string of command
			//movement would go here
		}
		tmanager.draw(m_pRenderer);

	} while (m_brunning);
}
void Game::quit() {
	//game cleanup
	m_brunning = false;
	//sdl cleanup
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
	//font cleanup
	TTF_Quit();
	TTF_CloseFont(m_pfont);
	m_pfont = 0;
	system("pause");
}


Game::Game() {
}
Game::~Game() {
}