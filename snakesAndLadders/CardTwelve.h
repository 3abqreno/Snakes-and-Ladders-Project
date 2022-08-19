#pragma once

#include "Card.h"
class CardTwelve :	public Card
{
public:
		CardTwelve(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card12 on  Player
	                                                  
	virtual void Save(ofstream& OutFile, ObjectType Type);	// Saves the GameObject parameters to the file
	void Load(ifstream& Infile, Grid* pGrid);
	virtual ~CardTwelve();


};