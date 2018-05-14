#pragma once
#include <string>

#ifndef NAME_H
#define NAME_H

using namespace std;

// all the characters' name
enum Name {
	Ent_Miner_Bob,

	Ent_Lisa
};

inline string GetNameOfEntity(int id) {
	switch (id) {
	case Name::Ent_Miner_Bob:
		return "Miner Bob";
		break;
	case Name::Ent_Lisa:
		return "Lisa";
		break;
	default:
		return "Unknown!";
	}
};

#endif // !NAME_H



