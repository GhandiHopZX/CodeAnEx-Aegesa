#pragma once
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <iostream>
#include "aegesa.h"
#include "stateEffects.h"
#include "inventory.h"

using namespace std;

class battleSystem
{
private:

	// variables
	bool battleTime; // if its time to fight
	bool* aGuage;
	int turn_Number;
	enum t
	{
		a = 0, b = 1, c = 2, d = 3, e = 4, f = 5
	}; //turn number

	int mx = 8;// change this for the maximum amount of enemy fighters
	int numMembers = 0; // current number of members

public:

	//objects
	stateEffects::statusEff me;

	// constructor
	battleSystem();

	//player vs enemy encounter
	battleSystem(Player_Actor partyCrew[], Enemy enemyCrew[], bool battleMode);

	//dummy battle or possible pvp
	battleSystem(Player_Actor PartyOne[], Player_Actor PartyTwo[]);

	// variables

	bool ActorCrit;

	bool AiCrit;

	int turnGuageNum;

	// getters/accessors
	template <class targeting> // 
	targeting getTargetArray();

	template <class targeting> // 
	targeting getAITarget();

	// setters/mutators
	template <class targeting> // 
	targeting setTargetArray(targeting d[]);

	template <class aiTargeting> //
	aiTargeting setAiTargetArray(aiTargeting d[]);

	// functions

	template <class targeting> // cmd placements 
	targeting playerDeck(targeting d[]);

	template <class aiTargeting> // cmd checks
	aiTargeting aiDeck(aiTargeting d[]);

#pragma region Functions

	// the core functions of what the player can do when the player can do
	void turn(); // call player deck and then give options

	// recalls all or any stat plus modifier
	//functions for reauthentications when a number of turns are up
	void battleMode();

	void countEnemies(aegesa tArr[]); // this is the setter

	string lineStop();

	int statusCall(int ti);

	int getNumMembers();

	bool playerTGuage(int, int spd, int fp);

	bool enemyTGuage(int, int spd, int fp);

	// output types

	void statTurn(stateEffects::statusEff);

	void turnSystem(int);

	void healOutput(string);

	void normalOutput(string);

	void damageOutput(string);

	void critDmgOutput(string);

	void multiDamageOutput(string[]);

	void hackOutput(string);

	void rewardOutput(string);

	//getters
	/*Player_Actor getActors
	{

	}*/
#pragma endregion

	// rewards

	template <typename victory> // cmd process
	victory rewards(aegesa tArr[]);

	// templates
	template <class TURNA>
	TURNA turn_A_mode(aegesa d[], aegesa u[]);

	template <class statPwr>
	statPwr point_plier(statPwr atk, statPwr mgk, statPwr auraFp) // mainly for attacks not anything else
	{
		int newAtk_value = 0;
		int oldAtk = 0;
		int selfCritmultiplier = 1; // hard set to 1 for now
		int weaponCritplier = 1; // hard set to 1 for now
		int statCritplier = 1; // same until stats and weapons play a role in this parameter's math
		int attr_size = atk + mgk + auraFp;
		int atk_value = .75 * +.66 * +attr_size; // crit // maybe lower these for the ARPG

		// constants 
		int MAX_DMG = atk_value; // Max allowed damage
		int MIN_DMG = attr_size; // Min allowed damage

		selfCritmultiplier = attr_size % 1; // self crit chance is supposed to go here
		weaponCritplier = attr_size % 1; // weapon crit
		statCritplier = attr_size % 1; //stat crit

		int culmCHance = selfCritmultiplier * weaponCritplier * statCritplier;

		oldAtk = atk_value;

		// Randomizer
		newAtk_value = (rand() % (MAX_DMG - MIN_DMG + 1)) + (MIN_DMG * culmCHance);

		// determine critical
		if (newAtk_value > oldAtk)
		{
			critDmgOutput("Critical: " + newAtk_value);
			ActorCrit = true;
		}
		else
		{
			normalOutput("Damages for: " + newAtk_value);
			ActorCrit = false;
		}

		return newAtk_value;
	}

