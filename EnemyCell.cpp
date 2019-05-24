#include "EnemyCell.h"
int EnemyCell::number_of_enemies = 0;
EnemyCell::EnemyCell(int r, int c) :Cell(r, c){
	number_of_enemies++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\enemy.jpg";
}
bool EnemyCell::ActOn(Player* p){
	// to be edited..
	return true;
}
int EnemyCell::Act(Player*p){
	return 4;
}
void EnemyCell::Save(ofstream &f){
	f << "Enemy Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;

}
