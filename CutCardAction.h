#pragma once
#include "Action.h"

class CutCardAction : public Action
{
	// [Action Parameters](done)
	CellPosition cardPosition;

public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();// 1- The first line of any Action Execution is to read its parameter first(done)
						  // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~CutCardAction(); // A Virtual Destructor



};

