#include "stateEffects.h"
#include "aegesa.h"

stateEffects::stateEffects()
{
	EXP = 0;
	minusState = false;
	rating = 0;
	restriction = 0;
	zeroHP = false;
	addState = false;
}



string stateEffects::indexer(int s)
{
	return string();
}

bool stateEffects::isFull(int d)
{
	for (int i = 0; i < 20; i++)
	{	
		sizeupAEG += nameInt(allEffGet[i]);
	}
	
	return false;
}

void stateEffects::insertStatus(int key, string m)
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

	if (!m.empty())
	{
		cell.emplace_front(key, m);
	}
	return;
}

void stateEffects::remove_state(int id, bool force = false)
{

}

void stateEffects::add_state(int id, bool force, string kd[])
{
	force = false;
	// ineffective state
	/*if (allEffGet[id].turns_Of_aff == NULL)
	{
		return;
	}*/

	if (!force)
	{
		for (int i = 0; i < 20; i++)
		{
			//weird narrowing but workable narrowing
			// makes sure minus works
			/*if (allEffGet[i].minusState == true && !allEffGet[id].minusState)
			{
				return;
			}*/
		}
	}

	//if (!(kd[id].addState)) // state id > if the state is not added
	//{
	//	insertStatus(id, allEffGet[id]);
	//}

	//if (allEffGet[id].zeroHP == true)
	//{
	//	//stateEffects::setHpd(0);
	//}



	for (int i = 0; i < sizeupAEG; i++)
	{
		//if (allEffGet[id].addState ? (i) : false)
		//{
		//	insertStatus(i, allEffGet[id]);
		//}

		//if (allEffGet[id].minusState ? (i) : false)
		//{
		//	// remove state
		//	remove_state(id, force);
		//}
	}

	// line change to a large rating order (if value is the same, then a strong restriction order)


	int a = 0;
	int b = 0;
	/*stateEffects::statusEff state_a;
	stateEffects::statusEff state_b;*/
	/*state_a = allEffGet[statusGroups];
	state_b = allEffGet[statusGroups];*/

	//sort time; 


	//for loops for sorting
	for (int i = 0; i < sizeupAEG; i++)
	{
		//if (state_a.rating > state_b.rating)
		//{
		//	-1;
		//}

		//else if (state_a.rating < state_b.rating)
		//{
		//	+1;
		//}

		//else if (state_a.restriction > state_b.restriction)
		//{
		//	-1;
		//}

		//else if (state_a.restriction < state_b.restriction)
		//{
		//	+1;
		//}

		//else
		//{
		//	//a <=> b; combined comparison
		//}
	}

	

}

int stateEffects::nameInt(string choiceBuffer)
{
	//string choiceBuffer;
	char choice = NULL;
	//cin >> choice;
	char* choiceWritable = new char[choiceBuffer.size() + 1];

	copy(choiceBuffer.begin(), choiceBuffer.end(), choiceWritable);

	int y = 0;

	// mental ju jitstu
	for (int i = 0; i < choiceBuffer.size(); i++)
	{
		if (i >= 1)
		{
			y = 1;
		}
		else
		{
			y = 0;
		}
	}

	choiceWritable[choiceBuffer.size()] = '\0';

	char* choice3 = choiceWritable;

	char& choice4 = *choice3;
	
	choice = choice4;

	delete[] choiceWritable;

	return y;
}

stateEffects::~stateEffects()
{
}