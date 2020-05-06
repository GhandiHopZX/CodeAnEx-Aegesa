#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>
#include <algorithm>
#include <fstream>
#include "World.h"
// battle system stuff
#include "Enemy.h"
#include "aegesa.h"
#include "Player_Actor.h"
#include "inventory.h"
#include "battleSystem.h"

using namespace std;

// full party GLOBALS
Player_Actor Actor1; // Proper instantiation
Player_Actor Alicia; // 
Player_Actor Renae; // 
Player_Actor Iyn; // 
inventory mainInventory; //

//HashTableSet anyHash; // magic hash of many things 

World::World()
{

	mao = 0; // int posx = 0;
	tse = 0; // int posy = 0;
	tung = 0; // int posz = 0;

	//set time

	StartTime();
	// file load for play_time goes here
	// "                     "
	play_time += StartTime(); //every time the world is loaded =) also playtime contains the file_data

	map maps[5] =
	{
		lostCity[5][0][0],
		darkForest[5][0][0],
		eikka[5][0][0],
		rheTan[5][0][0],
		aegesaShrine[5][0][0]
	};
}

void World::beginningStory()
{
	//system("COLOR e4"); // shop color
	system("COLOR 09");
	system("CLS");

	string nameIn = "k";
	string bioIn = "";

	// What's Your Name?

	cout << "What's Your Name?: " << endl;
	cin >> nameIn;
	Actor1.setName(nameIn);
	cout << endl;

	// What's Your Story?
	cout << "What's Your Story?: " << endl;
	Actor1.setBio(bioIn);
	cin >> bioIn;

	cout << endl;

#pragma region Alicia_SetStats
	Alicia.setName("Alicia");
	Alicia.setBio("Lost class 3 Android unit. Locked Away for 10 years, now follows you in your journey for the AType upgrade to save her friend..");
	Alicia.setATK(6);
	Alicia.setSPD(8);
	Alicia.setDEF(4);
	Alicia.setSTR(10);
	Alicia.setDEX(12);
	Alicia.setCON(7);
	Alicia.setEND(5);
	Alicia.setINT(6);

	Alicia.setHp(15);
	Alicia.setSp(155);
	Alicia.setFp(5);
	Alicia.setAp(5);
	Alicia.setDp(0); // always set these defaulted to 0
#pragma endregion

#pragma region opening setting
	// location name set
	maps->name = "Lost City";

	system("COLOR 07");
	dialougeAction(Actor1, "Wakes up");
	cout << Actor1.getName() + ": " + "Huhhh..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "damn..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Where am I" << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "how.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "How did I survive?" << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Shit... I hope he doesn't find me. Wherever here is.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Huh... Hmmmn.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "This opening above me.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "It feels.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "good..." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "Weird.." << endl;
	cin.get();
	cout << Actor1.getName() + ": " + "WAIT!" << endl;
	cin.get();
	dialouge(Actor1, "I wana see if I can find that light I just saw...");
	dialouge(Actor1, "I wana see if if its even real.");
	dialougeAction(Actor1, "Looks up");
	dialouge(Actor1, "No way....");
	dialougeAction(Actor1, "Jolts from the cold now heated air...");
	dialougeAction(Actor1, "Sees the now visible white clad figure.");
	dialougeAction(Alicia, "Figure steps in from the darkness..");
	dialouge(Alicia, "Aegesa... Type.");
	dialouge(Actor1, "W... what..? What are you talking about?");
	dialouge(Alicia, "Aegesa Type.. ARE YOU COGNIZANT OF YOUR ENVIRONMENT?");
	dialouge(Actor1, "cogni.. of what?.. What are you talking about?");
	dialouge(Alicia, "You are aware of your surroundings are you not?");
	dialouge(Actor1, "No I'm stupid... Sorry. Not very cognizant of anything at the moment...");
	dialouge(Alicia, "Your genetic template says your a savant compared to the average...");
	dialouge(Actor1, "So you're another one of those hackers AREN'T YOU!?");
	dialouge(Alicia, "I am not sure of what argument this pertains to..");
	dialouge(Actor1, "You talk like a robot... Are you that then?");
	dialougeAction(Alicia, "FLASH");
	dialougeAction(Alicia, "POSE");
	dialouge(Alicia, "I am a CLASS III GUARDIAN TIER ANDROID!");
	dialouge(Alicia, "I have searched for a compatable Aegesa type. Suitable for both combat and architectural assembly..");
	dialouge(Actor1, "Whoa that means you're.. No kidding you're the real deal!");
	dialouge(Alicia, "What are you referencing?");
	dialouge(Actor1, "Ok You're from the machine itself huh?");
	dialouge(Alicia, "I'm from the Crown City...");
	dialouge(Actor1, "......");
	dialouge(Alicia, "I know it may seem hard to believe but I am not what you may hypothesize...");
	dialouge(Actor1, "I don't even know what you're talking about..");
	dialouge(Alicia, "....");
	dialouge(Actor1, "If you came from some make believe world that hasn't existed before on the world maps then tell me where it is!");
	dialouge(Alicia, "Alright then..");
	dialouge(Alicia, "I'll show you where it is. If you help me find my friend..");
	dialouge(Actor1, "I'm not too sure I should even really trust you to go with you to any place...");
	
	// party insert

	//playerParty[partySize] = this also needs to be a list
	//{ with lots of functions
	//Actor1,
	//Alicia
	//};
	//

	system("CLS");
	cout << "-----======= ALICIA HAS JOINED YOUR PARTY ======-----" << endl;
	lineStop();
#pragma endregion

	//end of chapter 0

	chapter1();
}