	template <class T>
	T absolute(T ab0, T ab1, T ab2, T ab3)
	{
		// absolute calculation
		if (ab0 != 0) // long
		{
			return static_cast<long>(abs(ab0));
		}
		else if (ab1 != 0) // double
		{
			return static_cast<double>(abs(ab1));
		}
		else if (ab2 != 0) // int
		{
			return static_cast<int>(abs(ab2));
		}
		else if (ab3 != 0) // float
		{
			return static_cast<float>(abs(ab3));
		}
		else
		{
			return abs(ab1);
		}
	}

	// your choices processed
	template <class iter> // cmd process
	iter attack(aegesa tArr[]);

	template <class iter> // cmd process
	iter def(aegesa tArr[]);

	template <class iter> // cmd process
	iter hack(aegesa tArr[]);

	template <class iter> // cmd process
	iter itemUse(aegesa tArr[]);

	template <class iter> // cmd process
	iter attackPlus(iter atk, iter bonus, iter hpE, aegesa tArr[]); // bonuses granted from party strikes, skills and buffs 

	template <class iter> // cmd process
	iter skill(iter atk, iter statPlus14[], stateEffects::statusEff me, bool rangeType, aegesa tArr[]); //

	template <class iter> // cmd process
	iter actorThrow(iter atk, iter statPlus14[], stateEffects::statusEff me, bool rangeType, aegesa tArr[]); //

	template <class iter> // cmd process
	iter teamAttack(iter atk, iter statPlus14[], stateEffects::statusEff me, bool rangeType, aegesa tArr[]); //

	template <class iter> // cmd process
	iter auralAttack(iter atk, iter statPlus14[], stateEffects::statusEff me, bool rangeType, aegesa tArr[]); // super aura attack

	template <class iter> // cmd process
	iter transform(iter atk, iter statPlus14[], stateEffects::statusEff me, aegesa tArr[]); // SUPER ZENKAI BOOST

#pragma region AiCmds

	// ai choices processed
	//template <class iter> // cmd process
	//iter aiAttack(HashTableSet targetArr[]);

	//template <class iter> // cmd process
	//iter aiSkill(HashTableSet targetArr[]);

	//template <class iter> // cmd process
	//iter aiDef(HashTableSet tArr[]);

	//template <class iter> // cmd process
	//iter aiHack(HashTableSet tArr[]);

	//template <class iter> // cmd process
	//iter aiAttackPlus(HashTableSet targetArr[], iter atk, iter bonus, iter hpE);

	//template <class iter> // cmd process
	//iter aiTeamAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, HashTableSet tArr[]); //

	//template <class iter> // cmd process
	//iter aiAuralAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, HashTableSet tArr[]); // super aura attack

	//template <class iter> // cmd process
	//iter transform(iter atk, iter statPlus14[], aegesa::statusEff me, HashTableSet tArr[]); // SUPER ZENKAI BOOST
#pragma endregion

	//interpreter 1 2 3 4 5

	template <class Intepreter> // cmd process
	Intepreter toE(aegesa* targetarr[], Intepreter choices[]);

