#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <thread>
#include "Player_Actor.h"
#include "stateEffects.h"
//#include "inventory.h"
#include "aegesa.h"

using namespace std;

class Player_Actor : public aegesa
{
private:
	// variables

	string bio; // YOUR STORY!
	string name; // YOUR NAME!

	// variables

public:

	// stat multiplier flag
	/*bool statmulti;
	int dummyPlus;
	*/
	// Constructors
	Player_Actor();

	// getters / accessors

	string normalOutput(string normal)
	{
		return normal;
	};

	// new get 
	string getBio()
	{
		return bio;
	}
	// new set
	void setBio(string bin)
	{
		bio = bin;
	}



	//#pragma region getters
	//
	//	int getParty_num()
	//	{
	//		return party_num;
	//	}
	//
	//	string getName()
	//	{
	//		return name;
	//	};
	//
	//	string getBio()
	//	{
	//		return bio;
	//	}
	//
	//	bool getSMulti()
	//	{
	//		return statmulti;
	//	}
	//
	//	//Hp Getter
	//	int getHp()
	//	{
	//		return hp;
	//	};
	//
	//	//Sp Getter
	//	int getSp()
	//	{
	//		return sp;
	//	};
	//
	//	//Fp Getter
	//	int getFp()
	//	{
	//		return fp;
	//	};
	//
	//	//Ap Getter
	//	int getAp()
	//	{
	//		return ap;
	//	};
	//
	//	//Dp Getter
	//	int getDp()
	//	{
	//		return dp;
	//	};
	//
	//	//atk Getter
	//	int getATK()
	//	{
	//		return ATK;
	//	};
	//
	//	//def Getter
	//	int getDEF()
	//	{
	//		return DEF;
	//	};
	//
	//	//spd Getter
	//	int getSPD()
	//	{
	//		return SPD;
	//	};
	//
	//	//agi Getter
	//	int getAGI()
	//	{
	//		return AGI;
	//	};
	//
	//	//dex Getter
	//	int getDEX()
	//	{
	//		return DEX;
	//	};
	//
	//	//int Getter
	//	int getINT()
	//	{
	//		return INT;
	//	};
	//
	//	//spr Getter
	//	int getSPR()
	//	{
	//		return SPR;
	//	};
	//
	//	//str Getter
	//	int getSTR()
	//	{
	//		return STR;
	//	};
	//
	//	//end Getter
	//	int getEND()
	//	{
	//		return END;
	//	};
	//
	//	//con Getter
	//	int getCON()
	//	{
	//		return CON;
	//	};
	//
	//	//exp Getter
	//	int getExp()
	//	{
	//		return EXP;
	//	};
	//
	//#pragma endregion
	//
	//#pragma region setters
	//	
	//
	//	void setName(string x)
	//	{
	//		name = x;
	//	}
	//
	//	void setBio(string x)
	//	{
	//		bio = x;
	//	}
	//
	//	void statMSet(bool d)
	//	{
	//		statmulti = d;
	//	}
	//
	//	void setHp(int hpin)
	//	{
	//		hp = hpin;
	//	}
	//
	//	void setSp(int spin)
	//	{
	//		sp = spin;
	//	}
	//
	//	void setFp(int fpin)
	//	{
	//		fp = fpin;
	//	}
	//
	//	void setAp(int apin)
	//	{
	//		ap = apin;
	//	}
	//
	//	void setDp(int dpin)
	//	{
	//		dp = dpin;
	//	}
	//
	//	void setATK(int atin)
	//	{
	//		ATK = atin;
	//	}
	//
	//	void setDEF(int dein)
	//	{
	//		DEF = dein;
	//	}
	//
	//	void setSPD(int sdin)
	//	{
	//		SPD = sdin;
	//	}
	//
	//	void setSTR(int stin)
	//	{
	//		STR = stin;
	//	}
	//
	//	void setAGI(int agin)
	//	{
	//		AGI = agin;
	//	}
	//
	//	void setEND(int send)
	//	{
	//		END = send;
	//	}
	//
	//	void setCON(int coin)
	//	{
	//		CON = coin;
	//	}
	//
	//	void setDEX(int dexin)
	//	{
	//		DEX = dexin;
	//	}
	//
	//	void setINT(int intIn)
	//	{
	//		INT = intIn;
	//	}
	//
	//	void setSPR(int sprIn)
	//	{
	//		SPR = sprIn;
	//	}
	//
	//	void setEXP(int expin, int plus)
	//	{
	//		//int eDrain = plus;
	//
	//		if (statmulti == true)
	//		{
	//			EXP = expin + plus;
	//		}
	//		else
	//		{
	//			cout << "EXP multiplier gain has faded." << endl;
	//			EXP = expin;
	//			//EXP -= eDrain;
	//		}
	//	}
	//
	//	void statPlus(char stat, int plus)
	//	{
	//		int* eDrain = new int;
	//
	//		switch (stat)
	//		{
	//		case 'h':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cHp = getHp();
	//				cHp += plus;
	//				setHp(cHp);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				//battleSystem b;
	//				cout << "HP plus modifier has faded" << endl;
	//
	//				int dHp = getHp();
	//				dHp = dHp - *eDrain;
	//				setHp(dHp);
	//				delete eDrain;
	//			}
	//			break;
	//		case 's':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cSp = getSp();
	//				cSp += plus;
	//				setSp(cSp);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "SP plus modifier has faded" << endl;
	//				int dSp = getSp();
	//				dSp = dSp - *eDrain;
	//				setSp(dSp);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'f':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cFp = getFp();
	//				cFp += plus;
	//				setFp(cFp);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "FP plus modifier has faded" << endl;
	//
	//				int dFp = getFp();
	//				dFp = dFp - *eDrain;
	//				setFp(dFp);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'a':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cAp = getAp();
	//				cAp += plus;
	//				setSp(cAp);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "AP plus modifier has faded" << endl;
	//
	//				int dAp = getAp();
	//				dAp = dAp - *eDrain;
	//				setHp(dAp);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'd':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cDp = getDp();
	//				cDp += plus;
	//				setDp(cDp);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "DP plus modifier has faded" << endl;
	//
	//				int dDp = getDp();
	//				dDp = dDp - *eDrain;
	//				setDp(dDp);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'str':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cStr = getSTR();
	//				cStr += plus;
	//				setSTR(cStr);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "STR plus modifier has faded" << endl;
	//
	//				int dStr = getSTR();
	//				dStr = dStr - *eDrain;
	//				setSTR(dStr);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'atk':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cAtk = getATK();
	//				cAtk += plus;
	//				setATK(cAtk);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "ATK plus modifier has faded" << endl;
	//
	//				int dAtk = getATK();
	//				dAtk = dAtk - *eDrain;
	//				setATK(dAtk);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'def':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cDef = getDEF();
	//				cDef += plus;
	//				setDEF(cDef);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "DEF plus modifier has faded" << endl;
	//
	//				int dDef = getDEF();
	//				dDef = dDef - *eDrain;
	//				setDEF(dDef);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'agi':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cAgi = getAGI();
	//				cAgi += plus;
	//				setSp(cAgi);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "AGI plus modifier has faded" << endl;
	//
	//				int dAgi = getAGI();
	//				dAgi = dAgi - *eDrain;
	//				setAGI(dAgi);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'spd':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cSpd = getSPD();
	//				cSpd += plus;
	//				setSp(cSpd);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "SPD plus modifier has faded" << endl;
	//
	//				int dSpd = getSPD();
	//				dSpd = dSpd - *eDrain;
	//				setSPD(dSpd);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'end':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cEnd = getEND();
	//				cEnd += plus;
	//				setEND(cEnd);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "END plus modifier has faded" << endl;
	//
	//				int dEnd = getEND();
	//				dEnd = dEnd - *eDrain;
	//				setEND(dEnd);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'con':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cCon = getCON();
	//				cCon += plus;
	//				setCON(cCon);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "CON plus modifier has faded" << endl;
	//
	//				int dCon = getCON();
	//				dCon = dCon - *eDrain;
	//				setCON(dCon);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'int':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cInt = getINT();
	//				cInt += plus;
	//				setINT(cInt);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "INT plus modifier has faded" << endl;
	//
	//				int cInt = getINT();
	//				cInt = cInt - *eDrain;
	//				setINT(cInt);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'spr':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cSpr = getSPR();
	//				cSpr += plus;
	//				setSPR(cSpr);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "SPR plus modifier has faded" << endl;
	//
	//				int dSpr = getSPR();
	//				dSpr = dSpr - *eDrain;
	//				setSPR(dSpr);
	//				delete eDrain;
	//			}
	//			break;
	//		case 'dex':
	//			*eDrain = plus;
	//			if (statmulti == true)
	//			{
	//				int cDex = getDEX();
	//				cDex += plus;
	//				setDEX(cDex);
	//				delete eDrain;
	//			}
	//			else if (statmulti == false)
	//			{
	//				cout << "DEX plus modifier has faded" << endl;
	//
	//				int cDex = getDEX();
	//				cDex = cDex - *eDrain;
	//				setDEX(cDex);
	//				delete eDrain;
	//			}
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//
	//#pragma endregion



/*nventory::armor getArmorEQ();

inventory::weapon getWeaponEQ();

void setArmor(int y, inventory::armor d);
void setWeapon(int y, inventory::weapon d);*/


//templates;



		/*
		void setParty(Player_Actor currentPa, int pos);
		Player_Actor getParty();
		Player_Actor callPartyMember(int pos);
		//void battleGuage();
		*/

// Deconstructor
	~Player_Actor();
};