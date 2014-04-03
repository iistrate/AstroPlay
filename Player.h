#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "GLOBALS.h"

class Player : public GameObject {
private:
	int m_idirection;
	int m_ispeed;
	bool m_bmoving;

public:
	Player(int x, int y, int w, int h, int t);
	~Player();

	void setDirection(int);
	void setSpeed(int);
	void setMoving(bool);

	int getDirection();
	int getSpeed();
	bool isMoving();
	void move(int);
};

#endif