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

	int mx = 8;// change this for the maximum amount of enemy fighters
	int numMembers = 0; // current number of members
	
public:

	//objects
	aegesa::statusEff me;
	inventory award;

	// constructor
	battleSystem();

	battleSystem(Player_Actor fromPartyHash[], Enemy RandEncounterHash[]);

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

	// the core functions of what the player can do when the player can do
	void turn(); // call player deck and then give options

	// recalls all or any stat plus modifier
	//functions for reauthentications when a number of turns are up
	void battleMode();

	void countEnemies(Enemy tArr[]); // this is the setter

	string lineStop();

	int statusCall(int ti);

	int getNumMembers();

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

	//getters
	/*Player_Actor getActors
	{
		
	}*/

	// rewards

	template <class victory> // cmd process
	victory rewards(Enemy tArr[]);

	// templates
	template <class TURNA>
	TURNA turn_A_mode(Enemy d[], Player_Actor u[]);

	template <class statPwr>
	statPwr point_plier(statPwr atk, statPwr mgk, statPwr auraFp)
	{
		int newAtk_value = 0;
		int oldAtk = 0;
		int selfCritmultiplier = 1; // hard set to 1 for now
		int weaponCritplier = 1; // hard set to 1 for now
		int statCritplier = 1; // same until stats and weapons play a role in this parameter's math
		int attr_size = atk + mgk + auraFp;
		int atk_value = .75* + .66* attr_size; // crit // maybe lower these for the ARPG

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
	iter attack(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter def(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter hack(Player_Actor tArr[]);

	template <class iter> // cmd process
	iter attackPlus(iter atk, iter bonus, iter hpE, Player_Actor tArr[]); // bonuses granted from party strikes, skills and buffs 

	template <class iter> // cmd process
	iter skill(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Player_Actor tArr[]); //

	template <class iter> // cmd process
	iter actorThrow(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Player_Actor tArr[]); //

	template <class iter> // cmd process
	iter teamAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Player_Actor tArr[]); //

	template <class iter> // cmd process
	iter auralAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Player_Actor tArr[]); // super aura attack

	template <class iter> // cmd process
	iter transform(iter atk, iter statPlus14[], aegesa::statusEff me, Player_Actor tArr[]); // SUPER ZENKAI BOOST

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

	template <class iter> // cmd process
	iter teamAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Enemy tArr[]); //

	template <class iter> // cmd process
	iter auralAttack(iter atk, iter statPlus14[], aegesa::statusEff me, bool rangeType, Enemy tArr[]); // super aura attack

	template <class iter> // cmd process
	iter transform(iter atk, iter statPlus14[], aegesa::statusEff me, Enemy tArr[]); // SUPER ZENKAI BOOST

	//interpreter 1 2 3 4 5

	template <class Intepreter> // cmd process
	Intepreter toE(Enemy *targetarr[], Intepreter choices[]);

	template <class Intepreter> // cmd process
	Intepreter toActor(Player_Actor *targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter finalizerACTOR(Player_Actor *targetArr1[], Enemy *targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of both actors and enemies virtually everything
	Intepreter finalizerE(Enemy *targetArr1[], Player_Actor *targetArr2[], Intepreter choices[]);

	template <class Intepreter> // knowledge of literally everything
	Intepreter accounts(Player_Actor *targetArr1[], Enemy *targetArr2[], Intepreter turns); // keeping track of turns, sending necessary state data and changes and looking at stat bases
};

template<class victory>
inline victory battleSystem::rewards(Enemy tArr[]) // TODO: add inventory param and output the goodness
{
	countEnemies(); // resetting numMembers 

	for (int i = 0; i < getNumMembers(); i++)
	{
		award = tArr[i].itemN;
		return award;
	}
	
}

template<class TURNA>
inline TURNA battleSystem::turn_A_mode(Enemy d[], Player_Actor u[])
{
	return TURNA();
}

template<class iter>
inline iter battleSystem::attack(Player_Actor tArr[])
{
	int newAttack;
	int newMagickPwr;
	int auralPwr;
	int attkValue;

	newAttack = tArr->getATKd(); // so weapons are added to the mix apparently and subtracted
	newMagickPwr = ((tArr->getINTd() + tArr->getSpd()) / 1.3);
	auralPwr = tArr->getFpd();

	tArr;
	attkValue = point_plier(newAttack, newMagickPwr, auralPwr);

	return attkValue;
}

template<class iter>
inline iter battleSystem::def(Player_Actor tArr[])
{
	return iter();
}
