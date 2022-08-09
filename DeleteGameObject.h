#pragma once
#include"Action.h"
#include"CellPosition.h"
#include"Grid.h"
#include"ApplicationManager.h"
#include"Output.h"
#include"Input.h"
#include"Cell.h"
class DeleteGameObject :
    public Action
{
    CellPosition cp;
public:
    DeleteGameObject(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~DeleteGameObject();
};

