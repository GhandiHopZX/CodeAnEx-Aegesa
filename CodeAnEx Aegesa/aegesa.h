#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "aegesa.h"

using namespace std;
//this is a parent class for enemies, actors and player actors
class aegesa
{
private:
	static const int statusGroups = 20;
	
public:
	aegesa();

#pragma region vars
	// is this a player
	bool isPlayer = false;

	// statbase 15
	unsigned int hp = 0; // health
	unsigned int sp = 0; // special
	unsigned int fp = 0; // fighter (aural)
	unsigned int ap = 0; // abiliy (optained after every level) (you'll also obtain -ap- from special items, Bosses and TurnA clashes)
	unsigned int dp = 0; // dynamic points (obtained after a Turn A clash for leveling)

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

	//deductables
	int hpd = 0; // health
	int spd = 0; // special
	int fpd = 0; // fighter (aural)

	int ATKd = 0; // attack
	int DEFd = 0; // defence (armor based)
	int SPDd = 0; // speed

	int AGId = 0; // agility
	int DEXd = 0; // dexterity
	int INTd = 0; // intelligence
	int SPRd = 0; // spirit
	int STRd = 0; // strength (also effects status)
	int ENDd = 0; // endurance (bodily based / also effects status)
	int CONd = 0; // constitution (mental, body, soul, based / also effects status)
	int party_num; // number of people you can have
	bool leader;
	int num_Statuses = 0;

	int sizeupAEG = allEffGet2->max_size();

	// experience
	unsigned int EXP; // experience to obtain the per level ap gain
	string title;
#pragma endregion

	struct statusEff
	{
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

	list<pair<int, aegesa::statusEff>> allEffGet2[statusGroups];

	//allEffGet2[];
	
	aegesa::statusEff My_Statuses[statusGroups];

	list<pair<int, aegesa::statusEff>> My_Statuses2[20];

	// variables
	string name = ""; // YOUR NAME!
	string bio = ""; // YOUR STORY!

	// stat multiplier flag
	bool statmulti;
	int dummyPlus;
	int newSpd;

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

#pragma region getters
	string getName()
	{
		return name;
	};

	string getTitle()
	{
		return title;
	}

	int getParty_num()
	{
		return party_num;
	}

	bool getSMulti()
	{
		return statmulti;
	}

	//Hp Getter
	int getHp()
	{
		return hp;
	};

	//Sp Getter
	int getSp()
	{
		return sp;
	};

	//Fp Getter
	int getFp()
	{
		return fp;
	};

	//Ap Getter
	int getAp()
	{
		return ap;
	};

	//Dp Getter
	int getDp()
	{
		return dp;
	};

	//atk Getter
	int getATK()
	{
		return ATK;
	};

	//def Getter
	int getDEF()
	{
		return DEF;
	};

	//spd Getter
	int getSPD()
	{
		return SPD;
	};

	//agi Getter
	int getAGI()
	{
		return AGI;
	};

	//dex Getter
	int getDEX()
	{
		return DEX;
	};

	//int Getter
	int getINT()
	{
		return INT;
	};

	//spr Getter
	int getSPR()
	{
		return SPR;
	};

	//str Getter
	int getSTR()
	{
		return STR;
	};

	//end Getter
	int getEND()
	{
		return END;
	};

	//con Getter
	int getCON()
	{
		return CON;
	};

	//get Status
	//statusEff getStatus();

	//exp Getter
	int getExp()
	{
		return EXP;
	};

#pragma endregion

	// setters / mutators

#pragma region setters
	void setParty_num(int n)
	{
		party_num = n;
	}

	void setSPDplus(int m)
	{
		dummyPlus = m;
	}

	void setName(string x)
	{
		name = x;
	}

	void statMSet(bool d)
	{
		statmulti = d;
	}

	void setHp(int hpin)
	{
		hp = hpin;
	}

	void setSp(int spin)
	{
		sp = spin;
	}

