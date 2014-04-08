#include "World.h"

//temp
#include <iostream>

World::World():m_itileHeight(32), m_itileWidth(64), SCREEN_HEIGHT(GLOBALS::SCREEN_HEIGHT), SCREEN_WIDTH(GLOBALS::SCREEN_WIDTH) {
	//height and width as percentage of screen
	m_iheight = GLOBALS::LEVEL_HEIGHT;
	m_iwidth = GLOBALS::LEVEL_WIDTH;

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
	Ioan = new Player(620, 490, 29, 37, 1);
	//initial cam setup
	PlayerCamera.setCamX(0);
	PlayerCamera.setCamY(0);
}
void World::movePlayerCamera(int d) {
	//player position
	int newX = Ioan->getX();
	int newY = Ioan->getY();
	int speed = Ioan->getSpeed();
	//Camera
	int oldCamX = PlayerCamera.getCamX();
	int oldCamY = PlayerCamera.getCamY();
	int origCamX = 0, origCamY = 0;
	int newCamX = origCamX, newCamY = origCamY;

	//set camera position
	//X pos
	if (newX > 1180 && d == RIGHT) {
		newCamX = oldCamX + speed;
	}
	else if (newX > 1180 && d == LEFT) {
		newCamX = oldCamX - speed;
	}
	else {
		newCamX = oldCamX;
	}
	//Y pos
	if (newY > 900 && d == UP) {
		newCamY = oldCamY - speed;
	}
	else if (newY > 900 && d == DOWN) {
		newCamY = oldCamY + speed;
	}
	else {
		newCamY = oldCamY;
	}
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
}
//interface for Camera->TextureManager
Camera World::getCamera() {
	return PlayerCamera;
}
//interface for Player->DebugMode
Player* World::getPlayer() {
	return Ioan;
}
