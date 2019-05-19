#pragma once
#include "cell.h"
class PlayerCell : public Cell
{
public:
	static int number_of_players;
	PlayerCell(int row, int col);
	virtual ~PlayerCell();

	virtual bool ActOn(Player* p);
	void Save(ofstream &f);

};
