#include "World.h"
#include <iostream>

World::World(int h, int w):tileHeight(24), tileWidth(24) {
	//height and width as percentage of screen
	height = h * 0.7;
	width = w * 0.7;

	//size of vector, figure out how many tiles we need
	m_vectorY = height / tileHeight;
	m_vectorX = width / tileWidth;

	//populate tile vector
	for (int i = 0; i < m_vectorY; i++) {
		Map.push_back(std::vector <GameObject*>());
		for (int j = 0; j < m_vectorX; j++) {
			Map[i].push_back(new Tile(j * tileWidth, i * tileHeight, tileWidth, tileHeight, BLANK));
		}
	}
}
int World::getHeight() {
	return height;
}
int World::getWidth() {
	return width;
}
void World::getImages(std::vector < Image* > &f_Images) {
	for (int i = 0; i < m_vectorY; i++) {
		for (int j = 0; j < m_vectorX; j++) {
			f_Images.push_back(Map[i][j]->getImage());
		}
	}
}