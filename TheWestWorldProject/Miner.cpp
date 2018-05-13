#include "Miner.h"


Miner::Miner(int ID): BaseGameEntity(ID)
{
	
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
