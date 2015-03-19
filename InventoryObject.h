#ifndef INVENTORY_OBJECT_H
#define INVENTORY_OBJECT_H

#include "GameObject.h"

class InventoryObject: public GameObject {
private:
	int m_identifier;
	int m_weight;
public:
	InventoryObject(int identifier, int x, int y, int sx, int sy): m_identifier(identifier) {
	}
	int getIdentifier(void) {
		return m_identifier;
	}
	void setWeight(int weight) {
		m_weight = weight;
	}
	int getWeight(void) {
		return m_weight;
	}
};

#endif //Inventory.h