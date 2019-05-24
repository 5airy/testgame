#include "GoalCell.h"
int GoalCell::number_of_goals = 0;

GoalCell::GoalCell(int r, int c) :Cell(r, c){
	number_of_goals++;
	SetRow(r);
	SetCol(c);
	ImagePath = "images\\MenuItems\\goal.jpg";
}
bool GoalCell::ActOn(Player* p){
	// to be edited.

	return true;
}
int GoalCell::Act(Player*p){
	return 1;
}	

void GoalCell::Save(ofstream &f){
	f << "Goal Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;


}
