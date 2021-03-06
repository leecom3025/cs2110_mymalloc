#include <stdlib.h>
#include "./list.h"
#include "./my_malloc.h"

/**
 * pushFront
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the head of the list, and increment size
 */
void pushFront(LIST *list, int data)
{
	// if list or data is null, break
	if (!list || !data) return; 

	NODE *node = my_malloc(sizeof(NODE));
	if (!node) // if fail to get proper memory location
		return; // break

	node->data = data; //else assign data to data in node

	if (!list->head) { //empty case
		list->head = node; // assign to head
		node->next = NULL; // assign node's next to null
		list->tail = node; // assign to tail
		list->size++; // increment size
	} else {
		NODE *t = list->head; // temp pointer of current head
		list->head = node; // move head
		t->prev = node; // current head's prev to new head
		node->next = t; // new head's next to current head
		list->size++; // increment size
	}

}

/**
 * pushBack -_-
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the tail of the list, and increment size
 */
void pushBack(LIST *list, int data)
{
	// if list or data is null, break
	if (!list || !data) return; 
	
	NODE *node = my_malloc(sizeof(NODE));
	if (!node) // if fail to get proper memory location
		return; // break

	node->data = data; //else assign data to data in node


	if (!list->head) { //empty case
		list->head = node; // assign to head
		node->next = NULL; // assign node's next to null
		list->tail = node; // assign to tail
		list->size++; // increment size
	} else {
		NODE *t = list->tail; // temp pointer of current tail
		list->tail = node; // move tail
		t->next = node; // current tail's next to new tail
		node->prev = t; // new tail's prev to current tail
		list->size++; // increment size
	}
}

/**
 * popFront
 * Takes in ptr to a list
 * Remove and free node at the front of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */
int popFront(LIST *list)
{
	if (!list) return -1; // woops somethig is bad :( 
	
	if (list->size == 0) return 0;

	int result = -1;
	NODE *t = list->head; // get the head
	if (list->head != list->tail) // if head and tail is NOT same
		list->head = t->next; // now head points to next of head
	list->head->prev = NULL; // make head's prev points to NULL in any case
	if (t->data) // if data is there, should be !!
		result = t->data;
	my_free(t); // free the front one. RIP my friend
	list->size--; // decrement size
	return result;
}

/**
 * popBack
 * Takes in ptr to a list
 * Remove and free node at the back of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */
int popBack(LIST *list)
{
	if (!list) return -1; // woops somethig is bad :( 
	
	if (list->size == 0) return 0;

	int result = -1;
	NODE *t = list->tail; // get tail
	if (list->head != list->tail) // if head and tail is NOT same
		list->tail = t->prev; // move the tail to prev node
	list->tail->next = NULL; // make new or current tail's next to NULL
	if (t->data) // data, are you there?
		result = t->data; // yes, I am 
	my_free(t); // RIP my friend
	list->size--; // my friend is gone. we have no size-1
	return result;
}


