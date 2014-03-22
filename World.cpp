#include "World.h"
#include <iostream>

World::World(int h, int w):tileHeight(32), tileWidth(64) {
	//height and width as percentage of screen
	height = h * 2;
	width = w * 2;

	//size of vector, figure out how many tiles we need
	m_vectorY = (height / tileHeight*2);
	m_vectorX = (width / tileWidth*2);

	//populate tile vector
	for (int i = 0; i < m_vectorY; i++) {
		Map.push_back(std::vector <GameObject*>());
		for (int j = 0; j < m_vectorX; j++) {
			//first and last rows
			if (i == 0 || i == (m_vectorY - 1)) {
				Map[i].push_back(new Tile((j * tileWidth) - (tileWidth / 2)*j, (i * tileHeight) - (tileHeight / 2)*i, tileWidth, tileHeight, BLANK));
			}
			else {
				Map[i].push_back(new Tile((j * tileWidth) - (tileWidth / 2)*j, (i * tileHeight) - (tileHeight / 2)*i, tileWidth, tileHeight, BLANK));
			}
		}
	}
	Ioan = new Player(600, 400, 29, 37, 1);
}
void World::movePlayer(int d) {
	Ioan->setDirection(d);
	int oldX = Ioan->getX();
	int oldY = Ioan->getY();
	int newY = 0;
	int newX = 0;
	int speed = Ioan->getSpeed();
	const int direction = d;
	switch (d) {
	case UP:
		newY = oldY - speed;
		newX = oldX;
		break;
	case RIGHT:
		newX = oldX + speed;
		newY = oldY;
		break;
	case DOWN:
		newY = oldY + speed;
		newX = oldX;
		break;
	case LEFT:
		newX = oldX - speed;
		newY = oldY;
		break;
	}
	//set layer position
	Ioan->setX(newX);
	Ioan->setY(newY);
	//set camera position
	Cam1.setCamX(newX);
	Cam1.setCamY(newY);
}
void World::update() {
	//std::cout << Ioan->getY() << std::endl;
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
	f_Images.push_back(Ioan->getImage());
}
//interface for Camera->TextureManager
Camera World::getCamera() {
	return Cam1;
}
