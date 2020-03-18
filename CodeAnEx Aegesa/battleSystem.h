#pragma once
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include "aegesa.h"
#include "Player_Actor.h"
#include "Enemy.h"

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

public:
	
	aegesa::statusEff me;

	// constructor
	battleSystem();

	// variables
	int turnGuageNum;

	// getters/accessors
	template <class targeting> // 
	targeting getTargetArray();

	template <class targeting> // 
	targeting getAITarget();
	
	// setters/mutators
	template <class targeting> // 
	targeting setTargetArray(targeting d[]);

	template <class targeting> //
	targeting setAiTargetArray(targeting d[]);

	// functions

	template <class targeting> // cmd placements 
	targeting playerDeck(targeting d[]);

	template <class targeting> // cmd checks
	targeting aiDeck(targeting d[]);

	// the core functions of what the player can do when the player can do
	void turn(); // call player deck and then give options

	// recalls all or any stat plus modifier
	//functions for reauthentications when a number of turns are up

	void battleMode();

	int statusCall(int ti);

	bool playerTGuage(int, int spd, int fp);

	bool enemyTGuage(int, int spd, int fp);

	// output types

	void statTurn(aegesa::statusEff);

	void turnSystem(int);

	void healOutput(string);

	void normalOutput(string);

	void damageOutput(string);

	void critDmgOutput(string);

	void multiDamageOutput(string[]);

	void hackOutput(string);

	void rewardOutput(string);

	// rewards

	template <class victory> // cmd process
	victory rewards(Enemy tArr[]);

	// templates
	template <class TURNA>
	TURNA turn_A_mode(Enemy d[], Player_Actor u[]);

	template <class statPwr>
	statPwr point_plier(statPwr atk, statPwr mgk, statPwr auraFp)
	{
		int attr_size = atk + mgk + auraFp;
		int atk_value = .75 * + .67 * attr_size;
		return atk_value;
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
	iter attack(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter def(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter hack(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter attackPlus(iter atk, iter bonus, iter hpE, Player_Actor tArr[]); // bonuses granted from party strikes, skills and buffs 

	template <class iter> // cmd process
	iter skill(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Player_Actor tArr[]); //


	// ai choices processed
	template <class iter> // cmd process
	iter aiAttack(Enemy targetArr[]);

	template <class iter> // cmd process
	iter aiSkill(Enemy targetArr[]);

	template <class iter> // cmd process
	iter aiDef(Enemy tArr[]);

	template <class iter> // cmd process
	iter aiHack(Enemy tArr[]);

	template <class iter> // cmd process
	iter aiAttackPlus(Enemy targetArr[], iter atk, iter bonus, iter hpE);

	//interpreter 1 2 3 4 5

	template <class Intepreter> // cmd process
	Intepreter fromACTOR(Enemy targetarr[]);

	template <class Intepreter> // cmd process
	Intepreter fromE(Player_Actor targetArr2[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter finalizerACTOR(Player_Actor targetArr1[], Enemy targetArr2[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter finalizerE(Enemy targetArr1[], Player_Actor targetArr2[]);

	template <class Intepreter> // knowledge of literally everything
	Intepreter accounts(Player_Actor targetArr1[], Enemy targetArr2[], Intepreter turns); // keeping track of turns, sending necessary state data and changes and looking at stat bases
};

