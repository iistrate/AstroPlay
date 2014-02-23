#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>
#include <string>

class UserInput {
private:
	SDL_Event event;
	enum {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON,
		QUIT = 9
	};
	int m_ipressed;
	std::string m_scommand;
	//mouse x and y
	int m_imouseX;
	int m_imouseY;
public:
	UserInput();
	~UserInput() {}
	
	std::string getStringCommand();
	int getCommand();
	int getMouseX();
	int getMouseY();

};

#endif // end UserInput.h