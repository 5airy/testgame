#include "LifeCell.h"
int LifeCell::number_of_lifes = 0;

LifeCell::LifeCell(int r, int c) :Cell(r, c){
	number_of_lifes++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\life.jpg";
}
bool LifeCell::ActOn(Player* p){
	// to be edited..
	return true;
}
void LifeCell::Save(ofstream &f){
	f << "Life Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;


}