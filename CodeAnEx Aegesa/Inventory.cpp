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
	headw = nullptr;
	heada = nullptr;
	headi = nullptr;
	size = 20;
	capacity = 100;

	sum_weapons = 0; // total number of nodes
	sum_armors = 0; // total number of nodes
	sum_items = 0;
}

inventory::inventory(int)
{
	headw = nullptr;
	heada = nullptr;
	headi = nullptr;
	size = 20;
	capacity = 100;
	stackArray = 0;

	sum_weapons = 0; // total number of nodes
	sum_armors = 0; // total number of nodes
	sum_items = 0;
}

inventory::inventory(const inventory&)
{
	capacity = MAX_INTEGRITY;
	headw = nullptr;
	heada = nullptr;
	headi = nullptr;
	size = 20;
	capacity = 100;
	stackArray = 0;

	sum_weapons = 0; // total number of nodes
	sum_armors = 0; // total number of nodes
	sum_items = 0;
}

void inventory::push(int val)
{
	val++;
}

void inventory::pop(int& a)
{
	--a;
}

bool inventory::isFull() const
{
	return false;
}

bool inventory::isEmpty() const
{
	return false;
}

void inventory::appendNodeItem(item, int sitm)
{
	item* newNode;
	item* nodePtr;

	// allocation
	newNode = new item;
	newNode->ivalue = sitm; //value
	newNode->node = nullptr;

	if (!headi)
		headi = newNode;
	else
	{
		my_items[headi->ivalue].quantity += sitm;
		nodePtr = headi;
		while (nodePtr->node)
			nodePtr = nodePtr->node;
		nodePtr->node = newNode;
	}
}

