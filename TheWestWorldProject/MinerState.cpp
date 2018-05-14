#include "MinerState.h"
#include "Miner.h"
#include "EntityNames.h"
#include <iostream>

using namespace std;

//class Miner;

// State EnterMineAndDigForNugget
void EnterMineAndDigForNugget::Enter(Miner * pMiner)
{
	// if the miner is not already located at the gold mine
	// he must chagne location to the gold mine
	if (pMiner->getLocation() != Location::goldmine) {
		std::cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " 
			 << "Walkin' to the gold mine";

		pMiner->ChangeLocation(Location::goldmine);
	}
}

// asking to actually do work of this state
void EnterMineAndDigForNugget::Execute(Miner * pMiner)
{
	// the miner digs for gold until he is carrying in excess of MaxNuggets
	// if he gets thirsty during his digging he stops working
	// then he change state to go to the saloon for a whiskey

	// dig the gold
	pMiner->AddToGoldCarried(1);

	// digging is a hard work
	pMiner->IncreaseFatigue();

	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " 
		 << "Pickin' up a nugget";

	// if enough gold mined, go and put it in the bank
	if (pMiner->isPocketFull()) {
		pMiner->getFSM()->ChangeState(VisitBankAndDepositGold::getInstance());
	}

	// if thirsty
	if (pMiner->isThirsty()) {
		pMiner->getFSM()->ChangeState(QuenchThirst::getInstance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner * pMiner)
{
	// telling us the miner is going to leave the place
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		 << "Ah'm leavin' the gold mine wiht mah pockets full o' sweet gold";
}

EnterMineAndDigForNugget * EnterMineAndDigForNugget::getInstance()
{
	static EnterMineAndDigForNugget instance;

	return &instance;
}



// methods for State VisitBankAndDepositGold
void VisitBankAndDepositGold::Enter(Miner * pMiner)
{
}

void VisitBankAndDepositGold::Execute(Miner * pMiner)
{
}

void VisitBankAndDepositGold::Exit(Miner * pMiner)
{
}

VisitBankAndDepositGold * VisitBankAndDepositGold::getInstance()
{
	static VisitBankAndDepositGold instance;

	return &instance;
}


// State GoHomeAndSleep
void GoHomeAndSleep::Enter(Miner * pMiner)
{
}

void GoHomeAndSleep::Execute(Miner * pMiner)
{
}

void GoHomeAndSleep::Exit(Miner * pMiner)
{
}

GoHomeAndSleep * GoHomeAndSleep::getInstance()
{
	static GoHomeAndSleep instance;

	return &instance;
}


// State QuenchThirst
void QuenchThirst::Enter(Miner * pMiner)
{
}

void QuenchThirst::Execute(Miner * pMiner)
{
}

void QuenchThirst::Exit(Miner * pMiner)
{
}

QuenchThirst * QuenchThirst::getInstance()
{
	static QuenchThirst instance;

	return &instance;
}

void MinerGlobalState::Enter(Miner * pMiner)
{
}

void MinerGlobalState::Execute(Miner * pMiner)
{
}

void MinerGlobalState::Exit(Miner * pMiner)
{
}

MinerGlobalState * MinerGlobalState::getInstance()
{
	static MinerGlobalState instance;

	return &instance;
}
