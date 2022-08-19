#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"Card.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}



void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces(done)
		///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
		// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces(done)
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardPosition" parameter (its cell position) and set its data member (done)
	pOut->PrintMessage("Cut Card: Click on its Card ...");
	cardPosition = pIn->GetCellClicked();

	// 3- Make the needed validations on the read parameters(done)
	if (cardPosition.GetCellNum() == -1)
	{
		pGrid->PrintErrorMessage("Error: There Is No Card In This Cell ,Plese Try Again, click to continue... ...");
	}

	// 4- Clear status bar(done)
	pOut->ClearStatusBar();

}

void CutCardAction::Execute()
{
	ReadActionParameters();


	Grid* pGrid = pManager->GetGrid(); //3- We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (cardPosition.GetCellNum() != -1)
	{
		Card* pCard = new Card(cardPosition);
		if(pGrid->SetClipboard(pCard))
		pGrid->RemoveObjectFromCell(pCard->GetPosition());
	}
}
