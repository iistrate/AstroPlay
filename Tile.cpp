#include "Tile.h"

Tile::Tile(int x, int y, int w, int h, int t) {
	//sprite x and y
	int sx = 0;
	int sy = 0;

	static int counter = 0;
	//48 is the line tile count
	if (t == EDGE_TOP) {
		sx = 9 * h/2;
		sy = 3 * w/2;
	} 
	else if (t == EDGE_BOTTOM) {
		sx = 9 * h / 2;
		sy = 3 * w / 2;
	}
	counter++;

	m_Image = new Image("assets/sprites-tileset.png", x, y, w, h, sx, sy, 1, false, 1, 1, false);
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_type = t;
}
Tile::~Tile() {
	delete m_Image;
	delete this;
}

void Tile::setType(int t) {
	m_type = t;
}
int Tile::getType() {
	return m_type;
}