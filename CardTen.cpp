#include "CardTen.h"

#include"Cards9_11.h"
#include<fstream>
CardTen::CardTen(const CellPosition& pos) : Cards9_11(pos) // set the cell position of the card
{
	cardNumber = 10; // set the inherited cardNumber data member with the card number (10 here)

}
CardTen::~CardTen()
{
}

Player* CardTen::pOwn10 = NULL;
int CardTen::price = -1;
int CardTen::fees = -1;


void CardTen::ReadCardParameters(Grid* pGrid)
{
	Cards9_11::ReadCardParameters(pGrid, 10, fees, price);
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Cards9_11::Apply(pGrid, pPlayer, 10, pOwn10, fees, price);
}



int CardTen::getPrice()const {
	return price;
}
Player* CardTen::getOwner() const
{
	return pOwn10;
}
void CardTen::setOwner(Player* pPlayer)
{
	pOwn10 = pPlayer;
}
void CardTen::Save(ofstream& OutFile, ObjectType Type)
{
    if (Type == card)
    {
        Cards9_11::save(OutFile, Type, price, fees);

    }

}

void CardTen::Load(ifstream& Infile, Grid* pGrid)
{
	
		Cards9_11::Load(Infile, pGrid, price, fees);
	
}