#include "ObstacleCell.h"
int ObstacleCell::number_of_obstacles = 0;

ObstacleCell::ObstacleCell(int r, int c) :Cell(r, c){
	number_of_obstacles++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\obstacle.jpg";
}
bool ObstacleCell::ActOn(Player* p){
	// to be edited..
	return true;
}
void ObstacleCell::Save(ofstream &f){
	f << "Obstacle Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;


}