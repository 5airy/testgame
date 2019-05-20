#include "Grid.h"
#include <iostream>
#include "Player.h"
#include "EmptyCell.h"
#include "PlayerCell.h"
#include "EnemyCell.h"
#include "ObstacleCell.h"
#include "DateCell.h"
#include "goalCell.h"
#include "HoleCell.h"
#include "LifeCell.h"
#include "VirusCell.h"
#include "EmptyCell.h"

Grid::Grid()
{
	// initializes all the GameObject pointer of the List to NULL
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)		{

			GameCells[i][j] = new EmptyCell(i, j);	//start with all cells as empty cells
			GameCellsnum[i][j] = EMPTYC;
		}
	}
	pGUI = new GUI;
	DrawAllCells();
	//ecelltype GameCellsnum[NumRowCells][NumColumnCells] = { EMPTYC };
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Moves the entered position in the passed direction if possible
// updates currentCell if move takes place
// Note: It returns bool indicating if a move occured or not
bool Grid::MoveIfPossible(Cell* pCurrentCell, ActionType dir)
{

	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int playerOldRow = pCurrentCell->getRow();
	int playerOldCol = pCurrentCell->getCol();

	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol;


	switch (dir)
	{
	case MOVE_UP:
		TargetRow--;
		break;
	case MOVE_DOWN:
		TargetRow++;
		break;
	case MOVE_LEFT:
		TargetCol--;
		break;
	case MOVE_RIGHT:
		TargetCol++;;
		break;
	}

	if (!IsValidCell(TargetRow, TargetCol))
		return false;

	//get the target cell
	Cell *pTargetCell = GameCells[TargetRow][TargetCol];

	if (!pTargetCell->ActOn(player))	//The target cell is an obstacle ==> no action should be taken
		return false;

	//The target cell is not an obstacle and has acted on the player
	//The player position should be updated to the target cell

	//Player should be moved to the target cell
	//1-delete the target cell and make it point to the PlayerCell
	setCell(TargetRow, TargetCol, pCurrentCell);

	//2- update player position
	pCurrentCell->SetRow(TargetRow);
	pCurrentCell->SetCol(TargetCol);

	//3- Convert the old player position to an Empty cell
	GameCells[playerOldRow][playerOldCol] = new EmptyCell(playerOldRow, playerOldCol);

	//4- Redraw both cells
	pGUI->DrawCell(GameCells[TargetRow][TargetCol]);
	pGUI->DrawCell(GameCells[playerOldRow][playerOldCol]);

	return true;
}

void Grid::DrawAllCells() const
{
	// Draw Empty Grid
	pGUI->ClearGridArea();

	// Draw all the GameObject of the Grid
	for (int i = 0; i < NumRowCells; i++)
	for (int j = 0; j < NumColumnCells; j++)
		pGUI->DrawCell(GameCells[i][j]);
}

void Grid::setCell(int row, int col, Cell* pCell)
{
	if (GameCells[row][col])
		delete GameCells[row][col];	//if cell ptr is not null, delete it first

	GameCells[row][col] = pCell;

}


GUI * Grid::getGUI() const
{
	return pGUI;
}
///////////////////////////////////////////////////////////////////
//				Action-related functions
///////////////////////////////////////////////////////////////////

