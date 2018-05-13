#pragma once

class BaseGameEntity
{
public:
	BaseGameEntity(int);

	~BaseGameEntity();

	// update at each frame to update the state
	virtual void Update();

	int getID() const;

private:
	// every entity has an ID session number
	int myID;

	// each time a BaseGameEntity is instantiated, this number will get updated
	static int myNextValidID;
	
	// make sure the ID is set correctly
	void setID(int);
};



