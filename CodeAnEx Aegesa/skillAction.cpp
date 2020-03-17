#include <iostream>
#include <fstream>
#include "skillAction.h"
#include "aegesa.h"
#include "HashTableSet.h"

HashTableSet kHash;

//default
skillAction::skillAction()
{
	name = "";
	dec = "";
	type = static_cast<elementType>(9);
	rangeType = false;
	num = 0;
}

//calling the skill into existance
skillAction::skillAction(int call)
{
	// using cout for the sake of simplicity
	// because normalOutput is for the battleSystem.
	// this is for the menu

	cout << skillcall(call).name << endl;
	skillcall(call).dec;
	cout << endl;
	displayElementType(skillcall(call).getElementType());
	cout << endl;
	getRangeType();
	cout <<
		skillcall(call).num + '\n' +
		skillcall(call).hpAdd + '\n' +
		skillcall(call).spAdd + '\n' +
		skillcall(call).dpAdd + '\n' +
		skillcall(call).fpAdd + '\n' +
		skillcall(call).apAdd + '\n' +

		skillcall(call).atkAdd + '\n' +
		skillcall(call).defAdd + '\n' +
		skillcall(call).spdAdd + '\n' +

		skillcall(call).agiAdd + '\n' +
		skillcall(call).conAdd + '\n' +
		skillcall(call).dexAdd + '\n' +
		skillcall(call).endAdd + '\n' +
		skillcall(call).strAdd + '\n' +
		skillcall(call).intAdd + '\n' +
		skillcall(call).sprAdd + '\n'
		<< endl;
}

skillAction::skillAction(int numid, string name, elementType d, string dec,
	bool rType, int sp_succ, int fp_succ)
{
	// sp consume
	sp_succ = 0;
	// fp consume
	fp_succ = 0;

	num = numid;

	rangeType = rType;

	type = d;

	fpAdd += 0;
	spAdd += 0;
	hpAdd += 0;
}

skillAction skillAction::skillcall(int p)
{
#pragma region Skillist
	skillAction FireWeave(0, "FireWeave", elementType::Fire, "Weaves of unending flame lash about the targets", true, 1300, 12);
	skillAction WaterFlash(1, "WaterFlash", elementType::Water, "A singular riptide of water..", false, 234, 2);
	skillAction MagnaFlare(2, "MagnaFlare", elementType::Lightning, "A raving magnetic flash of plasma.", true, 300, 5);
	skillAction WindShear(3, "WindShear", elementType::Air, "A Wind blast that cuts anybody who brandishes.", false, 230, 2);
#pragma endregion

	kHash.insertSkill(0, FireWeave);
	kHash.insertSkill(1, WaterFlash);
	kHash.insertSkill(2, MagnaFlare);
	kHash.insertSkill(3, WindShear);

	skillAction d = kHash.skillCall(p);
	return d;
}

skillAction::elementType skillAction::getElementType()
{
	return type;
}

void skillAction::displayElementType(elementType d)
{
	switch (d)
	{
	case skillAction::elementType::Water:
		cout << "Water" << endl;
		break;
	case skillAction::elementType::Fire:
		cout << "Fire" << endl;
		break;
	case skillAction::elementType::Earth:
		cout << "Earth" << endl;
		break;
	case skillAction::elementType::Air:
		cout << "Air" << endl;
		break;
	case skillAction::elementType::Lightning:
		cout << "Lightning" << endl;
		break;
	case skillAction::elementType::Phase:
		cout << "Phase" << endl;
		break;
	case skillAction::elementType::Bio:
		cout << "Bio" << endl;
		break;
	case skillAction::elementType::Light:
		cout << "Light" << endl;
		break;
	case skillAction::elementType::Dark:
		cout << "Dark" << endl;
		break;
	case skillAction::elementType::Normal:
		cout << "Normal" << endl;
		break;
	default:
		cout << "Normal" << endl;
		break;
	}
}

void skillAction::setRangeType(bool rangeT)
{
	rangeType = rangeT;

	if (rangeType == true) // aoe true
	{
		cout << "AOE set" << endl;

	}
	else // single false
	{	
		cout << "Single set" << endl;
	}
}

bool skillAction::getRangeType()
{
	return rangeType;
}

string skillAction::getDescription()
{
	return dec;
}

skillAction::elementType skillAction::setElementType(int m)
{
	type = static_cast<elementType>(m);
	return type;
}