#pragma once
#ifndef STATE_H
#define STATE_H

class Miner;

enum Location {
	goldmine,
};

class State
{
public:

	virtual ~State() {};

	virtual void Enter(Miner* a) = 0;

	virtual void Execute(Miner* b) = 0;

	virtual void Exit(Miner* c) = 0;
};





#endif


