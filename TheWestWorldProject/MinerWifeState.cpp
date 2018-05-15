#include "MinerWifeState.h"
#include "MinerWife.h"
#include "EntityNames.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void DoHousework::Enter(MinerWife* pMinerWife)
{
	if (pMinerWife->getLocation != shack) {
		pMinerWife->ChangeLocation(shack);
	}
}

void DoHousework::Execute(MinerWife* pMinerWife)
{
	int i = rand() % 3;

	switch (i) {
	case 0:
		cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
			<< "Moppin' the floor";
		break;
	case 1:
		cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
			<< "Makin' the bed";
		break;
	case 2:
		cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
			<< "Doin' the laundury";
		break;
	default:
		break;
	}
}

void DoHousework::Exit(MinerWife* pMinerWife)
{
}

DoHousework * DoHousework::getInstance()
{
	static DoHousework instance;

	return &instance;
}

// VisitBathroom state
void VisitBathroom::Enter(MinerWife* pMinerWife)
{
	if (pMinerWife->getLocation != loc) {
		cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
			<< "Walkin' to the can. Need to powda mah pretty li'l nose";

		pMinerWife->ChangeLocation(loc);
	}
}

void VisitBathroom::Execute(MinerWife* pMinerWife)
{
	cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
		 << "Ahhhhhh! Sweet relief";

	pMinerWife->getFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinerWife* pMinerWife)
{
	cout << "\n" << GetNameOfEntity(pMinerWife->getID()) << ": "
		<< "Leavin' the john";
}

VisitBathroom * VisitBathroom::getInstance()
{
	static VisitBathroom instance;

	return &instance;
}


// global state
void WifeGlobalState::Enter(MinerWife *)
{
}

void WifeGlobalState::Execute(MinerWife * pMinerWife)
{
	// 1 out of 10 go to bathroom
	int j = rand() % 10;

	if (j == 5) {
		pMinerWife->getFSM()->ChangeState(VisitBathroom::getInstance());
	}
}

void WifeGlobalState::Exit(MinerWife *)
{
}

WifeGlobalState * WifeGlobalState::getInstance()
{
	static WifeGlobalState instance;

	return &instance;
}
