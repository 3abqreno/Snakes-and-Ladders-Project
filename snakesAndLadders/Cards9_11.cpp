#include "Cards9_11.h"
#include<fstream>
Cards9_11::Cards9_11(const CellPosition& pos) :Card (pos)
{
}

void Cards9_11::ReadCardParameters(Grid* pGrid,int cardnum, int &fees, int &price)
{
	//TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces from the Grid(done)
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read an Integer from the user using the Input class and set the  parameters
	
	if (fees == -1 && price == -1)
	{
		pOut->PrintMessage("New Card(" + to_string(cardnum) + ") : Enter its price ...");
		price = pIn->GetInteger(pOut);
		pOut->PrintMessage("New Card(" + to_string(cardnum) + "): Enter its fees ...");
		fees = pIn->GetInteger(pOut);
		// 3- Clear the status bar(done)
		pOut->ClearStatusBar();
	}

}

void Cards9_11::Apply (Grid* pGrid, Player* pPlayer,int cardnum , Player*&pOwn, int fees ,int price)
{
	int x, y;//parameters for get point clicked 
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Gives the player the option to buy this cell and all cells containing a card with the same number
	string answer;

	if (pOwn==NULL)
	{
		pOut->PrintMessage("Card"+ to_string(cardnum) +":  Do you want to buy these cards bearing the number( "+ to_string(cardnum) +" ) Price =" + to_string(price) + "   Click to continue");
		pIn->GetPointClicked(x, y);
		pOut->PrintMessage("If you want to enter (yes) if not enter (no)");
		answer = pIn->GetSrting(pOut);

		if (answer == "yes")
		{
			int w = pPlayer->GetWallet();
			if (w - price >= 0)
			{

				pPlayer->SetWallet(w - price);
				pOwn = pPlayer;
				pOut->PrintMessage("Congratulations, you have purchased all the cards bearing the number (" + to_string(cardnum) + ")...click to continue");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				
			}
			else
			{

				pOut->PrintMessage("Unfortunately, you do not have enough money....click to continue");
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else
		{
			pOut->PrintMessage(" Card was not purchased....click to continue");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}

	else
	{

		if (pPlayer != pOwn)
		{
			int x, y;
			int w = pPlayer->GetWallet();
			pPlayer->SetWallet(w - fees);
			pOut->PrintMessage("You have stood on card number "+ to_string(cardnum)+ ": Fees will be deducted...click to continue");
			pOwn->SetWallet(pOwn->GetWallet() + fees);
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();

		}
	}
}
void Cards9_11::save(ofstream& OutFile, ObjectType Type) {

}
void Cards9_11::save(ofstream& OutFile, ObjectType Type, int price, int fees)const

{
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << "\t" << price << "\t" << fees << endl;
	}

}

void Cards9_11::Load(ifstream& Infile, Grid* pGrid, int& price, int& fees)
{
	int p, f;
	Infile  >>p >> f;
	fees = f;
	price = p;
	pGrid->AddObjectToCell(this);

}