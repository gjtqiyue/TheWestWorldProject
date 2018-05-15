#include "Miner.h"
#include "MinerState.h"

int Miner::myComfortLevel = 0;

Miner::Miner(int ID): BaseGameEntity(ID)
{
	myLocation = Location::shack;
	myGoldCarried = 0;
	myThirst = 0;
	myFatigue = 0;
	myMoneyInBank = 0;

	// set up the FSM
	myStateMachine = new StateMachine<Miner>(this);

	myStateMachine->SetCurrentState(GoHomeAndSleepTilRested::getInstance());
	myStateMachine->SetGlobalState(MinerGlobalState::getInstance());
}

void Miner::Update()
{
	myThirst++;

	myStateMachine->Update();
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

int Miner::BankSaving() const
{
	return myMoneyInBank;
}

int Miner::GoldCarried() const
{
	return myGoldCarried;
}

int Miner::ComfortLevel() const
{
	return myComfortLevel;
}

void Miner::DepositGold(int amount)
{
	myMoneyInBank += myGoldCarried;
	myGoldCarried = 0;
}

void Miner::setComfortLevel(int n)
{
	myComfortLevel += n;
}

void Miner::setThirst()
{
	myThirst = 0;
}

void Miner::Rest()
{
	if (myFatigue >= 2) {
		myFatigue-=2;
	}
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

bool Miner::isRested() const
{
	if (myFatigue == 0) {
		return true;
	}
	else {
		return false;
	}
}

