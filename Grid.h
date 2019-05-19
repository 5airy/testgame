
#pragma once

#include "GUI.h"
#include "DEFS.h"
#include "Cell.h"
class Player;	//forward class declaration

class Grid
{
	GUI * pGUI;   // a pointer to the the interface
	Cell*	GameCells[NumRowCells][NumColumnCells];	// Array of Pointers to Cell
	Player* player;
	ecelltype GameCellsnum[NumRowCells][NumColumnCells] = { EMPTYC };
public:
	static int iEnemy, iDate, iObstacle, iHole, iGoal, iPlayer, iVirus, iLife, iEmpty;
	int x, y; //For locations
	int desiredRow, desiredColumn;
	Grid();

	// ========== Action-Related Functions ==========

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type

	void ExecuteAction(ActionType);  // Creates an action of the passed actionType and executes it
	void ExecuteAction(ActionType ActType, Cell* myCell);
	void setCell(int r, int c, Cell* pCell);	//updates cell r,c to hold the new pointer pCell
	void getClickedCell();
	bool MoveIfPossible(Cell * pCurrentCell, ActionType dir); // Moves the entered position in the passed direction if no obstacles
	// updates currentCell if move takes place
	// Note: It returns bool indicating if a move occured or not

	bool IsValidCell(int r, int c) const;
	void CheckAction(ActionType ActType, int Gamecellsnum);

	void DrawAllCells() const; // Draws the Grid and All its GameObjects


	GUI * getGUI() const;	// Gets a Pointer to the GUI

	~Grid();
	void RunApp();	//Runs the application
	void SaveAll(); // 
	//void Load(); // For load Operation OF COURSE
	void deleteTheCells(); // We'll use it in LOADING to delete all the available cells before loading
private:

};