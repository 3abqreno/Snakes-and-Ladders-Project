#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}

CardSeven::~CardSeven(void)
{
}


void CardSeven::ReadCardParameters(Grid* pGrid)
{
	//no parameters to be read
}


void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("you have reached Card 7...it restarts the next player ahead of you...click to contiue");
	if (pGrid->getNextPlayer(pPlayer) != NULL) {
		pGrid->UpdatePlayerCell(pGrid->getNextPlayer(pPlayer), CellPosition(1));
	}
	else {
		pGrid->PrintErrorMessage("there is no player ahead to restart...click to continue");
	}
	
}

void CardSeven::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}
void CardSeven::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}