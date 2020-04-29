#include <iostream>
#include <list>
#include "aegesa.h"
#include <map>
#include <stack>
using namespace std;

aegesa::aegesa()
{
	EXP = NULL;
	dummyPlus = NULL;
	statmulti = NULL;
	party_num = 4;
	num_Statuses = 0;

	hpd = getHp();
	spd = getSp(); // special
	fpd = getFp(); // fighter (aural)

	ATKd = getATK(); // attack
	DEFd = getDEF(); // defence (armor based)
	SPDd = getSPD(); // speed

	AGId = getAGI(); // agility
	DEXd = getDEX(); // dexterity
	INTd = getINT(); // intelligence
	SPRd = getSPR(); // spirit
	STRd = getSTR(); // strength (also effects status)
	ENDd = getEND(); // endurance (bodily based / also effects status)
	CONd = getCON(); // constitution (mental, body, soul, based / also effects status)
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

string aegesa::printStatus()
{
	for (int i = 0; i < 20; i++)
	{
		return My_Statuses[i].buffName;
	}
}

void aegesa::setTitle(string n)
{
	title = n;
}

int aegesa::getSPDPlus()
{
	return dummyPlus;
}

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

bool aegesa::isFull(int d)
{
	for (int i = 0; i < 20; i++)
	{
		if (allEffGet[d].buffName != My_Statuses[i].buffName)
		{
			return false; // then the state isn't existant here
		}

		if (My_Statuses[i].turns_Of_aff == -1)
		{
			return true;
		}

		if (My_Statuses[i].turns_Of_aff == allEffGet[d].turns_Of_aff)
		{
			return true;
		}
	}

	return false;
}

void aegesa::insertStatus(int key, aegesa::statusEff m)
{
	auto& cell = aegesa::allEffGet2[num_Statuses];
	auto bItr = begin(cell);
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			bItr->second = m;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}

	if (! m.buffName.empty())
	{
		cell.emplace_back(key, num_Statuses);
	}
	return;
}

void aegesa::remove_state(int id, bool force = false)
{

}

void aegesa::add_state(int id, bool force = false)
{
// ineffective state
	if (allEffGet[id].turns_Of_aff == NULL)
	{
		return;
	}

	if (!force)
	{
		for (int i = 0; i < 20; i++)
		{
			//weird narrowing but workable narrowing
			// makes sure minus works
			if (allEffGet[i].minusState == true && !allEffGet[id].minusState) 
			{
				return;
			}
		}
	}

	if (!(My_Statuses[id].addState)) // state id > if the state is not added
	{
		insertStatus(id, allEffGet[id]);
	}

	if (allEffGet[id].zeroHP == true)
	{
		setHpd(0);
	}

	

	for (int i = 0; i < sizeupAEG; i++)
	{
		if (allEffGet[id].addState?(i):false)
		{
			insertStatus(i, allEffGet[id]);
		}

		if (allEffGet[id].minusState?(i):false)
		{
			// remove state
			remove_state(id, force);
		}
	}

	// line change to a large rating order (if value is the same, then a strong restriction order)
	

	int a = 0;
	int b = 0;
	aegesa::statusEff state_a;
	aegesa::statusEff state_b;
	state_a = allEffGet[statusGroups];
	state_b = allEffGet[statusGroups];

	//sort time; 


	//for loops for sorting
	for (int i = 0; i < sizeupAEG; i++)
	{
		if (state_a.rating > state_b.rating)
		{
			- 1;
		}

		else if (state_a.rating < state_b.rating)
		{
			+1;
		}

		else if (state_a.restriction > state_b.restriction)
		{
			-1;
		}

		else if (state_a.restriction < state_b.restriction)
		{
			+1;
		}

		else
		{
			//a <=> b; combined comparison
		}
	}
}



int aegesa::battleGuage(int spd)
{
	return spd;
}

aegesa::~aegesa()
{
}

