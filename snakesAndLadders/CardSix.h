#pragma once
#include "Card.h"
class CardSix :
    public Card
{
	CellPosition cpos;
	int  cellnumber;  // data member  that will be read from the user 
public:
	
	CardSix(const CellPosition& pos); // A Constructor takes card position
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFour on the passed Player
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: cell needed to move to 
	CardSix(CellPosition pos, int n);
	virtual void Save(ofstream& OutFile, ObjectType Type);
	void Load(ifstream& Infile, Grid* pGrid);
	~CardSix();

};

