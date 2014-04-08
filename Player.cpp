#include "Player.h"
#include <iostream>

Player::Player(int x, int y, int w, int h, int t):m_idirection(0), m_ispeed(30), m_bmoving(false) {
	m_Image = new Image("assets/sprites-astronaut.png", x, y, w, h, 0, 0, 1, true, 1, 3, true);
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}
Player::~Player() {
	delete m_Image;
}
void Player::move(int d) {
	setDirection(d);
	m_idirection = d; 
	int oldX = m_x;
	int oldY = m_y;
	int newY = 0, newX = 0;
	switch (d) {
	case UP:
		newY = oldY - m_ispeed > 0 ? oldY - m_ispeed : oldY;
		newX = oldX;
		break;
	case RIGHT:
		newX = oldX + m_ispeed < GLOBALS::LEVEL_WIDTH ? oldX + m_ispeed : oldX;
		newY = oldY;
		break;
	case DOWN:
		newY = oldY + m_ispeed < GLOBALS::LEVEL_HEIGHT ? oldY + m_ispeed : oldY;
		newX = oldX;
		break;
	case LEFT:
		newX = oldX - m_ispeed > 0 ? oldX - m_ispeed : oldX;
		newY = oldY;
		break;
	}
	//set player position
	setX(newX);
	setY(newY);
}
void Player::setX(int x) {
	m_x = x;
	if (x > 0 && x < (GLOBALS::SCREEN_WIDTH - m_width)) {
		getImage()->setX(x);
	} 
}
void Player::setY(int y) {
	m_y = y;
	if (y > 0 && y < (GLOBALS::SCREEN_HEIGHT - m_height)) {
		getImage()->setY(y);
	}
}
void Player::setDirection(int i) {
	if ((i == LEFT && m_idirection == RIGHT)) {
		m_Image->setFlipped(true);
	}
	else if (i == RIGHT && m_idirection == LEFT) {
		m_Image->setFlipped(false);
	}
	else if (i == LEFT) {
		m_Image->setFlipped(true);
	}
	else if (i == RIGHT) {
		m_Image->setFlipped(false);
	}
	m_idirection = i;
}
void Player::setMoving(bool b) {
	m_bmoving = b;
}
void Player::setSpeed(int i) {
	m_ispeed = i;
}

int Player::getDirection() {
	return m_idirection;
}
bool Player::isMoving() {
	return m_bmoving;
}
int Player::getSpeed() {
	return m_ispeed;
}
