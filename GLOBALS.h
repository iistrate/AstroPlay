#ifndef GLOBALS_H
#define GLOBALS_H

//my little helper
#define P(x) std::cout << #x << "'s value is " << x << std::endl;

namespace GLOBALS {
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 960;
	const int LEVEL_HEIGHT = SCREEN_HEIGHT * 2;
	const int LEVEL_WIDTH = SCREEN_WIDTH * 2;
	const int FPS_CAP = 90;
	const int COMMAND_PANEL_LINE_WRAP = 305;
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
	DEBUG_MODE,
	CAMERA_MODE
};
//tile type
enum {
	BLANK,
	EDGE_TOP,
	EDGE_BOTTOM,
};
//buttons
enum {
	CLOSE,
	PLAY,
	BACK,
	FORWARD,
	PAUSE
};
//image sets
enum {
	GUI,
	WORLD,
	MOVING
};
//layers
enum {
	BACKGROUND_LAYER = 1,
	MOVING_LAYER = 3,
	CONTROLS_LAYER = 9
};

#endif // end GLOBALS.h