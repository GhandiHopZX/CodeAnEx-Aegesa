#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <exception>
#include <optional>
#include "aegesa.h"
#include "skillAction.h"
#include "HashTableSet.h"

using namespace std;

// make more constructors?

HashTableSet::HashTableSet() // you cant include this class anywhere else bc of its identity 
{
	skill_Sum = {};
	shash_Value = {};
	skey_exists = {};
}

HashTableSet::HashTableSet(int key, skillAction meeep)
{
	skill_Sum = {};
	shash_Value = {};
	skey_exists = {};
}

//HashTableSet SkillList;

#pragma region skillList
bool HashTableSet::sisEmpty() const
{
	int addAll{};
	for (int i{}; i < skillGroups; i++)
	{
		addAll += (skillTable[i].size());
	}

	if (!addAll)
	{
		return true;
	}
	return false;
}

int HashTableSet::skillHash(int key)
{
	return key % skillGroups;
}

void HashTableSet::insertSkill(int key, skillAction m)
{
	shash_Value = skillHash(key);
	auto& cell = skillTable[shash_Value];
	auto bItr = begin(cell);
	skey_exists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			skey_exists = true;
			bItr->second = shash_Value;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}

	if (!skey_exists)
	{
		cell.emplace_back(key, shash_Value);
	}
	return;
}

void HashTableSet::removeSkItem(int key)
{
	shash_Value = skillHash(key);
	auto& cell = skillTable[shash_Value];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Skill removed." << endl;
			break;
		}
	}

	if (!keyExists)
	{
		cout << "[WARNING] Skill not found. PAIR NOT REMOVED." << endl;
	}
	return;
}

string HashTableSet::searchSkTable(int key)
{
	int findKey{};
	shash_Value = skillHash(key);
	auto& cell = skillTable[shash_Value];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (int i{}; i < skillGroups; i++)
	{
		findKey = skillTable[i].size();

		if (skillTable[i].size() == findKey)
		{
			return "Skill" + bItr->second.name + " found.";
		}
		else if (skillTable[i].size() != key)
		{
			return "Not found in Skill Groups.";
		}
	}

	return "NULL - If this is the only message you see then this function is busted...";
}

void HashTableSet::printSkTable()
{
	for (int i{}; i < skillGroups; i++)
	{
		if (skillTable[i].size() == 0) continue;

		auto bItr = skillTable[i].begin();
		for (; bItr != skillTable[i].end(); bItr++)
		{
			cout << "[INFO] Key: " << bItr->first << " Skill_Name: " << bItr->second.name << endl;
		}
	}
	return;
}

int HashTableSet::getSkillSum()
{
	return skill_Sum;
}

void HashTableSet::setSkillSum(int m)
{
	skill_Sum = m;
}

skillAction HashTableSet::skillCall(int sk)
{
	int findKey{};
	shash_Value = skillHash(sk);
	auto& cell = skillTable[shash_Value];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (int i{}; i < skillGroups; i++) // hope this works
	{

		if (skillTable[i].size() == findKey)
		{
			return bItr->second;
		}
		else if(skillTable[i].empty())
		{
			cout << "Skill no. " << sk + " Not found or availiable moving to next skill..." << endl;
			++shash_Value;
			return bItr->second;
		}
	}	return skillAction();
}
#pragma endregion


HashTableSet::~HashTableSet()
{

}

// operator++
int HashTableSet::operator++(int k)
{
	int *m = &k;
	++m;
	int& oldVal = *m;
	return oldVal;
}