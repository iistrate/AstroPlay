#ifndef CAMERA_H
#define CAMERA_H

#include "GLOBALS.h"
#include "Image.h"

class Camera {
private:
	//camera position
	int m_icamX;
	int m_icamY;
	int m_icamSpeed;
	bool m_bplayerCamera;
	Image* m_pImage;
public:
	Camera();
	~Camera();
	//setters
	void setCamX(int);
	void setCamY(int);
	void setFollowPlayer(bool);
	void move(int);
	//getters
	int getCamX();
	int getCamY();
	bool isFollowingPlayer();
	Image* getImage();
};

#endif // Camera.h