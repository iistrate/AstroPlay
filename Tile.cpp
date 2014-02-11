#include "Tile.h"

Tile::Tile(int x, int y, int w, int h) {
	m_Image = new Image("assets/sprites-tiles.64x64.bmp", x, y, w, h, 0, 32, 1, false, 1, 1);
}