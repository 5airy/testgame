#include "Cell.h"
#include "Player.h"
#include "GUI.h"

Cell::Cell()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	row = -1;
	col = -1;
}

Cell::Cell(int r, int c)
{
	SetRow(r);
	SetCol(c);
}

bool Cell::SetRow(int c) // the setter of row (the setter here sets only if in the the cell is in grid range)
{
	if (c >= 0 && c < NumRowCells)
	{
		row = c;
		return true;
	}
	return false;
}

bool Cell::SetCol(int c) // the setter of col (the setter here sets only if in the the cell is in grid range)
{
	if (c >= 0 && c < NumColumnCells)
	{
		col = c;
		return true;
	}
	return false;
}

int Cell::getRow() const // the getter of row
{
	return row;
}

int Cell::getCol() const // the getter of col
{
	return col;
}

string Cell::getImage() const
{
	return ImagePath;
}


bool Cell::operator == (const Cell & other) const
{
	return (row == other.getRow()) && (col == other.getCol());
}

bool Cell::operator != (const Cell & other) const
{
	return !((*this) == other);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//returns true if current cell is not an obstacle
bool Cell::ActOn(Player* p)
{

	//Takes appropriate action on the player according to cell type
	//it should be overriden by each derived cell class

	return true;

}
void Cell::Save(ofstream &f){

	f << "TRY" << endl;
}
int Cell::Act(Player*p){
	return 0;
}

Cell::~Cell()
{}
