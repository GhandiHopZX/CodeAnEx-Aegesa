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

	string savePath;
	string saveName;
	string loadedDir;
	int numberOfFiles = 0;
	string loadedDirs[1] = {};

public:

	// vars
	struct CLASS_PROGRESSION_STATE
	{
		string className;
		int expTier1MAX;
		int expTier2MAX;
		int expTier3MAX;
		int expTier4MAX;
		int expTier5MAX;
		int expTier6MAX;
		int expTier7MAX;
		int expMAX;
	};

	struct SKILLSET
	{
		int keys[24];
	};

	struct PARTY_MEMBER_DATA
	{
		string PLAYER_NAME;
		string BIO;
		SKILLSET SKILLS;
		int STATS[14]; //15 TOTAL
		CLASS_PROGRESSION_STATE jobState;
	};

	struct FILEDATA
	{
		string PLAYER_NAME;
		string BIO;
		int STATS[14]; // 15 TOTAL
		int GOLD;
		string CLASS_PROGRESSION_STATE;
		SKILLSET SKILLS;
		long PLAY_TIME;
		int CURRENT_PARTY; //NUMBER AND NAMES 
		int STORY_SEG; // INT WILL BE CALLED INTO A METHOD
		int COMPLETED_SEG;
		int LOCATION_XYZ[3];
	};

	PARTY_MEMBER_DATA PMD01[3]; // Find a way to hashify this number
	int INVENTORY_KEYS[50]{}; // this one too

	struct FileLoad
	{
		SKILLSET l1;
		PARTY_MEMBER_DATA l2[3];
		FILEDATA l3;
		int INVENTORY_KEYS_l4[49];
	};

	FileLoad nuwData; // one for fstream

	//functions

	FileSave();

	void saveFile(vector<FileSave::SKILLSET>& SkillSet, vector<FileSave::PARTY_MEMBER_DATA> PMD[], vector<FileSave::FILEDATA>& FileData)
	{
		fstream JavaFile((savePath + '/' + saveName + ".dat").c_str(), ios::out, ios_base::trunc);

		// = &SkillSet;
	};

	void setSavePath(string m)
	{
		savePath = m;
	};

	void setFileName(string m)
	{
		saveName = m;
	};

	FileLoad loadFile()
	{
		//int choice = 0;
		//cout << "FILE Select.. (1) for pasting directory or (2) for QuickLoad" << endl;
		//cin >> choice;

		//switch (choice)
		//{
		//case 1:
		//	getline(cin, loadedDir);
		//	break;
		//case 2:

		//	// scan through for files for the numberOfFiles
		//	// find the .dat ones
		//	/*for each (FILE var in derp)
		//	{

		//	}*/
		//	// put them in this array "numberOfFiles"
		//	for (int i = 0; i < numberOfFiles; i++)
		//	{
		//		loadedDirs[numberOfFiles] += loadedDir;
		//	}
		//	cout << endl;
		//	// load selections
		//	for (int i = 0; i < numberOfFiles; i++)
		//	{
		//		cout << endl;
		//		cout << i + 1 << loadedDirs[numberOfFiles] << endl;
		//	}

		//	int selectFileNumb = 0;
		//	cin >> selectFileNumb;
		//	try
		//	{
		//		switch (selectFileNumb)
		//		{

		//		case 0: // check for number
		//			// if selectFileNumb is a number 
		//			int j = selectFileNumb;
		//			int i = 0;
		//			do
		//			{
		//				loadedDirs[i];
		//			} while (i != selectFileNumb);

		//			if (selectFileNumb <= 0)
		//			{
		//				cout << "No File Found..." << endl;
		//			}
		//			break;

		//		default:
		//			cout << "Invalid Choice.." << endl;
		//			loadFile();
		//			break;
		//		}
		//	}
		//	catch (const std::invalid_argument& dis) // find something for the alphabet
		//	{
		//		cout << "Sorry try again..." << endl;
		//		loadFile();
		//	}
		//	break;
		//	
		//default:
		//
		//	break;
		//}
		//// fstream stuff here...
		//fstream JavaFile((loadedDir + '/' + saveName + ".dat").c_str(), ios::in, ios_base::trunc);

		//// end here
		//return nuwData;
	};

	string getSavePath()
	{
		return savePath;
	};

	string getSaveName()
	{
		return saveName;
	};

	~FileSave();

};
