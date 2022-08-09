#pragma once

#include "Action.h"

class PasteCardAction : public Action
{
	CellPosition cardPosition;

public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor


	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell
	virtual void ReadActionParameters();
	virtual ~PasteCardAction(); // A Virtual Destructor

};

