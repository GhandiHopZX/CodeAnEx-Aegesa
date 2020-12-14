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


inventory::inventory()
{
	this->itemCount = 19;
	this->armorCount = 19;
	this->weaponCount = 19;
	this->size = 20;
	this->stackArray = &capacity;
	this->capacity = 20;
}

inventory::inventory(int)
{
	this->itemCount = 19;
	this->armorCount = 19;
	this->weaponCount = 19;
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
void inventory::EquipA(Player_Actor ip, ItemType::armor aq, int selected)
{
	// virtual keys here
	//
	system("CLS");
	
	ItemType::armor stackIn[19] = {}; // leave this

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
			setCurrent(d + 1);
			setMarker(current, itemCount/2); // marker initialization itemCount/2 will never be accessed 
			cout << d + 1 << " " << my_armors[d + 1].name << getMarker(markers[d + 1]) << endl;
			lastM = d;
		}

		
#pragma warning(disable : 4996)
		char key = getch();
		int value = key;
		int choice4{};
		ItemType::armor lArmor;
		int eqArmors{};

		while (choice3 == NULL || value != KEY_X)
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

			case KEY_Z:
				choice3 = getMarkerInt(current);
				// slot selector Yay...
				// just do a number input
				
				for (int i = 0; i < 2; i++)
				{
					if (ip.getArmorEQ2(i).name.empty())
					{
						cout << "empty slot " << endl;
					}
					else
					{
						++eqArmors;
						cout << ip.getArmorEQ2(i).name << endl;

					}
				}
				if (eqArmors <= 0)
				{
					system("CLS");
					cout << "No armor items to equip" << endl;
					system("PAUSE");
				}
				cin >> choice4;

				while (choice4 >= 2 || choice4 <= 2)
				{
					cout << "wrong choice" << endl;
					cin >> choice4;
				}

				// conversions needed
				//lArmor = ip.getArmorEQ2(choice4); //convertMethod
				 //if checking if lArmor is empty, replace with an empty slot
				//if (lArmor.name.empty())
				//{
					//zeroOutAr(getCurrent());
				//}
				//ip.setArmor(choice4, my_armors[getCurrent()]); //convertMethod
				//my_armors[getCurrent()] = lArmor; // convertMethod
				

			default:
				break;
			}
		}

		key = getch();
		value = key;
		i = 0;

	}
}

void inventory::listGetchArmorUp(int d, int itemCount, int lastM, ItemType::armor stackIn[])
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
		current = 0;
		inventory::setMarker(0, lastM);
		lastM = 0;
	}
	else if (lastM <= 0)
	{
		lastM = 0;
		current = itemCount;
		inventory::setMarker(itemCount, lastM);
		lastM = itemCount;
	}
	else
	{
		current = lastM - 1;
		setMarker(lastM - 1, lastM);
		lastM = lastM + 1;
	}

#pragma endregion
}

void inventory::listGetchArmorDown(int d, int itemCount, int lastM, ItemType::armor stackIn[])
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
		current = 0;
		lastM = itemCount;
		inventory::setMarker(0, lastM);
		lastM = 0;
	}
	else if (lastM <= 0)
	{
		lastM = 0;
		current = itemCount;
		inventory::setMarker(itemCount, lastM);
		lastM = itemCount;
	}
	else
	{
		current = lastM + 1;
		setMarker(lastM + 1, lastM);
		lastM = lastM - 1;
	}

#pragma endregion
}

void inventory::EquipW(Player_Actor i, ItemType::weapon wq, int selected)
{
}

void inventory::UnequipA(Player_Actor i, ItemType::armor aq, int selected)
{
}

void inventory::UnequipW(Player_Actor i, ItemType::weapon wq, int selected)
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

int inventory::GetItem(string id, ItemType::item inventItem)
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

bool inventory::TakeItem(ItemType::item im)
{
	ItemType::item b = im;
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

void inventory::addItem(ItemType::item n)
{
	ItemType::item m;
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

void inventory::add(ItemType::item n)
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
	ItemType::item inventoryItem;
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
	ItemType::item b;
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

void inventory::zeroOutAr(int ix)
{
	my_armors[ix].agiAdd = NULL;
	my_armors[ix].agiAdd = NULL;
	my_armors[ix].atkAdd = NULL;
	my_armors[ix].name = "";
	my_armors[ix].defAdd = NULL;
	my_armors[ix].spdAdd = NULL;
	my_armors[ix].dexAdd = NULL;
	my_armors[ix].intAdd = NULL;
	my_armors[ix].sprAdd = NULL;
	my_armors[ix].endAdd = NULL;
	my_armors[ix].conAdd = NULL;
	my_armors[ix].goldValue = NULL;
	my_armors[ix].quantity = NULL;
}

void inventory::zeroOutWe(int ix)
{
	my_weapons[ix].agiAdd = NULL;
	my_weapons[ix].agiAdd = NULL;
	my_weapons[ix].atkAdd = NULL;
	my_weapons[ix].name = "";
	my_weapons[ix].defAdd = NULL;
	my_weapons[ix].spdAdd = NULL;
	my_weapons[ix].dexAdd = NULL;
	my_weapons[ix].intAdd = NULL;
	my_weapons[ix].sprAdd = NULL;
	my_weapons[ix].endAdd = NULL;
	my_weapons[ix].conAdd = NULL;
	my_weapons[ix].goldValue = NULL;
	my_weapons[ix].quantity = NULL;
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