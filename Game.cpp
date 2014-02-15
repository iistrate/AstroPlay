#include "Game.h"


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

	//size of vector, figure out how many tiles we need
	int tileHeight = 32;
	int tileWidth = 96;
	int m_vectorY = SCREEN_HEIGHT / tileHeight;
	int m_vectorX = (SCREEN_WIDTH / tileWidth) * 0.45;


	//create world
	Askeron = new World(SCREEN_HEIGHT, SCREEN_WIDTH);

	//get images
	Askeron->getImages(m_Images);
	//to be moved
	//custom images
	for (int i = 0; i < m_vectorY; i++) {
		for (int j = 0; j < m_vectorX; j++) {
			//bordered left
			if (j == 0) {
				//top 
				if (i == 0) {
					m_Images.push_back(new Image("assets/sprites-ui.png", j * tileWidth, i * tileHeight, 32, 36, 34, 53, 2, 0, 0, 0));
				}
				//bottom
				else if (i == (m_vectorY - 1)) {
					m_Images.push_back(new Image("assets/sprites-ui.png", j * tileWidth, i * tileHeight, 32, 36, 34, 136, 2, 0, 0, 0));
				}
				//everything else
				else {
					m_Images.push_back(new Image("assets/sprites-ui.png", j * tileWidth, i * tileHeight, 32, 36, 34, 96, 2, 0, 0, 0));
				}
			}
			//bordered right
			else if (j == (m_vectorX - 1)) {
				//top
				if (i == 0) {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, 32, 36, 176, 53, 2, 0, 0, 0));
				}
				//bottom
				else if (i == (m_vectorY - 1)) {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, 32, 36, 176, 136, 2, 0, 0, 0));
				}
				//everything else
				else {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, 32, 36, 176, 96, 2, 0, 0, 0));
				}
			}
			//gray area 
			else {
				//top
				if (i == 0) {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, tileWidth, tileHeight, 72, 53, 2, 0, 0, 0));
				}
				//bottom
				else if (i == (m_vectorY - 1)) {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, tileWidth, tileHeight, 72, 136, 2, 0, 0, 0));
				}
				//everything else
				else {
					m_Images.push_back(new Image("assets/sprites-ui.png", (j * tileWidth) - 66, i * tileHeight, tileWidth, tileHeight, 72, 96, 2, 0, 0, 0));
				}
			}
		}
	}
	//game loop
	do {
		f_iinput = ui.getInput();
		if (f_iinput == QUIT) {
			quit();
		}
		else {
			//P(ui.getCommand()); //string of command
			//movement would go here
		}
		
		
		//python script
		m_scommand = ui.getCommand();

		//clear window
		SDL_RenderClear(m_pRenderer);

		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//draw images
		tmanager.draw(m_pRenderer, m_Images);
		//draw text
		tmanager.drawText(m_pRenderer, m_scommand);

		//render window
		SDL_RenderPresent(m_pRenderer);
	} while (m_brunning);
}
void Game::quit() {
	m_brunning = false;
}


Game::Game():SCREEN_HEIGHT(960), SCREEN_WIDTH(1200), m_brunning(false), m_pRenderer(0), m_pWindow(0) {
}
Game::~Game() {
	//sdl cleanup; font cleanup handled in tmanager
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
}