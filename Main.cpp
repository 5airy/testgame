#include "GUI.h"
#include "Player.h"
#include "Grid.h"

//This is a test code to test the Input and Output classes

int main()
{

	Grid *pGrid = new Grid;
	pGrid->RunApp();

	delete pGrid;

	return 0;
}