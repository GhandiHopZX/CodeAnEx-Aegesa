#include <list>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class ItemType
{
public:
	// getters / setters
	
	//constructors
	ItemType();

	ItemType(string name, int at1, int at2, int at3, 
		int at4, int at5, int at6, int at7, int at8, 
		int at9, int at10, int at11, int at12, int at13,
		int at14, int at15, bool w16, bool a17, bool i18);

	ItemType(bool w16, bool a17, bool i18);

	//mutators / accessors

	template <class T>
	T attFNCall(int call, T thing, bool ret)
	{
		list<pair<int, T>> typedD[27];

		switch (ret)
		{
		case false:
			typedD->emplace_back(call, thing);
			break;
		default:
			for (int i = 0; i < containerSize; i++)
			{
				if (typedD[i] == call)
				{
					return typedD[i];
				}
			}
			return typedD[call];
			break;
		}
		return;
	}
	
	// deconstructor
	~ItemType();

private:
#pragma region MyRegion
	string name;
	unsigned int hpAdd = 0;
	unsigned int spAdd = 0;
	unsigned int fpAdd = 0;
	unsigned int apAdd = 0;
	unsigned int atkAdd = 0;
	unsigned int defAdd = 0;
	unsigned int spdAdd = 0;
	unsigned int dexAdd = 0;
	unsigned int intAdd = 0;
	unsigned int sprAdd = 0;
	unsigned int endAdd = 0;
	unsigned int conAdd = 0;
	unsigned int strAdd = 0;
	unsigned int agiAdd = 0;
	unsigned int goldValue = 0;
	unsigned int quantity = 0;
	bool weapon = false;
	bool armor = false;
	bool item = true;
#pragma endregion
	int containerSize = 27;
};

