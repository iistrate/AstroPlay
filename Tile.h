#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "Image.h"

class Tile : public GameObject {
private:
	int m_type;
	
	Image* m_Image;
	
	enum {
		BLANK,
		INVENTORY,
		PLAYER,
		ENEMY
	};
public:
	Tile(int x, int y, int w, int h, int t);
	~Tile(){}

	void setType(int t);
	int getType();
};

#endif // Tile.h