#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <chrono>
#include "aegesa.h"
#include "Player_Actor.h"
#include "Enemy.h"

class World // this is the mainline story for Code AnEx AEGESA
{
	// this game has up to 5 chapters...
	// I know shocking!!!
	// but its a prequel to a story I haven't fully written yet.
	// sorry for the bad storytelling if that's your thing....

private:
	// Hub worlds that have cellular navigation 
	// for now we only have ch 0 - 5 to cover the lost city arc
	// and that's it for now. 
	// this is the lost city player pos and map
	struct map
	{
		int x = 0;
		int y = 0;
		int z = 0;
		string name;
	};

	int mao = 0;
	int tse = 0;
	int tung = 0;
	long play_time = 0;
	int location = 0; // 0 lostCity, 1 darkForest, 2 ekana, 3 rheTan, 4 aegesaShrine...
	const int MIN = 1;
	const static int partySize = 6;
	const static int ePartySize = 4;

	map lostCity[11][11][4];
	map darkForest[11][11][2];
	map eikka[11][11][1];
	map rheTan[11][11][1];
	map aegesaShrine[11][11][5];

public:

	map maps[5] =
	{
		lostCity[5][0][0],
		darkForest[5][0][0],
		eikka[5][0][0],
		rheTan[5][0][0],
		aegesaShrine[5][0][0]
	};

	World();

	// setters/mutators

	void beginningStory(); //Awaken Marko(or Player one)
	void chapter1(); //RE-BIRTH
	void chapter2(); //Shattered and Hollow
	void chapter3(); //Green Gold
	void chapter4(); //Renae's Secret/Lost Civilization
	void chapter5(); //Alicia's Verdict

	void endGame(); // game end

	// menu stuff
	void menu();

	// menu calls
	void inventory();

	void navigation();

	void partyMenu();

	void dataCall();

	void optionMenuCall();

	//Main game loop: 1. main menu, 2. when move, 3. randomizer or => 4. if theres a story ev that engages. 5. back to top
	void gameLoop(int mx, int my, int mz, map m, int location, Player_Actor party[]);

	void evRandomizer(Player_Actor party[], map location, int mx, int my, int mz); // location is for mob levels

	void partyMenu(Player_Actor party[]);

	void eventCalls(World::map local, bool trigger, string dialougeOut);

	void dialouge(Player_Actor pn, string in);

	void dialougeAction(Player_Actor pn, string in);

	string dialougeInput(string pvalue);

	void navigation(int selectedMap, int m, int c, int e);

	void whereAmI(int selectedMap, int x, int y, int z);

	char choiceIn(string);

	string lineStop();

	void StopTime();

	long StartTime();

	// getters/accessors

	// other functions
	Player_Actor playerParty[partySize]; // menus

	aegesa battlersP[partySize]; // for the player_Actors
	aegesa battlersE[ePartySize]; // for the enemy

	~World();
};
