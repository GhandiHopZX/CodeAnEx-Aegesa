#include <iostream>
#include <string>
#include <map>
#include <stack>
#include "inventory.h"

// use tha multimap function
using namespace std;

//items

#pragma region All_items
inventory::item AEGESA_FRAGMENT;
inventory::item kaider_shard;
inventory::item greenball_bun;
inventory::item enchantment_crystal;
inventory::item music_chord;
inventory::item static_weave;
inventory::item marble_eye;
inventory::item tiny_fingers;
inventory::item chared_beast_skin;
inventory::item magical_mane;
inventory::item masters_cane;
inventory::item broken_wing;
inventory::item ripped_coat;
inventory::item shattered_broach;
#pragma endregion

inventory::item itemlist[100] =
{
	AEGESA_FRAGMENT,
	kaider_shard,
	greenball_bun,
	enchantment_crystal,
	music_chord,
	static_weave,
	marble_eye,
	tiny_fingers,
	chared_beast_skin,
	magical_mane,
	masters_cane,
	broken_wing,
	ripped_coat,
	shattered_broach,
};

inventory::item allitemList(int integer)
{
	return itemlist[integer];
}

#pragma region itemNames
string itemNames[100] =
{
	AEGESA_FRAGMENT.name = "AEGESA FRAGMENT",
	kaider_shard.name = "kaider shard",
	greenball_bun.name = "greenball bun",
	enchantment_crystal.name = "enchantment crystal",
	music_chord.name = "music chord",
	static_weave.name = "static weave",
	marble_eye.name = "marble eye",
	tiny_fingers.name = "tiny fingers",
	chared_beast_skin.name = "chared beast skin",
	magical_mane.name = "magical mane",
	masters_cane.name = "masters mane",
	broken_wing.name = "broken wing",
	ripped_coat.name = "ripped coat",
	shattered_broach.name = "shattered broach",
};

#pragma endregion

#pragma region All_armors
	inventory::armor broad_armor;
	inventory::armor kavelar_gear;
	inventory::armor carbonite_gear;
	inventory::armor crystalline_armor;
	inventory::armor aerolite_gear;
	inventory::armor vandham_armor;
	inventory::armor antiImpact_armor;
	inventory::armor katType_armor;
	inventory::armor grenadier_composite_armor;
	inventory::armor anti_nuclear_armor;
#pragma endregion

inventory::armor armorlist[100] =
{
		broad_armor,
		kavelar_gear,
		carbonite_gear,
		crystalline_armor,
		aerolite_gear,
		vandham_armor,
		antiImpact_armor,
		katType_armor,
		grenadier_composite_armor,
		anti_nuclear_armor
	};

inventory::armor allarmorList(int integer)
{
	return armorlist[integer];
}

inventory::weapon my_weapons[inventory::MAX_INTEGRITY] =
{};

inventory::armor my_armors[inventory::MAX_INTEGRITY] =
{};

inventory::item my_items[inventory::MAX_INTEGRITY] =
{};

inventory::inventory()
{
	this->heada = 0;
	this->headi = 0;
	this->headw = 0;
	this->size = 20;
	this->capacity = 20;
}

inventory::inventory(int)
{
	this->heada = 0;
	this->headi = 0;
	this->headw = 0;
	this->size = 20;
	this->capacity = 20;
}

void inventory::displaylistItem()
{
	this->capacity = 20;
}

inventory::~inventory()
{
	
}

int inventory::searchItem(string name)
{
	for (int i = 0; i < 100; i++)
	{
		if (itemlist->name == name)
		{
			return i;
		}
	}
	return NULL;
}

int inventory::GetItem(string id, item inventItem)
{
	for (int i = 0; i < 20; ++i)
	{
		if (my_items[i].name == id)
		{
			inventItem = my_items[i];
			return i;
		}
	}
	return -1;
}

bool inventory::TakeItem(item im)
{
	item b = im;
	int itemSlot = GetItem(im.name, b);
	if (itemSlot == -1)
	{
		return false;
	}

	if (0 <= im.quantity)
	{
		removeItem(b.name);
		return false;
	}

	if (b.quantity > im.quantity)
	{
		b.quantity -= im.quantity;
	}
	else
	{
		zeroOut(searchItem(my_items[itemSlot].name));
		b.quantity = 0;
	}
	return true;
}

void inventory::rewardCall(string index, int howMany)
{
	if (itemlist[searchItem(index)].name.empty())
	{
		removeItem(index);
	}
	cout << itemlist[searchItem(index)].name << "Aquired..." << endl;
}

void inventory::addItem(item n)
{
	item m;
	int in = GetItem(n.name, m);
	for (int i = 0; i < 20; i++)
	{
		if (!itemlist[i].name.empty() && itemlist[i].name != m.name)
		{
			return;
		}
	}
	if (GetItem(n.name, m) == -1)
	{
		m = n;
		add(m);
	}
	else
	{
		m.quantity += n.quantity;
	}
}

void inventory::add(item n)
{
	for(int i = 0; i < 20; i++) 
	{
		if (my_items[i].name.empty() || my_items[i].name == "")
		{
			my_items[i] = n;
		}
	}
}

void inventory::removeItem(string id)
{
	item inventoryItem;
	int itemSlot = GetItem(id, inventoryItem);
	if (itemSlot == -1)
	{
		return;
	}

	zeroOut(itemSlot);

	inventoryItem.quantity = 0;
}

int inventory::getItemQuantity(string id)
{
	item b;
	if (GetItem(id, b) == -1)
	{
		return 0;
	}

	return b.quantity;
}

void inventory::zeroOut(int ix) 
{
	my_items[ix].agiAdd = 0;
	my_items[ix].agiAdd = 0;
	my_items[ix].apAdd = 0;
	my_items[ix].atkAdd = 0;
	my_items[ix].name = "";
	my_items[ix].hpAdd = 0;
	my_items[ix].spAdd = 0;
	my_items[ix].fpAdd = 0;
	my_items[ix].defAdd = 0;
	my_items[ix].spdAdd = 0;
	my_items[ix].dexAdd = 0;
	my_items[ix].intAdd = 0;
	my_items[ix].sprAdd = 0;
	my_items[ix].endAdd = 0;
	my_items[ix].conAdd = 0;
	my_items[ix].goldValue = 0;
	my_items[ix].quantity = 0;
}