ActionType Grid::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pGUI->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void Grid::ExecuteAction(ActionType ActType)
{
	// According to Action Type, create the corresponding action object	
	switch (ActType)
	{
	case LOAD:
		// Call Load function to load game from a file
		break;

	case SAVE:
		// Call Save function to Save current game to a file
		//pGUI->save()
		break;

	case START:	//start game 
		pGUI->setInterfaceMode(MODE_GAME);
		break;

	case PAUSE:	//pause game
		pGUI->setInterfaceMode(MODE_MENU);
		break;


		///TODO: Add a case for EACH Action type
	case MOVE_UP:
	case MOVE_DOWN:
	case MOVE_RIGHT:
	case MOVE_LEFT:
		player->Move(this, ActType);
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

}

void Grid::CheckAction(ActionType ActType, ecelltype GameCellsnum)
{
	switch (GameCellsnum)
	{
	case OBSTACLEC:
		//IGNORE THE MOVE;
		break;
	case DATEEC:
		player->IncreaseDate();
		player->Move(this, ActType);
		break;
	case ENEMYC:
		player->DecreaseLife();
		player->Move(this, ActType);
		break;
	case GOALC:
		pGUI->PrintMessage("Congeratulations!!");
		player->Move(this, ActType);
		break;
	case HOLEC:

		break;
	case LIFEC:
		player->IncreaseLife();
		player->Move(this, ActType);
		break;
	case VIRUSC:
		break;
	case EMPTYC:
		player->Move(this, ActType);
		break;
	}
}


Grid::~Grid()
{
	delete pGUI;
}

//////////////////////////////////////////////////////////////////////////////////


// Runs the application

void Grid::RunApp()
{
	int row = 7, col = 12;
	PlayerCell* pCell = new PlayerCell(row, col);
	setCell(row, col, pCell);
	player = new Player(*pCell);
	pGUI->DrawCell(pCell);

	EnemyCell* enemy[100]; DateCell* datee[100]; ObstacleCell* obstacle[100]; GoalCell* goal[100]; HoleCell* hole[100]; LifeCell* life[100];
	VirusCell* virus[100]; EmptyCell* empty[100]; PlayerCell* playerarr[100];

	while (1)
	{
		static int iEnemy = -1, iDate = -1, iObstacle = -1, iHole = -1, iGoal = -1, iPlayer = -1, iVirus = -1, iLife = -1, iEmpty = -1;
		ActionType act = GetUserAction();
		if (act == EXIT)
			return;
		ExecuteAction(act, pCell);
		if (act == ENEMY){
			iEnemy++;
			enemy[iEnemy] = new EnemyCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, enemy[iEnemy]);
			pGUI->DrawCell(enemy[iEnemy]);
			GameCellsnum[desiredRow][desiredColumn] = ENEMYC;
		}
		else if (act == DATEE){
			iDate++;
			datee[iDate] = new DateCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, datee[iDate]);
			pGUI->DrawCell(datee[iDate]);
			GameCellsnum[desiredRow][desiredColumn] = DATEEC;
		}
		else if (act == OBSTACLE){
			iObstacle++;
			obstacle[iObstacle] = new ObstacleCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, obstacle[iObstacle]);
			pGUI->DrawCell(obstacle[iObstacle]);
			GameCellsnum[desiredRow][desiredColumn] = OBSTACLEC;
		}
		else if (act == GOAL){
			iGoal++;
			goal[iGoal] = new GoalCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, goal[iGoal]);
			pGUI->DrawCell(goal[iGoal]);
			GameCellsnum[desiredRow][desiredColumn] = GOALC;
		}
		else if (act == HOLE){
			iHole++;
			hole[iHole] = new HoleCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, hole[iHole]);
			pGUI->DrawCell(hole[iHole]);
			GameCellsnum[desiredRow][desiredColumn] = HOLEC;
		}
		else if (act == LIFE){
			iLife++;
			life[iLife] = new LifeCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, life[iLife]);
			pGUI->DrawCell(life[iLife]);
			GameCellsnum[desiredRow][desiredColumn] = LIFEC;
		}
		else if (act == VIRUS){
			iVirus++;
			virus[iVirus] = new VirusCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, virus[iVirus]);
			pGUI->DrawCell(virus[iVirus]);
			GameCellsnum[desiredRow][desiredColumn] = VIRUSC;
		}
		else if (act == EMPTY){
			iEmpty++;
			empty[iEmpty] = new EmptyCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, empty[iEmpty]);
			pGUI->DrawCell(empty[iEmpty]);
			GameCellsnum[desiredRow][desiredColumn] = EMPTYC;
		}
		else if (act == PLAYER){
			iPlayer++;
			playerarr[iPlayer] = new PlayerCell(desiredRow, desiredColumn);
			setCell(desiredRow, desiredColumn, playerarr[iPlayer]);
			pGUI->DrawCell(playerarr[iPlayer]);
			GameCellsnum[desiredRow][desiredColumn] = PLAYERC;
		}
		else if (act == LOAD)
		{
			deleteTheCells();
			string filename;
			cout << "Choose the name of the file to load from [add .txt]: ";
			cin >> filename;
			ifstream infile; infile.open(filename);
			string celltype; string loadedRow, loadedColumn;
			int lRow, lCol;
			getline(infile, celltype, '\n'); //Get the first line (Will be ignored)
			getline(infile, celltype, '\n'); //Get the second line (Will be ignored)
			while (!infile.eof()){
				getline(infile, celltype, '\t'); //The cell type is now SAVED HERE;
				getline(infile, loadedRow, '\t'); //The row number is now SAVED.
				getline(infile, loadedColumn, '\n');//The column number is now SAVED.
				lRow = stoi(loadedRow); lCol = stoi(loadedColumn); // convert string to INTEGER
				lRow--; lCol--; // Minus ONE, because the rows and columns indexes start from 0;

				if (celltype == "Enemy Cell"){
					iEnemy++;
					enemy[iEnemy] = new EnemyCell(lRow, lCol);
					GameCells[lRow][lCol] = enemy[iEnemy];
					pGUI->DrawCell(enemy[iEnemy]);
				}
				else if (celltype == "Player Cell"){
					iPlayer++;
					playerarr[iPlayer] = new PlayerCell(lRow, lCol);
					GameCells[lRow][lCol] = playerarr[iPlayer];
					pGUI->DrawCell(playerarr[iPlayer]);
				}
				else if (celltype == "Obstacle Cell"){
					iObstacle++;
					obstacle[iObstacle] = new ObstacleCell(lRow, lCol);
					GameCells[lRow][lCol] = obstacle[iObstacle];
					pGUI->DrawCell(obstacle[iObstacle]);
				}
				else if (celltype == "Hole Cell"){
					iHole++;
					hole[iHole] = new HoleCell(lRow, lCol);
					GameCells[lRow][lCol] = hole[iHole];
					pGUI->DrawCell(hole[iHole]);
				}
				else if (celltype == "Goal Cell"){
					iGoal++;
					goal[iGoal] = new GoalCell(lRow, lCol);
					GameCells[lRow][lCol] = goal[iGoal];
					pGUI->DrawCell(goal[iGoal]);
				}
				else if (celltype == "Virus Cell"){
					iVirus++;
					virus[iVirus] = new VirusCell(lRow, lCol);
					GameCells[lRow][lCol] = virus[iVirus];
					pGUI->DrawCell(virus[iVirus]);
				}
				else if (celltype == "Life Cell"){
					iLife++;
					life[iLife] = new LifeCell(lRow, lCol);
					GameCells[lRow][lCol] = life[iLife];
					pGUI->DrawCell(life[iLife]);
				}
				else if (celltype == "Date Cell"){
					iDate++;
					datee[iDate] = new DateCell(lRow, lCol);
					GameCells[lRow][lCol] = datee[iDate];
					pGUI->DrawCell(datee[iDate]);
				}
			}
		}
		pGUI->PrintMessage(" ");
		Sleep(100);
	}
}

