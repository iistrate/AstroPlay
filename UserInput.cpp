#include "UserInput.h"


UserInput::UserInput(){

}
int UserInput::getInput() {
	if (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				pressed = UP;
				break;
			case SDLK_RIGHT:
				pressed = RIGHT;
				break;
			case SDLK_DOWN:
				pressed = DOWN;
				break;
			case SDLK_LEFT:
				pressed = LEFT;
				break;
			case SDLK_ESCAPE:
				pressed = QUIT;
				break;
			}
		case SDL_KEYUP:
			pressed = 0;
			break;
		case SDL_QUIT:
			pressed = QUIT;
			break;
		}
	}
	return pressed;
}