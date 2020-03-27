#include <list>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "skillAction.h"
#include "inventory.h"
#include <ObjIdl.h>

using namespace std;

class HashTableSet // with this you can make multiple hashes with calculations that will be handy through out this project
{
private:
	static const int hashGroups = 400;
	static const int skillGroups = 200;

	int skill_Sum;
	int shash_Value;
	bool skey_exists;

	static const int hashTe = 300;
	int templateHSum;
	int tHash_Value;
	int tKey_Exists;
	int tLastCall;

	list<pair<int, skillAction>> skillTable[skillGroups];
	list<pair<int, string>> nametable[hashGroups];

public:
	HashTableSet();

	~HashTableSet();

	int operator++(int k);

	// names
	bool isEmpty() const;
	int hash(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
	
	// skill
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

	template <class Hash>
	Hash fullTemp(int choice, int key, Hash objType);

	template<typename Hash>
	Hash isEmpty();

	template<typename Hash>
	Hash hashT(int keyT);

	template<typename Hash>
	Hash insertT(int, Hash);

	template<typename Hash>
	Hash remove(int key);

	template<typename Hash>
	Hash search(int key);

	template<typename Hash>
	Hash printTableT();

	template<typename Hash>
	Hash get();

	template<typename Hash>
	Hash set(int key);

};

