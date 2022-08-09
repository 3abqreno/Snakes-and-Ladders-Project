#include "LoadGridAction.h"
#include"Grid.h"
#include"Ladder.h"
#include"Snake.h"
#include<fstream>
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void LoadGridAction::ReadActionParameters()
{
	
	 Grid * pGrid = pManager->GetGrid();
	Output *  pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter The File Name");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}

void LoadGridAction::Execute()
{
	Card* pCard=NULL;
	
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	
	ifstream Infile((filename + ".txt"));
	if (Infile.is_open())
	{
		pGrid->DeleteAllGameObject();
		int ladderNum;
		Infile >> ladderNum;

		for (int i = 0; i < ladderNum; i++)
		{	
			Ladder::Load(Infile, pGrid);
		}

		int  snakeNum;
		Infile >> snakeNum;

		for (int i = 0; i < snakeNum; i++)
		{
			Snake::Load(Infile, pGrid);
		}

		int  cardnum;
		Infile >> cardnum;

		for (int i = 0; i < cardnum; i++)
		{
			int num,cellnum;
			Infile >> num>> cellnum;
			switch (num)
			{
			case 1:
				pCard =  new CardOne(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 2:
			    pCard = new CardTwo(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 3:
				pCard = new CardThree(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 4:
				pCard = new CardFour(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 5:
				pCard = new CardFive(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 6:
				pCard = new CardSix(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 7:
				pCard = new CardSeven(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 8:
				pCard = new CardEight(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 9:
				pCard = new CardNine(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 10:
				pCard = new CardTen(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 11:
				pCard = new CardEleven(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			case 12:
				pCard = new CardTwelve(CellPosition(cellnum));
				pCard->Load(Infile, pGrid);
				break;
			}
		}

	}
	else
	{
		pGrid->PrintErrorMessage("There is no file with this name, try again Click to continue");
	}




}

LoadGridAction::~LoadGridAction()
{

}
