#include "Game.h"
#include <Python.h>

void Game::init(const char* title, int x, int y, int w, int h, int flags) {
	//game loop condition
	m_brunning = true;

	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);
		if (m_pWindow) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(m_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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


	//create PythonParser
	StringParser Sparser;
	Sparser.init();

	//create panel
	GameGUI.buildPanel(SCREEN_HEIGHT, SCREEN_WIDTH);

	//create world
	Askeron = new World();

	//set initial camera view
	Tmanager.setCamX(Askeron->getCamera().getCamX());
	Tmanager.setCamY(Askeron->getCamera().getCamY());

	//get images
	Askeron->getImages(m_Images_WORLD);
	GameGUI.getImages(m_Images_GUI);
	m_Images_MOVING.push_back(Askeron->getPlayer()->getImage());

	//debug
	m_DebugImages.push_back(Askeron->getCamera().getImage());

	//game loop
	do {
		f_iinput = Ui.getCommand();
		
		//get command from input
		m_scommand = Ui.getStringCommand();
		//send string to python and get sanitized string and list of commands as a vector of ints
		m_scommand = Sparser.parseString(m_icommand, m_scommand);
		Ui.setStringCommand(m_scommand);

		if (f_iinput == CAMERA_MODE && m_bcameraMode == false) {
			m_bcameraMode = true;
		}
		else if (f_iinput == CAMERA_MODE) {
			m_bcameraMode = false;
		}

		if (f_iinput == QUIT) {
			quit();
		}
		else {
			//move player
			if (f_iinput == UP || f_iinput == DOWN || f_iinput == LEFT || f_iinput == RIGHT) {
				if (m_bcameraMode) {
					Askeron->getCamera().move(f_iinput);
				}
				else {
					Askeron->getPlayer()->move(f_iinput);
					Askeron->movePlayerCamera(f_iinput);
				}
				//set camera view
				Tmanager.setCamX(Askeron->getCamera().getCamX());
				Tmanager.setCamY(Askeron->getCamera().getCamY());
			}
			else if (f_iinput == DEBUG_MODE) {
				m_bdebugMode = m_bdebugMode == true ? m_bdebugMode = false : m_bdebugMode = true;
			}
			//check for clicks
			if (f_iinput == LEFT_MOUSE_BUTTON) {
				if (Ui.getMouseX() >= 125 && Ui.getMouseX() <= 145) {
					if (Ui.getMouseY() >= 890 && Ui.getMouseY() <= 930) {
						//if there's commands
						if (m_icommand.size() > 0) {
							m_bexecute = true;
						}
					}
				}
			}
			//needs work
			if (m_bexecute && m_icommand.size() > 0) {
				Askeron->getPlayer()->move(m_icommand[m_commandCursor]);
				Askeron->movePlayerCamera(m_icommand[m_commandCursor]);
				m_commandCursor++;
				if (m_commandCursor > m_icommand.size() - 1) {
					m_commandCursor = 0;
					m_bexecute = false;
				}
			}
			//update game 
			Askeron->update();
		}


		//clear window
		SDL_RenderClear(m_pRenderer);

		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//draw images
		Tmanager.draw(m_pRenderer, m_Images_WORLD);
		Tmanager.draw(m_pRenderer, m_Images_GUI);
		Tmanager.draw(m_pRenderer, m_Images_MOVING);

		//draw command
		Tmanager.drawText(m_pRenderer, m_scommand, 20, 70, GLOBALS::COMMAND_PANEL_LINE_WRAP, true);
		//instruction settings
		Tmanager.drawText(m_pRenderer, "Please enter command: ", 20, 40);

		//Debug mode
		if (m_bdebugMode) {
			/*
			 * CMD_Window
			*/
			//image array size
			std::cout << "World Image Array Size: " << m_Images_WORLD.size() << std::endl;
			std::cout << "GUI Image Array Size: " << m_Images_GUI.size() << std::endl;
			std::cout << "MOVING Image Array Size: " << m_Images_MOVING.size() << std::endl;

			/*
			 * SDL_Window
			*/
			
			/*
				image
			*/
			Tmanager.draw(m_pRenderer, m_DebugImages);
			/*
				text
			*/
			//show command
			Tmanager.drawText(m_pRenderer, "Command: " + std::to_string(f_iinput), 750, 920);
			//show turn
			Tmanager.drawText(m_pRenderer, "TURN: " + std::to_string(m_turn) + "  FPS:" + std::to_string(m_fpsCap), 100, 920);
			//show mouse position
			Tmanager.drawText(m_pRenderer, "X: " + std::to_string(Ui.getMouseX()) + " Y: " + std::to_string(Ui.getMouseY()), 600, 920);
			//show camera x and y
			Tmanager.drawText(m_pRenderer, "Camera: X " + std::to_string(Askeron->getCamera().getCamX()) + " Y " + std::to_string(Askeron->getCamera().getCamY()), 450, 20);
			//show player x and y
			Tmanager.drawText(m_pRenderer, "Player: X " + std::to_string(Askeron->getPlayer()->getX()) + " Y " + std::to_string(Askeron->getPlayer()->getY()), 650, 20);
		}
		//render window
		SDL_RenderPresent(m_pRenderer);

		//cap fps
		fpsCap();
		//increase game turn
		m_turn++;

	} while (m_brunning);
	//close command parser
	Sparser.close();
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

Game::Game():SCREEN_HEIGHT(GLOBALS::SCREEN_HEIGHT), SCREEN_WIDTH(GLOBALS::SCREEN_WIDTH), m_brunning(false), m_pRenderer(0)
, m_pWindow(0), m_fps(0), m_fpsCap(GLOBALS::FPS_CAP), m_turn(0), m_bdebugMode(false), m_bcameraMode(false), m_bexecute(false), m_commandCursor(0) {
}
Game::~Game() {
	//sdl cleanup; font cleanup handled in tmanager
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
}