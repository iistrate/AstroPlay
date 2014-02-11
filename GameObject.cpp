#include "GameObject.h"

//setters
void GameObject::setY(int i) {
	m_y = i;
}
void GameObject::setX(int i) {
	m_x = i;
}
void GameObject::setW(int i) {
	m_width = i;
}
void GameObject::setH(int i) {
	m_height = i;
}
//getters
int GameObject::getY() {
	return m_y;
}
int GameObject::getX() {
	return m_x;
}
int GameObject::getW() {
	return m_width;
}
int GameObject::getH() {
	return m_height;
}
Image* GameObject::getImage() {
	return m_Image;
}