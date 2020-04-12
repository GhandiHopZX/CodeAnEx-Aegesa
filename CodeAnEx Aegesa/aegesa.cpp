#include <iostream>
#include "aegesa.h"
#include "Player_Actor.h"
#include "Enemy.h"
using namespace std;

aegesa::aegesa()
{
	EXP = NULL;
	dummyPlus = NULL;
	statmulti = NULL;
	party_num = 4;
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
	isPlayer = false;
	
}

void aegesa::setTitle(string n)
{
	title = n;
}

void aegesa::setStatus(statusEff statusName[])
{
	// Base stats
	statusName[0].hp += 5;

	// a criterion is checked here
	// and used to see what statuses are present in said
	// player status then are passed
	// into the statusEFF index then the index is passed into
	// gameSystem...
	// this is where the statuses are taken

	statusName[20] = {};
	statusEff thisStatus[20] = {};
	for (int i = 0; i < 20; i++)
	{
		My_Statuses[i] = statusName[i];
	}
	// beta test
	string beta = "test";
	// statusEff;
}

int aegesa::getSPDPlus()
{
	return dummyPlus;
}

aegesa::statusEff aegesa::getStatus()
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		My_Statuses[i];
		//statuses herpos
	}
	return My_Statuses[i];
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

void aegesa::battleGuage()
{
}

aegesa::~aegesa()
{
}