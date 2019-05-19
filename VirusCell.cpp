#include "VirusCell.h"
int VirusCell::number_of_viruses = 0;

VirusCell::VirusCell(int r, int c) :Cell(r, c){
	number_of_viruses++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\virus.jpg";
}
bool VirusCell::ActOn(Player* p){
	// to be edited..
	return true;
}
void VirusCell::Save(ofstream &f){
	f << "Virus Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;


}