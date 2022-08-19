#include "Card.h"
#include "CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"cardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"

Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::setpos(const CellPosition& pos)
{
	position = pos;
}

void Card::Draw(Output* pOut) const
{
	pOut->DrawCell(position, cardNumber);
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"(done)

}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
}
void Card::Save(ofstream& OutFile, ObjectType Type) {

}

void Card::Load(ifstream& Infile, Grid* pGrid)
{

}
Card* Card::makeCopy(Card* Clipboard, Card* posCard) const
{
    Card* pCard = posCard;


    switch (posCard->GetCardNumber()) {
    case 1:
        Clipboard = new CardOne(pCard->GetPosition());
        *Clipboard = *posCard;;
        break;
    case 2:
        Clipboard = new CardTwo(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 3:
        Clipboard = new CardThree(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 4:
        Clipboard = new CardFour(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 5:
        Clipboard = new CardFive(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 6:
        Clipboard = new CardSix(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 7:
        Clipboard = new CardSeven(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 8:
        Clipboard = new CardEight(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 9:
        Clipboard = new CardNine(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 10:
        Clipboard = new CardTen(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 11:
        Clipboard = new CardThree(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    case 12:
        Clipboard = new CardTwelve(pCard->GetPosition());
        *Clipboard = *posCard;
        break;
    }
    return Clipboard;
}