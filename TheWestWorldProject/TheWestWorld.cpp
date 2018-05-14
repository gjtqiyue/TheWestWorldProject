#include <iostream>
#include "Miner.h"
#include "EntityNames.h"


int main() {
	Miner miner(Ent_Miner_Bob);
	//int x = miner->getID;
	//entity = new BaseGameEntity(2);
	int x = miner.getID();
	std::cout << "hello" << x << std::endl;

	system("PAUSE");
	return 0;
}