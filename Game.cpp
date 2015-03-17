#include "Game.h"

//globals
void sortByLayer(std::vector < ImageSet* > &ImageSets);

void Game::run() {
	//init game
	int f_iinput = 0;
	init("Practicum", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	//create PythonParser
	StringParser Sparser;
	Sparser.init();

	Panel *ControlPanel = new Panel(SCREEN_WIDTH*0.26, SCREEN_HEIGHT, 0, 0);
	m_Images.push_back(new ImageSet(ControlPanel->getImages(), CONTROLS_LAYER, CONTROL_PANEL));
	m_BtnControlPanel = new Button(0, 0, 50, 50, new Image("assets/controlPanel.png", 0, 0, 50, 50, 0, 0, 1, 0, 1, 1, true), OPEN_CONTROL_PANEL);
	m_Images.push_back(new ImageSet(m_BtnControlPanel->getImage(), HIDDEN, OPEN_CONTROL_PANEL));


	//create world
	Mars = new World();

	//set initial camera view for the texture manager
	Tmanager.setCamX(Mars->getCamera().getCamX());
	Tmanager.setCamY(Mars->getCamera().getCamY());

	//get world image sets
	m_Images.push_back(new ImageSet(Mars->getImages(), BACKGROUND_LAYER, WORLD));
	//get player image
	m_Images.push_back(new ImageSet(Mars->getPlayer()->getImage(), MOVING_LAYER, MOVING));

	//debug mode camera image
	m_DebugImages.push_back(new ImageSet(Mars->getCamera().getImage(), MOVING_LAYER, MOVING));
	//game loop
	do {
		//get user input
		f_iinput = Ui.getCommand();
		
		//get command from input
		m_scommand = Ui.getStringCommand();
		//send string to python and get sanitized string and list of commands as a vector of ints
		m_scommand = Sparser.parseString(m_icommand, m_scommand);
		Ui.setStringCommand(m_scommand);

		//camera mode on/off
		if (f_iinput == CAMERA_MODE && m_bcameraMode == false) {
			m_bcameraMode = true;
		}
		else if (f_iinput == CAMERA_MODE) {
			m_bcameraMode = false;
		}
		//quit
		if (f_iinput == QUIT) {
			quit();
		}
		else {
			//move player
			if (f_iinput == UP || f_iinput == DOWN || f_iinput == LEFT || f_iinput == RIGHT) {
				if (m_bcameraMode) {
					Mars->getCamera().move(f_iinput);
				}
				else {
					Mars->getPlayer()->move(f_iinput);
					Mars->movePlayerCamera(f_iinput);
				}
				//set camera view
				Tmanager.setCamX(Mars->getCamera().getCamX());
				Tmanager.setCamY(Mars->getCamera().getCamY());
			}
			else if (f_iinput == DEBUG_MODE) {
				m_bdebugMode = m_bdebugMode == true ? m_bdebugMode = false : m_bdebugMode = true;
			}
			//check for clicks
			if (f_iinput == LEFT_MOUSE_BUTTON) {
				//check if mouse click location belongs to any buttons
				int mouseX = Ui.getMouseX();
				int mouseY = Ui.getMouseY();
				int buttonPressed = -1;
				std::vector < Button* > Buttons = ControlPanel->getButtons();
				for (int i = 0; i < Buttons.size(); i++) {
					if (Buttons[i]->isClicked(mouseX, mouseY)) {
						buttonPressed = Buttons[i]->getIdentifier();
					}
				}
				if (m_BtnControlPanel->isClicked(mouseX, mouseY)) {
					buttonPressed = m_BtnControlPanel->getIdentifier();
					P(buttonPressed);
				}
				switch (buttonPressed) {
				//close panel
				case CLOSE:
					for (int i = 0; i < m_Images.size(); i++) {
						if (m_Images[i]->getIdentifier() == CONTROL_PANEL) {
							m_Images[i]->hide();
						}
						else if (m_Images[i]->getIdentifier() == OPEN_CONTROL_PANEL) {
							m_Images[i]->reveal();
						}
					}
					m_showCommandPrompt = false;
					break;
				case OPEN_CONTROL_PANEL:
					for (int i = 0; i < m_Images.size(); i++) {
						if (m_Images[i]->getIdentifier() == CONTROL_PANEL) {
							m_Images[i]->reveal();
						}
						else if (m_Images[i]->getIdentifier() == OPEN_CONTROL_PANEL) {
							m_Images[i]->hide();
						}
					}
					m_showCommandPrompt = true;
					break;
				//play script
				case PLAY:
					//if there's commands
					if (m_icommand.size() > 0) {
						m_bexecute = true;
					}
					break;
				//pause script
				case PAUSE:
					//if there's commands
					if (m_icommand.size() > 0) {
						m_bexecute = false;
					}
					break;
				default:
					buttonPressed = -1;
					break;
				}
			}
			//execute written command
			if (m_bexecute && m_icommand.size() > 0) {
				Mars->getPlayer()->move(m_icommand[m_commandCursor]);
				Mars->movePlayerCamera(m_icommand[m_commandCursor]);
				m_commandCursor++;
				if (m_commandCursor > m_icommand.size() - 1) {
					m_commandCursor = 0;
					m_bexecute = false;
				}
			}
			//update game 
			Mars->update();
		}


		//clear window
		SDL_RenderClear(m_pRenderer);
		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
		
		//sort by zIndex CSS style :)
		sortByLayer(m_Images);
		//draw images
		for (std::vector < ImageSet* >::size_type i = 0; i < m_Images.size(); i++) {
			Tmanager.draw(m_pRenderer, m_Images[i]->getImages());
		}


		if (m_showCommandPrompt) {
			//draw command
			Tmanager.drawText(m_pRenderer, m_scommand, 20, 70, GLOBALS::COMMAND_PANEL_LINE_WRAP, true);
			//instruction settings
			Tmanager.drawText(m_pRenderer, "Please enter command: ", 20, 40);
		}
		else {
			//draw images
			for (std::vector < ImageSet* >::size_type i = 0; i < m_Images.size(); i++) {
				if (m_Images[i]->getIdentifier() == OPEN_CONTROL_PANEL) {
					Tmanager.draw(m_pRenderer, m_Images[i]->getImages());
				}
			}
		}

		//Debug mode
		if (m_bdebugMode) {
			/*
			 * CMD_Window
			*/
			//image array size
			for (std::vector < ImageSet* >::size_type i = 0; i < m_Images.size(); i++) {
				int identity = m_Images[i]->getIdentifier();
				if (identity == WORLD) {
					std::cout << "World Image Array Size: " << m_Images[i]->getImages().size() << std::endl;
				}
				else if (identity == GUI) {
					std::cout << "GUI Image Array Size: " << m_Images[i]->getImages().size() << std::endl;
				}
				else {
					std::cout << "MOVING Image Array Size: " << m_Images[i]->getImages().size() << std::endl;
				}
			}

			/*
			 * SDL_Window
			*/
			
			/*
				image
			*/
			Tmanager.draw(m_pRenderer, m_DebugImages[0]->getImages());
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
			Tmanager.drawText(m_pRenderer, "Camera: X " + std::to_string(Mars->getCamera().getCamX()) + " Y " + std::to_string(Mars->getCamera().getCamY()), 450, 20);
			//show player x and y
			Tmanager.drawText(m_pRenderer, "Player: X " + std::to_string(Mars->getPlayer()->getX()) + " Y " + std::to_string(Mars->getPlayer()->getY()), 650, 20);
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
, m_pWindow(0), m_fps(0), m_fpsCap(GLOBALS::FPS_CAP), m_turn(0), m_bdebugMode(false), m_bcameraMode(false), m_bexecute(false), 
m_commandCursor(0), m_showCommandPrompt(true) {
}

void Game::init(const char* title, int x, int y, int w, int h, int flags) {
	//game loop condition
	m_brunning = true;

	//drag and drop helpers
	m_shelpers.push_back("UP RIGHT DOWN LEFT ");
	m_shelpers.push_back("GET PUT INVENTORY ");
	m_shelpers.push_back("REPEAT IF ");

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
Game::~Game() {
	//sdl cleanup; font cleanup handled in tmanager
	SDL_Quit();
	SDL_DestroyWindow(m_pWindow);
	m_pWindow = 0;
	SDL_DestroyRenderer(m_pRenderer);
	m_pRenderer = 0;
}
//which layer to be drawn on top z-index style
void sortByLayer(std::vector < ImageSet* > &ImageSets) {
	//go through each of the image set
	for (int i = 0; i < ImageSets.size(); i++) {
		//and compare to each other one 
		for (int j = i + 1; j < ImageSets.size(); j++) {
			int zIndexOriginal = ImageSets[i]->getzIndex();
			int zIndexCompare = ImageSets[j]->getzIndex();
			//bigger zIndex gets added at end of list
			if (zIndexOriginal > zIndexCompare) {
				ImageSet* temp = ImageSets[i];
				ImageSets[i] = ImageSets[j];
				ImageSets[j] = temp;
			}
		}
	}
}