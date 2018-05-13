#pragma once
#include "BaseGameEntity.h"
#include "State.h"

class Miner : public BaseGameEntity
{
public:
	Miner(int ID);

	~Miner();

	void Update();

	void ChangeState(State*);

private:

	// a pointer to an instance of a State
	State * pCurrentState;

	// the place where the miner is situated
	// TODO should be changed to a location type
	int myLocation;

	// the number of nuggets
	int myGoldCarried;

	// the money the miner has deposited in the bank
	int myMoneyInBank;

	// thrist of the miner
	int myThirst;

	// tiredness of the miner
	int myFatigue;


};

