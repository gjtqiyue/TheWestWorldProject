#pragma once
#ifndef MY_SINGLETON
#define MY_SINGLETON

#include "State.h"

class EnterMineAndDigForNugget : public State
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

class VisitBankAndDepositGold : public State
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

class GoHomeAndSleep : public State
{
private:

	GoHomeAndSleep() {};

	// copy ctor and assignment should be private
	GoHomeAndSleep(const GoHomeAndSleep &);
	GoHomeAndSleep& operator=(const GoHomeAndSleep &);

public:

	//~GoHomeAndSleep();

	// methods
	virtual void Enter(Miner* pMiner);

	virtual void Execute(Miner* pMiner);

	virtual void Exit(Miner* pMiner);

	static GoHomeAndSleep* getInstance();

};

class QuenchThirst : public State
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