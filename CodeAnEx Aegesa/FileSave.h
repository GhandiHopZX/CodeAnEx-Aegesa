#pragma once
// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "FileSave.h"

using namespace std;

class FileSave // this is the fileSystem for the game for saving and loading
{
protected:

private:

public:
	
	struct PARTY_MEMBER_DATA
	{
		string PLAYER_NAME;
		string BIO;
		int STATS[15];
		string CLASS_PROGRESSION_STATE;
	};
	struct FILEDATA
	{
		string PLAYER_NAME;
		string BIO;
		//int STATS[15];
		int GOLD;
		//int INVENTORY_KEYS[50];
		string CLASS_PROGRESSION_STATE;
		long PLAY_TIME;
		int CURRENT_PARTY; //NUMBER AND NAMES 
		//PARTY_MEMBER_DATA PMD01[];
	};


	// vars

	FileSave();


	~FileSave();

};
