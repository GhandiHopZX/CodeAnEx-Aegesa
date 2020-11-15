#include "LinkedList.h"

// this function is useless?
void LinkedList::list(int n[], int u)
{
	struct node* frntNode, * tmp;
	int num, i;

	i = u;

	stnode = (struct node*)malloc(sizeof(struct node));

	if (stnode == NULL)
	{
		cout << " Memory can not be allocated";
	}
	else
	{
		num = n[0];
		if (n[0] <= 0)
		{
			n[0] == 1;
		}
		stnode->nextptr = NULL;
		tmp = stnode;

		for (i = 0; i <= n[0]; i++)
		{
			frntNode = (struct node*)malloc(sizeof(struct node));

			if (frntNode == NULL)
			{
				cout << "Memory can not be allocated";
				break;
			}
			else
			{
				//cout << "Enter the data for node " << i << ": "; // Entering data in nodes.
				//cin >> num;
				frntNode->num = num;
				frntNode->nextptr = NULL;
				tmp->nextptr = frntNode;
				tmp = tmp->nextptr;
			}
		}
	}
}

// reverse the list
void LinkedList::reverse(node** stnode)
{
	struct node* temp = NULL;
	struct node* prev = NULL;
	struct node* current = (*stnode);
	while (current != NULL) 
	{
		temp = current->nextptr;
		current->nextptr = prev;
		prev = current;
		current = temp;
	}
	(*stnode) = prev;
}

// use this for displaying info
void LinkedList::listD()
{
	struct node* tmp;
	if (stnode == NULL)
	{
		cout << "List is empty";
	}
	else
	{
		tmp = stnode;
		while (tmp != NULL)
		{
			cout << tmp->num << "\t";
			tmp = tmp->nextptr;
		}
	}
}
