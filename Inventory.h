#ifndef INVENTORY_H
#define INVENTORY_H

#include "InventoryObject.h"
#include <vector>

using std::vector;

class Inventory {
private:
	vector < InventoryObject* > m_Objects;
	int m_weight;
public:
	vector < InventoryObject* > getObjects(void) {
		return m_Objects;
	}
	InventoryObject* getObject(int identifier) {
		for (vector < InventoryObject*> ::size_type i = 0; i < m_Objects.size(); i++) {
			if (identifier == m_Objects[i]->getIdentifier()) {
				return m_Objects[i];
			}
		}
	}
	void setWeight(int weight) {
		m_weight = weight;
	}
	int getWeight(void) {
		return m_weight;
	}
};

#endif //Inventory.h