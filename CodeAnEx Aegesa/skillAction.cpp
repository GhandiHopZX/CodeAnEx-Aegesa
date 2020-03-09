#include <iostream>
#include "skillAction.h"
#include "aegesa.h"

//default
skillAction::skillAction()
{
	name = "";
	dec = "";
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

skillAction::skillAction(int num, string name, elementType d, string dec,
	bool rangeType, int sp_succ, int fp_succ)
{
	
	// sp consume
	sp_succ = 0;
	// fp consume
	fp_succ = 0;

	fpAdd += 0;
	spAdd += 0;
	hpAdd += 0;

}

skillAction skillAction::skillcall(int p)
{
#pragma region Skillist
	skillAction FireWeave(0, "FireWeave", elementType::Fire, "Weaves of unending flame lash about the targets", true, 1300, 12);
	skillAction WaterFlash(1, "WaterFlash", skillAction::elementType::Water, "A singular riptide of water..", false, 234, 2);
#pragma endregion

	skillAction allSkills[50] =
	{
		FireWeave,
		WaterFlash
	};
	return allSkills[p];
}

skillAction::elementType skillAction::getElementType()
{
	switch (elementType::Water)
	{
	case skillAction::elementType::Water:
		return elementType::Water;
		break;
	case skillAction::elementType::Fire:
		return elementType::Fire;
		break;
	case skillAction::elementType::Earth:
		return elementType::Earth;
		break;
	case skillAction::elementType::Air:
		return elementType::Air;
		break;
	case skillAction::elementType::Lightning:
		return elementType::Lightning;
		break;
	case skillAction::elementType::Phase:
		return elementType::Phase;
		break;
	case skillAction::elementType::Bio:
		return elementType::Bio;
		break;
	case skillAction::elementType::Light:
		return elementType::Light;
		break;
	case skillAction::elementType::Dark:
		return elementType::Dark;
		break;
	case skillAction::elementType::Normal:
		return elementType::Normal;
		break;
	default:
		return elementType::Normal;
		break;
	}
}

skillAction::elementType skillAction::setElementType(int m)
{
	return static_cast<elementType>(m);
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

void skillAction::getDescription()
{
	cout << dec;
}

void skillAction::getRangeType()
{
	if (rangeType = true)
	{
		cout << "AOE" << endl;
	}
	else
	{
		cout << "Single" << endl;
	}
}

template <>
struct hash<skillAction>
{
	size_t operator() (const skillAction& sk) const
	{
		//individual Hashes
	}
};