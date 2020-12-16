#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include "inventory.h"
#include "Player_Actor.h"
#include "ItemType.h"
using namespace std;

class inventory
{
private:

	// inventory
	int* stackArray;
	int capacity; // stack size
	int size;
	int itemCount;
	int armorCount;
	int weaponCount;
	
	// selections
	bool markers[19]{}; // capacity can't change... Yet..
	int current{};

	int getCurrent()
	{
		return current;
	}

	void setCurrent(int d)
	{
		current = d;
	}

	string getMarker(bool marker)
	{
		switch (marker)
		{
		case true:
			return " < --";
			break;
		default:
			return "";
			break;
		}
	}

	int getMarkerInt(int dl)
	{
		return markers[dl];
	}

	// upon moving last cursor
	void setLastMarker(int l, bool d)
	{
		markers[l] = d;
	}

	void setMarker(int k, int l)
	{
		setLastMarker(l, false);
		markers[k] = true;
	}

public:
	// structs

	// you're going to have to look at
	// different hash creations for each item, armor and weapon types
	// so that these can be saved to a file called to decoding then called to be
	// stored on a stack of memory (a method that stores it into an array)
	// to then be used from that list of data
	// ie: a non h file method but object method only
	// "ArmorBase", "WeaponBase", "ItemBase" etc...
	// to then call it to any other object (.cpp) not an h file
	// this could work with anything else
	// there are other methods but this is the only thing I could think of.


	//node heads

	unsigned int sum_weapons = 0; // total number of nodes
	unsigned int sum_armors = 0; // total number of nodes
	unsigned int sum_items = 0; // total number of nodes

	// constant variables
	static const int MAX_INTEGRITY = 20;

	// constructor
	inventory();

	inventory(int);

	inventory(const inventory&);

	// displayListo =)
	void displaylistItem();
	void displaylistWeapon();
	void displaylistArmor();
	void displayAll();

	void PlayerItemInventory(Player_Actor party[]);

	// other functions
	int GetItemCount()
	{
		return itemCount;
	}
	int GetArmorCount()
	{
		return armorCount;
	}
	int GetWeaponCount()
	{
		return weaponCount;
	}

	void SetItemCount(int m)
	{
		itemCount = m;
	}
	void SetArmorCount(int m)
	{
		armorCount = m;
	}
	void SetWeaponCount(int m)
	{
		weaponCount = m;
	}

	int GetItem(string id, ItemType inventItem);

	bool TakeItem(string id, int count, int agi, int ap, int atk, int hp,
		int sp, int fp, int def, int spd, int dex, int intell, int spr, int end, int con,
		int gold, int ivalue, int quantity, int node);

	bool TakeItem(ItemType im);

	// battleSystem

	void rewardCall(string index, int howMany);

	void addItem(string id, int count, int agi, int ap, int atk, int hp, int sp,
		int fp, int def, int spd, int dex, int intell, int spr, int end,
		int con, int gold, int ivalue, int quantity, int node);

	void addItem(ItemType n);

	void add(ItemType n);

	void removeItem(string id);

	int getItemQuantity(string id);

	void EquipItemSelect(Player_Actor p[]);

	void DisplayEQArmors(Player_Actor p[]);

	void DisplayEQWeapons(Player_Actor p[]);

	

	void DisplayEQArmorSelected(Player_Actor p[], int call);

	void DisplayEQWeaponsSelected(Player_Actor p[], int call);

	// conversions and conv back

	// conv back
	inventory pTIA(ItemType v, ItemType p, int select);

	inventory pTIW(ItemType v, ItemType p, int select);

	inventory pTII(ItemType v, ItemType p, int select);

	void zeroOut(int ix);

	void zeroOutAr(int ix);

	void zeroOutWe(int ix);

	char choiceIn(string choiceBuffer);



	// selections
	//item getItem(int);
	void itemExecute(Player_Actor i[], ItemType newI, int selectParty)
	{
		i[selectParty].setAGId(newI.agiAdd);
		i[selectParty].setATKd(newI.atkAdd);
		i[selectParty].setCONd(newI.conAdd);
		i[selectParty].setDEFd(newI.defAdd);
		i[selectParty].setDEXd(newI.dexAdd);
		i[selectParty].setENDd(newI.endAdd);
		i[selectParty].setSPDd(newI.spdAdd);
		i[selectParty].setSPRd(newI.sprAdd);
		i[selectParty].setINTd(newI.intAdd);
		i[selectParty].setSTRd(newI.strAdd);

		i[selectParty].setHpd(newI.hpAdd);
		i[selectParty].setSpd(newI.spAdd);
		i[selectParty].setFpd(newI.fpAdd);
		cout << newI.name << " used" << endl;
	}

	void EquipA(Player_Actor i[], ItemType aq, int selected);

	void EquipA(Player_Actor ip, ItemType aq, int selected);

	void listGetchArmorUp(int d, int itemCount, int lastM, ItemType stackIn[]);

	void listGetchArmorDown(int d, int itemCount, int lastM, ItemType stackIn[]);

	void EquipW(Player_Actor i, ItemType wq, int selected);

	void UnequipA(Player_Actor i, ItemType aq, int selected);

	void UnequipW(Player_Actor i, ItemType wq, int selected);

	void EquipW(Player_Actor i[], ItemType wq, int selected);

	void UnequipA(Player_Actor i[], ItemType aq, int selected);

	void UnequipW(Player_Actor i[], ItemType wq, int selected);

	// setters / mutators

	// shop_time

	// templates

	template <class aGCall>
	aGCall anyItemEver(aGCall index[], int select)
	{
		return aGCall[select];
	}

	// Deconstructor
	~inventory();
	int searchItem(string name);
};