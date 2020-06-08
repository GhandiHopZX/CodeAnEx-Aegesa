#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include "inventory.h"

using namespace std;

class inventory
{
private:

	// inventory
	int* stackArray;
	int capacity; // stack size
	int size;


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

	struct weapon
	{
		string name;
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
		unsigned int goldValue = 0;

		unsigned int wvalue = 0; // node
		unsigned int quantity = 0;
		struct weapon* next; //next item
	};

	struct armor
	{
		string name;
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
		unsigned int goldValue = 0;

		unsigned int avalue = 0; //node
		unsigned int quantity = 0;
		struct armor* next; //next armor
	};

	struct item
	{
		string name;
		unsigned int hpAdd = 0;
		unsigned int spAdd = 0;
		unsigned int fpAdd = 0;
		unsigned int apAdd = 0;
		// no dp plus plz

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
		unsigned int goldValue = 0;

		unsigned int ivalue = 0; // node for items
		unsigned int quantity = 0;
		struct item* node;

		// next item
	};

	//node heads
	weapon* headw;

	armor* heada;

	item* headi;

	unsigned int sum_weapons = 0; // total number of nodes
	unsigned int sum_armors = 0; // total number of nodes
	unsigned int sum_items = 0; // total number of nodes

	// constant variables
	static const int MAX_INTEGRITY = 20;

	// constructor
	inventory();

	inventory(int);

	inventory(const inventory&);

	/*inventory(int, weapon);

	inventory(int, armor);

	inventory(int, item);*/
	// arrays for the player's inventory.

	/*inventory::weapon ActorWeaponE[1] = {};
	inventory::armor ActorArmorE[1] = {};*/

	// functions
	void push(int);
	void pop(int&);
	bool isFull() const;
	bool isEmpty() const;

	// append
	void appendNodeItem(item, int);
	void appendNodeWeapon(weapon, int);
	void appendNodeArmor(armor, int);

	// insert
	void insertNodeItem(item, int);
	void insertNodeWeapon(weapon, int);
	void insertNodeArmor(armor, int);

	// delete node
	void deleteNodeItem(item, int);
	void deleteNodeWeapon(weapon, int);
	void deleteNodeArmor(armor, int);

	// displayListo =)
	void displaylistItem() const;
	void displaylistWeapon() const;
	void displaylistArmor() const;

	void PlayerItemInventory();

	void combatItemInventory(inventory);

	// battleSystem
	void rewardCall(int);

	void addItem(int);

	void remItem(int);


#pragma region All_weapons
	inventory::weapon brawd_injector;
	inventory::weapon glass_gauntlet;
	inventory::weapon carbonite_knuckle;
	inventory::weapon crystalline_injector;
	inventory::weapon aerolite_gauntlet;
	inventory::weapon vandham_gauntlet;
	inventory::weapon antimatter_injector;
	inventory::weapon shinobi_claws;
	inventory::weapon tacheyon_injector;
	inventory::weapon magic_glove;
	inventory::weapon bomber_injector;
	inventory::weapon titanium_infused_gauntlet;
	inventory::weapon anti_nuclear_injector;
#pragma endregion

	inventory::weapon weaponlist[100] =
	{
	 brawd_injector,
	 glass_gauntlet,
	 carbonite_knuckle,
	 crystalline_injector,
	 aerolite_gauntlet,
	 vandham_gauntlet,
	 antimatter_injector,
	 shinobi_claws,
	 tacheyon_injector,
	 magic_glove,
	 bomber_injector,
	 titanium_infused_gauntlet,
	 anti_nuclear_injector
	};

	// selections

	// setters / mutators

	// shop_time

	// templates
	template <class Equip>
	Equip output(Equip i[], Equip newG, int select)
	{
		i[select] = newG;
	}

	template <class aGCall>
	aGCall anyItemEver(aGCall index[], int select)
	{
		return aGCall[select];
	}

	// Deconstructor
	~inventory();
};