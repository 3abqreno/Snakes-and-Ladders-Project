#pragma once
#include "Card.h"
class CardFive :
    public Card
{

public:
	CardFive(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player

	virtual void Save(ofstream& OutFile, ObjectType Type);
	virtual void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardFive();

};

