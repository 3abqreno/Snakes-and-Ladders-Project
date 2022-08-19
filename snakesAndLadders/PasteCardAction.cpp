#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"cardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void PasteCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces(done)
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardPosition" parameter (its cell position) and set its data member (done)
	pOut->PrintMessage("Paste Card: Click on its Cell ...");
	cardPosition = pIn->GetCellClicked();

	// 3- Make the needed validations on the read parameters(done)
	if (cardPosition.GetCellNum() == 1)
	{
		pGrid->PrintErrorMessage("Error: You Can't Put Card on First Cell(1) , click to contuine ...");
		return;
	}
	if (cardPosition.GetCellNum() == -1)
	{
		pGrid->PrintErrorMessage("Error: You Can't Put Card out side the grid , click to contuine ...");
		return;
	}


	// 4- Clear status bar(done)
	pOut->ClearStatusBar();





}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::Execute()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first(done)
	ReadActionParameters();
	Card* Pcardnew;




	if (cardPosition.GetCellNum() != -1 && cardPosition.GetCellNum() != 1)
	{
		Grid* pGrid = pManager->GetGrid();
		Output* pOut = pGrid->GetOutput();
		Card* pCard = NULL;

		if (pGrid->GetClipboard())
		{
			int n = pGrid->GetClipboard()->GetCardNumber();
			switch (n)
			{
			case 1:
				Pcardnew = new CardOne(cardPosition);
				*Pcardnew = *(dynamic_cast<CardOne*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 2:
				Pcardnew = new CardTwo(cardPosition);
				*Pcardnew = *(dynamic_cast<CardTwo*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;


			case 3:
				Pcardnew = new CardThree(cardPosition);
				*Pcardnew = *(dynamic_cast<CardThree*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 4:
				Pcardnew = new CardFour(cardPosition);
					*Pcardnew = *(dynamic_cast<CardFour*>(pGrid->GetClipboard()));
					Pcardnew->setpos(cardPosition);
					pCard = Pcardnew;
					break;
			case 5:
				Pcardnew = new CardFive(cardPosition);
				*Pcardnew = *(dynamic_cast<CardFive*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 6:
				Pcardnew = new CardSix(cardPosition);
				*Pcardnew = *(dynamic_cast<CardSix*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 7:
				Pcardnew = new CardSeven(cardPosition);
				*Pcardnew = *(dynamic_cast<CardSeven*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 8:
				Pcardnew = new CardEight(cardPosition);
				*Pcardnew = *(dynamic_cast<CardEight*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;

			case 9:
				Pcardnew = new CardNine(cardPosition);
				*Pcardnew = *(dynamic_cast<CardNine*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;

			case 10:
				Pcardnew = new CardTen(cardPosition);
				*Pcardnew = *(dynamic_cast<CardTen*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;

			case 11:
				Pcardnew = new CardEleven(cardPosition);
				*Pcardnew = *(dynamic_cast<CardEleven*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			case 12:
				Pcardnew = new CardTwelve(cardPosition);
				*Pcardnew = *(dynamic_cast<CardTwelve*>(pGrid->GetClipboard()));
				Pcardnew->setpos(cardPosition);
				pCard = Pcardnew;
				break;
			}
			bool added = pGrid->AddObjectToCell(pCard);
			if (!added)
			{
				// Print an appropriate message
				pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
			}
		}

		else
		{
			pGrid->PrintErrorMessage("Error: Please Copy Card First ...");
		}
	}
}



