#pragma once

#include "Card.h"

class CardEight : public Card
{
	static int prisonPrice;
	
public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	void Save(ofstream& OutFile, ObjectType Type);
	void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardEight(); // A Virtual Destructor
};

