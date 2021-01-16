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

	ItemType(string name, int at0, int at1, int at2, int at3, 
		int at4, int at5, int at6, int at7, int at8, 
		int at9, int at10, int at11, int at12, int at13,
		int at14, int at15, bool w16, bool a17, bool i18);

	ItemType(bool w17, bool a18, bool i19);

	//mutators / accessors

	string getName();

	void setName(string n);

	void setStatBank(int call, int set);

	void setBools(int call, bool);

	int getStatBank(int call);

	bool getBools(int call);

	//leave this the way it is
	template <class T>
	T attFNCall(int call, T thing, bool ret)
	{
		switch (ret)
		{
			// false doesn't change the value and returns it
		case false:
			switch (call)
			{
			case 0:
				return getName(thing);
				break;
			case 1:
				return getStatBank(call);
				break;
			case 2:
				return getStatBank(call);
				break;
			case 3:
				return getStatBank(call);
				break;
			case 4:
				return getStatBank(call);
				break;
			case 5:
				return getStatBank(call);				break;
			case 6:
				return getStatBank(call);				break;
			case 7:
				return getStatBank(call);				break;
			case 8:
				return getStatBank(call);				break;
			case 9:
				return getStatBank(call);				break;
			case 10:
				return getStatBank(call);				break;
			case 11:
				return getStatBank(call);				break;
			case 12:
				return getStatBank(call);				break;
			case 13:
				return getStatBank(call);			break;
			case 14:
				return getStatBank(call);				break;
			case 15:
				return getStatBank(call);			break;
			case 16:
				return getBools(call);			break;
			case 17:
				return getBools(call);			break;
			case 18:
				return getBools(call);			break;
			default:
				return getStatBank(call);				break;
			}
			break;
			// true changes the value and returns it
		default:
			switch (call)
			{
			case 0:
				setName(thing);
				return getName();
				break;
			case 1:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 2:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 3:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 4:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 5:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 6:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 7:
				setStatBank(call, thing);			
				return getStatBank(call);
				break;
			case 8:
				setStatBank(call, thing);			
				return getStatBank(call);
				break;
			case 9:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 10:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 11:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 12:
				setStatBank(call, thing);
				return getStatBank(call);
				break;
			case 13:
				setStatBank(call, thing);			
				return getStatBank(call);
				break;
			case 14:
				setStatBank(call, thing);			
				return getStatBank(call);
				break;
			case 15:
				setStatBank(call, thing);			
				return getStatBank(call);
				break;
			case 16:
				setBools(call, thing);			
				return getBools(call);
				break;
			case 17:
				setBools(call, thing);
				return getBools(call);
				break;
			case 18:
				setBools(call, thing);
				return getBools(call);
				break;
			default:
				setStatBank(call, thing);
				break;
			}
			break;
			return;
			break;
		}
		return;
	}
	
	// deconstructor
	~ItemType();

private:
#pragma region MyRegion
	string name;
	int tegerBank[16]; // added one for the 0th placement helps with confusion
	bool wai[2]; // one two three
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
	int containerSize = 19;
};

