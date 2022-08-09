#include "SaveGridAction.h"
#include"Ladder.h"
#include"Snake.h"
SaveGridAction:: SaveGridAction(ApplicationManager* pApp) : Action(pApp) {

}
SaveGridAction::~SaveGridAction() {
}

void SaveGridAction::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("ENTER THE FILE NAME");
	filename = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}


void SaveGridAction::Execute() {
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	ofstream Outfile((filename+".txt"), ios::out);
	Outfile << Ladder::getCounter() << endl;
	pGrid->SaveAll(Outfile, ladder);
	Outfile << Snake::getCounter() << endl;
	pGrid->SaveAll(Outfile, snake);
	
	Outfile << pGrid->GetCardNum() << endl;
	pGrid->SaveAll(Outfile,card);
	Outfile.close();

}