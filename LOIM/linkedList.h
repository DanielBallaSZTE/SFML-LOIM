#include <iostream>
#include "QuestionManager.h"

#ifndef _LINKEDLIST
#define _LINKEDLIST

typedef struct node {
	struct Question *q;
	node	*next;
} node;

class linkedList {
private:
	node	*head;
	node	*tail;

public:
	linkedList();
	~linkedList();
	void	createNode(Question *q); // Creates a node (a list)
	void	display(); // Displays the list
	void	insert_start(Question *q); // Insert an element at the beginning of the list
	void	insert_position(int pos, Question *q); // Insert an element at the given position of the list
	void	freeNodes();
};

#endif