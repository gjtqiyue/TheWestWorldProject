#pragma once
#ifndef MY_SINGLETON
#define MY_SINGLETON

#include "State.h"

class MinerGlobalState : public State<Miner>
{
private:

	// constructor is private
	MinerGlobalState() {};

	// copy ctor and assignment should be private
	MinerGlobalState(const MinerGlobalState &);
	MinerGlobalState& operator=(const MinerGlobalState &);

public:

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static MinerGlobalState* getInstance();
};

class EnterMineAndDigForNugget : public State<Miner>
{
private:

	// constructor is private
	EnterMineAndDigForNugget() {};

	// copy ctor and assignment should be private
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget &);
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget &);

public:

	//~EnterMineAndDigForNugget();

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static EnterMineAndDigForNugget* getInstance();

};

class VisitBankAndDepositGold : public State<Miner>
{
private:

	VisitBankAndDepositGold() {};

	// copy ctor and assignment should be private
	VisitBankAndDepositGold(const VisitBankAndDepositGold &);
	VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold &);	

public:

	//~VisitBankAndDepositGold();

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static VisitBankAndDepositGold* getInstance();

};

class GoHomeAndSleepTilRested : public State<Miner>
{
private:

	GoHomeAndSleepTilRested() {};

	// copy ctor and assignment should be private
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested &);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested &);

public:

	//~GoHomeAndSleep();

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static GoHomeAndSleepTilRested* getInstance();

};

class QuenchThirst : public State<Miner>
{
private:

	QuenchThirst() {};

	// copy ctor and assignment should be private
	QuenchThirst(const QuenchThirst &);
	QuenchThirst& operator=(const QuenchThirst &);

public:

	//~QuenchThirst();

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static QuenchThirst* getInstance();

};

#endif // !MY_SINGLETON