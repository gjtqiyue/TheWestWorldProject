#pragma once

class Miner;

class State
{
public:
	State();

	~State();

	virtual void Enter(Miner* a);

	virtual void Execute(Miner* b);

	virtual void Exit(Miner* c);
};

