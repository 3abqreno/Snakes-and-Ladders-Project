
#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (startPos.HCell() != endPos.HCell()|| startPos.VCell() >= endPos.VCell())
		//checks for the cells if they are on the same 
		//checks that end cell is under start cell

	{
		startPos = CellPosition(-1, -1);
		endPos = startPos;
	}


	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	//checks if readactionparameters has returned valid cells or invalid with(-1,-1)

	Snake* pSnake = new Snake(startPos, endPos);
	
	if (startPos.IsValidCell() && !pGrid->isOverLappingGrid(pSnake)) {
		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}
	else {
		delete pSnake;

		pGrid->PrintErrorMessage("invalid Snake placment...click to continue");
	}


}
// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction


