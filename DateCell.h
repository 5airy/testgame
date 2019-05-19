#pragma once 
#include "Cell.h"
//The player needs to get specific number of DATES. When the player passes by this cell, this 	number decreases by one.
class DateCell : public Cell {
public:
	static int number_of_dates;
	DateCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);

};