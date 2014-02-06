#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>

class UserInput {
private:
	SDL_Event event;
	enum {
		UP = 1,
		RIGHT = 2,
		DOWN = 3,
		LEFT = 4
	};
	int pressed = 0;
public:
	UserInput();
	~UserInput() {}
	
	int getInput();

};

#endif // end UserInput.h