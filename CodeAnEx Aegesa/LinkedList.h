#pragma once
#include <iostream>
#include "HashTableSet.h"
/* this is primarily for stateEffects.
 and that functionality for said state effects is such that we have a linked list capable of instatniating a 
// controlled list of tasks to pop
// statuses in this case to activate their effect.
// actions in battle.
// skills/events in the background.
// Use for proper thread handling. (hierarchy system)
// so being able to change the order of 
// these actions will give us a class 
 that can be used even in a Battle system. 
 */
class LinkedList : public HashTableSet
{
private:
	struct node
	{
		int num;
		node* nextptr;
	}*stnode;

	void list(int n[]);
	void reverse(node **stnode);
	void listD();
};

