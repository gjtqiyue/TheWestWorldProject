#include "Miner.h"
#include "MinerState.h"

//Miner::Miner(int ID): BaseGameEntity(ID)
//{
//	myLocation = Location::shack;
//	myGoldCarried = 0;
//	myThirst = 0;
//	myFatigue = 0;
//	myMoneyInBank = 0;
//
//	// set up the FSM
//	myStateMachine = new StateMachine<Miner>(this);
//
//	myStateMachine->SetCurrentState(GoHomeAndSleep::getInstance());
//	myStateMachine->SetGlobalState(MinerGlobalState::getInstance());
//}

void Miner::Update()
{
	myThirst++;

	// execute the state
	//if (pCurrentState) { // make sure the pointer is valid
	//	pCurrentState->Execute(this);
	//}
}

Location Miner::getLocation() const
{
	return myLocation;
}

void Miner::ChangeLocation(Location newLocation)
{
	myLocation = newLocation;
}

void Miner::AddToGoldCarried(int n)
{
	myGoldCarried += 1;
}

void Miner::IncreaseFatigue()
{
	myFatigue += 1;
}

bool Miner::isPocketFull() const
{
	if (myGoldCarried > MAX_NUGGETS) {
		return true;
	}
	else {
		return false;
	}
}

bool Miner::isThirsty() const
{
	if (myThirst > MAX_THIRST) {
		return true;
	}
	else {
		return false;
	}
}
