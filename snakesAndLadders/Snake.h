#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"
	static int Counter;
	CellPosition endCellPos; // here is the ladder's End Cell Position

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	virtual bool isOverLapping(GameObject* newObj) const;
	static int getCounter();
	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	void Save(ofstream& OutFile, ObjectType Type);
	static void Load(ifstream& Infile, Grid* pGrid);


	virtual ~Snake(); // Virtual destructor
};

