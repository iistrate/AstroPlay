#ifndef CAMERA_H
#define CAMERA_H

class Camera {
private:
	int m_icamX;
	int m_icamY;
public:
	Camera():m_icamX(0), m_icamY(0) {}
	~Camera() {}
	//setters
	void setCamX(int);
	void setCamY(int);
	//getters
	int getCamX();
	int getCamY();
};

#endif // Camera.h