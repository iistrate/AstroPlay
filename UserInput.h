#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>

class UserInput {
private:
	SDL_Event event;
	enum m_Keys {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		QUIT = 9
	};
	int pressed = 0;
public:
	UserInput();
	~UserInput() {}
	
	int getInput();

};

#endif // end UserInput.h