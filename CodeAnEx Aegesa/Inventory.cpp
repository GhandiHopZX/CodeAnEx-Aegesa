#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <conio.h>
#include <wtypes.h>
#include "inventory.h"

// use tha multimap function
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120
#define KEY_Z 90

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
	this->itemCount = 19;
	this->armorCount = 19;
	this->weaponCount = 19;
	this->heada = 0;
	this->headi = 0;
	this->headw = 0;
	this->size = 20;
	this->stackArray = &capacity;
	this->capacity = 20;
}

inventory::inventory(int)
{
	this->itemCount = 19;
	this->armorCount = 19;
	this->weaponCount = 19;
	this->heada = 0;
	this->headi = 0;
	this->headw = 0;
	this->size = 20;
	this->stackArray = &capacity;
	this->capacity = 20;
}

void inventory::displaylistItem()
{
	for (size_t i = 0; i < 19; i++)
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
	for (size_t i = 0; i < 19; i++)
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
	for (size_t i = 0; i < 19; i++)
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

// unfinished fix number input
void inventory::EquipA(Player_Actor i[], inventory::armor aq, int selected)
{
	// virtual keys here
	//
	system("CLS");
	
	armor stackIn[19] = {};

	int itemCount = 0;
	for (int i = 0; i < 19; i++)
	{
		if (my_armors[i].name.empty())
		{
		}
		else
		{
			stackIn[i] = my_armors[i];
			++itemCount;
		}
	}

	// update
	SetItemCount(itemCount);
	int lastM{};
	int choice3 = 0;
	bool itemS = false;
	// infinite loop
	for (int i = 0; i < 1; i++)
	{
		system("CLS");
		switch (itemS)
		{
		case true:
			cout << " Select another Item..? " << endl;
			break;
		default:
			cout << " Here is the list of equippable items Equip item? (1 - 20)" << endl;
			//displaylistArmor();
			break;
		}

		for (int d = 0; d < itemCount - 1; d++)
		{
			if (my_armors[d].name.empty())
			{
			}

			else
			{
				stackIn[d] = my_armors[d];
				cout << d + 1 << " " << my_armors[d].name << getMarker(markers[d]) << endl;
			}

			setMarker(d + 1, itemCount/2); // marker initialization itemCount/2 will never be accessed 
			cout << d + 1 << " " << my_armors[d + 1].name << getMarker(markers[d + 1]) << endl;
			lastM = d;
		}

		// loop back
		/*HKL ActivateKeyboardLayout(
			HKL hkl,
			UINT Flags
		);*/
		
#pragma warning(disable : 4996)
		char key = getch();
		int value = key;

		while (choice3 == NULL || value != KEY_X || value != KEY_Z)
		{
			int d = 0;
			switch (getch())
			{
			case KEY_UP:
				listGetchArmorUp(d, itemCount, lastM, stackIn);
				// equip ask
				//  < -- here
				system("CLS");
				break;
			case KEY_DOWN:
				listGetchArmorDown(d, itemCount, lastM, stackIn);
				// equip ask
				//  < -- here
				system("CLS");

				break;
			default:
				break;
			}
		}
		key = getch();
		value = key;
		i = 0;
	}
}

void inventory::listGetchArmorUp(int d, int itemCount, int lastM, armor stackIn[])
{
#pragma region
	d = 0;
	for (; d < itemCount - 1; d++)
	{
		if (my_armors[d].name.empty())
		{
		}

		else
		{
			stackIn[d] = my_armors[d];
			cout << d + 1 << " " << my_armors[d].name << inventory::getMarker(markers[d]) << endl;
		}
	}
	cout << d + 1 << " " << my_armors[d + 1].name << getMarker(markers[d + 1]) << endl;

	if (lastM >= itemCount)
	{

		lastM = itemCount;
		inventory::setMarker(0, lastM);
		lastM = 0;
	}
	else if (lastM <= 0)
	{
		lastM = 0;
		inventory::setMarker(itemCount, lastM);
		lastM = itemCount;
	}
	else
	{
		setMarker(lastM - 1, lastM);
		lastM = lastM + 1;
	}

#pragma endregion
}

void inventory::listGetchArmorDown(int d, int itemCount, int lastM, armor stackIn[])
{
#pragma region 
	d = 0;
	for (; d < itemCount - 1; d++)
	{
		if (my_armors[d].name.empty())
		{
		}
		else if (lastM <= 0)
		{
			lastM = 0;
			inventory::setMarker(itemCount, lastM);
			lastM = itemCount;
		}
		else
		{
			stackIn[d] = my_armors[d];
			cout << d + 1 << " " << my_armors[d].name << inventory::getMarker(markers[d]) << endl;
		}
	}
	cout << d + 1 << " " << my_armors[d + 1].name << getMarker(markers[d + 1]) << endl;

	if (lastM >= itemCount)
	{

		lastM = itemCount;
		inventory::setMarker(0, lastM);
		lastM = 0;
	}
	else if (lastM <= 0)
	{
		lastM = 0;
		inventory::setMarker(itemCount, lastM);
		lastM = itemCount;
	}
	else
	{
		setMarker(lastM + 1, lastM);
		lastM = lastM - 1;
	}

#pragma endregion
}

void inventory::EquipW(Player_Actor i[], inventory::weapon wq, int selected)
{
}

void inventory::UnequipA(Player_Actor i[], inventory::armor aq, int selected)
{
}

void inventory::UnequipW(Player_Actor i[], inventory::weapon wq, int selected)
{
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
	char choice2{};
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
			cout << i << " " << p[i].getName() << endl;
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
		system("PAUSE");
		cout << "Armors(a) or weapons(w)?" << endl;

		cin >> choice2;

		if (choice <= partyNum)
		{
			switch (choice2)
			{
			case 'a':
				DisplayEQArmors(p);
				// armor list
				cout << "	-unequipped armors-" << endl;
				displaylistArmor();

				EquipItemSelect(p);
				break;

			case 'w':
				DisplayEQWeapons(p);
				// weapon list
				cout << "	-unequipped weapons-" << endl;
				displaylistWeapon();
				EquipItemSelect(p);
				break;
			default:
				cout << "Invalid selection. Reselect...";
				cin >> choice2;
				break;
			}
		}
		break;
	}
}

void inventory::DisplayEQArmors(Player_Actor p[])
{
	system("CLS");
	for (size_t i = 0; i < 3; i++)
	{
		if (p[i].getArmorEQ().name.empty())
		{
			cout << "empty slot " << endl;
		}
		else
		{
			cout << p[i].getArmorEQ().name << endl;
			
		}
	}
	system("PAUSE");
}

void inventory::DisplayEQWeapons(Player_Actor p[])
{
	system("CLS");
	for (size_t i = 0; i < 1; i++)
	{
		if (p[i].getWeaponEQ().name.empty())
		{
			cout << "empty slot " << endl;
		}
		else
		{
			cout << p[i].getWeaponEQ().name << endl;
		}
	}
	system("PAUSE");
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