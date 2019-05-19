#pragma once 
#include "Cell.h"
// VirusCell is a type of cell. When the player passes by this cell, his directions will differ form what he actually need;
// For example, if the user clicks FORWARD, he will move to right (This will be randomly assigned).

class VirusCell : public Cell {
public:
	static int number_of_viruses;

	VirusCell(int r, int c); //default constructor
	bool ActOn(Player* p);
	void Save(ofstream &f);

};