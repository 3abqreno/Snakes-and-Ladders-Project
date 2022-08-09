#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
#include"ApplicationManager.h"
#include<fstream>
//#include"Snake.h"

class SaveGridAction :

    public Action
{
    string filename;


public:
    SaveGridAction(ApplicationManager * pApp);
    virtual ~SaveGridAction();
    virtual void ReadActionParameters();
    virtual void Execute();


};

