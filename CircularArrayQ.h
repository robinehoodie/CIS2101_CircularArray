#ifndef CIRCULARARRAYQ_H
#define CIRCULARARRAYQ_H

#include <stdbool.h>
#include "Person.h"
#define MAX 10

typedef Person Type;

typedef struct {
    Type data[MAX];
    int front;
    int rear;
} CircularArrayQueue;

/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue()
{
		CircularArrayQueue list;

		return list;
}

/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list)
{
		list->front = 1 ;
		list->rear=0;
		
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Type p)
{
	bool retval = false;
	
	if (list->front != ((list->rear + 2) % MAX)){
	     list->rear++;
		 list->data[list->rear] = p;
     	retval = true;
     }
     
     return retval;
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list)
{
	bool retval = false;
	 if (list->front != ((list->rear +1) % MAX)){
       list->front++;
       retval = true;
    }
    
    return retval;
    
}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list)
{
	bool retval = false;
	if(list.front == ((list.rear +1) % MAX)){
		retval =true;
	}
	
	return retval;
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list)
{
	bool retval= false;
	if (list.front == ((list.rear + 2) % MAX)){
     	retval = true;
     }
     
     return retval;
}

/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list)
{
	Type dummy = {"empty", 'D', "dummy"};
	if(list.front != ((list.rear +1) % MAX)){
		dummy = list.data[list.front];
	}
	return dummy;
}

#endif
