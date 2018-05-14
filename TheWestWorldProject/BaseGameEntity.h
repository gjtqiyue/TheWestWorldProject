#pragma once
#ifndef BASEENTITY_H
#define BASEENTITY_H

class BaseGameEntity
{
public:
	BaseGameEntity(int);

	virtual ~BaseGameEntity() {};

	// update at each frame to update the state
	// more implementation in the extended class, =0 means no need to implement in this class
	virtual void Update() = 0;

	
	int getID() const { return myID; }

private:
	// every entity has an ID session number
	int myID;

	// each time a BaseGameEntity is instantiated, this number will get updated
	static int myNextValidID;
	
	// make sure the ID is set correctly
	void setID(int);
};

#endif // !BASEENTITY_H



