#include "World.h"
#include <iostream>

World::World(int h, int w) {
	//height and width as percentage of screen
	height = h * 0.7;
	width = w * 0.7;

	//size of vector, figure out how many tiles we need
	const int vectorY = height / tileHeight;
	const int vectorX = width / tileWidth;

	//populate tile vector
	for (int i = 0; i < vectorY; i++) {
		Map.push_back(std::vector <Tile*>());
		for (int j = 0; j < vectorX; j++) {
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