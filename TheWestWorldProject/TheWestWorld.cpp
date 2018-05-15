#include <iostream>
#include "Miner.h"
#include "MinerWife.h"
#include "EntityNames.h"
#include <conio.h>
#include <windows.h>


int main() {
	Miner miner(Ent_Miner_Bob);
	MinerWife wife(Ent_Elsa);
	
	for (int i = 0; i <= 30; i++) {
		miner.Update();

		wife.Update();

		Sleep(1000);
	}

	system("PAUSE");
	return 0;
}