#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <SDL.h>
#include <string>

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
	std::string m_scommand = "";
public:
	UserInput();
	~UserInput() {}
	
	int getInput();
	std::string getCommand();

};

#endif // end UserInput.h