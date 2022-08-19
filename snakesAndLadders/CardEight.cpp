#include "CardEight.h"


int CardEight::prisonPrice = 0;

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
}

CardEight::~CardEight(void)
{

}


void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();




	if (prisonPrice == 0) {
		pOut->PrintMessage("New CardEight: Enter Prison Price ...");
		prisonPrice = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}


void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->PrintErrorMessage("CardEight:you will be put into prison if you don't pay  " + to_string(prisonPrice) + "   Click to continue");
	
	pOut->PrintMessage("If you want to pay (yes) if not enter (no)");
	string answer = pIn->GetSrting(pOut);
	

	if (answer == "yes")
	{
		if ((pPlayer->GetWallet() - prisonPrice) > 0)
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - prisonPrice);
			pGrid->PrintErrorMessage("you purshased your way out of jail...click to continue");
		}
		else
		{

			pGrid->PrintErrorMessage("Unfortunately, you do not have enough money....click to continue");
			pPlayer->setPrison(3);
		}
	}
	else {
		pOut->ClearStatusBar();
		pPlayer->setPrison(3);
	}
	

}
void CardEight::Save(ofstream& OutFile, ObjectType Type) 
{
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() <<"\t"<<prisonPrice<<endl;
	}

}
void CardEight::Load(ifstream& Infile, Grid* pGrid)
{
	int p;
	Infile >> p;
	prisonPrice = p;
	pGrid->AddObjectToCell(this);
}