#include "EmptyCell.h"

int EmptyCell::number_of_empties = 0;

EmptyCell::EmptyCell(int row, int col) :Cell(row, col)
{
	number_of_empties++;
	ImagePath = "images\\Cells\\EmptyCell.jpg";
}


EmptyCell::~EmptyCell(void)
{
}

bool EmptyCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}
void EmptyCell::Save(ofstream &f){
	// DO NOTIHNG YEEEEEEEES I FOUND MY ERROR HEEEEEEEEEEREEEEEEEEEEE
}
