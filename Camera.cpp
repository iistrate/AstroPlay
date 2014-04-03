#include "Camera.h"

Camera::Camera():m_icamX(0), m_icamY(0), m_bplayerCamera(false) {
	m_pImage = new Image("assets/camera.png", m_icamX, m_icamY, 48, 48, 0, 0, 1, false, 1, 1, true);
}
Camera::~Camera() {}

void Camera::setCamX(int i) {
	m_icamX = i;
	m_pImage->setX(i);
}
void Camera::setCamY(int i) {
	m_icamY = i;
	m_pImage->setY(i);
}
void Camera::setFollowPlayer(bool b) {
	m_bplayerCamera = b;
}
void Camera::move(int d) {

}

bool Camera::isFollowingPlayer() {
	return m_bplayerCamera;
}
int Camera::getCamY() {
	return m_icamY;
}
int Camera::getCamX() {
	return m_icamX;
}
Image* Camera::getImage() {
	return m_pImage;
}