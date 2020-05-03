#pragma once

// this will replace statusEffects and anything imitating this
// using a static container the index will be based on integers and strings
// returning to the upper layer of things only strings
// then when World.CPP is used or battleSystem.CPP with a method that'll
// count the turns from pulling said names from this class index
// a method will pass effects to said actor or enemy within the battle system
// and from battle the effects will pass into a container that'l be 
// this class's several instantiations will be inside World.CPP
// or battleSystem.cpp

class stateEffects
{
private:
	static const int statusGroups = 20;
public:

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
	aegesa::statusEff REGENERATION;
	aegesa::statusEff POISON;
	aegesa::statusEff STUNED;
	aegesa::statusEff DEAD;
	aegesa::statusEff HACKED;
	aegesa::statusEff CRIPPLE;
	aegesa::statusEff INEBREATED;
	aegesa::statusEff SLEEP;
	aegesa::statusEff CURSEDVSDARK; // AGONY
	aegesa::statusEff CURSRDVSLIGHT; // DEPRESSION
	aegesa::statusEff CURSEDVSDEMONIC; // ACCURSED
	aegesa::statusEff CURSED;
	aegesa::statusEff ANGER; // ADRENELINE
#pragma endregion

	// this needs to be a list

	aegesa::statusEff allEffGet[statusGroups] = {
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
	string buffName;
	int turns_Of_aff = 0;
	int rating;
	int restriction;
	bool inEff = false;
	bool minusState;
	bool addState;
	bool zeroHP;

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

	int sizeupAEG = allEffGet2->max_size();

	// experience
	unsigned int EXP; // experience to obtain the per level ap gain
	string title;
#pragma endregion

	list<pair<int, aegesa::statusEff>> allEffGet2[statusGroups];

	//allEffGet2[];

	aegesa::statusEff My_Statuses[statusGroups];

	list<pair<int, aegesa::statusEff>> My_Statuses2[20];

	stateEffects();
	~stateEffects();

};

stateEffects::stateEffects()
{
}

stateEffects::~stateEffects()
{
}

