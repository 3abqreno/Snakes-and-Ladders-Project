#include "CardThree.h"
#include"Ladder.h"

CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree(void)
{
}


void CardThree::ReadCardParameters(Grid* pGrid)
{
	//no parameters to be read
}


void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	pGrid->PrintErrorMessage("you have reahed Card 3 it gives you an extra dice roll...click to continue");
	pGrid->SetcurrPlayerNumber(pGrid->getCurrPlayerNumber()-1);

}
void CardThree::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}
void CardThree::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}