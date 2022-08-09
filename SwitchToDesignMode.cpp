#include "SwitchToDesignMode.h"
#include"NewGameAction.h"
SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) : Action(pApp) {
	pApp->ExecuteAction(NEW_GAME);
}
SwitchToDesignMode::~SwitchToDesignMode() {

}
void SwitchToDesignMode::ReadActionParameters() {
	


}
void SwitchToDesignMode::Execute() {
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	
	ReadActionParameters();
	pOut->CreateDesignModeToolBar();

}
