#pragma once
#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "State.h"
#include "MinerState.h"
#include "StateMachine.h"

class Miner : public BaseGameEntity
{
public:
	Miner(int id) :BaseGameEntity(id),
		myLocation(Location::shack),
		myGoldCarried(0),
		myMoneyInBank(0),
		myThirst(0),
		myFatigue(0)
	{
		myStateMachine = new StateMachine<Miner>(this);

		myStateMachine->SetCurrentState(GoHomeAndSleep::getInstance());
	}

	~Miner() { delete myStateMachine; };

	void Update();

	// get the state machine
	StateMachine<Miner>* getFSM() const {
		return myStateMachine;
	}

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

	// state machine
	StateMachine<Miner>* myStateMachine;

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

