#include "DeleteGameObject.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void DeleteGameObject::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Delete Game Object , Click on a object to delete :");
	cp = pIn->GetCellClicked();
	pOut->ClearStatusBar();




}
void DeleteGameObject::Execute() {
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	
	

	if (pGrid->RemoveObjectFromCell(cp))
	{
		
	}
	else {
		pGrid->PrintErrorMessage("There is no Game Object in this cell ");
	}

	

}
DeleteGameObject::~DeleteGameObject() {


}
