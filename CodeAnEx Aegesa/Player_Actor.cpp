#include <iostream>
#include <string>
#include <ctime>
#include "Player_Actor.h"
#include "inventory.h"
#include "stateEffects.h"

Player_Actor::Player_Actor()
{
	name = "";
	bio = "";
	statmulti = false;
	party_num = 4;
	isPlayer = true;

#pragma region Stat_Instantiation

	// base stats
	hp = 10;
	sp = 5;
	ap = 5;
	dp = 0;
	fp = 1;

	// battler stats
	ATK = 5;
	DEF = 5;
	SPD = 5;

	AGI = 5;
	DEX = 5;
	END = 5;
	INT = 5;
	SPR = 5;
	STR = 5;
	CON = 5;

	// exp

	EXP = 0;
#pragma endregion
}

inventory::weapon mActorWeaponE[1];
inventory::armor mActorArmorE[3];

inventory::armor getArmorEQ()
{
	for (int i = 0; i < 4; i++)
	{
		return mActorArmorE[i];
	}
}

inventory::weapon getWeaponEQ()
{
	for (int i = 0; i < 4; i++)
	{
		return mActorWeaponE[i];
	}
}


template <class ArmorOut>
ArmorOut setArmor(int y, ArmorOut d)
{
	mActorArmorE[y] = d;
	cout << "armor " << d.name << "equipped" << endl;
}

template <class WeaponOut>
WeaponOut setWeapon(int y, WeaponOut d)
{
	mActorWeaponE[y] = d;
	cout << "weapon " << d.name << "equipped" << endl;
}
// use this to kill the player and when they die
Player_Actor::~Player_Actor()
{
}