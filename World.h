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
	World(void);
	~World(void);

	void update(void);
	void movePlayerCamera(int);

	//getters
	int getHeight(void);
	int getWidth(void);
	std::vector < Image* > getImages(void);

	Camera getCamera(void);	
	Player* getPlayer(void);
};

#endif // World.h