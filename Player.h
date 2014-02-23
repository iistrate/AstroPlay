#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

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
};

#endif