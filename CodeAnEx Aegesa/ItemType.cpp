#include "ItemType.h"
#include <iostream>

using namespace std;

ItemType::ItemType()
{

}

ItemType::ItemType(item d)
{
	d.agiAdd = NULL;
	d.agiAdd = NULL;
	d.apAdd = NULL;
	d.atkAdd = NULL;
	d.name = "";
	d.hpAdd = NULL;
	d.spAdd = NULL;
	d.fpAdd = NULL;
	d.defAdd = NULL;
	d.spdAdd = NULL;
	d.dexAdd = NULL;
	d.intAdd = NULL;
	d.sprAdd = NULL;
	d.endAdd = NULL;
	d.conAdd = NULL;
	d.goldValue = NULL;
	d.quantity = NULL;
}

ItemType::ItemType(armor d)
{
	d.agiAdd = NULL;
	d.agiAdd = NULL;
	d.atkAdd = NULL;
	d.name = "";
	d.defAdd = NULL;
	d.spdAdd = NULL;
	d.dexAdd = NULL;
	d.intAdd = NULL;
	d.sprAdd = NULL;
	d.endAdd = NULL;
	d.conAdd = NULL;
	d.goldValue = NULL;
	d.quantity = NULL;
}

ItemType::ItemType(weapon d)
{
	d.agiAdd = NULL;
	d.agiAdd = NULL;
	d.atkAdd = NULL;
	d.name = "";
	d.defAdd = NULL;
	d.spdAdd = NULL;
	d.dexAdd = NULL;
	d.intAdd = NULL;
	d.sprAdd = NULL;
	d.endAdd = NULL;
	d.conAdd = NULL;
	d.goldValue = NULL;
	d.quantity = NULL;
}

ItemType::ItemType()
{
}

// conversion methods
ItemType::armor pTIA(ItemType::armor v, ItemType::armor p, int select)
{
	p.name = v.name;
	p.agiAdd = v.agiAdd;
	p.atkAdd = v.atkAdd;
	p.conAdd = v.conAdd;
	p.defAdd = v.defAdd;
	p.dexAdd = v.dexAdd;
	p.endAdd = v.endAdd;
	p.goldValue = v.goldValue;
	p.intAdd = v.intAdd;
	p.quantity = v.quantity;
	p.spdAdd = v.spdAdd;
	p.sprAdd = v.sprAdd;
	p.strAdd = v.strAdd;

	return p;
}

ItemType::weapon pTIW(ItemType::weapon v, ItemType::weapon p, int select)
{
	p.name = v.name;
	p.agiAdd = v.agiAdd;
	p.atkAdd = v.atkAdd;
	p.conAdd = v.conAdd;
	p.defAdd = v.defAdd;
	p.dexAdd = v.dexAdd;
	p.endAdd = v.endAdd;
	p.goldValue = v.goldValue;
	p.intAdd = v.intAdd;
	p.quantity = v.quantity;
	p.spdAdd = v.spdAdd;
	p.sprAdd = v.sprAdd;
	p.strAdd = v.strAdd;

	return p;
}

ItemType::item pTII(ItemType::item v, ItemType::item p, int select)
{
	p.name = v.name;
	p.agiAdd = v.agiAdd;
	p.atkAdd = v.atkAdd;
	p.conAdd = v.conAdd;
	p.defAdd = v.defAdd;
	p.dexAdd = v.dexAdd;
	p.endAdd = v.endAdd;
	p.goldValue = v.goldValue;
	p.intAdd = v.intAdd;
	p.quantity = v.quantity;
	p.spdAdd = v.spdAdd;
	p.sprAdd = v.sprAdd;
	p.strAdd = v.strAdd;
	p.hpAdd = v.hpAdd;
	p.fpAdd = v.fpAdd;
	p.apAdd = v.apAdd;
	p.spAdd = v.spAdd;

	return p;
}


ItemType::~ItemType()
{

}