void inventory::appendNodeWeapon(weapon, int w)
{
	weapon* newNode;
	weapon* nodePtr;

	// allocation
	newNode = new weapon;
	newNode->wvalue = w; //value
	newNode->next = nullptr;

	if (!headw)
		headw = newNode;
	else
	{
		nodePtr = headw;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void inventory::appendNodeArmor(armor, int a)
{
	armor* newNode;
	armor* nodePtr;

	// allocation
	newNode = new armor;
	newNode->avalue = a; //value
	newNode->next = nullptr;

	if (!heada)
		heada = newNode;
	else
	{
		nodePtr = heada;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void inventory::insertNodeItem(item, int i)
{
	item* newNode;
	item* nodePtr;
	item* previousItem = nullptr;

	newNode = new item;
	newNode->ivalue = i;

	if (!headi)
	{
		headi = newNode;
		newNode->node = nullptr;
	}

	else
	{
		nodePtr = headi;
		previousItem = nullptr;

		while (nodePtr != nullptr && nodePtr->ivalue < i)
		{
			previousItem = nodePtr;
			nodePtr = nodePtr->node;
		}

		if (previousItem == nullptr)
		{
			headi = newNode;
			newNode->node = nodePtr;
		}

		else
		{
			previousItem->node = newNode;
			newNode->node = nodePtr;
		}
	}
}

void inventory::insertNodeWeapon(weapon, int w)
{
	weapon* newNode;
	weapon* nodePtr;
	weapon* previousItem = nullptr;

	newNode = new weapon;
	newNode->wvalue = w;

	if (!headw)
	{
		headw = newNode;
		newNode->next = nullptr;
	}

	else
	{
		nodePtr = headw;
		previousItem = nullptr;

		while (nodePtr != nullptr && nodePtr->wvalue < w)
		{
			previousItem = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousItem == nullptr)
		{
			headw = newNode;
			newNode->next = nodePtr;
		}

		else
		{
			previousItem->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void inventory::insertNodeArmor(armor, int a)
{
	armor* newNode;
	armor* nodePtr;
	armor* previousItem = nullptr;

	newNode = new armor;
	newNode->avalue = a;

	if (!heada)
	{
		heada = newNode;
		newNode->next = nullptr;
	}

	else
	{
		nodePtr = heada;
		previousItem = nullptr;

		while (nodePtr != nullptr && nodePtr->avalue < a)
		{
			previousItem = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousItem == nullptr)
		{
			heada = newNode;
			newNode->next = nodePtr;
		}

		else
		{
			previousItem->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void inventory::deleteNodeItem(item, int i)
{
	item* nodePtr;
	item* previousNode = {};

	if (!headi)
	{
		return;
	}
	if (headi->ivalue == i)
	{
		nodePtr = headi->node;
		delete headi;
		headi = nodePtr;
	}
	else
	{
		nodePtr = headi;
		while (nodePtr != nullptr && nodePtr->ivalue != i)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->node;
		}
		if (nodePtr->quantity <= 0)
		{
			previousNode->node = nodePtr->node;
			delete nodePtr;
		}
	}
}

void inventory::deleteNodeWeapon(weapon, int w)
{
	weapon* nodePtr;
	weapon* previousNode = {};

	if (!headw)
	{
		return;
	}
	if (headw->wvalue == w)
	{
		nodePtr = headw->next;
		delete headw;
		headw = nodePtr;
	}
	else
	{
		nodePtr = headw;
		while (nodePtr != nullptr && nodePtr->wvalue != w)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr->quantity <= 0)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void inventory::deleteNodeArmor(armor, int a)
{
	armor* nodePtr;
	armor* previousNode = {};

	if (!headi)
	{
		return;
	}
	if (headi->ivalue == a)
	{
		nodePtr = heada->next;
		delete heada;
		heada = nodePtr;
	}
	else
	{
		nodePtr = heada;
		while (nodePtr != nullptr && nodePtr->avalue != a)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr->quantity <= 0)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void inventory::displaylistItem() const
{
	item* nodePtr;

	nodePtr = headi;

	while (nodePtr)
	{
		nodePtr->ivalue;
		cout << nodePtr->node << '\t' << '\t' << nodePtr->quantity << endl;
		nodePtr = nodePtr->node;
	}
}

void inventory::displaylistWeapon() const
{
	weapon* nodePtr;

	nodePtr = headw;

	while (nodePtr)
	{
		nodePtr->wvalue;
		cout << nodePtr->next << '\t' << '\t' << nodePtr->quantity << endl;
		nodePtr = nodePtr->next;
	}
}

void inventory::displaylistArmor() const
{
	armor* nodePtr;

	nodePtr = heada;

	while (nodePtr)
	{
		nodePtr->avalue;
		cout << nodePtr->next << '\t' << '\t' << nodePtr->quantity << endl;
		nodePtr = nodePtr->next;
	}
}

Player_Actor::weapon inventory::wConvert(Player_Actor::weapon ar, inventory::weapon ar2)
{
	
#pragma region stat match
	ar.agiAdd = ar2.agiAdd;
	ar.atkAdd = ar2.atkAdd;
	ar.conAdd = ar2.conAdd;
	ar.defAdd = ar2.defAdd;
	ar.dexAdd = ar2.dexAdd;
	ar.endAdd = ar2.endAdd;
	ar.goldValue = ar2.goldValue;
	ar.intAdd = ar2.intAdd;
	ar.name = ar2.name;
	ar.quantity = ar2.quantity;
	ar.spdAdd = ar2.spdAdd;
	ar.sprAdd = ar2.sprAdd;
	ar.strAdd = ar2.strAdd;
	ar.wvalue = ar2.wvalue;
#pragma endregion

	return ar;
}

Player_Actor::armor inventory::aConvert(Player_Actor::armor ar, inventory::armor ar2)
{

#pragma region stat match
	ar.agiAdd = ar2.agiAdd;
	ar.atkAdd = ar2.atkAdd;
	ar.conAdd = ar2.conAdd;
	ar.defAdd = ar2.defAdd;
	ar.dexAdd = ar2.dexAdd;
	ar.endAdd = ar2.endAdd;
	ar.goldValue = ar2.goldValue;
	ar.intAdd = ar2.intAdd;
	ar.name = ar2.name;
	ar.quantity = ar2.quantity;
	ar.spdAdd = ar2.spdAdd;
	ar.sprAdd = ar2.sprAdd;
	ar.strAdd = ar2.strAdd;
	ar.avalue = ar2.avalue;
#pragma endregion
	return ar;
}


//for combat
void inventory::PlayerItemInventory(Player_Actor party[]) // gotta make an inventory that'll work in the world menu
{
	system("CLS");
	// show choices'
	cout << "What menu would you like to select..?" << endl;
	cout << "Items(i), Armors(a), Weapons(w), Equipped(e), Quit(q)" << endl;
	char choice = {};
	int i = 0;
	int a = 0;
	int listCount = 1;
	int listCount2 = 1;
	int choiceInt;
	int hd = 0;
	int maxP = party->getParty_num();
	bool thaCurry = true;

	cin >> choice;
	
	switch (choice)
	{
	case 'i':
		do
		{
#pragma region inventory items
			//cout << "Select an Item? or Exit? (n): use an number to select one.. 0 - " << endl;
			i = 0;
			listCount = 1;
			for (size_t i = 0; i < MAX_INTEGRITY; i++)
			{
				cout << "(" << listCount << ") " << my_items[i].name << endl;
				if (!(my_items[i].name.empty()))
				{
					listCount += 1;
				}
				else
				{
					listCount += 0;
				}
			}
			//displaylistItem();

			/*for (size_t i = 0; i < listCount; i++)
			{
				cout << my_items[i].name << endl;
			}*/

			// select an item? using a #
			cout << "Select an item? Using a number.." << endl;
			//int i = 0;

			choice = NULL;
			cin >> i;
			cout << "Would you like to use this item? Yes(Y) or No(N) ?" << endl;
			cout << "[" << my_items[i].name << "]" << endl;

			choice = NULL;
			switch (choice)
			{
			case 'y':
				listCount = 1;
				hd = 0;
				cout << "On who?" << endl;
				for (int h = 0; h < maxP; h++)
				{
					cout << listCount << party[h].getName() << endl;
					++listCount;
				}
				cin >> hd;

				if (!(isalpha(hd)))
				{
					cout << "try again.." << endl;
					cin >> hd;
				}

				itemExecute(party, allitemList(i), hd);

				PlayerItemInventory(party);
				break;
			case 'n':
				PlayerItemInventory(party);
				break;
			default:
				PlayerItemInventory(party);
				break;
			}
			// select_Item(my_items[i]);
			//selectlistItem(i, o); // usage
			cout << "Make another selection?" << endl;
			PlayerItemInventory(party);
			break;
#pragma endregion
		


#pragma region armors

	case 'a':
		listCount = 1;
		hd = 0;
		choice = NULL;
		choiceInt;
		int choiceA;
		a = 0;
		int choiceB;
	
	    	for (size_t i = 0; i < listCount; i++)
	    	{
	    		cout << my_armors[i].name << endl;
	    		if (!(my_armors[i].name.empty()))
	    		{
	    			listCount += 1;
	    		}
	    		else
	    		{
	    			listCount += 0;
	    		}
	    	}
	    
	    	cout << "Select an Actor to select an armor.. 0 - " << maxP << endl;
	    	for (int h = 0; h < maxP; h++)
	    		{
	    			cout << listCount << party[h].getName() << endl;
	    			++listCount;
	    		}
	    	cin >> hd;
	    
	    	for (a = 0; a < listCount; a++)
	    	    {
	    			cout << a + 1 << my_armors[a].name << endl;
	    		}
	    
	    		cout << "Select an Armor .. 0 - " << listCount << endl;
	    		cin >> choiceA;
	    
	    		cout << "Select Actor's Armor .. 0 - " << 4 << endl;
	    		listCount = 1;
	    	for (int h = 0; h < maxP; h++)
	    		{
	    			cout << listCount << party[h].getArmorEQ().name << endl;
	    			++listCount;
	    		}
	    	cin >> choiceB;
	    
	    	//convert Type
	    	aConvert(party[choiceB].getArmorEQ(), armorlist[choiceA]);
	    
	    	party->setArmor(choiceB, aConvert(party[choiceB].getArmorEQ(), armorlist[choiceA]));
	    
	    	if (!(isalpha(choiceA)))
	    	{
	    		cout << "try again.." << endl;
	    		cin >> choiceA;
	    	}
	    
	    	choice = NULL;
	    	cin >> choice;
	    
	    	cout << "Make another selection?" << endl;
	    	PlayerItemInventory(party);
		break;
#pragma endregion

#pragma region weapons

	case 'w':
		listCount = 1;
		hd = 0;
		choice = NULL;
		choiceInt;
		choiceA = 0;
		a = 0;
		choiceB = 0;

		for (size_t i = 0; i < listCount; i++)
		{
			cout << my_weapons[i].name << endl;
			if (!(my_weapons[i].name.empty()))
			{
				listCount += 1;
			}
			else
			{
				listCount += 0;
			}
		}

		cout << "Select an Actor to select an weapon.. 0 - " << maxP << endl;
		for (int h = 0; h < maxP; h++)
		{
			cout << listCount << party[h].getName() << endl;
			++listCount;
		}
		cin >> hd;

		for (a = 0; a < listCount; a++)
		{
			cout << a + 1 << my_weapons[a].name << endl;
		}


		cout << "Select a weapon .. 0 - " << listCount << endl;
		cin >> choiceA;
		//displaylistWeapon();
		cout << "select an weapon? using a #" << endl;

		cout << "Select Actor's Weapon .. 0 - " << 4 << endl;
		listCount = 1;
		for (int h = 0; h < maxP; h++)
		{
			cout << listCount << party[h].getWeaponEQ().name << endl;
			++listCount;
		}
		cin >> choiceB;

		//convert Type
		wConvert(party[choiceB].getWeaponEQ(), weaponlist[choiceA]);

		party->setWeapon(choiceB, wConvert(party[choiceB].getWeaponEQ(), weaponlist[choiceA]));

		if (!(isalpha(choiceA)))
		{
			cout << "try again.." << endl;
			cin >> choiceA;
		}

		choice = NULL;
		cin >> choice;

		cout << "Make another selection?" << endl;
		PlayerItemInventory(party);
		break;
#pragma endregion

#pragma region equipment

	case 'e':
		listCount2 = 1;
		
		cout << "(" << listCount2 << ") " << my_weapons[i].name << endl;
		for (int i = 0; i < listCount2; i++)
		{
			cout << my_weapons[i].name << endl;
			if (!(my_weapons[i].name.empty()))
			{
				listCount2 += 1;
			}
			else
			{
				listCount2 += 0;
			}
			cout << my_armors[i].name << endl;
			if (!(my_armors[i].name.empty()))
			{
				listCount += 1;
			}
			else
			{
				listCount += 0;
			}
		}

		cout << " All equipped: select one for overview.. 0 - " + listCount2 << endl;
		//displaylistEQWgear();
		cout << endl;
		//displaylistEQAgear();
		cout << endl;
		cout << "select equipment? using a number.." << endl;
		//int i = 0;
		choice = {};
		cin >> i;

		//selectlistWeapon(i);
		//equip armor
		if (isalpha(i))
		{
			cout << "invalid option" << endl;
			PlayerItemInventory(party);
			break;
		}
		cout << "Make another selection?" << endl;
		PlayerItemInventory(party);
		break;
#pragma endregion

			case 'q':
				// exit
				break;
			
			default:
				cout << "try again biatch" << endl;
				cin >> choice;
				break;
				} while (thaCurry);
			}
}

void inventory::rewardCall(int index, int howMany)
{
	cout << itemlist[index].name << endl;
	addItem(itemlist[index].quantity, howMany);
	//return allitemList(index);
}

void inventory::addItem(int find, int howMany) {
	int i = 1;
	int length;
	item b;
	b.quantity = howMany;

	for (size_t g = 0; g < MAX_INTEGRITY; g++)
	{
		b = itemlist[find];
		if (my_items[g].name.empty())
		{
			my_items[g].agiAdd = b.agiAdd;
			my_items[g].name = b.name;
			my_items[g].apAdd = b.apAdd;
			my_items[g].atkAdd = b.atkAdd;
			my_items[g].conAdd = b.conAdd;
			my_items[g].defAdd = b.defAdd;
			my_items[g].dexAdd = b.dexAdd;
			my_items[g].endAdd = b.endAdd;
			my_items[g].fpAdd = b.fpAdd;
			my_items[g].goldValue = b.goldValue;
			my_items[g].hpAdd = b.hpAdd;
			my_items[g].intAdd = b.intAdd;
			my_items[g].ivalue = b.ivalue;
			my_items[g].node = b.node;
			my_items[g].quantity = b.quantity;
			my_items[g].spAdd = b.spAdd;
			my_items[g].spdAdd = b.spdAdd;
			my_items[g].sprAdd = b.sprAdd;
			my_items[g].strAdd = b.strAdd;
		}
	}

	if (b.ivalue != my_items[find].ivalue)
	{
		insertNodeItem(allitemList(find), i);
	}
	appendNodeItem(allitemList(find), i); // calls the index and adds 1
	
} //adding to the struct array

void inventory::remItem(int find) {
	int i = 1;
	my_items[find].quantity -= i; // calls the index and adds 1
	deleteNodeItem(my_items[find], i);
} //removing to the struct array

inventory::~inventory()
{
	armor* nodeAPtr;
	armor* nextANode;
	item* nodeIPtr;
	item* nextINode;
	weapon* nodeWPtr;
	weapon* nextWNode;

	nodeAPtr = heada;
	nodeIPtr = headi;
	nodeWPtr = headw;

	while (nodeAPtr != nullptr)
	{
		nextANode = nodeAPtr->next;
		delete nodeAPtr;
		nodeAPtr = nextANode;
	}

	while (nodeIPtr != nullptr)
	{
		nextINode = nodeIPtr->node;
		delete nodeIPtr;
		nodeIPtr = nextINode;
	}

	while (nodeWPtr != nullptr)
	{
		nextWNode = nodeWPtr->next;
		delete nodeWPtr;
		nodeWPtr = nextWNode;
	}

	//delete [] stackArray;
}

