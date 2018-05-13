#include "BaseGameEntity.h"



BaseGameEntity::BaseGameEntity(int newID)
{
	setID(newID);
}


BaseGameEntity::~BaseGameEntity()
{
}

void BaseGameEntity::Update()
{
}

int BaseGameEntity::getID() const
{
	return myID; 
}

// check the id to make sure the id is unique
// must be equal or greater than the next valid id otherwise a error is thrown
void BaseGameEntity::setID(int val)
{

	// check the new ID
	if (val < BaseGameEntity::myNextValidID) {
		// throw error
		
	}

	//myNextValidID
	// increment the avaliable id
	BaseGameEntity::myNextValidID = val + 1;

	// update the id
	myID = val;
}
