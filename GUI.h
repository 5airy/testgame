#pragma once
#include <fstream>
#include "DEFS.h"
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Cell.h"



#define WindowWidth		1100
#define WindowHeight	660
#define GridCellWidth	50		// Width of 1 CELL (Assume: Cells are squares: width = height)
#define ToolBarHeight	50		//Menu Bar Height (distance from top of window to bottom line of menu bar)
#define StatusBarHeight	60		//Status Bar Height
#define NumColumnCells	WindowWidth/ GridCellWidth	//No. of cells along X-axis  --->
#define NumRowCells	(WindowHeight-ToolBarHeight-StatusBarHeight)/GridCellWidth			//No. of cells along Y-axis   v


enum GUI_MODE	// Graphical user interface mode
{
	MODE_MENU,	// User intracting with menu
	MODE_GAME   // Game is running
};

enum MENU_ITEMS // The items of the Creat Grid Mode (you should add more items)
{
	// Note: Items MUST be ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_LOAD,
	ITM_SAVE,
	ITM_START,
	ITM_EXIT,
	ITM_ENEMY,
	ITM_DATE,
	ITM_OBS,
	ITM_GOAL,
	ITM_HOLE,
	ITM_LIFE,
	ITM_VIRUS,
	ITM_EMPTY,
	ITM_PLAYER,


	///TODO: Add more items names here

	MENU_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};

enum GAME_ITEMS // The items of the Game Mode (you should add more items)
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_CHOOSE_GRID,

	///TODO: Add more items names here

	PLAY_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};




//The Graphical User Interface class
//This class is responsible for getting all user input and drawing game objects
class GUI
{
private:
	window *pWind;	// Pointer to the Graphics Window 
	GUI_MODE InterfaceMode;
	ofstream myOutputFile;


	// Some Static Constant Data Members: ---------------------

	static const int

		MenuItemWidth = 50,		//Width of each item in menu bar menu

		WindWidth = WindowWidth,		// make it divisible by NumColumnCells
		WindHeight = WindowHeight; // the grid height (window width/2)


	color MsgColor;			// Messages color (usually used in statusbar)
	color BkGrndColor;		// Background color (grid background)
	color StatusBarColor;	// Status bar color (statusbar background)

	color GridLineColor;	// Color of the Lines separating adjacent cells
	color ObstacleColor;	// Color of the Obstacle (its background color)



public:
	GUI();

	// ========== Input Functions ==========

	void GetPointClicked(int &x, int &y, bool wait = true) const; // Gets real coordinates (x,y) where user clicks
	// ==> (wait=true) means: It waits and pauses the program till mouse click
	// ==> (wait=false) means: It does NOT wait 
	//     but take coordinates whenever a mouse click occurs after the call

	string GetSrting() const; // Returns a string entered by the user

	// ========== Game Input Functions ==========

	ActionType GetUserAction() const;	  // Reads the user click and map it to an action


	//DIRECTION TakeMoveDirection(const Cell& current) const;  // Reads Returns direction from keybaord 
	// Keyboard Keys: 'i'-> UP, 'j'-> Left, 'k'-> Down, 'l'-> Right
	//Cell GetCellClicked() const; // Waits for a mouse click and Returns the Clicked Cell
	// It is needed only in Create-Grid Mode
	// If the click is NOT on a cell, (-1,-1) is returned




	// ========== Output Functions ==========

	//window* CreateWind(int, int, int , int) const; // Creates the application window

	GUI_MODE getInterfaceMode() const;
	void setInterfaceMode(GUI_MODE);

	void ClearStatusBar() const;	// Clears the status bar
	void ClearGridArea() const;	    // Draws an empty grid (horizontal and vertical lines with empty cells)

	void CreateMenu(); 	// Creates Create-Grid mode toolbar menu
	void CreateGameModeToolBar(); 	// Creates Game mode toolbar menu

	void PrintMessage(string msg) const;	// Prints a message on Status bar

	// ========== Game Objects Drawing Functions ==========

	//void DrawObstacle(const Cell & cell) const;	// Draws an obstacle in the passed cell
	//void DrawGameObject(string imgPath, const Cell & cell) const; // Draws the passed image in the passed cell

	void DrawCell(const Cell *cell) const;		//Draws a cell
	// This will be used to draw a game object (enemy, player, friendlyItem, ...etc.)
	void ClearCell(const Cell & cell) const; // Clears a cell from any drawings ( Reset it to empty cell  )
	~GUI();
};