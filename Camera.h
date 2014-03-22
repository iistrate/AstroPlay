#ifndef CAMERA_H
#define CAMERA_H

class Camera {
private:
	//camera position
	int m_icamX;
	int m_icamY;
public:
	Camera();
	~Camera();
	//setters
	void setCamX(int);
	void setCamY(int);
	//getters
	int getCamX();
	int getCamY();
};

#endif // Camera.h