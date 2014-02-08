#include "Game.h"
#include <iostream>


//my little helper
#define P(x) std::cout << #x << "'s value is " << x << std::endl;

void Game::init(const char* title, int x, int y, int w, int h, int flags) {
	//game loop condition
	m_brunning = true;

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
	int f_iinput = 0;
	init("Practicum", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	do {
		f_iinput = ui.getInput();
		if (f_iinput == QUIT) {
			quit();
		}
		else {
			P(ui.getCommand()); //string of command
			//movement would go here
		}
		m_scommand = ui.getCommand();

		//clear window
		SDL_RenderClear(m_pRenderer);

		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//draw
		tmanager.draw(m_pRenderer);
		tmanager.drawText(m_pRenderer, m_scommand);

		//render window
		SDL_RenderPresent(m_pRenderer);


	} while (m_brunning);
}
void Game::quit() {
	m_brunning = false;
}


Game::Game() {
}
Game::~Game() {
	//sdl cleanup; font cleanup handled in tmanager
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
}