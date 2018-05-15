#pragma once
#ifndef MINERWIFESTATE_H
#define MINERWIFESTATE_H

#include "State.h"

class MinerWife;

// global state
class WifeGlobalState : public State<MinerWife>
{
public:

	virtual ~WifeGlobalState() {};

	virtual void Enter(MinerWife*);

	virtual void Execute(MinerWife*);

	virtual void Exit(MinerWife*);

	static WifeGlobalState* getInstance();

private:

	// constructor
	WifeGlobalState() {};

	WifeGlobalState(const WifeGlobalState &);
	WifeGlobalState& operator=(const WifeGlobalState &);
};

class DoHousework : public State<MinerWife>
{
public:

	virtual ~DoHousework() {};

	virtual void Enter(MinerWife*);

	virtual void Execute(MinerWife*);

	virtual void Exit(MinerWife*);

	static DoHousework* getInstance();

private:

	// constructor
	DoHousework() {};

	DoHousework(const DoHousework &);
	DoHousework& operator=(const DoHousework &);
};


class VisitBathroom : public State<MinerWife>
{
public:
	
	virtual ~VisitBathroom() {};

	virtual void Enter(MinerWife*);

	virtual void Execute(MinerWife*);

	virtual void Exit(MinerWife*);

	static VisitBathroom* getInstance();

private:

	// constructor
	VisitBathroom() {};

	VisitBathroom(const VisitBathroom &);
	VisitBathroom& operator=(const VisitBathroom &);
};

#endif // !MINERWIFESTATE_H

