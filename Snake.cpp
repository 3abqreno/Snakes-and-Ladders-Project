#include "Snake.h"
#include"Ladder.h"
#include "grid.h"

int Snake::Counter = 0;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	Counter++;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder.Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), endCellPos);
	//    Review the "pGrid" functions and decide which function can be used for that

}



bool Snake::isOverLapping(GameObject* newObj) const
{
	int thisStartVcell = this->GetPosition().VCell();
	int thisEndVcell = this->GetEndPosition().VCell();
	Snake* newSnake = dynamic_cast<Snake*>(newObj);

	if (newSnake != NULL) {
		int newStartVcell = newSnake->GetPosition().VCell();
		int newEndVcell = newSnake->GetEndPosition().VCell();
		if (!((thisStartVcell > newEndVcell && thisEndVcell > newEndVcell) || (thisStartVcell < newStartVcell && thisEndVcell < newStartVcell)))
		{
			return true;
		}

	}
	Ladder* newLadder = dynamic_cast<Ladder*>(newObj);
	if (newLadder != NULL)
	{
		if (thisStartVcell == newLadder->GetEndPosition().VCell()||thisEndVcell==newLadder->GetPosition().VCell())
		{
			return true;
		}

	}
	return false;

}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == snake) {
		OutFile << position.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;
	}
}

void Snake::Load(ifstream& Infile, Grid* pGrid)
{
	int startcellnum, endcellnum;
	Infile >> startcellnum >> endcellnum;
	GameObject* Psnake = new Snake(CellPosition(startcellnum), CellPosition(endcellnum));
	pGrid->AddObjectToCell(Psnake);
}



Snake::~Snake()
{
	Counter--;
}

int Snake::getCounter() {
	return Counter;
}
