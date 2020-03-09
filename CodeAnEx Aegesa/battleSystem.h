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

	// constructor
	battleSystem();

	// variables
	int turnGuageNum;

	// getters/accessors
	
	// setters/mutators

	void enemyTroop();
	void allyTroop();

	// functions

	void targetEnemy();
	void aiTargeting();

	void targetedEnemy(int index);


	void aItargeted();

	// the core functions of what the player can do when the player can do
	void turn();

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

	// choices

	void attack();

	void defend();

	void skill();

	void hack();

	void turn_A_mode();

	void enemyTurn();

	// rewards

	void rewardOutput();


	// templates

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

	void skill(int* statMul[], int statNum);

};