void World::chapter1()
{
	int i = 0;
	// menu time
	menu();

	//end of chapter
	chapter2();
}

void World::chapter2()
{

	//end of chapter
	chapter3();
}

void World::chapter3()
{

	//end of chapter
	chapter4();
}

void World::chapter4()
{

	//end of chapter
	chapter5();
}

void World::chapter5()
{

	//end of chapter
	endGame();
}

void World::endGame()
{
	// end of game? =)
	lineStop();
	cout << "Will you dream again?" << endl;
}

//Enemy Encounter call ins
// call the battle system stuff

// celluar world navigation.
// with a map ;)

void World::menu()
{
	char choice = {};
	cout << "Please select an option....\n (i) Inventory,\n (n) Navigation,\n (p) Party,\n (d) Save/Load,\n (o) Options";
	cin >> choice;
	switch (choice)
	{
	case 'i':
	case 'item':
		//mainInventory.PlayerItemInventory(); // do this within a method
		//Actor1;
		break;

	case 'n':
	case 'navi':
		navigation(location, mao, tse, tung);
		break;

	case 'p':
	case 'part':
		partyMenu(playerParty);
		break;

	case 'd':
	case 'data':
		dataCall();
		break;

	case 'o':
	case 'opti':
		optionMenuCall();
		break;

	default:
		cout << "Invalid Choice" << endl;
		menu();
		break;
	}
}

void World::inventory()
{
}

void World::navigation()
{
}

void World::partyMenu()
{
}

void World::gameLoop(int mx, int my, int mz, map m, int location, Player_Actor party[])
{
	if (mEVTriggerActive() == true)
	{
		if (m.name == "Lost City")
		{
			evRandomizer(party, m, mx, my, mz);
		}

		if (m.name == "Dark Forest")
		{

		}

		if (m.name == "Eikka")
		{

		}

		if (m.name == "RheTan")
		{

		}

		if (m.name == "Aegesa Shrine")
		{

		}
	}
	
}

// work on this
void World::evRandomizer(Player_Actor party[], map location, int mx, int my, int mz)
{
	const int MAX_EVRAND = 450;
	unsigned int evRand = (rand() % (MAX_EVRAND - MIN + 1)) + MIN;

	//battle processing and dot giving
	for (int i = 0; i < partySize; i++)
	{
		if ((party[i].My_Statuses[i].at(i) = 'D') && party[i].isPlayer == true)
		{
			// game over
		}
		else if (!(party[i].My_Statuses[i].at(i) = 'D') && party[i].isPlayer == true) // check for in_party npcs and dead ppl
		{
			eventCalls(location, mEVTriggerActive(), evRand);
		}
		else
		{
			eventCalls(location, mEVTriggerActive(), evRand);
		}
		//party[i]; 
	}

	party->isPlayer;
}

void World::partyMenu(Player_Actor party[])
{
	char choice2 = ' ';
	string scin = "";

	system("CLS");
	cout << "Current Party" << endl;
	cout << "" << endl;

	int party_ppl = party->getParty_num();

	// print menu
	for (int i = 0; i < party_ppl; i++)
	{
		//int v = party[i].getStatus().turns_Of_aff;

		cout << party[i].getName() << ": " << '\n' << "HP" << ": " << '\t' << party[i].getHpd() << '/' << party[i].getHp();
		cout << '\n' << "SP" << ": " << '\t' << party[i].getSPDd() << '/' << party[i].getSp() << endl;

		//cout << "[state(s)]" << endl;
		for (int k = 0; k < party[i].num_Statuses; k++)
		{
			//party[i].getStatus().buffName;
			cout << "["  << party[i].printStates()  << " " << "]" << "Turns Left: " << /*v<<*/ endl;
		}
		cout << endl;
	}

	choice2 = choiceIn(scin);

	cout << "Please select an option....\n (s) Status,\n (e) Equip,\n (sa) SkillActions,\n (t) ClassTree \n";
	switch (choice2)
	{
	case 's':
		// select party member
		// status for member
		menu();
		break;

	case 'e':
		// select party member
		// equip items

		//mainInventory.PlayerItemInventory(Actor1);
		menu();
		break;

	case 'sa':
		// select party member
		// skill set
		menu();
		break;

	case 'c':
		// select party member
		// class tree
		menu();
		break;

	default:
		cout << "Invalid choice..." << endl;
		menu();
		break;
	}
}