////////////////////////////////////////////////////////////////////////////////////
bool Grid::IsValidCell(int row, int col) const
{
	return (row >= 0 && row < NumRowCells)
		&& (col >= 0 && col < NumColumnCells);
}


void Grid::getClickedCell(){
	pGUI->GetPointClicked(x, y);
	desiredRow = (y - ToolBarHeight) / GridCellWidth;
	desiredColumn = x / GridCellWidth;
}

// Creates aother action and executes it [special one made by SAYED to be applicable to use it with SAVING 
void Grid::ExecuteAction(ActionType ActType, Cell* myCell)
{
	//Calculate the row and col of the cell to move to
	//First initialize them as current row and col
	int playerOldRow = myCell->getRow();
	int playerOldCol = myCell->getCol();
	int TargetRow = playerOldRow;
	int TargetCol = playerOldCol;
	// According to Action Type, create the corresponding action object	
	switch (ActType)
	{
	case LOAD:
		// Call Load function to load game from a file
		break;

	case SAVE:
		// Call Save function to Save current game to a file
		SaveAll();
		break;

	case START:	//start game 
		pGUI->setInterfaceMode(MODE_GAME);
		break;

	case PAUSE:	//pause game
		pGUI->setInterfaceMode(MODE_MENU);
		break;
	case OBSTACLE:
	case DATEE:
	case ENEMY:
	case GOAL:
	case HOLE:
	case LIFE:
	case VIRUS:
	case EMPTY:
	case PLAYER:
		pGUI->setInterfaceMode(MODE_MENU);
		pGUI->PrintMessage("Choose The Desired Cell");
		getClickedCell();
		break;

		///TODO: Add a case for EACH Action type
	case MOVE_UP:
		//TargetRow--;
		CheckAction(ActType, GameCellsnum[playerOldRow-1][playerOldCol]);
		break;
	case MOVE_DOWN:
		//TargetRow++;
		CheckAction(ActType, GameCellsnum[playerOldRow+1][playerOldCol]);
		break;
	case MOVE_RIGHT:
		//TargetCol++;
		CheckAction(ActType, GameCellsnum[playerOldRow][playerOldCol+1]);
		break;
	case MOVE_LEFT:
	//	TargetCol--;
		CheckAction(ActType, GameCellsnum[playerOldRow][playerOldCol-1]);
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;
	}

}

void Grid::SaveAll(){
	ofstream of; string filename;
	cout << "Choose the name of the file [add .txt]: ";
	cin >> filename;
	of.open(filename); //Open the file to write in  
	of << "Player Information" << endl;
	int numberOfNECells = PlayerCell::number_of_players + GoalCell::number_of_goals + HoleCell::number_of_holes + ObstacleCell::number_of_obstacles +
		DateCell::number_of_dates + EnemyCell::number_of_enemies + LifeCell::number_of_lifes + VirusCell::number_of_viruses;
	of << "Number of non-empty Cells = " << numberOfNECells << endl;
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)
		{
			if (GameCells[i][j]) // not null; 
				GameCells[i][j]->Save(of);
		}
	}
}

void Grid::deleteTheCells(){
	for (int i = 0; i < NumRowCells; i++)
	{
		for (int j = 0; j < NumColumnCells; j++)
		{
			if (GameCells[i][j]) // not null;
			{
				delete GameCells[i][j]; // Clear up all the pointers
			}
		}
	}
}