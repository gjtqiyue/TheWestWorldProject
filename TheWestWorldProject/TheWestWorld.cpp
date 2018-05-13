#include <iostream>
#include "BaseGameEntity.h"
#include "Miner.h"

BaseGameEntity* entity;

Miner* miner;

int main() {
	//miner = new Miner(1);
	//int x = miner->getID;
	entity = new BaseGameEntity(2);
	int x = entity->getID();
	std::cout << "hello" << x << std::endl;
}