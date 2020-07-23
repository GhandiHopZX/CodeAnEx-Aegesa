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
	string saveName = "SaveData.dat";
	string loadedDir;
	int numberOfFiles = 0;
	string loadedDirs[1] = {};

public:

	// vars
	struct CLASS_PROGRESSION_STATE
	{
		string className;
		unsigned int expTier1MAX;
		unsigned int expTier2MAX;
		unsigned int expTier3MAX;
		unsigned int expTier4MAX;
		unsigned int expTier5MAX;
		unsigned int expTier6MAX;
		unsigned int expTier7MAX;
		unsigned int expMAX;
	};

	struct SKILLSET
	{
		string names[24] = { 0 };
		int keys[24] = {0};
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

	struct FileLoad
	{
		SKILLSET l1;
		PARTY_MEMBER_DATA l2[3];
		FILEDATA l3;
		int INVENTORY_KEYS_l4[49];
	};

	FileLoad nuwData; // one for fstream
	FileLoad currentFileLoaded;

	PARTY_MEMBER_DATA PMD01[3]; // Find a way to hashify this number
	int INVENTORY_KEYS[50]{}; // this one too
	SKILLSET SkillSet;
	FILEDATA FileData;
	//functions

	FileSave();

	string getSavePath()
	{
		return savePath;
	}

	void setSaveData(SKILLSET SkillSetIn, PARTY_MEMBER_DATA PMD[], FILEDATA FileDataIn, int inVKeys[])
	{
		for (int i = 0; i < 24; i++)
		{
			currentFileLoaded.l1.keys[i] = SkillSetIn.keys[i];
		}
		for (int i = 0; i < 3; i++)
		{
			currentFileLoaded.l2[i] = PMD[i];
		}
		currentFileLoaded.l3 = FileDataIn;
		for (int i = 0; i < 49; i++)
		{
			currentFileLoaded.INVENTORY_KEYS_l4[i] = inVKeys[i];
		}
		saveFile();
	}

	string path = getSavePath() + '/' + saveName + ".dat";

	fstream SaveFile;

	void saveFile()
	{
		// = &SkillSet;
		// check to see if file is saving
		if (SaveFile.fail())
		{
			cout << "Error Recording the File.\n";
		}
		else
		{
			SaveFile.seekg(0L, ios::beg);    // to set position to read the file
			SaveFile.write(reinterpret_cast<char*>(&currentFileLoaded), sizeof(currentFileLoaded));
			cout << "Record Successed\n";
		}
		// close the file
		SaveFile.close();
	};

	void loadFile()
	{
		FileLoad c;
		int i = 0;
		SaveFile.open(getSavePath(), ios::in | ios::out | ios::binary);
		SaveFile.seekg(0L, ios::beg);    // to set position to read the file
		while (SaveFile.peek() != EOF)
		{

			SaveFile.read(reinterpret_cast<char*>(&c), sizeof(c));
			setSaveData(c.l1, c.l2, c.l3, c.INVENTORY_KEYS_l4);
			/*cout << "Name: " << c.INVENTORY_KEYS_l4 << endl;
			cout << "Address: " << c.l1 << endl;
			cout << "City:  " << c.l2 << endl;
			 << "State: " << c.l3 << endl;*/
			i++;
		}
		cout << "recording successful" << endl;
		SaveFile.close();
	}

	void setSavePath(string m)
	{
		savePath = m;
	};

	void setFileName(string m)
	{
		saveName = m;
	};

	void loadFileOp()
	{
		int selectFileNumb = 0;
		int choice = 0;
		cout << "FILE Select.. (1) for pasting directory or (2) for QuickLoad" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			getline(cin, loadedDir);
			break;
		case 2:

			// scan through for files for the numberOfFiles in a directory
			// find the .dat ones
			/*for each (FILE var in derp)
			{

			}*/
			// put them in this array "numberOfFiles"
			for (int i = 0; i < numberOfFiles; i++)
			{
				loadedDirs[numberOfFiles] += loadedDir;
			}
			cout << endl;
			// load selections
			for (int i = 0; i < numberOfFiles; i++)
			{
				cout << endl;
				cout << i++ << loadedDirs[numberOfFiles] << endl;
			}

			
			cin >> selectFileNumb;
			try
			{

				
				if (selectFileNumb <= 0)
				{
					cout << "No File Found..." << endl;
				}

				cout << "Invalid Choice.." << endl;
				loadFile();
			}
			catch (const std::invalid_argument&) // find something for the alphabet
			{
				cout << "Sorry try again..." << endl;
				loadFile();
			}
			break;
			
		default:
		
			break;
		}
		// fstream stuff here...
		//fstream JavaFile((loadedDir + '/' + saveName + ".dat").c_str(), ios::in, ios_base::trunc);

		// end here
	};


	string getSaveName()
	{
		return saveName;
	};

	~FileSave();

};
