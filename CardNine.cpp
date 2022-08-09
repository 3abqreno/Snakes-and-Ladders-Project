#include "CardNine.h"
#include"Cards9_11.h"
#include<fstream>
CardNine::CardNine(const CellPosition& pos) : Cards9_11(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
	
}
CardNine::~CardNine()
{
}

Player* CardNine::pOwn9 = NULL;
int CardNine::price = -1;
int CardNine::fees = -1;


void CardNine::ReadCardParameters(Grid* pGrid)
{
	Cards9_11::ReadCardParameters(pGrid,9,fees,price);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards9_11::Apply(pGrid, pPlayer, 9, pOwn9, fees, price);
}

int CardNine::getPrice()const {
	return price;
}
Player* CardNine::getOwner() const
{
	return pOwn9;
}
void CardNine::setOwner(Player* pPlayer)
{
	pOwn9 = pPlayer;
}

void CardNine::Save(ofstream& OutFile, ObjectType Type)
{
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << "\t" << price << "\t" << fees << endl;

	}

}

void CardNine::Load(ifstream& Infile, Grid* pGrid)
{

	Cards9_11::Load(Infile, pGrid, price, fees);

}