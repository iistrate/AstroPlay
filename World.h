#ifndef WORLD_H
#define WORLD_H

#include "GLOBALS.h"

#include "Tile.h"
#include "Player.h"
#include "Camera.h"
#include <vector>

class World {
private:
	//px h and w
	int m_iheight;
	int m_iwidth;

	//tile height and width
	const int m_itileHeight;
	const int m_itileWidth;

	//tile vector size
	int m_vectorY;
	int m_vectorX;

	//screen sizes
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;

	//tile type
	enum {
		BLANK,
		CLIFF,
	};

	//holds world's images
	std::vector < Image* > m_Images;
	//holds tiles
	std::vector < std::vector < GameObject* > > Map;

	//player
	Player* Ioan;
	//camera
	Camera PlayerCamera;

public:
	//gets px height and width from Game
	World();
	~World();

	void update();
	void movePlayerCamera(int);

	//getters
	int getHeight();
	int getWidth();
	void getImages(std::vector < Image* > &f_Images);

	Camera getCamera();	
	Player* getPlayer();
};

#endif // World.h