	void setFp(int fpin)
	{
		fp = fpin;
	}

	void setAp(int apin)
	{
		ap = apin;
	}

	void setDp(int dpin)
	{
		dp = dpin;
	}

	void setATK(int atin)
	{
		ATK = atin;
	}

	void setDEF(int dein)
	{
		DEF = dein;
	}

	void setSPD(int sdin)
	{
		SPD = sdin;
	}

	void setSTR(int stin)
	{
		STR = stin;
	}

	void setAGI(int agin)
	{
		AGI = agin;
	}

	void setEND(int send)
	{
		END = send;
	}

	void setCON(int coin)
	{
		CON = coin;
	}

	void setDEX(int dexin)
	{
		DEX = dexin;
	}

	void setINT(int intIn)
	{
		INT = intIn;
	}

	void setSPR(int sprIn)
	{
		SPR = sprIn;
	}

	void setEXP(int expin, int plus)
	{
		//int eDrain = plus;

		if (statmulti == true)
		{
			EXP += expin + plus;
		}
		else
		{
			cout << "EXP multiplier gain has faded." << endl;
			EXP += expin;
			//EXP -= eDrain;
		}
	}

	void statPlus(char stat, int plus);



#pragma endregion

	// down couts

#pragma region getters
	//Hp Getter
	int getHpd()
	{
		return hpd;
	};

	//Sp Getter
	int getSpd()
	{
		return spd;
	};

	//Fp Getter
	int getFpd()
	{
		return fpd;
	};

	//atk Getter
	int getATKd()
	{
		return ATKd;
	};

	//def Getter
	int getDEFd()
	{
		return DEFd;
	};

	//spd Getter
	int getSPDd()
	{
		return SPDd;
	};

	//agi Getter
	int getAGId()
	{
		return AGId;
	};

	//dex Getter
	int getDEXd()
	{
		return DEXd;
	};

	//int Getter
	int getINTd()
	{
		return INTd;
	};

	//spr Getter
	int getSPRd()
	{
		return SPRd;
	};

	//str Getter
	int getSTRd()
	{
		return STRd;
	};

	//end Getter
	int getENDd()
	{
		return ENDd;
	};

	//con Getter
	int getCONd()
	{
		return CONd;
	};

	int getBGspd()
	{
		return newSpd;
	};

#pragma endregion

#pragma region setters

	void setHpd(int hpin)
	{
		hpd = hpin;
	}

	void setSpd(int spin)
	{
		spd = spin;
	}

	void setFpd(int fpin)
	{
		fpd = fpin;
	}

	void setATKd(int atin)
	{
		ATKd = atin;
	}

	void setDEFd(int dein)
	{
		DEFd = dein;
	}

	void setSPDd(int sdin)
	{
		SPDd = sdin;
	}

	void setSTRd(int stin)
	{
		STRd = stin;
	}

	void setAGId(int agin)
	{
		AGId = agin;
	}

	void setENDd(int send)
	{
		ENDd = send;
	}

	void setCONd(int coin)
	{
		CONd = coin;
	}

	void setDEXd(int dexin)
	{
		DEXd = dexin;
	}

	void setINTd(int intIn)
	{
		INTd = intIn;
	}

	void setSPRd(int sprIn)
	{
		SPRd = sprIn;
	}

	void setBGSpd(int spdIn);
#pragma endregion

	//// functions

	void setStatus(statusEff);

	statusEff getStatus();

	string printStatus();

	void setTitle(string n);

	int getSPDPlus();

	//void setStatus(statusEff statusName);

	//states (I called status effects please excuse me on that.)
	aegesa::statusEff indexer(int);

	bool isFull(int);

	void insertStatus(int key, aegesa::statusEff m);

	void remove_state(int id, bool force);

	void add_state(int id, bool force);

	int battleGuage(int spd);
	string normalOutput(string normal)
	{
		return normal;
	};

	~aegesa();
};
