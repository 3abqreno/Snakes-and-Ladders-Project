#pragma once

#include "Card.h"

class Cards9_11 : public Card
{

public:

	Cards9_11(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid, int cardnum, int& fees, int& price); // Reads the parameters of CardOne which is: walletAmount
	virtual void Apply(Grid* pGrid, Player* pPlayer, int cardnum, Player*& pOwn, int fees, int price);
	virtual void save(ofstream& OutFile, ObjectType Type);
	virtual void save(ofstream& OutFile, ObjectType Type, int price, int fees) const;
	virtual void Load(ifstream& Infile, Grid* pGrid, int& price, int& fees);
};

