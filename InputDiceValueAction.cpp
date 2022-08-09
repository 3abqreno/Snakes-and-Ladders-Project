#include "InputDiceValueAction.h"
#include"Grid.h"
#include "Player.h"
InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) :Action(pApp) {

}

void InputDiceValueAction::ReadActionParameters() //reads user input numberr
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("please enter number from 1-6");
	input = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

}

void InputDiceValueAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (input > 0 && input < 7) {
		
		(pGrid->GetCurrentPlayer())->Move(pGrid, input);//gets pointer to current player then Applies move function to the current player
		pGrid->AdvanceCurrentPlayer();
	}
	else {

		pGrid->PrintErrorMessage("you entered and invalid input. Click to continue ...");
	}


}

InputDiceValueAction::~InputDiceValueAction()  {

}
