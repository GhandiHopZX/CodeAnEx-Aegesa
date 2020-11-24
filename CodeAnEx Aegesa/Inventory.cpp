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
	this->stackArray = &capacity;
	this->capacity = 20;
}

inventory::inventory(int)
{
	this->heada = 0;
	this->headi = 0;
	this->headw = 0;
	this->size = 20;
	this->stackArray = &capacity;
	this->capacity = 20;
}

void inventory::displaylistItem()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (my_items[i].name.empty())
		{
		}
		else
		{
			cout << my_items[i].name << endl;
		}
	}
}

void inventory::displaylistWeapon()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (my_weapons[i].name.empty())
		{
		}
		else
		{
			cout << my_weapons[i].name << endl;
		}
	}
}

void inventory::displaylistArmor()
{
	for (size_t i = 0; i < 20; i++)
	{
		if (my_armors[i].name.empty())
		{
		}
		else
		{
			cout << my_armors[i].name << endl;
		}
	}
}

void inventory::displayAll()
{
	displaylistArmor();
	displaylistItem();
	displaylistWeapon();
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

void inventory::PlayerItemInventory(Player_Actor party[])
{
	system("CLS");
	string c;
	cout << "			-ALL ITEMS Inventory- " << endl;
	displayAll();

	cout << "	Sort Lists?  (1)weapons, (2)armors, (3)items, (Q)quit " << endl;
	cout << "			NOTICE: 	ALL OF WHICH ARE UNEQUIPPED...			  " << endl;

	cin >> c;

	// player selection
	switch (choiceIn(c))
	{
	case 1:
		system("CLS");
		displaylistWeapon();
		cout << "Ok?" << endl;
		system("PAUSE");
		PlayerItemInventory(party);
		break;

	case 2:
		system("CLS");
		displaylistArmor();
		cout << "Ok?" << endl;
		system("PAUSE");
		PlayerItemInventory(party);
		break;

	case 3:
		system("CLS");
		displaylistItem();
		cout << "Ok?" << endl;
		system("PAUSE");
		PlayerItemInventory(party);
		break;

	case 'q':
		// end
		break;
	default:
		break;
	}
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
	for (int i = 0; i < 20; i++)
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

void inventory::EquipItemSelect(Player_Actor p[])
{
	int partyNum = p->getParty_num();
	int choice = 0;
	int choice2 = 0;
	char choiceC = ' ';

	system("CLS");

	cout << "Equip Armor/Weapon for what Member?(Any Key) Or exit? (Q)" << endl;

	cin >> choiceC;

	switch (choiceC)
	{
	case 'Q':
		return;
		break;
	case 'q':
		return;
		break;
	default:
		for (int i = 0; i < partyNum; i++)
		{
			// for the ones to choose
			cout << p[i].getName() << endl;
			cout << endl;
		}

		cout << "Select Member... " << "0 - " << partyNum - 1 << endl;

		cin >> choice;

		system("CLS");

		while (choice < 0 || choice > partyNum)
		{
			cout << "Invalid selection. Reselect...";
			cin >> choice;
			break;
		}

		system("CLS");

		cout << "Armors(0) or weapons(1)?" << endl;

		cin >> choice2;

		while (choice2 < 0 || choice2 > 1)
		{
			cout << "Invalid selection. Reselect...";
			cin >> choice2;
			break;
		}

		if (choice <= partyNum)
		{
			switch (choice2)
			{
			case 0:
				DisplayEQArmors(p, choice);
				EquipItemSelect(p);
				break;

			default:
				DisplayEQWeapons(p, choice);
				EquipItemSelect(p);
				break;
			}
		}
		break;
	}
}

void inventory::DisplayEQArmors(Player_Actor p[], int call)
{
	for (size_t i = 0; i < 3; i++)
	{
		if (p[call].getArmorEQ().name.empty())
		{
			cout << "empty slot " << endl;
		}
		else
		{
			cout << p[call].getArmorEQ().name << endl;
		}
	}
}

void inventory::DisplayEQWeapons(Player_Actor p[], int call)
{
	for (size_t i = 0; i < 1; i++)
	{
		if (p[call].getWeaponEQ().name.empty())
		{
			cout << "empty slot " << endl;
		}
		else
		{
			cout << p[call].getWeaponEQ().name << endl;
		}
	}
}

void inventory::zeroOut(int ix)
{
	my_items[ix].agiAdd = NULL;
	my_items[ix].agiAdd = NULL;
	my_items[ix].apAdd = NULL;
	my_items[ix].atkAdd = NULL;
	my_items[ix].name = "";
	my_items[ix].hpAdd = NULL;
	my_items[ix].spAdd = NULL;
	my_items[ix].fpAdd = NULL;
	my_items[ix].defAdd = NULL;
	my_items[ix].spdAdd = NULL;
	my_items[ix].dexAdd = NULL;
	my_items[ix].intAdd = NULL;
	my_items[ix].sprAdd = NULL;
	my_items[ix].endAdd = NULL;
	my_items[ix].conAdd = NULL;
	my_items[ix].goldValue = NULL;
	my_items[ix].quantity = NULL;
}

char inventory::choiceIn(string choiceBuffer)
{
	//string choiceBuffer;
	char choice = NULL;
	//cin >> choice;
	char* choiceWritable = new char[choiceBuffer.size() + 1];

	copy(choiceBuffer.begin(), choiceBuffer.end(), choiceWritable);

	choiceWritable[choiceBuffer.size()] = '\0';

	char* choice3 = choiceWritable;

	char& choice4 = *choice3;

	choice = choice4;

	delete[] choiceWritable;

	return choice;
}