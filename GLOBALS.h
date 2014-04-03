#ifndef GLOBALS_H
#define GLOBALS_H

namespace GLOBALS {
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 960;
	const int LEVEL_HEIGHT = SCREEN_HEIGHT * 2;
	const int LEVEL_WIDTH = SCREEN_WIDTH * 2;

	const int FPS_CAP = 50;
}

//controls
enum {
	UP = 1,
	RIGHT,
	DOWN,
	LEFT,
	LEFT_MOUSE_BUTTON,
	RIGHT_MOUSE_BUTTON,
	QUIT = 9,
	DEBUG_MODE
};

#endif // end GLOBALS.h