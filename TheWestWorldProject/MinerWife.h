#pragma once
#ifndef MINERWIFE_H
#define MINERWIFE_H

#include "BaseGameEntity.h"
#include "State.h"
#include "StateMachine.h"
#include "MinerWifeState.h"

class MinerWife : public BaseGameEntity
{
public:
	MinerWife(int);

	virtual ~MinerWife();

	void Update();

	StateMachine<MinerWife>* getFSM() const { return myStateMachine; }

	Location getLocation() const { return myLocation; }

	void ChangeLocation(Location loc) { myLocation = loc; }

private:
	// miner wife's state machine
	StateMachine<MinerWife>* myStateMachine;

	// location
	Location myLocation;
};

#endif

