#include "Camera.h"


void Camera::setCamX(int i) {
	m_icamX = i;
}
void Camera::setCamY(int i) {
	m_icamY = i;
}

int Camera::getCamY() {
	return m_icamY;
}
int Camera::getCamX() {
	return m_icamX;
}