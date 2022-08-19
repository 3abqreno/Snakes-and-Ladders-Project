#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; 
}

CardFour::~CardFour(void)
{
}


void CardFour::ReadCardParameters(Grid* pGrid)
{
	//no parameters to be read here
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PrintErrorMessage("you have reached card 4 it prevents you from rolling dice once....click to continue");
	pPlayer->setPrison(1);
}

void CardFour::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}
void CardFour::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}