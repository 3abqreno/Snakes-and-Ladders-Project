#include"CardTwelve.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardNine.h"
#include<fstream>

CardTwelve::CardTwelve(const CellPosition & pos):Card(pos)
{
	cardNumber = 12;

}
CardTwelve::~CardTwelve(void)
{
}
void CardTwelve::ReadCardParameters(Grid * pGrid){}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{


	int PriceNine = 0, PriceTen = 0, PriceEleven = 0;
	int MaximumPrice = 0;

	CardTen* CTen=new CardTen(position);
	CardEleven* CEleven=new CardEleven(position);
	CardNine* CNine=new CardNine(position);
	CTen->getOwner();
	CEleven->getOwner();
	CNine->getOwner();
	if (pPlayer == CTen->getOwner())// this to konow the ownership of the statoins that the playerowns
		PriceTen = CTen->getPrice();

	if (pPlayer == CNine->getOwner())
		PriceNine = CNine->getPrice();

	if (pPlayer == CEleven->getOwner())
		PriceEleven = CEleven->getPrice();
	// to know the most expensive station

	if (PriceNine > PriceTen)
		MaximumPrice = PriceNine;
	else
		MaximumPrice = PriceTen;
	if (MaximumPrice < PriceEleven)
		MaximumPrice = PriceEleven;

	if (MaximumPrice != 0)
	{
		Player* PoorPlayer = pGrid->GetleastPlayerWallet();// give the ownership to the poor player
		if (MaximumPrice == PriceNine)
			CNine->setOwner(PoorPlayer);
		else if (MaximumPrice == PriceTen)
			CTen->setOwner(PoorPlayer);
		else if (MaximumPrice == PriceEleven)
			CEleven->setOwner(PoorPlayer);
	}
}

void CardTwelve::Save(ofstream& OutFile, ObjectType Type) {
	if (Type == card)
	{
		OutFile << cardNumber << "\t" << position.GetCellNum() << endl;
	}

}

void CardTwelve::Load(ifstream& Infile, Grid* pGrid)
{
	pGrid->AddObjectToCell(this);
}