#include "MinerWife.h"
#include "MinerWifeState.h"

MinerWife::MinerWife(int ID) : BaseGameEntity(ID),
                               myLocation(shack)
{
	myStateMachine = new StateMachine<MinerWife> (this);

	myStateMachine->SetCurrentState(DoHousework::getInstance());
	myStateMachine->SetGlobalState(WifeGlobalState::getInstance());
}


MinerWife::~MinerWife()
{
}

void MinerWife::Update()
{
	myStateMachine->Update();
}
