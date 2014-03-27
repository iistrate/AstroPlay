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


	//create panel
	gameGUI.buildPanel(SCREEN_HEIGHT, SCREEN_WIDTH);

	//create world
	Askeron = new World(SCREEN_HEIGHT, SCREEN_WIDTH);

	//set initial camera view
	tmanager.setCamX(Askeron->getCamera().getCamX());
	tmanager.setCamY(Askeron->getCamera().getCamY());

	//get images
	Askeron->getImages(m_Images);
	gameGUI.getImages(m_Images);

	//init font
	tmanager.initFont();

	//game loop
	do {
		f_iinput = ui.getCommand();

		if (f_iinput == QUIT) {
			quit();
		}
		else {
			//P(ui.getStringCommand()); //string of command
			//move player
			if (f_iinput == UP || f_iinput == DOWN || f_iinput == LEFT || f_iinput == RIGHT) {
				Askeron->movePlayer(f_iinput);
				//set camera view
				tmanager.setCamX(Askeron->getCamera().getCamX());
				tmanager.setCamY(Askeron->getCamera().getCamY());
			}
			//update game 
			Askeron->update();
		}
		
		//python script
		m_scommand = ui.getStringCommand();

		//clear window
		SDL_RenderClear(m_pRenderer);

		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//draw images
		tmanager.draw(m_pRenderer, m_Images);

		//draw command
		tmanager.drawText(m_pRenderer, m_scommand, 20, 70);
		//instruction settings
		tmanager.drawText(m_pRenderer, "Please enter command: ", 20, 40);
		//show turn
		tmanager.drawText(m_pRenderer, "TURN: " + std::to_string(m_turn) + "  FPS:" + std::to_string(m_fpsCap), 100, 920);
		//show mouse position
		tmanager.drawText(m_pRenderer, "X: " + std::to_string(ui.getMouseX()) + " Y: " + std::to_string(ui.getMouseY()), 600, 920);
		//show command
		tmanager.drawText(m_pRenderer, "Command: " + std::to_string(f_iinput), 750, 920);
		//show camera x and y
		tmanager.drawText(m_pRenderer, "Camera: X " + std::to_string(Askeron->getCamera().getCamX()) + " Y " + std::to_string(Askeron->getCamera().getCamY()), 550, 20);

		//render window
		SDL_RenderPresent(m_pRenderer);

		fpsCap();
		m_turn++;

	} while (m_brunning);
}
void Game::fpsCap() {
	//time in seconds
	m_fps = SDL_GetTicks() / 1000;
	if (m_fps < 1000 / m_fpsCap) {
		//fps per seconds - time difference from when the loop started till the end in seconds
		SDL_Delay((1000 / m_fpsCap) - (m_fps / 1000));
	}
}
void Game::quit() {
	m_brunning = false;
}


Game::Game():SCREEN_HEIGHT(960), SCREEN_WIDTH(1200), m_brunning(false), m_pRenderer(0), m_pWindow(0), m_fps(0), m_fpsCap(50), m_turn(0) {
}
Game::~Game() {
	//sdl cleanup; font cleanup handled in tmanager
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
}