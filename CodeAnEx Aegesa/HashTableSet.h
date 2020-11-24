#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>
#include "skillAction.h"

using namespace std;

class HashTableSet // with this you can make multiple hashes with calculations that will be handy through out this project
{
private:
	static const int hashGroups = 400;
	static const int skillGroups = 200;
	static const int statusGroups = 20;

	int skill_Sum;
	int shash_Value;
	bool skey_exists;

	list<pair<int, skillAction>> skillTable[skillGroups];
	list<pair<int, string>> nametable[hashGroups];

public:
	HashTableSet();
	HashTableSet(int, skillAction);
	~HashTableSet();

	int operator++(int k);

	// names
	//bool isEmpty() const;
	//int hash(int key);
	//void insertItem(int key, string value);
	//void removeItem(int key);
	//string searchTable(int key);
	//void printTable();

	// skill and stat
	bool sisEmpty() const;
	int skillHash(int);
	void insertSkill(int key, skillAction m);
	void removeSkItem(int);
	string searchSkTable(int);
	void printSkTable();
	int getSkillSum();
	void setSkillSum(int);


	// for hashes
	skillAction skillCall(int sk); //operator for this
};