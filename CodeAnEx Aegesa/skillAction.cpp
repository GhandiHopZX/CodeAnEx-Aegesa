#include <iostream>
#include <fstream>
#include "skillAction.h"
#include "aegesa.h"
#include "HashTableSet.h"

HashTableSet kHash;

//default
skillAction::skillAction()
{
	hpAdd = 0;
	spAdd = 0;
	fpAdd = 0;
	apAdd = 0;
	dpAdd = 0;

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

	hpPerc = 0;
	spPerc = 0;
	fpPerc = 0;
	atkPerc = 0;
	defPerc= 0;
	spdPerc= 0;
	agiPerc= 0;
	dexPerc= 0;
	intPerc= 0;
	sprPerc= 0;
	strPerc= 0;
	endPerc= 0;
	conPerc= 0; //13

	name = "";
	dec = "";
	type = static_cast<elementType>(9);
	rangeType = false;
	num = 0;
	herpesus.buffName = "none";
	statsForSkill;
	this->stat14Percentages[statsForSkill];
	this->strikeType = 'o';
}

//calling the skill into existance
skillAction::skillAction(int call)
{
	// using cout for the sake of simplicity
	// because normalOutput is for the battleSystem.
	// this is for the menu

	hpPerc = 0;
	spPerc = 0;
	fpPerc = 0;
	atkPerc = 0;
	defPerc = 0;
	spdPerc = 0;
	agiPerc = 0;
	dexPerc = 0;
	intPerc = 0;
	sprPerc = 0;
	strPerc = 0;
	endPerc = 0;
	conPerc = 0;
	this->strikeType = 'o';

	cout << skillcall(call).name << endl;
	skillcall(call).dec;
	
	cout << "Element\n";
	displayElementType(skillcall(call).getElementType())
		;
	cout << endl;
	cout << " RangeType\n" + getRangeType() << endl;
	cout << "num#\n" <<
		skillcall(call).num + '\n';

		cout << "Buff/Debuff name\n" +
		skillcall(call).herpesus.buffName << endl;

		cout << "StrikeType (O) OVERHAND, (L) LUNGE, (WS) WIDE-SWING, (P) PARRY\n " <<
			 "O < L < W > P > L > O\n" <<
			 "W AND L COLLIDE CAUSES DAMAGE TO BOTH SIDES\n" <<
			 "O AND P CANCEL BOTH ATTACKS\n" <<
		skillcall(call).strikeType + '\n' << endl;

		cout << "Buff/debuff effects" +
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
		
		<< "Viable Percentage of Stat boost/effect\n" <<
		skillcall(call).stat14Percentages[0] + '\n' +
		skillcall(call).stat14Percentages[hpPerc] +'\n' +
		skillcall(call).stat14Percentages[spPerc] +'\n' +
		skillcall(call).stat14Percentages[fpPerc] +'\n' +
		skillcall(call).stat14Percentages[atkPerc] +'\n' +
		skillcall(call).stat14Percentages[defPerc] +'\n' +
		skillcall(call).stat14Percentages[spdPerc] +'\n' +
		skillcall(call).stat14Percentages[agiPerc] +'\n' +
		skillcall(call).stat14Percentages[dexPerc] +'\n' +
		skillcall(call).stat14Percentages[intPerc] +'\n' +
		skillcall(call).stat14Percentages[sprPerc] +'\n' +
		skillcall(call).stat14Percentages[endPerc] +'\n' +
		skillcall(call).stat14Percentages[conPerc] + '\n'
		<< endl;
		

	herpesus.buffName = "none";
	stat14Percentages[statsForSkill];
}

skillAction::skillAction(int numid, string name, elementType d, string dec,
	bool rType, int sp_succ, int fp_succ, int stat13[], aegesa::statusEff hopesis, char strikeType)
{
	hpPerc = 0;
	spPerc = 0;
	fpPerc = 0;
	atkPerc = 0;
	defPerc = 0;
	spdPerc = 0;
	agiPerc = 0;
	dexPerc = 0;
	intPerc = 0;
	sprPerc = 0;
	strPerc = 0;
	endPerc = 0;
	conPerc = 0;
	
	stat13[13] = stat14Percentages[statsForSkill];

	stat13[0] = 0;
	stat13[1] = hpPerc;
	stat13[2] = spPerc;
	stat13[3] = fpPerc;
	stat13[4] = atkPerc;
	stat13[5] = defPerc;
	stat13[6] = spdPerc;
	stat13[7] = agiPerc;
	stat13[8] = dexPerc;
	stat13[9] = intPerc;
	stat13[10] = sprPerc;
	stat13[11] = strPerc;
	stat13[12] = endPerc;
	stat13[13] = conPerc;

	hopesis.buffName = "dummyu"; // you may need to initialize these

	// sp consume
	spAdd += sp_succ;

	// fp consume
	fpAdd += fp_succ;

	// strike type
	this->strikeType = 'o';
	
	num = numid;

	rangeType = rType;

	type = d;
}

skillAction skillAction::skillcall(int p)
{
#pragma region Skillist
	/*skillAction FireWeave(0, "FireWeave", elementType::Fire, "Weaves of unending flame lash about the targets", true, 1300, 12);
	skillAction WaterFlash(1, "WaterFlash", elementType::Water, "A singular riptide of water..", false, 234, 2);
	skillAction MagnaFlare(2, "MagnaFlare", elementType::Lightning, "A raving magnetic flash of plasma.", true, 300, 5);
	skillAction WindShear(3, "WindShear", elementType::Air, "A Wind blast that cuts anybody who brandishes.", false, 230, 2);*/
#pragma endregion

	/*kHash.insertSkill(0, FireWeave);
	kHash.insertSkill(1, WaterFlash);
	kHash.insertSkill(2, MagnaFlare);
	kHash.insertSkill(3, WindShear);*/

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