#include "Game.h"
#include <iostream>

//my little helper
#define P(x) std::cout << #x << "'s value is " << x << std::endl;

void Game::init(const char* title, int x, int y, int w, int h, int flags = SDL_WINDOW_SHOWN) {
	//game loop condition
	m_brunning = true;
	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		if (m_pWindow) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
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
	init("Practicum", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
	do {
		quit();
	} while (m_brunning);
}
void Game::quit() {
	m_brunning = false;
	system("pause");
}


Game::Game() {
}
Game::~Game() {
}