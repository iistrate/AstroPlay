#include "World.h"
#include <iostream>

World::World(int h, int w):m_itileHeight(32), m_itileWidth(64) {
	//height and width as percentage of screen
	m_iheight = h * 2;
	m_iwidth = w * 2;

	//size of vector, figure out how many tiles we need
	m_vectorY = (m_iheight / m_itileHeight*2);
	m_vectorX = (m_iwidth / m_itileWidth*2);

	//populate tile vector
	for (int i = 0; i < m_vectorY; i++) {
		Map.push_back(std::vector <GameObject*>());
		for (int j = 0; j < m_vectorX; j++) {
			//first and last rows
			if (i == 0 || i == (m_vectorY - 1)) {
				Map[i].push_back(new Tile((j * m_itileWidth) - (m_itileWidth / 2)*j, (i * m_itileHeight) - (m_itileHeight / 2)*i, m_itileWidth, m_itileHeight, BLANK));
			}
			else {
				Map[i].push_back(new Tile((j * m_itileWidth) - (m_itileWidth / 2)*j, (i * m_itileHeight) - (m_itileHeight / 2)*i, m_itileWidth, m_itileHeight, BLANK));
			}
		}
	}
	Ioan = new Player(600, 400, 29, 37, 1);
	//initial cam setup
	PlayerCamera.setCamX(Ioan->getX() + 20);
	PlayerCamera.setCamY(Ioan->getY() + 60);
}
void World::movePlayer(int d) {
	//Player
	Ioan->setDirection(d);
	int oldX = Ioan->getX();
	int oldY = Ioan->getY();
	int newY = 0, newX = 0;
	int speed = Ioan->getSpeed();
	const int direction = d;
	//Camera
	int oldCamX = PlayerCamera.getCamX();
	int oldCamY = PlayerCamera.getCamY();
	int newCamX = 0, newCamY = 0;

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
	//set player position
	Ioan->setX(newX);
	Ioan->setY(newY);
	//set camera position
	PlayerCamera.setCamX(newCamX);
	PlayerCamera.setCamY(newCamY);
}
void World::update() {
	//std::cout << Ioan->getY() << std::endl;
}
int World::getHeight() {
	return m_iheight;
}
int World::getWidth() {
	return m_iwidth;
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
	return PlayerCamera;
}
