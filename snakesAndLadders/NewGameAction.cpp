#include"Grid.h"
#include "NewGameAction.h"
#include"Player.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp) {

}

void NewGameAction::ReadActionParameters() {
	//no parameters to be read
}
void NewGameAction::Execute() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Cell startCell =(CellPosition(1));
	CardNine::setOwner(NULL);
	CardTen::setOwner(NULL);
	CardEleven::setOwner(NULL);
	pGrid->SetEndGame(false);
	pGrid->SetcurrPlayerNumber(0);//sets current player to zero then goes through every player and resets his values
	for (int i = 0; i < 4; i++) {
		Player*  currplayer= pGrid->GetCurrentPlayer();
		currplayer->ClearDrawing(pOut);
		currplayer->SetTurnCount(0);//sets turncount to zero 
		pGrid->UpdatePlayerCell(currplayer, CellPosition(1));//makes player go to start
		currplayer->SetWallet(100);//sets wallet to default amount at start
		currplayer->setPrison(0);
		currplayer->Draw(pOut);//draws player after now he is at start
		pGrid->AdvanceCurrentPlayer();//advances so the loop goes through the 4 players
		
	}
	
}

NewGameAction::~NewGameAction() {

}



