#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <unordered_set>
#include "aegesa.h"
// this will replace statusEffects and anything imitating this
// using a static container the index will be based on integers and strings
// returning to the upper layer of things only strings
// then when World.CPP is used or battleSystem.CPP with a method that'll
// count the turns from pulling said names from this class index
// a method will pass effects to said actor or enemy within the battle system
// and from battle the effects will pass into a container that'l be 
// this class's several instantiations will be inside World.CPP
// or battleSystem.cpp
using namespace std;

class stateEffects
{
private:
	static const int statusGroups = 20;

public:
	int sizeupAEG = 0;

	string buffName = "";
	int turns_Of_aff = 0;
	int rating = 0;
	int restriction = 0;
	bool inEff = false;
	bool minusState = false;
	bool addState = false;
	bool zeroHP = false;

	// afflictions statbase
	unsigned int hp = 0; // health
	unsigned int sp = 0; // special
	unsigned int fp = 0; // fighter (aural)

	// battler statbase <- ap goes here
	unsigned int ATK = 0; // attack
	unsigned int DEF = 0; // defence (armor based)
	unsigned int SPD = 0; // speed

	// ability stats <- dp goes here
	unsigned int AGI = 0; // agility
	unsigned int DEX = 0; // dexterity
	unsigned int INT = 0; // intelligence
	unsigned int SPR = 0; // spirit
	unsigned int STR = 0; // strength (also effects status)
	unsigned int END = 0; // endurance (bodily based / also effects status)
	unsigned int CON = 0; // constitution (mental, body, soul, based / also effects status)

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

#pragma region statusTypes
	string REGENERATION;
	string POISON;
	string STUNED;
	string DEAD;
	string HACKED;
	string CRIPPLE;
	string INEBREATED;
	string SLEEP;
	string CURSEDVSDARK; // AGONY
	string CURSRDVSLIGHT; // DEPRESSION
	string CURSEDVSDEMONIC; // ACCURSED
	string CURSED;
	string ANGER; // ADRENELINE
#pragma endregion

	// this needs to be a list

	string allEffGet[statusGroups] = {
		REGENERATION,
		POISON,
		STUNED,
		DEAD,
		HACKED,
		CRIPPLE,
		INEBREATED,
		SLEEP,
		CURSEDVSDARK,
		CURSRDVSLIGHT,
		CURSEDVSDEMONIC,
		CURSED,
		ANGER
	}; // wip


#pragma region vars

	int num_Statuses = 0;

	// experience
	unsigned int EXP; // experience to obtain the per level ap gain
	string title;
#pragma endregion

	list<pair<int, string>> allEffGet2[statusGroups];


	//allEffGet2[];

	//stateEffects::statusEff My_Statuses[statusGroups];

	//list<pair<int, stateEffects::statusEff>> My_Statuses2[20];

	//states (I called status effects please excuse me on that.)

	string indexer(int);

	//string printStatus(); reserve for player

	//bool isFull(int);

	bool isFull(int d);

	void insertStatus(int key, string m);

	void remove_state(int id, bool force);

	void add_state(int id, bool force, string kd[]);

	int nameInt(string choiceBuffer);

	stateEffects();
	~stateEffects();

};





