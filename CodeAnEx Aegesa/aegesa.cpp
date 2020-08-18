#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <vector>
#include <utility>
#include "aegesa.h"

using namespace std;

aegesa::aegesa()
{
	EXP = 0;
	dummyPlus = NULL;
	statmulti = NULL;
	party_num = 4;
	num_Statuses = 0;

	hpd = getHpd();
	spd = getSpd(); // special
	fpd = getFpd(); // fighter (aural)

	ATKd = getATKd(); // attack
	DEFd = getDEFd(); // defence (armor based)
	SPEEDd = getSPDd(); // speed

	AGId = getAGId(); // agility
	DEXd = getDEXd(); // dexterity
	INTd = getINTd(); // intelligence
	SPRd = getSPRd(); // spirit
	STRd = getSTRd(); // strength (also effects status)
	ENDd = getENDd(); // endurance (bodily based / also effects status)
	CONd = getCONd(); // constitution (mental, body, soul, based / also effects status)
}

void aegesa::setBGSpd(int spdIn)
{
	newSpd = getSPDd() + static_cast<int>(0.3) *(spdIn * getSPD());
}

//void aegesa::setStatus(statusEff)
//{
//}
//
//aegesa::statusEff aegesa::getStatus()
//{
//	return statusEff();
//}

//bool stateEffects::isFull(int d)
//{
//	for (int i = 0; i < 20; i++)
//	{
//		if (allEffGet[d].buffName != aegesa::My_Statuses[i].buffName)
//		{
//			return false; // then the state isn't existant here
//		}
//
//		if (aegesa::My_Statuses[i].turns_Of_aff == -1)
//		{
//			return true;
//		}
//
//		if (aegesa::My_Statuses[i].turns_Of_aff == allEffGet[d].turns_Of_aff)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}

// states are added here
void aegesa::setState(string name)
{
	stateCheck();
	for (int i = 0; i < 20; i++)
	{
		int m = getNumOfStates() + 1;
		//My_Statuses2.
		//validate actual states
		//add one if needed
		//put in the state 
		My_Statuses2->insert(pair<int, string>(m, name));
	}
}

// gets all states
string aegesa::getState()
{
	stateCheck();
	map<int, string>::iterator it;
	string sups[20];

	for (int i = 0; i < getNumOfStates(); i++)
	{
		for (it = My_Statuses2[i].begin(); it != My_Statuses2[i].end(); ++it)
		{
			sups[i] += it->second;
		}
		return sups[i];
	}
}

// print all states
void aegesa::printStates()
{
	string cstate;
	cstate = " CURRENT STATES";

	// iterator
	map<int, string>::iterator it;

	for (int i = 0; i < getNumOfStates(); i++)
	{
		for (it = My_Statuses2[i].begin(); it!= My_Statuses2[i].end(); ++it)
		{
			cout << "[" << it->second << "]" << " /" << " ";
		}
	}
}

// Title change
void aegesa::setTitle(string n)
{
	title = n;
}

// speed add for in battle status 
int aegesa::getSPDPlus()
{
	return dummyPlus;
}

// no state avaliable
bool aegesa::stateIsEmpty()
{
	for (int i = 0; i < 20; i++)
	{
		if (My_Statuses2->at(i).empty())
		{
			return true;
		}

		if (My_Statuses2->at(i) == "")
		{
			return true;
		}

		if (My_Statuses2->at(i).size() > My_Statuses2->at(i).empty())
		{
			return false; // then the state isn't existant here its something else
		}
	}
	
	return false;
}

// gets rid of states
void aegesa::removeStates(int io)
{
	My_Statuses2->at(io).erase();
	setNumOfStates(-1);
}

// is the state there??
void aegesa::stateCheck()
{
	for (int i = 0; i < getNumOfStates(); i++)
	{
		if (My_Statuses2->at(i).empty())
		{
			removeStates(i);
		}
	}
}

