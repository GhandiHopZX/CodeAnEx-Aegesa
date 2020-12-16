#include <iostream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType()
{
#pragma region MyRegion
	name;
	hpAdd = 0;
	spAdd = 0;
	fpAdd = 0;
	apAdd = 0;

	atkAdd = 0;
	defAdd = 0;
	spdAdd = 0;

	dexAdd = 0;
	intAdd = 0;
	sprAdd = 0;
	endAdd = 0;
	conAdd = 0;
	strAdd = 0;
	agiAdd = 0;
	goldValue = 0;

	quantity = 0;

	weapon = false;
	armor = false;
	item = true;

#pragma endregion
	
	attFNCall(0, this->name, true);
	attFNCall(1, this->spAdd, true);
	attFNCall(2, this->fpAdd, true);
	attFNCall(3, this->apAdd, true);
	attFNCall(4, this->atkAdd, true);
	attFNCall(5, this->defAdd, true);
	attFNCall(6, this->spdAdd, true);
	attFNCall(7, this->dexAdd, true);
	attFNCall(8, this->intAdd, true);
	attFNCall(9, this->sprAdd, true);
	attFNCall(10, this->endAdd, true);
	attFNCall(11, this->conAdd, true);
	attFNCall(12, this->strAdd, true);
	attFNCall(13, this->agiAdd, true);
	attFNCall(14, this->goldValue, true);
	attFNCall(15, this->quantity, true);
	attFNCall(16, this->weapon, false);
	attFNCall(17, this->armor, false);
	attFNCall(18, this->item, true);
}

ItemType::ItemType(string n, int at1, int at2,
	int at3, int at4, int at5, int at6, 
	int at7, int at8, int at9, int at10, int at11, 
	int at12, int at13, int at14, 
	int at15, bool w16, bool a17, bool i18)
{
	attFNCall(0, n, true);
	attFNCall(1, at1, true);
	attFNCall(2, at2, true);
	attFNCall(3, at3, true);
	attFNCall(4, at4, true);
	attFNCall(5, at5, true);
	attFNCall(6, at6, true);
	attFNCall(7, at7, true);
	attFNCall(8, at8, true);
	attFNCall(9, at9, true);
	attFNCall(10, at10, true);
	attFNCall(11, at11, true);
	attFNCall(12, at12, true);
	attFNCall(13, at13, true);
	attFNCall(14, at14, true);
	attFNCall(15, at15, true);
	attFNCall(16, w16, true);
	attFNCall(17, a17, true);
	attFNCall(18, i18, true);
}

ItemType::ItemType(bool w16, bool a17, bool i18)
{
	attFNCall(0, this->name, true);
	attFNCall(1, this->spAdd, true);
	attFNCall(2, this->fpAdd, true);
	attFNCall(3, this->apAdd, true);
	attFNCall(4, this->atkAdd, true);
	attFNCall(5, this->defAdd, true);
	attFNCall(6, this->spdAdd, true);
	attFNCall(7, this->dexAdd, true);
	attFNCall(8, this->intAdd, true);
	attFNCall(9, this->sprAdd, true);
	attFNCall(10, this->endAdd, true);
	attFNCall(11, this->conAdd, true);
	attFNCall(12, this->strAdd, true);
	attFNCall(13, this->agiAdd, true);
	attFNCall(14, this->goldValue, true);
	attFNCall(15, this->quantity, true);
	attFNCall(16, w16, true);
	attFNCall(17, a17, true);
	attFNCall(18, i18, true);
}

// data 
#pragma region All_weapons
ItemType brawd_injector;
ItemType glass_gauntlet;
ItemType carbonite_knuckle;
ItemType crystalline_injector;
ItemType aerolite_gauntlet;
ItemType vandham_gauntlet;
ItemType antimatter_injector;
ItemType shinobi_claws;
ItemType tacheyon_injector;
ItemType magic_glove;
ItemType bomber_injector;
ItemType titanium_infused_gauntlet;
ItemType anti_nuclear_injector;
#pragma endregion

ItemType weaponlist[100] =
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
ItemType AEGESA_FRAGMENT;
ItemType kaider_shard;
ItemType greenball_bun;
ItemType enchantment_crystal;
ItemType music_chord;
ItemType static_weave;
ItemType marble_eye;
ItemType tiny_fingers;
ItemType chared_beast_skin;
ItemType magical_mane;
ItemType masters_cane;
ItemType broken_wing;
ItemType ripped_coat;
ItemType shattered_broach;
#pragma endregion

ItemType itemlist[100] =
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


#pragma region itemNames
string itemNames[100] =
{
	AEGESA_FRAGMENT.attFNCall(0,  "AEGESA FRAGMENT", true),
	kaider_shard.attFNCall(0, "kaider shard", true),
	greenball_bun.attFNCall(0, "greenball bun", true),
	enchantment_crystal.attFNCall(0, "enchantment crystal", true),
	music_chord.attFNCall(0, "music chord", true),
	static_weave.attFNCall(0, "static weave", true),
	marble_eye.attFNCall(0, "marble eye", true),
	tiny_fingers.attFNCall(0, "tiny fingers", true),
	chared_beast_skin.attFNCall(0, "chared beast skin", true),
	magical_mane.attFNCall(0, "magical mane", true),
	masters_cane.attFNCall(0, "masters cane", true),
	broken_wing.attFNCall(0, "broken wing", true),
	ripped_coat.attFNCall(0, "ripped coat", true),
	shattered_broach.attFNCall(0, "shattered broach", true),
};

#pragma endregion

#pragma region All_armors
ItemType broad_armor;
ItemType kavelar_gear;
ItemType carbonite_gear;
ItemType crystalline_armor;
ItemType aerolite_gear;
ItemType vandham_armor;
ItemType antiImpact_armor;
ItemType katType_armor;
ItemType grenadier_composite_armor;
ItemType anti_nuclear_armor;
#pragma endregion

ItemType armorlist[100] =
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

ItemType allarmorList(int integer)
{
	return armorlist[integer];
}

ItemType allitemList(int integer)
{
	return itemlist[integer];
}

// conversion methods


ItemType::~ItemType()
{

}