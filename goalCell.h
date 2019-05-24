#pragma once 
#include "Cell.h"
// GoalCell is a type of cell. The player aims to reach this cell to finish his level.

class GoalCell : public Cell {
public:
	static int number_of_goals;

	GoalCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);
	int Act(Player*p);

};
