#include "DateCell.h"

int DateCell::number_of_dates = 0;
DateCell::DateCell(int r, int c) :Cell(r, c){

	number_of_dates++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\dates.jpg";
}
bool DateCell::ActOn(Player* p){
	// to be edited..
	return true;
}
void DateCell::Save(ofstream &f){
	f << "Date Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;
}