	template <class Intepreter> // cmd process
	Intepreter toActor(aegesa* targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter FinalizerACTOR(aegesa* targetArr1[], aegesa* targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter aiFinalizerE(aegesa* targetArr1[], aegesa* targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of literally everything
	Intepreter accounts(aegesa* targetArr1[], aegesa* targetArr2[], Intepreter turns); // keeping track of turns, sending necessary state data and changes and looking at stat bases
};

//template<class victory>
//inline victory battleSystem::rewards(aegesa tArr[]) // TODO: add inventory param and output the goodness
//{
//	countEnemies(); // resetting numMembers 
//
//	for (int i = 0; i < getNumMembers(); i++)
//	{
//		award = tArr[i];
//		return award;
//	}
//}
//
//template<class TURNA>
//inline TURNA battleSystem::turn_A_mode(Enemy d[], Player_Actor u[])
//{
//	return TURNA();
//}

//template<class iter>
//inline iter battleSystem::attack(Player_Actor tArr[])
//{
//	int newAttack;
//	int newMagickPwr;
//	int auralPwr;
//	int attkValue;
//
//	newAttack = tArr->getATKd(); // so weapons are added to the mix apparently and subtracted
//	newMagickPwr = ((tArr->getINTd() + tArr->getSpd()) * .33);
//	auralPwr = (tArr->getFpd() * .33);
//
//	attkValue = point_plier(newAttack, newMagickPwr, auralPwr);
//
//	return attkValue;
//}

//template<class iter>
//inline iter battleSystem::def(Player_Actor tArr[])
//{
//	int newDef;
//	int mDef;
//	int auralDef;
//	int defValue;
//
//	defValue = tArr->getDEFd(); // def items are added 
//	auralDef = tArr->getFpd();
//	mDef = (tArr->getDEFd() + tArr->getINTd() + auralDef) * .45;
//
//	newDef = defValue + auralDef + mDef + (tArr->getSTRd() * .33 + tArr->getENDd() * .33 + tArr->getCONd() * .33);
//
//	return newDef;
//}

// this can't be a template unless it can use a void function
//template<class iter>
//inline iter battleSystem::hack(Player_Actor tArr[])
//{
//	tArr->getDEXd();
//	// get the enemy target
//	//targetEnemy();
//
//	wstring window;
//
//	// movement grid
//	wstring grid[26][6]; 
//	// one plus higher for
//	//the actuall char amount in the order
//	// grid array
//	window += L"=== === ===";
//	window += L"=== === ===";
//	window += L"=== === ===";
//
//	// snap to grid
//	grid[25][5] = window;
//	
//	while (VK_SPACE)
//	{
//		normalOutput("press space to fire when \n your marker (X) lands on (*) \n making a (#)");
//		//system("CLS");
//
//		// platforms 
//
//		// 1 2 3
//		// 4 5 6
//		// 7 8 9
//
//		// X< 1 = 0 1 2
//		//	  2 = 3 4 5
//		//	  3 = 6 7 8
//		// 	  4 = 9 10 11
//		//	  5 = 12 13 14
//		//	  6 = 15 16 17
//		//    7 = 18 19 20
//		//	  8 = 21 22 23
//		//	  9 = 24 25 26 >X
//
//		wstring actorT, enemy, hitMarkA;
//		actorT = L"X"; // XX
//		enemy = L"*"; // **
//		hitMarkA = L"#"; // ## mark empty when actorT overlays enemy
//
//		// player startpoint
//		int x, y;
//		grid[0][1] = actorT;
//		grid[1][1] = actorT;
//		grid[2][1] = actorT;
//
//		// enemy startpoint
//		int ex, ey;
//		grid[8][1] = enemy;
//		grid[9][1] = enemy;
//		grid[10][1] = enemy;
//
//		// key console
//#pragma region VirtualKey input
//		switch (INPUT_KEYBOARD)
//		{
//		case VK_UP:
//			//movement -y
//#pragma region up
//			// movement y
//			if (y >= 0)
//			{
//				for (int i = 0; i < 2; i++)
//				{
//					x += 0;
//					y -= 0;
//
//					actorT = grid[x][y];
//				}
//			}
//			else if (y <= 5)
//			{
//				for (int i = 0; i < 2; i++)
//				{
//					x += 0;
//					y -= i;
//
//					actorT = grid[x][y];
//				}
//			}
//#pragma endregion
//			if (actorT != grid[x][y]) //replacemet space
//			{
//				actorT[y + 1] = '='; // behind u
//			}
//			break;
//
//		case VK_DOWN:
//			// movement +y
//#pragma region down
//			if (y >= 5)
//			{
//				for (int i = 0; i < 2; i++)
//				{
//					x += 0;
//					y += 0;
//
//					actorT = grid[x][y];
//				}
//			}
//			else if (y <= 0)
//			{
//				for (int i = 0; i < 2; i++)
//				{
//					x += 0;
//					y += i;
//
//					actorT = grid[x][y];
//				}
//			}
//#pragma endregion
//			if (actorT != grid[x][y]) //replacemet space
//			{
//				actorT[y - 1] = '=';
//			}
//			break;
//
//		case VK_LEFT:
//			// movement x-
//			// validation
//#pragma region left
//			if (x <= 25)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					x -= i;
//					y += 0;
//					actorT = grid[x][y];
//				}
//			}
//			else if (x >= 0)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					x += 0;
//					y += 0;
//					actorT = grid[x][y];
//				}
//			}
//
//#pragma endregion
//			if (actorT != grid[x][y]) //replacemet space
//			{
//				actorT[x + 1] = '=';
//				actorT[x + 2] = '=';
//				actorT[x + 3] = '=';
//			}
//			break;
//
//		case VK_RIGHT:
//			// movement x+
//#pragma region right
//			if (x >= 25)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					x += 0;
//					y += 0;
//					actorT = grid[x][y];
//				}
//			}
//			else if (x <= 0)
//			{
//				for (int i = 0; i < 4; i++)
//				{
//					x += i;
//					y += 0;
//					actorT = grid[x][y];
//				}
//			}
//#pragma endregion
//			if (actorT != grid[x][y]) //replacemet space
//			{
//				actorT[x - 1] = '=';
//				actorT[x - 2] = '=';
//				actorT[x - 3] = '=';
//			}
//			break;
//
//		default:
//			break;
//		}
//#pragma endregion
//		
//#pragma region AI
//
//		//--------- enemy movement ------------
//		if (ex | ey == y | x)
//		{
//			enemy[ex - 1 | +1] | enemy[ey - 1 | +1];
//		}
//
//		// movement replacement
//		//up
//		if (enemy != grid[ex][ey]) //replacemet space
//		{
//			enemy[ey + 1] = '='; // behind u
//		}
//		//down 
//		if (enemy != grid[ex][ey]) //replacemet space
//		{
//			enemy[ey - 1] = '=';
//		}
//		//left
//		if (enemy != grid[ex][ey]) //replacemet space
//		{
//			enemy[ex + 1] = '=';
//			enemy[ex + 2] = '=';
//			enemy[ex + 3] = '=';
//		}
//		//right
//		if (enemy != grid[ex][ey]) //replacemet space
//		{
//			enemy[ex - 1] = '=';
//			enemy[ex - 2] = '=';
//			enemy[ex - 3] = '=';
//		}
//
//		// ai move away from player 
//		if (actorT[x] -1 >= enemy[ex] || actorT[x] - 1 <= enemy[ex])
//		{
//			// check if theres space and seek a way to escape
//			// wait
//			// move again
//		}
//
//		if (actorT[y] - 1 >= enemy[ey] || actorT[y] - 1 <= enemy[ey])
//		{
//			// check if theres space and seek a way to escape
//			// wait
//			// move again
//		}
//		
//		// collision
//		if (grid[x][y] == grid[ex][ey] && grid[ex] == grid[ey])
//		{
//			enemy = hitMarkA;
//			actorT = hitMarkA;
//
//			switch (VK_SPACE)
//			{
//				hackOutput("HIT");
//				lineStop();
//				hackOutput("HACKED!");
//			default:
//				break;
//			}
//		}
//		else
//		{
//			enemy = enemy;
//			actorT = actorT;
//
//			switch (VK_SPACE)
//			{
//			default:
//				break;
//			}
//		}
//		/*
//		  1  2  3  4  5  6
//		  11 12 13 14 15 16
//		  21 22 23 24 25 26
//		 */
//#pragma endregion
//
//	
//{
//	return iter();
//}