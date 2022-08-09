#include "CardTwo.h"
#include"Ladder.h"
CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{ 
	//no data to read 
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2- Moves the player forward to the start of the next ladder in the grid.
	// If no ladders ahead, do nothing.

	Ladder * nextladder = NULL;
	pGrid->PrintErrorMessage("you have reached card 2...i takes you to next Ladder...Click to continue");
	if (pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition()))
	{
		nextladder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());

	 pGrid->UpdatePlayerCell( pPlayer , nextladder->GetPosition());
	 
	  nextladder->Apply(pGrid, pPlayer);
	}
	else
	{
		pGrid->PrintErrorMessage("no ladders ahead click to continue ");



	}
}

CardTwo::~CardTwo()
{
}
void CardTwo::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}

void CardTwo::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}