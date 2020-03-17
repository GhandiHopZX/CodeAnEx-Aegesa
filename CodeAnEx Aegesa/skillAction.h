#pragma once
#include <iomanip>
#include <iostream>
#include <list>
#include <cstring>
#include "battleSystem.h"
#include "aegesa.h"

using namespace std;

class skillAction
{
private:

	// variables
#pragma region other_vars

#pragma endregion

public:
	// every skill has an range type, element, name, description, sp/fp consumption, and stat multipliers 
	// and yes I'm putting it all in a magic hash
	// This exists because Enemy is not skillAction so ill compare the two in
	// validation when damage is processed...
	enum class elementType
	{
		Water = 0,
		Fire = 1,
		Earth = 2,
		Air = 3,
		Lightning = 4,
		Phase = 5,
		Bio = 6,
		Light = 7,
		Dark = 8,
		Normal = 9
	};

	int num;
	string name;
	string dec;
	elementType type;
	bool rangeType;
	aegesa::statusEff herpesus; // whatever it needs to be

	#pragma region Statpercentages
	int hpPerc;
	int spPerc;
	int fpPerc;
	int atkPerc;
	int defPerc;
	int spdPerc;
	int agiPerc;
	int dexPerc;
	int intPerc;
	int sprPerc;
	int strPerc;
	int endPerc;
	int conPerc;
	#pragma endregion

#pragma region statModifiers
	unsigned int hpAdd = 0;
	unsigned int spAdd = 0;
	unsigned int fpAdd = 0;
	unsigned int apAdd = 0;
	unsigned int dpAdd = 0;

	unsigned int atkAdd = 0;
	unsigned int defAdd = 0;
	unsigned int spdAdd = 0;

	unsigned int dexAdd = 0;
	unsigned int intAdd = 0;
	unsigned int sprAdd = 0;
	unsigned int endAdd = 0;
	unsigned int conAdd = 0;
	unsigned int strAdd = 0;
	unsigned int agiAdd = 0;

	const static int statsForSkill = 13;
	int stat14Percentages[statsForSkill] = {hpPerc, spPerc, fpPerc, atkPerc, defPerc, spdPerc, agiPerc, dexPerc, intPerc, sprPerc, strPerc, endPerc, conPerc}; // herp derp
#pragma endregion

	skillAction();

	skillAction(int);

	skillAction(int num, string name, elementType d, string dec, bool rangeType,
		int sp_succ, int fp_succ, int stat13[], aegesa::statusEff hopesis);

	skillAction skillcall(int);

	// hooking to the skill the
	// enum class
	elementType getElementType();

	// for element changes
	elementType setElementType(int m);

	void displayElementType(elementType d);

	string getDescription();

	void setRangeType(bool);

	bool getRangeType();

	template <class printedT>
	printedT output(string i)
	{
		cout << setprecision(2) << fixed << endl;
		return i;
	}
	//state changes - wip
};


