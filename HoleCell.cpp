#include "HoleCell.h"
int HoleCell::number_of_holes = 0;

HoleCell::HoleCell(int r, int c) :Cell(r, c){
	number_of_holes++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\hole.jpg";
}
bool HoleCell::ActOn(Player* p){
	// to be edited..
	return true;
}
void HoleCell::Save(ofstream &f){
	f << "Hole Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;

}