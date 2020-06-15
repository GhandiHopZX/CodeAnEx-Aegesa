#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include "FileSave.h"

const int keyMax = 23;

FileSave::FileSave()
{
	
	SKILLSET keysd[keyMax] = {};
	
	PARTY_MEMBER_DATA pmd[3];
	FILEDATA fd;

	keysd->names[keyMax] = {};
	keysd->keys[keyMax] = {};

	pmd->BIO = "";
	pmd->jobState.className = "";
	pmd->jobState.expMAX = 0;
	pmd->jobState.expTier1MAX = 0;
	pmd->jobState.expTier2MAX = 0;
	pmd->jobState.expTier3MAX = 0;
	pmd->jobState.expTier4MAX = 0;
	pmd->jobState.expTier5MAX = 0;
	pmd->jobState.expTier6MAX = 0;
	pmd->jobState.expTier7MAX = 0;
	pmd->PLAYER_NAME = "";
	pmd->SKILLS.keys[keyMax] = {};
	pmd->STATS[14] = {};
	
	fd.BIO = "";
	fd.CLASS_PROGRESSION_STATE = "";
	fd.COMPLETED_SEG = 0;
	fd.CURRENT_PARTY = 0;
	fd.GOLD = 0;
	fd.LOCATION_XYZ[2] = {0};
	fd.LOCATION_XYZ[1] = { 0 };
	fd.LOCATION_XYZ[0] = { 0 };
	fd.PLAYER_NAME = "";
	fd.PLAY_TIME = 0;
	fd.SKILLS.keys[keyMax] = { 0 };
	fd.STATS[13] = {0};
	fd.STORY_SEG = 0;
}


FileSave::~FileSave()
{
}
