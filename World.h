#ifndef WORLD_H
#define WORLD_H

#include "Tile.h"
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
		INVENTORY,
		PLAYER,
		ENEMY
	};

	//holds world's images
	std::vector < Image* > m_Images;
	//holds tiles
	std::vector < std::vector < GameObject* > > Map;

public:
	//gets px height and width from Game
	World(int, int);
	~World(){}

	//getters
	int getHeight();
	int getWidth();
	void getImages(std::vector < Image* > &f_Images);
	
};

#endif // World.h