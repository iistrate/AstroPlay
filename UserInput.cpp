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
			case SDLK_LEFT:
				pressed = LEFT;
				break;
			}
			break;
		case SDL_KEYUP:
			pressed = 0;
			break;
		}
	}
	return pressed;
}