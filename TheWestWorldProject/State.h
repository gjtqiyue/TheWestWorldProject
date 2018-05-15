#pragma once
#ifndef STATE_H
#define STATE_H

class Miner;

enum Location {
	goldmine,
	shack,
	bank,
	saloon,
	loc
};

template <class entity_type>
class State
{
public:

	virtual ~State() {};

	virtual void Enter(entity_type*) = 0;

	virtual void Execute(entity_type*) = 0;

	virtual void Exit(entity_type*) = 0;
};

#endif


