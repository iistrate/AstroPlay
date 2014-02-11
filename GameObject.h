#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject {
private:
	int x;
	int y;
	int width;
	int height;
public:
	//setters
	void setY(int);
	void setX(int);
	void setW(int);
	void setH(int);
	//getters
	int getY();
	int getX();
	int getW();
	int getH();
};

#endif // end GameObject.h