#pragma once 
#include "Cell.h"
// ObstacleCell is a type of cell. When the player passes by this cell, his lifes decreses -1;

class ObstacleCell : public Cell {
public:
	static int number_of_obstacles;

	ObstacleCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);

};