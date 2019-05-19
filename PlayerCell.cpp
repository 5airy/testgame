#include "PlayerCell.h"

int PlayerCell::number_of_players = 0;

PlayerCell::PlayerCell(int row, int col) :Cell(row, col)
{
	number_of_players++;
	ImagePath = "images\\MenuItems\\Player.jpg";
}


PlayerCell::~PlayerCell()
{
}

bool PlayerCell::ActOn(Player* p)
{
	//Empty cell takes no action on player
	//it returns true as it is NOT an obstacle cell
	return true;
}

void PlayerCell::Save(ofstream &f){
	f << "Player Cell" << '\t' << getRow() + 1 << '\t' << getCol() + 1 << endl;
}