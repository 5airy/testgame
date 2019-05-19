#pragma once
#include "cell.h"
class EmptyCell :
	public Cell
{
public:
	static int number_of_empties;
	EmptyCell(int row, int col);
	virtual ~EmptyCell();

	virtual bool ActOn(Player* p);
	void Save(ofstream &f);

};
