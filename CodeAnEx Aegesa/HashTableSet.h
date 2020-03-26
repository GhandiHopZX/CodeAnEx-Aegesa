#include <list>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "skillAction.h"
#include "inventory.h"

using namespace std;

class HashTableSet // with this you can make multiple hashes with calculations that will be handy through out this project
{
private:
	static const int hashGroups = 400;
	static const int skillGroups = 200;

	int skill_Sum;
	int shash_Value;
	bool skey_exists;

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

	// template_types
	template <class Hash>
	Hash fullTemp(int key, Hash objType)
	{
		static const int hashT = 300;
		int templateHSum;
		int tHash_Value;
		int tKey_Exists;

		list<pair<int, Hash>> INVENTORU[hashT];

	/*	bool isEmptyT() const
		{};

		template <typename Hash>
		Hash hashT(int keyCall)
		{};

		template <typename Hash>
		Hash insertT(int key, Hash type)
		{};

		template <typename Hash>
		Hash remove(int key)
		{};

		template <typename Hash>
		Hash search(int key)
		{};

		template <typename Hash>
		Hash printTableT()
		{};

		template <typename Hash>
		Hash get()
		{};

		template <typename Hash>
		Hash set()
		{};*/

	};

	template <class Hash>
	Hash isEmptyT() const;

	template <class Hash>
	Hash hashT(int);

	template <class Hash>
	Hash insertT();

	template <class Hash>
	Hash remove();

	template <class Hash>
	Hash search();

	template <class Hash>
	Hash printTableT();

	template <class Hash>
	Hash get();

	template <class Hash>
	Hash set();

	// for hashes
	skillAction skillCall(int sk); //operator for this
};

