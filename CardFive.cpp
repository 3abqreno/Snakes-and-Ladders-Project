#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos):Card(pos) {
	cardNumber = 5;
}


void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	
	pGrid->PrintErrorMessage("this card moves you backward the same steps you moved which is :" + to_string(pPlayer->GetJustRolledDiceNum()) + "  click to continue");

	int movement = pPlayer->GetJustRolledDiceNum();      //takes the number of steps just moved and  makes the player remove again

	int currentpostion=pPlayer->GetCell()->GetCellPosition().GetCellNum(); //current postion that player in it
	pGrid->UpdatePlayerCell(pPlayer, currentpostion - movement);    // move backward by dicevalue
	
	GameObject* obj = pPlayer->GetCell()->GetGameObject();
	if ( obj!= NULL) {
		obj->Apply(pGrid, pPlayer);
	}
	
}

void CardFive::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}
CardFive::~CardFive()
{
}

void CardFive::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}