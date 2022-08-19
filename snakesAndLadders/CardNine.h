#pragma once

#include "Card.h"
#include "Cards9_11.h"

class CardNine : public Cards9_11
{
	static int price;
	static int fees;//true mean Yes it has been sold false mean Not sold
	static Player* pOwn9;  //the owner

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data memb
	int getPrice()const;
	Player* getOwner()const;
	static void setOwner(Player *pPlayer);
	virtual void Save(ofstream& OutFile, ObjectType Type);
	virtual void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardNine(); // A Virtual Destructor

};