// stat add modifier for another modifiers
// like stat boosts or debufs and other status effects for transfer
void aegesa::statPlus(char stat, int plus)
{
	int* eDrain = new int;

	switch (stat)
	{
	case 'h':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cHp = getHp();
			cHp += plus;
			setHp(cHp);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			//battleSystem b;
			cout << "HP plus modifier has faded" << endl;

			int dHp = getHp();
			dHp = dHp - *eDrain;
			setHp(dHp);
			delete eDrain;
		}
		break;
	case 's':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cSp = getSp();
			cSp += plus;
			setSp(cSp);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "SP plus modifier has faded" << endl;
			int dSp = getSp();
			dSp = dSp - *eDrain;
			setSp(dSp);
			delete eDrain;
		}
		break;
	case 'f':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cFp = getFp();
			cFp += plus;
			setFp(cFp);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "FP plus modifier has faded" << endl;

			int dFp = getFp();
			dFp = dFp - *eDrain;
			setFp(dFp);
			delete eDrain;
		}
		break;
	case 'a':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cAp = getAp();
			cAp += plus;
			setSp(cAp);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "AP plus modifier has faded" << endl;

			int dAp = getAp();
			dAp = dAp - *eDrain;
			setHp(dAp);
			delete eDrain;
		}
		break;
	case 'd':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cDp = getDp();
			cDp += plus;
			setDp(cDp);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "DP plus modifier has faded" << endl;

			int dDp = getDp();
			dDp = dDp - *eDrain;
			setDp(dDp);
			delete eDrain;
		}
		break;
	case 'str':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cStr = getSTR();
			cStr += plus;
			setSTR(cStr);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "STR plus modifier has faded" << endl;

			int dStr = getSTR();
			dStr = dStr - *eDrain;
			setSTR(dStr);
			delete eDrain;
		}
		break;
	case 'atk':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cAtk = getATK();
			cAtk += plus;
			setATK(cAtk);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "ATK plus modifier has faded" << endl;

			int dAtk = getATK();
			dAtk = dAtk - *eDrain;
			setATK(dAtk);
			delete eDrain;
		}
		break;
	case 'def':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cDef = getDEF();
			cDef += plus;
			setDEF(cDef);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "DEF plus modifier has faded" << endl;

			int dDef = getDEF();
			dDef = dDef - *eDrain;
			setDEF(dDef);
			delete eDrain;
		}
		break;
	case 'agi':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cAgi = getAGI();
			cAgi += plus;
			setSp(cAgi);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "AGI plus modifier has faded" << endl;

			int dAgi = getAGI();
			dAgi = dAgi - *eDrain;
			setAGI(dAgi);
			delete eDrain;
		}
		break;
	case 'spd':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cSpd = getSPD();
			cSpd += plus;
			setSp(cSpd);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "SPD plus modifier has faded" << endl;

			int dSpd = getSPD();
			dSpd = dSpd - *eDrain;
			setSPD(dSpd);
			delete eDrain;
		}
		break;
	case 'end':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cEnd = getEND();
			cEnd += plus;
			setEND(cEnd);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "END plus modifier has faded" << endl;

			int dEnd = getEND();
			dEnd = dEnd - *eDrain;
			setEND(dEnd);
			delete eDrain;
		}
		break;
	case 'con':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cCon = getCON();
			cCon += plus;
			setCON(cCon);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "CON plus modifier has faded" << endl;

			int dCon = getCON();
			dCon = dCon - *eDrain;
			setCON(dCon);
			delete eDrain;
		}
		break;
	case 'int':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cInt = getINT();
			cInt += plus;
			setINT(cInt);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "INT plus modifier has faded" << endl;

			int cInt = getINT();
			cInt = cInt - *eDrain;
			setINT(cInt);
			delete eDrain;
		}
		break;
	case 'spr':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cSpr = getSPR();
			cSpr += plus;
			setSPR(cSpr);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "SPR plus modifier has faded" << endl;

			int dSpr = getSPR();
			dSpr = dSpr - *eDrain;
			setSPR(dSpr);
			delete eDrain;
		}
		break;
	case 'dex':
		*eDrain = plus;
		if (statmulti == true)
		{
			int cDex = getDEX();
			cDex += plus;
			setDEX(cDex);
			delete eDrain;
		}
		else if (statmulti == false)
		{
			cout << "DEX plus modifier has faded" << endl;

			int cDex = getDEX();
			cDex = cDex - *eDrain;
			setDEX(cDex);
			delete eDrain;
		}
		break;
	default:
		break;
	}
}

//aegesa::statusEff aegesa::indexer(int e)
//{
//	return allEffGet[e]; // indexed item if exists
//}

// speed = how fast you can take your turn
int aegesa::battleGuage(int spd)
{
	return spd;
}

aegesa::~aegesa()
{
}

