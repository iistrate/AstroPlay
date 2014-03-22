#include "Player.h"

Player::Player(int x, int y, int w, int h, int t):m_idirection(0), m_ispeed(20), m_bmoving(false) {
	m_Image = new Image("assets/sprites-astronaut.png", x, y, w, h, 0, 0, 1, true, 1, 3, true);
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}
Player::~Player() {
	delete m_Image;
}
void Player::setDirection(int i) {
	if (m_idirection == LEFT) {
		m_Image->setFlipped(true);
	}
	else if (m_idirection == RIGHT) {
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
