#include "Game.h"
#include <iostream>
#include <cassert>

//my little helper
#define P(x) std::cout << #x << "'s value is " << x << std::endl;

void Game::init() {
	//game loop condition
	m_brunning = true;
	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		g_pWindow = SDL_CreateWindow("Practicum", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	}
	else {
		std::cout << "SDL failed to initialize" << std::endl;
	}
}
void Game::run() {
	init();
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