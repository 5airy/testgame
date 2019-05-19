#pragma once 
#include "Cell.h"
// EnemyCell is a type of cell. When the player passes by this cell, he dies;

class EnemyCell : public Cell {
public:
	static int number_of_enemies;

	EnemyCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);

};