#include "GameObject.h"

//setters
void GameObject::setY(int i) {
	y = i;
}
void GameObject::setX(int i) {
	x = i;
}
void GameObject::setW(int i) {
	width = i;
}
void GameObject::setH(int i) {
	height = i;
}
//getters
int GameObject::getY() {
	return y;
}
int GameObject::getX() {
	return x;
}
int GameObject::getW() {
	return width;
}
int GameObject::getH() {
	return height;
}