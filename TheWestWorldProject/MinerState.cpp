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
	if (pMiner->getLocation() != goldmine) {
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": " 
			 << "Walkin' to the gold mine";

		pMiner->ChangeLocation(goldmine);
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
	// change the location of miner
	if (pMiner->getLocation() != bank) {
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			 << "Goin' to the bank. Yes siree";

		pMiner->ChangeLocation(bank);
	}

	
}

void VisitBankAndDepositGold::Execute(Miner * pMiner)
{
	pMiner->DepositGold(pMiner->GoldCarried());

	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		 << "Depositin' gold. Total saving now: " << pMiner->BankSaving();

	// go home and rest if enough gold is collected
	if (pMiner->BankSaving() >= pMiner->ComfortLevel()) {

		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			 << "Woohoo! Rich enough for now. Back home to mah li'l lady";

		pMiner->getFSM()->ChangeState(GoHomeAndSleepTilRested::getInstance());
	}

	// leave the bank for more gold if the gold is not enough
	if (pMiner->BankSaving() < pMiner->ComfortLevel()) {
		pMiner->getFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
	}

	
}

void VisitBankAndDepositGold::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
	  	 << "Leavin' the bank";
}

VisitBankAndDepositGold * VisitBankAndDepositGold::getInstance()
{
	static VisitBankAndDepositGold instance;

	return &instance;
}


// State GoHomeAndSleepTilRested
void GoHomeAndSleepTilRested::Enter(Miner * pMiner)
{
	// change the location of miner
	if (pMiner->getLocation() != shack) {
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			 << "Walkin' home";

		pMiner->ChangeLocation(shack);
	}
}

void GoHomeAndSleepTilRested::Execute(Miner * pMiner)
{
	if (!pMiner->isRested()) {
		pMiner->Rest();

		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			<< "ZZZZ...";
	}

	// if not tired anymore wake up and work
	if (pMiner->isRested()) {
		pMiner->setComfortLevel(5);

		pMiner->getFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
	}
}

void GoHomeAndSleepTilRested::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		<< "What a God-darn fantastic nap! Time to find more gold";
}

GoHomeAndSleepTilRested * GoHomeAndSleepTilRested::getInstance()
{
	static GoHomeAndSleepTilRested instance;

	return &instance;
}


// State QuenchThirst
void QuenchThirst::Enter(Miner * pMiner)
{
	// change the location of miner
	if (pMiner->getLocation() != bank) {
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			 << "Boy, ah sure is thusty! Walkin' to the saloon";

		pMiner->ChangeLocation(saloon);
	}
}

void QuenchThirst::Execute(Miner * pMiner)
{
	pMiner->setThirst();

	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		 << "That's mighty fine sippin' liquor";

	pMiner->getFSM()->ChangeState(EnterMineAndDigForNugget::getInstance());
}

void QuenchThirst::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		<< "Leavin' the saloon, feelin' good";
}

QuenchThirst * QuenchThirst::getInstance()
{
	static QuenchThirst instance;

	return &instance;
}

// Miner global state

void MinerGlobalState::Enter(Miner * pMiner)
{
	// change the location of miner
	if (pMiner->getLocation() != saloon) {
		cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
			 << "";

		pMiner->ChangeLocation(saloon);
	}
}

void MinerGlobalState::Execute(Miner * pMiner)
{

}

void MinerGlobalState::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->getID()) << ": "
		 << "Leavin' the ";
}

MinerGlobalState * MinerGlobalState::getInstance()
{
	static MinerGlobalState instance;

	return &instance;
}
