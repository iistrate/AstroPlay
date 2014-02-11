#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "Image.h"

class Tile : public GameObject {
private:
	Image* m_Image;
public:
	Tile(int x, int y, int w, int h);
	~Tile(){}
};

#endif // Tile.h