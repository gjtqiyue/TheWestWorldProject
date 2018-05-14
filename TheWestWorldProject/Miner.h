#pragma once
#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "State.h"

class Miner : public BaseGameEntity
{
public:
	Miner(int ID);

	~Miner();

	void Update();

	void ChangeState(State*);

	// getters
	Location getLocation() const;

	// methods
	// chagne the location of the miner
	void ChangeLocation(Location newLocation);

	// dig the gold
	void AddToGoldCarried(int n);

	// increase fatigue
	void IncreaseFatigue();

	bool isPocketFull() const;
	bool isThirsty() const;



private:

	// max nugget
	static const int MAX_NUGGETS = 5;

	// max thirst
	static const int MAX_THIRST = 3;

	// a pointer to an instance of a State
	State * pCurrentState;

	// the place where the miner is situated
	// TODO should be changed to a location type
	Location myLocation;

	// the number of nuggets
	int myGoldCarried;

	// the money the miner has deposited in the bank
	int myMoneyInBank;

	// thrist of the miner
	int myThirst;

	// tiredness of the miner
	int myFatigue;


};

#endif

