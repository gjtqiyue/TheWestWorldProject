#pragma once
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
#include <cassert>
#include <string>

/*
	This object controls all the state related activities 
	implmented as a template so a generic type should be specified
*/
template <class entity_type>
class StateMachine
{
private:

	// owner of this statemachine
	entity_type * pOwner;

	// global state
	State<entity_type> * pGlobalState;

	// current state
	State<entity_type> * pCurrentState;

	// previous state
	State<entity_type> * pPreviousState;


public:

	StateMachine(entity_type* owner) : pOwner(owner),
		                               pGlobalState(NULL),
		                               pCurrentState(NULL),
		                               pPreviousState(NULL)
	{}

	virtual ~StateMachine();

	void Update() const {
		// call to execute global state and current state if exist
		if (pGlobalState) { pGlobalState->Execute(pOwner); }

		if (pCurrentState) { pCurrentState->Execute(pOwner); }
	}

	void SetGlobalState(State<entity_type>* state) {
		pGlobalState = state;
	}

	void SetCurrentState(State<entity_type>* state) {
		pCurrentState = state;
	}

	void RevertToPreviousState() {
		ChangeState(pPreviousState);
	}

	void ChangeState(State<entity_type>* pNewState) {
		assert(pNewState && "StateMachine::ChangeState(State>: null pointer to new state");
		assert(pCurrentState && "<StateMachine::ChangeState(State>: null pointer to current state");

		// keep a record of previous state
		pPreviousState = pCurrentState;

		// exit the current state
		pCurrentState->Exit(pOwner);

		// update the new state
		pCurrentState = pNewState;

		// enter the current state
		pCurrentState->Enter(pOwner);
	}

	// getter
	State<entity_type>* CurrentState() const { return pCurrentState; }
	State<entity_type>* GlobalState() const { return pGlobalState; }
	State<entity_type>* PreviousState() const { return pPreviousState; }

	// returns true if the current state's type is equal to the type of the class passed as a param
	bool isInState(const State<entity_type>& st) const;
};

#endif

