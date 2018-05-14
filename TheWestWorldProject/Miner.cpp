#include "Miner.h"
#include "MinerState.h"

Miner::Miner(int ID): BaseGameEntity(ID)
{
	myGoldCarried = 0;
	myThirst = 0;
	myFatigue = 0;
	myMoneyInBank = 0;
}

Miner::~Miner()
{

}

void Miner::Update()
{
	myThirst++;

	// execute the state
	if (pCurrentState) { // make sure the pointer is valid
		pCurrentState->Execute(this);
	}
}

void Miner::ChangeState(State * pNewState)
{
	// try to check both pointers before calling it

	// exit the current state
	pCurrentState->Exit(this);

	// update the new state
	pCurrentState = pNewState;

	// enter the current state
	pCurrentState->Enter(this);
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
