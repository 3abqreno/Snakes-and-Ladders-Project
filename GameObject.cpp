#include "GameObject.h"


GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}

bool GameObject::isOverLapping(GameObject * newObj) const {
	return true;
}

GameObject::~GameObject()
{
}


void GameObject::Load(ifstream& Infile, Grid* pGrid)
{

}