#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"

class Button : public GameObject {
private:
	bool m_active;
	int m_identifier;
public:
	Button::Button(int x, int y, int w, int h, Image* btnImage, int identity) : m_active(true) {
		m_x = x;
		m_y = y;
		m_width = w;
		m_height = h;
		m_Image = btnImage;
		m_identifier = identity;
	}

	bool isActive(void) {
		return m_active;
	}
	bool isClicked(int x, int y) {
		if (x >= m_x && x <= m_x + m_width) {
			if (y >= m_y && y <= m_y + m_height) {
				return true;
			}
		}
		return false;
	}
	int getIdentifier(void) {
		return m_identifier;
	}
};

#endif