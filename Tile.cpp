#include "Tile.h"

Tile::Tile(int x, int y, int w, int h, int t) {
	m_Image = new Image("assets/sprites-tiles.64x64.bmp", x, y, w, h, 0, 32, 1, false, 1, 1);
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
	m_type = t;
}

void Tile::setType(int t) {
	m_type = t;
}
int Tile::getType() {
	return m_type;
}
