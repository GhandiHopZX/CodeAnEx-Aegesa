#include <iostream>
#include <string>
#include <ctime>
#include "Player_Actor.h"
#include "stateEffects.h"
#include "inventory.h"

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

// use this to kill the player and when they die
Player_Actor::~Player_Actor()
{
}