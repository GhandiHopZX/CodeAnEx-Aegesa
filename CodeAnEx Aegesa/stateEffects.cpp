#include "stateEffects.h"
#include "stateEffects.h"

stateEffects::statusEff stateEffects::indexer(int)
{
	return stateEffects::statusEff();
}


//
//bool stateEffects::isFull(int d)
//{
//	for (int i = 0; i < 20; i++)
//	{
//		if (allEffGet[d].buffName != My_Statuses[i].buffName)
//		{
//			return false; // then the state isn't existant here
//		}
//
//		if (My_Statuses[i].turns_Of_aff == -1)
//		{
//			return true;
//		}
//
//		if (My_Statuses[i].turns_Of_aff == allEffGet[d].turns_Of_aff)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
void stateEffects::insertStatus(int key, stateEffects::statusEff m)
{
	auto& cell = stateEffects::allEffGet2[num_Statuses];
	auto bItr = begin(cell);
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			bItr->second = m;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}

	if (!m.buffName.empty())
	{
		cell.emplace_back(key, num_Statuses);
	}
	return;
}
void stateEffects::remove_state(int id, bool force = false)
{

}
void stateEffects::add_state(int id, bool force = false)
{
	// ineffective state
	if (allEffGet[id].turns_Of_aff == NULL)
	{
		return;
	}

	if (!force)
	{
		for (int i = 0; i < 20; i++)
		{
			//weird narrowing but workable narrowing
			// makes sure minus works
			if (allEffGet[i].minusState == true && !allEffGet[id].minusState)
			{
				return;
			}
		}
	}

	if (!(My_Statuses[id].addState)) // state id > if the state is not added
	{
		insertStatus(id, allEffGet[id]);
	}

	if (allEffGet[id].zeroHP == true)
	{
		//stateEffects::setHpd(0);
	}



	for (int i = 0; i < sizeupAEG; i++)
	{
		if (allEffGet[id].addState ? (i) : false)
		{
			insertStatus(i, allEffGet[id]);
		}

		if (allEffGet[id].minusState ? (i) : false)
		{
			// remove state
			remove_state(id, force);
		}
	}

	// line change to a large rating order (if value is the same, then a strong restriction order)


	int a = 0;
	int b = 0;
	stateEffects::statusEff state_a;
	stateEffects::statusEff state_b;
	state_a = allEffGet[statusGroups];
	state_b = allEffGet[statusGroups];

	//sort time; 


	//for loops for sorting
	for (int i = 0; i < sizeupAEG; i++)
	{
		if (state_a.rating > state_b.rating)
		{
			-1;
		}

		else if (state_a.rating < state_b.rating)
		{
			+1;
		}

		else if (state_a.restriction > state_b.restriction)
		{
			-1;
		}

		else if (state_a.restriction < state_b.restriction)
		{
			+1;
		}

		else
		{
			//a <=> b; combined comparison
		}
	}
}
