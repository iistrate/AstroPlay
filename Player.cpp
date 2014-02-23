#include "Player.h"

Player::Player(int x, int y, int w, int h, int t):m_idirection(0), m_ispeed(20), m_bmoving(false) {
	m_Image = new Image("assets/sprites-astronaut.png", x, y, w, h, 0, 0, 1, false, 1, 1);
	m_x = x;
	m_y = y;
	m_width = w;
	m_height = h;
}
Player::~Player() {
	delete m_Image;
}
