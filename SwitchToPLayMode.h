#pragma once
#include "Action.h"
#include"Input.h"
#include"Output.h"
#include"Grid.h"
class SwitchToPlayMode :
    public Action
{
		int mode; // 1 for design mode 2 for play mode

	public:
		SwitchToPlayMode(ApplicationManager* pApp);
		virtual void ReadActionParameters();
		virtual void Execute();
		virtual ~SwitchToPlayMode();

	
};

