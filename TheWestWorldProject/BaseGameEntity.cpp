#ifndef ENTITY_H
#define ENTITY_H

#include "BaseGameEntity.h"
#include <cassert>

int BaseGameEntity::myNextValidID = 0;

BaseGameEntity::BaseGameEntity(int newID)
{
	setID(newID);
}

// check the id to make sure the id is unique
// must be equal or greater than the next valid id otherwise a error is thrown
void BaseGameEntity::setID(int val)
{

	// check the new ID
	assert((val >= myNextValidID) && "<BaseGameEntity::SetID>: invalid ID");

	//myNextValidID
	// increment the avaliable id
	myNextValidID = val + 1;

	// update the id
	myID = val;
}

#endif // !ENTITY_H