#include <iostream>
#include <string>
#include <ctime>
#include "Player_Actor.h"
#include "inventory.h"

Player_Actor::Player_Actor()
{
	name = "";
	bio = "";
	statmulti = false;
	leader = false;
	party_num = 4;

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

//Player_Actor Party[];

inventory::weapon mActorWeaponE[1];
inventory::armor mActorArmorE[1];

//
//void Player_Actor::setParty(Player_Actor currentPa, int pos)
//{
//	if (leader == true)
//	{
//		Party[pos] = currentPa;
//	}
//	else
//	{
//		cout << "not a party leader..." << endl;
//	}
//}
//
//Player_Actor Player_Actor::getParty()
//{
//	for (int i = 0; i < party_num; i++)
//	{
//		return Party[party_num];
//	};
//}
//
//Player_Actor Player_Actor::callPartyMember(int pos)
//{
//	return Party[pos];
//}

// use this to kill the player and when they die
Player_Actor::~Player_Actor()
{
}
