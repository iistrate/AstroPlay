#include "Tile.h"

Tile::Tile(int x, int y, int w, int h, int t) {
	m_Image = new Image("assets/sprites-tileset.png", x, y, w, h, 0, 0, 1, false, 1, 1, false);
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