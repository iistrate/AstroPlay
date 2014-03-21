#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
#include "Player.h"
#include "Camera.h"
#include <vector>

class World {
private:
	//px h and w
	int height;
	int width;

	//tile height and width
	const int tileHeight;
	const int tileWidth;

	//tile vector size
	int m_vectorY;
	int m_vectorX;

	//tile type
	enum {
		BLANK,
		CLIFF,
	};
	enum {
		UP = 1,
		RIGHT,
		DOWN,
		LEFT,
		LEFT_MOUSE_BUTTON,
		RIGHT_MOUSE_BUTTON,
		QUIT = 9
	};

	//holds world's images
	std::vector < Image* > m_Images;
	//holds tiles
	std::vector < std::vector < GameObject* > > Map;

	//player
	Player* Ioan;
	//camera
	Camera* Cam;

public:
	//gets px height and width from Game
	World(int, int);
	~World();

	void update();
	void movePlayer(int);

	//getters
	int getHeight();
	int getWidth();
	void getImages(std::vector < Image* > &f_Images);
	int getCameraX();
	int getCameraY();	
};

#endif // World.h