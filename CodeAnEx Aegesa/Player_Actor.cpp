#include <iostream>
#include <string>
#include <ctime>
#include "Player_Actor.h"
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
	SPEED = 5;

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

Player_Actor::armor Player_Actor::getArmorEQ()
{
	armor a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = mActorArmorE[i];
		return a[i];
	}
	return a[0];
}

Player_Actor::weapon Player_Actor::getWeaponEQ()
{
	weapon w[1];
	for (int i = 0; i < 1; i++)
	{
		w[i] = mActorWeaponE[i];
		return w[i];
	}
	return w[0];
}

Player_Actor::armor Player_Actor::getArmorEQ2(int me)
{
	return mActorArmorE[me];
}

Player_Actor::weapon Player_Actor::getWeaponEQ2(int me)
{
	return mActorWeaponE[me];
}

string Player_Actor::normalOutput(string normal)
{
	return string();
}

void Player_Actor::setArmor(int y, Player_Actor::armor d)
{
	mActorArmorE[y] = d;
}

void Player_Actor::setWeapon(int y, Player_Actor::weapon d)
{
	mActorWeaponE[y] = d;
}

// use this to kill the player and when they die
Player_Actor::~Player_Actor()
{
}