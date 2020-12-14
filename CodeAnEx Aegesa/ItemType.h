#include <string>

using namespace std;

class ItemType
{
public:

	struct weapon
	{
		string name;
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
	};

	struct armor
	{
		string name;
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
	};

	struct item
	{
		string name;
		unsigned int hpAdd = 0;
		unsigned int spAdd = 0;
		unsigned int fpAdd = 0;
		unsigned int apAdd = 0;
		// no dp plus plz

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

		// next item
	};

	int MAX_INTEGRITY = 20;

	// data 
#pragma region All_weapons
	ItemType::weapon brawd_injector;
	ItemType::weapon glass_gauntlet;
	ItemType::weapon carbonite_knuckle;
	ItemType::weapon crystalline_injector;
	ItemType::weapon aerolite_gauntlet;
	ItemType::weapon vandham_gauntlet;
	ItemType::weapon antimatter_injector;
	ItemType::weapon shinobi_claws;
	ItemType::weapon tacheyon_injector;
	ItemType::weapon magic_glove;
	ItemType::weapon bomber_injector;
	ItemType::weapon titanium_infused_gauntlet;
	ItemType::weapon anti_nuclear_injector;
#pragma endregion

	ItemType::weapon weaponlist[100] =
	{
	 brawd_injector,
	 glass_gauntlet,
	 carbonite_knuckle,
	 crystalline_injector,
	 aerolite_gauntlet,
	 vandham_gauntlet,
	 antimatter_injector,
	 shinobi_claws,
	 tacheyon_injector,
	 magic_glove,
	 bomber_injector,
	 titanium_infused_gauntlet,
	 anti_nuclear_injector
	};


	//items

#pragma region All_items
	ItemType::item AEGESA_FRAGMENT;
	ItemType::item kaider_shard;
	ItemType::item greenball_bun;
	ItemType::item enchantment_crystal;
	ItemType::item music_chord;
	ItemType::item static_weave;
	ItemType::item marble_eye;
	ItemType::item tiny_fingers;
	ItemType::item chared_beast_skin;
	ItemType::item magical_mane;
	ItemType::item masters_cane;
	ItemType::item broken_wing;
	ItemType::item ripped_coat;
	ItemType::item shattered_broach;
#pragma endregion

	ItemType::item itemlist[100] =
	{
		AEGESA_FRAGMENT,
		kaider_shard,
		greenball_bun,
		enchantment_crystal,
		music_chord,
		static_weave,
		marble_eye,
		tiny_fingers,
		chared_beast_skin,
		magical_mane,
		masters_cane,
		broken_wing,
		ripped_coat,
		shattered_broach,
	};

	ItemType::item allitemList(int integer)
	{
		return itemlist[integer];
	}

#pragma region itemNames
	string itemNames[100] =
	{
		AEGESA_FRAGMENT.name = "AEGESA FRAGMENT",
		kaider_shard.name = "kaider shard",
		greenball_bun.name = "greenball bun",
		enchantment_crystal.name = "enchantment crystal",
		music_chord.name = "music chord",
		static_weave.name = "static weave",
		marble_eye.name = "marble eye",
		tiny_fingers.name = "tiny fingers",
		chared_beast_skin.name = "chared beast skin",
		magical_mane.name = "magical mane",
		masters_cane.name = "masters mane",
		broken_wing.name = "broken wing",
		ripped_coat.name = "ripped coat",
		shattered_broach.name = "shattered broach",
	};

#pragma endregion

#pragma region All_armors
	ItemType::armor broad_armor;
	ItemType::armor kavelar_gear;
	ItemType::armor carbonite_gear;
	ItemType::armor crystalline_armor;
	ItemType::armor aerolite_gear;
	ItemType::armor vandham_armor;
	ItemType::armor antiImpact_armor;
	ItemType::armor katType_armor;
	ItemType::armor grenadier_composite_armor;
	ItemType::armor anti_nuclear_armor;
#pragma endregion

	ItemType::armor armorlist[100] =
	{
		broad_armor,
		kavelar_gear,
		carbonite_gear,
		crystalline_armor,
		aerolite_gear,
		vandham_armor,
		antiImpact_armor,
		katType_armor,
		grenadier_composite_armor,
		anti_nuclear_armor
	};

	ItemType::armor allarmorList(int integer)
	{
		return armorlist[integer];
	}



	// constructor
	ItemType();

	ItemType(item);

	ItemType(armor);

	ItemType(weapon);

	//mutators / accessors
	

	// deconstructor
	~ItemType();

private:

};