void World::dataCall() {}

void World::optionMenuCall() {}

void World::eventCalls(World::map local, bool trigger, int evNCall)
{
	// names and any other data goes here
	if (local.name == "Lost City")
	{
		eventTypeNamesLV1[evNCall];
	}

	if (local.name == "Dark Forest")
	{

	}

	if (local.name == "Eikka")
	{

	}

	if (local.name == "RheTan")
	{

	}

	if (local.name == "Aegesa Shrine")
	{

	}
}

void World::dialouge(Player_Actor pn, string in)
{
	cout << pn.getName() + ": " + in << endl;
	lineStop();
}

void World::dialougeAction(Player_Actor pn, string in)
{
	cout << pn.getName() + ": " + "*" + " " + in + "*" << endl;
	lineStop();
}

string World::dialougeInput(string pvalue)
{
	getline(cin, pvalue);
	pvalue.erase(remove(pvalue.begin(), pvalue.end(), '\n'), pvalue.end());
	return pvalue;
}

void World::navigation(int selectedMap, int x, int y, int z)
{
	// maps

	// n = north, ne = northeast, nw = northwest, 
	// sw = southwest, s = south, se = southeast
	// w = west, e = east
	// z = floor
	// these are for changing the coodinates to each floor 
	int xC = 0;
	int yC = 0;
	int zC = 0;

	whereAmI(selectedMap, x, y, z);

	cout << "\nWhere will you go?\n (n)north,\n"
		<< "(e)east,\n (w)west,\n (s)south,\n (ne)northeast,\n"
		<< "(nw)northwest,\n (se)southeast,\n (sw)southwest\n " << endl;

	char dir = {};
	cin >> dir;
	switch (dir)
	{
	case 'n':
		maps[selectedMap].y += 1;
		tse = maps[selectedMap].y;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'ne':
		maps[selectedMap].y += 1;
		tse = maps[selectedMap].y;
		maps[selectedMap].x -= 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'nw':
		maps[selectedMap].y += 1;
		maps[selectedMap].x += 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 's':
		maps[selectedMap].y -= 1;
		tse = maps[selectedMap].y;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'se':
		maps[selectedMap].y -= 1;
		maps[selectedMap].x -= 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'sw':
		maps[selectedMap].y -= 1;
		maps[selectedMap].x += 1;
		tse = maps[selectedMap].y;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'w':
		maps[selectedMap].x += 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	case 'e':
		maps[selectedMap].x -= 1;
		mao = maps[selectedMap].x;
		// event randomizer
		//mEVTriggerSetter(true);
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	default:
		cout << "not a direction or command" << endl;
		whereAmI(selectedMap, x, y, z);
		menu();
		break;
	}

	switch (z)
	{
	case (1):
		z++;
		break;

	case (-1):
		z--;
		break;
	default:
		maps[selectedMap].z = z;
		tung = maps[selectedMap].z;
		break;
	}
}

void World::whereAmI(int selectedMap, int x, int y, int z)
{
	cout << "\nCurrent Location:" << endl;
	cout << "AT: " << maps[selectedMap].name << endl;
	cout << "row: " << maps[selectedMap].x << endl;
	cout << "column: " << maps[selectedMap].y << endl;
	cout << "floor: " << maps[selectedMap].z << endl;
}

char World::choiceIn(string choiceBuffer)
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

// this thing eats the string that comes after every 
// 'ENTER' press so the system doesn't poop out too much at once...
// don't use this for anything but text dialouge unless you know what you're doing.
string World::lineStop()
{
	string pvalue;
	getline(cin, pvalue);
	pvalue.erase();
	return pvalue;
}

void World::StopTime()
{
	std::this_thread::yield();
}

long World::StartTime()
{
	long copy = 0;
	auto playtime = std::chrono::high_resolution_clock::now; // you might need to convert this into a long or some kind of type that can be saved and stored for later use
	//copy = static_cast<long>(playtime);
	return copy;
}

void World::mEVTriggerSetter(bool mEVT)
{
	movedEVTrigger = mEVT;
}

bool World::mEVTriggerActive()
{
	return movedEVTrigger;
}

World::~World()
{
	StopTime();
}
