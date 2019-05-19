#include "Player.h"
#include "Grid.h"
#include "GUI.h"

Player::Player(Cell pos)
{
	PositionCell = pos;
	lives = 4;
	health = 100;
	score = 0;
	// Makes all the needed initialization
}

void Player::Move(Grid* pGrid, ActionType dir)
{
	// Take a copy of the position before change
	Cell oldPosition = PositionCell; 

	// Try to take a Move from Keyboard
	GUI* pGUI = pGrid->getGUI();
	//DIRECTION dir = pGUI->TakeMoveDirection(PositionCell);

	// Check if the Move is Possible (No Obstacles)
	pGrid->MoveIfPossible(&PositionCell, dir); // if the move is possible, position will be changed (passed by ref)

}

void Player::setPosition(Cell pos)
{
	PositionCell = pos;
}

void Player::IncreaseDate()
{
	date++;
}
int Player::getdate()
{
	return date;
}

void Player::IncreaseLife()
{
	lives++;
}

void Player::DecreaseLife()
{
	lives--;
}
