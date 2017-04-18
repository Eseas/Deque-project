#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include "User_Data_Type_Deque.h"

#include <stdlib.h>
#include <stdio.h>


typedef struct dequeWhole
{
	struct dequeNode *head;
	struct dequeNode *tail;
}* deque;


struct dequeNode
{
	struct dequeNode *prev;
	struct dequeNode *next;
	userTypeDeque storedData;
};


deque createDeque();
int pushFrontDeque (deque, userTypeDeque);
int pushBackDeque (deque, userTypeDeque);
int popFrontDeque (deque, userTypeDeque *);
int popBackDeque (deque, userTypeDeque *);
int checkEmptyDeque (deque);
int checkFullDeque (deque);
int countElementsDeque (deque);
int deleteDeque (deque);
int valueFrontDeque (deque, userTypeDeque *);
int valueBackDeque (deque, userTypeDeque *);


#endif // DEQUE_H_INCLUDED
