#include "linkedList.h"
#include <iostream>
#include <string>

/**
 * Constructor for linkedList.
 */
linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
} /* linkedList */


/**
 * Destructor for linkedList.
 * Frees every node.
 */
linkedList::~linkedList()
{
	freeNodes();
} /* ~linkedList */


/**
 * creating the default node for the linkedList. Needs to be called only once.
 * @q a Question structure.
 */
void linkedList::createNode(Question *q)
{
	node *temp = new node;
	temp->q = q;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
} /* createNode */


/**
 * Displays every element of the linkedList
 */
void linkedList::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << "Question: " << temp->q->question << "; "
			<< "Answer 1: " << temp->q->a1 << "; "
			<< "Answer 2: " << temp->q->a2 << "; "
			<< "Answer 3: " << temp->q->a3 << "; "
			<< "Answer 4: " << temp->q->a4 << "; "
			<< "Correct: " << temp->q->correct << "; "
			<< "Difficulty: " << temp->q->difficulty << ";"
			<< std::endl;
		temp = temp->next;
	}
} /* display */


/**
 * Inserts an element at the beginning of the list.
 * @q a Question structure.
 */
void linkedList::insert_start(Question *q)
{
	node *temp = new node;
	temp->q = q;
	temp->next = head;
	head = temp;
} /* insert_start */


/**
 * Inserts an element at the given position.
 * @q a Question structure.
 */
void linkedList::insert_position(int pos, Question *q)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}

	temp->q = q;
	pre->next = temp;
	temp->next = cur;
} /* insert_position */


/**
 * Frees every single node of the linkedList.
 */
void linkedList::freeNodes()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		delete(temp->q);
		temp = temp->next;
	}
} /* freeNodes */