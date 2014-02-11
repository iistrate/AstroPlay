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
	const int tileHeight = 24;
	const int tileWidth = 24;

	//tile type
	enum {
		BLANK,
		INVENTORY,
		PLAYER,
		ENEMY
	};

	//holds world's images
	std::vector < Image* > m_Images;

public:
	World() {}
	//gets px height and width from Game
	World(int, int);
	~World(){}

	//getters
	int getHeight();
	int getWidth();

	std::vector < std::vector < Tile* > > Map;
};

#endif // World.h