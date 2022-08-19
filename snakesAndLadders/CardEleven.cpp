#include "CardEleven.h"



#include"Cards9_11.h"
CardEleven::CardEleven(const CellPosition& pos) : Cards9_11(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (10 here)

}
CardEleven::~CardEleven()
{
}

Player* CardEleven::pOwn11 = NULL;
int CardEleven::price = -1;
int CardEleven::fees = -1;


void CardEleven::ReadCardParameters(Grid* pGrid)
{
	Cards9_11::ReadCardParameters(pGrid, 11, fees, price);
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards9_11::Apply(pGrid, pPlayer, 11, pOwn11, fees, price);
}




int CardEleven::getPrice()const {
	return price;
}
Player* CardEleven::getOwner() const
{
	return pOwn11;
}
void CardEleven::setOwner(Player* pPlayer)
{
	pOwn11 = pPlayer;
}

void CardEleven::Save(ofstream& OutFile, ObjectType Type)
{
	if (Type == card)
	{
		Cards9_11::save(OutFile, Type, price, fees);

	}

}

void CardEleven::Load(ifstream& Infile, Grid* pGrid)
{

	Cards9_11::Load(Infile, pGrid, price, fees);

}