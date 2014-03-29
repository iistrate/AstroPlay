#ifndef CAMERA_H
#define CAMERA_H

#include "Image.h"

class Camera {
private:
	//camera position
	int m_icamX;
	int m_icamY;
	Image* m_pImage;
public:
	Camera();
	~Camera();
	//setters
	void setCamX(int);
	void setCamY(int);
	//getters
	int getCamX();
	int getCamY();
	Image* getImage();
};

#endif // Camera.h