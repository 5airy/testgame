#pragma once 
#include "Cell.h"
// LifeCell is a type of cell. When the player passes by this cell, his lifes increases +1.


class LifeCell : public Cell {
public:
	static int number_of_lifes;

	LifeCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);

};