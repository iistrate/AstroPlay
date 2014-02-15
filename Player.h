#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
private:

public:
	Player(int x, int y, int w, int h, int t);
	~Player(){}
};

#endif