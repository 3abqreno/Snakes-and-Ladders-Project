#include "Player.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	cancelRollDice = false;
	prison = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
		this->wallet=wallet;
	else {
		wallet = 0;
	}
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int turn) {
	if (turn >= 0 && turn <= 3) {
		turnCount = turn;
	}
}


int Player::getVcell()const {

	return pCell->GetCellPosition().VCell();
}


int Player::getHcell()const {

	return pCell->GetCellPosition().HCell();

}

int Player::GetJustRolledDiceNum()const {
	return justRolledDiceNum;
}

void Player::setCancelRollDice(bool cancel) {

	cancelRollDice = cancel;
}

void Player::setPrison(int turns) {
	prison = turns;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)


	// 3- Set the justRolledDiceNum with the passed diceNumber


	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	//creates new position object with the new cellnum
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)


	if (!pGrid->GetEndGame())//if the game is ended it doesn't move player
	{
		turnCount++;

		if (prison == 0)
		{
			justRolledDiceNum = diceNumber;
			if (turnCount == 3)//if it's the turn to take money it adds to wallet and returns 
			{
				SetWallet(wallet + 10 * diceNumber);
				turnCount = 0;
				return;
			}

			if (wallet > 0)//if player doesn't have coins it doesn't move him
			{

				int newcellnum = (CellPosition::GetCellNumFromPosition(pCell->GetCellPosition()) + diceNumber);
				if (newcellnum > NumVerticalCells * NumHorizontalCells)//checks if new cellnum is higher than allowed(99)
				{
					newcellnum = NumVerticalCells * NumHorizontalCells;
				}
				pGrid->UpdatePlayerCell(this, CellPosition(newcellnum));
				GameObject* currentobj = pCell->GetGameObject();//gets pointer of current gameobj

				if (currentobj != NULL)
				{

					currentobj->Apply(pGrid, this);//if there is an object it applies it's action to (this) player

				}
				if (newcellnum == NumHorizontalCells * NumVerticalCells)//if the player reachs top right corner it ends game
				{
					pGrid->SetEndGame(true);
				}
			}
		}
		else
		{

			if (turnCount == 3)
			{
				turnCount = 0;
			}
			prison--;
		}
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}



bool Player::isAfterPlayer(Player* nextPlayer) {
	
	if (this->GetCell()->GetCellPosition().GetCellNum()<nextPlayer->GetCell()->GetCellPosition().GetCellNum())//checks if nextplayer cellnum is higher than this player
	{
		return true;

	}
	else {
		return false;
	}

}