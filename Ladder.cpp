#include "Ladder.h"
#include "Snake.h"
#include "grid.h"
#include<fstream>

int Ladder::Counter = 0;

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	Counter++;

	///TODO: Do the needed validation
}



void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder.Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that

}



bool Ladder::isOverLapping(GameObject* newObj) const
{
	int thisStartVcell = this->GetPosition().VCell();
	int thisEndVcell = this->GetEndPosition().VCell();
	Ladder* newLadder = dynamic_cast<Ladder*>(newObj);

	if (newLadder != NULL) {
		int newStartVcell = newLadder->GetPosition().VCell();
		int newEndVcell = newLadder->GetEndPosition().VCell();
		if (!((thisStartVcell < newEndVcell && thisEndVcell < newEndVcell) || (thisStartVcell > newStartVcell && thisEndVcell > newStartVcell)))
		{
			return true;
		}

	}
	Snake* newSnake = dynamic_cast<Snake*>(newObj);
	if (newSnake != NULL) {
		if (thisEndVcell == newSnake->GetPosition().VCell()||thisStartVcell==newSnake->GetEndPosition().VCell())
		{
			return true;
		}

	}
	return false;

	


}
CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == ladder) {
		OutFile << position.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;
	}
}

void Ladder::Load(ifstream& Infile, Grid* pGrid)
{

	int startcellnum, endcellnum;
	Infile >> startcellnum >> endcellnum;
	GameObject* Pladder = new Ladder(CellPosition(startcellnum), CellPosition(endcellnum));

	pGrid->AddObjectToCell(Pladder);



}

int Ladder::getCounter() {
	return Counter;
}


Ladder::~Ladder()
{
	Counter--;
}
