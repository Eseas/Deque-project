#include "deque.h"



deque createDeque()
{
	struct dequeWhole *dn = ( struct dequeWhole * ) malloc ( sizeof ( struct dequeWhole ) );

	dn->head = NULL;
	dn->tail = NULL;

	return dn;
}



int pushFrontDeque (deque dn, userTypeDeque data)
{
	struct dequeNode *node;
	if (!(node = ( struct dequeNode * ) malloc ( sizeof ( struct dequeNode ) ) ) ) return 0;

	if (dn->head != NULL) dn->head->prev = node;		/* Assigning an address of this node to last used head */
	/* If there are elements */

	node->storedData = data;
	node->prev = NULL;
	node->next = dn->head;

	dn->head = node;

	if (dn->tail == NULL) dn->tail = dn->head;

	return 1;
}



int pushBackDeque (deque dn, userTypeDeque data)
{
	struct dequeNode *node;
	if (!(node = ( struct dequeNode * ) malloc ( sizeof ( struct dequeNode ) ) ) ) return 0;

	if (dn->head != NULL) dn->tail->next = node;		/* Assigning an address of this node to last used tail */
	/* If there are elements */

	node->storedData = data;
	node->prev = dn->tail;
	node->next = NULL; 	/* It'll be assigned an address if more than one "pushBack" function is applied. */

	dn->tail = node;

	if (dn->head == NULL) dn->head = dn->tail;

	return 1;
}


int popFrontDeque (deque dn, userTypeDeque* frontData)
{
	if (0 == countElementsDeque(dn) )
	{
		return 0;
	}

	*frontData = dn->head->storedData;

	struct dequeNode * toFree = dn->head;

	dn->head = dn->head->next;

	free(toFree);


	return 1;
}



int popBackDeque(deque dn, userTypeDeque* backData)
{
	if (0 == countElementsDeque(dn) )
	{
		return 0;
	}

	*backData = dn->tail->storedData;

	struct dequeNode * toFree = dn->tail;

	dn->tail = dn->tail->prev;

	free(toFree);

	return 1;
}



int countElementsDeque (deque dn)
{
	int q = 0;

	struct dequeNode *node = dn->head;

	while (node != NULL)
	{
		q++;
		node = node->next;
	}

	return q;
}



int checkEmptyDeque (deque dn)
{
	if( 0 == countElementsDeque(dn) ) return 1;
	else return 0;
}

int checkFullDeque (deque dn)
{
	return 0;
}



int valueFrontDeque (deque dn, userTypeDeque* frontData)
{
	if ( 0 == countElementsDeque(dn) )
		return 0;

	*frontData = dn->head->storedData;

	return 1;
}



int valueBackDeque (deque dn, userTypeDeque* backData)
{
	if ( 0 == countElementsDeque(dn) )
		return 0;

	*backData = dn->tail->storedData;

	return 1;
}



int deleteDeque (deque dn)
{
	struct dequeNode * toFree;

	while (dn->head != NULL)
	{
		toFree = dn->head;
		dn->head = dn->head->next;

		free(toFree);
	}

	free(dn);

	return 1;
}
