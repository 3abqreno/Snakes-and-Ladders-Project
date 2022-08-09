#include "SwitchToPlayMode.h"
SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp) {

}
SwitchToPlayMode:: ~SwitchToPlayMode() {
}
void SwitchToPlayMode::ReadActionParameters() {



}
void SwitchToPlayMode::Execute() {

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	pOut->CreatePlayModeToolBar();

}

 
