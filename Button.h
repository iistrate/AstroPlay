#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"

class Button : public GameObject {
private:
	bool m_active;
public:
	Button::Button(int x, int y, int w, int h, Image* btnImage) : m_active(true) {
		m_x = x;
		m_y = y;
		m_width = w;
		m_height = h;
		m_Image = btnImage;
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
};

#endif