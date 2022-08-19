#include "CardSix.h"
#include<fstream>
#include<istream>
CardSix::CardSix(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6;        // set the inherited cardNumber data member with the card number (9 here)
}



void  CardSix::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();     //getting pointer to input and outputs interfaces from the grid 
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("please click cell needed to move to  ");  //message to instruct user what to choose cell 
	cpos = pIn->GetCellClicked();
	
 while (cpos.GetCellNum() == GetPosition().GetCellNum())
 { 
	 pGrid->PrintErrorMessage("You can't move to the card's cellnumber, please try again");
		cpos = pIn->GetCellClicked();	
 }
 cellnumber = cpos.GetCellNum();
 pOut->ClearStatusBar();

}
void CardSix::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();


	pOut->PrintMessage("this card takes you to cell number " + to_string(cellnumber) + "  click to continue");
	Input* pIn = pGrid->GetInput();
	pIn->GetCellClicked();

	pGrid->UpdatePlayerCell(pPlayer, cpos.GetCellPositionFromNum(cellnumber));
	pOut->ClearStatusBar();
}



void CardSix::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() <<"\t"<<cellnumber<< endl;
	}

}

void CardSix::Load(ifstream& Infile, Grid* pGrid)
{
	int cellnum;
	Infile >> cellnum;
	cellnumber = cellnum;
	cpos = CellPosition(cellnum);
	pGrid->AddObjectToCell(this);

}






CardSix::CardSix(CellPosition pos, int n) :Card(pos)
{
	cellnumber = n;
	cardNumber = 6;
}
CardSix::~CardSix() {

}