#ifndef EXERCISE1_H
#define EXERCISE1_H

#include "CircularArrayQ.h"

/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list)
{
	return list.rear - list.front + 1;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list)
{
	PersonLinkedList L , temp;
	Type dum; 
	while(is_empty(list) != true){
			dum = front(list);
			if( toupper(dum.sex) == 'F'){
				insert_first_LL(&L, dum);
			}
			dequeue(&list);
		}
		
	return L;
}

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list)
{
	PersonDynamicArrayList A;
	init_DAL(&A);
	int x, y, limit;
	limit = get_queue_length(*list);
	
	for(x=0; list->front!= (list->rear +1) % MAX && x!=limit ; ){
		if(toupper(list->data[x].sex) == 'M' ){
			insert_first_DAL(&A, list->data[x]);
			list->front = (list->front+1) % MAX;
			limit -- ;
		}else{
			list->data[list->rear+1%MAX]= list->data[list->front];
			list->rear=(list->rear+1) % MAX;
			list->front = (list->front+1) %MAX;
			x++;
		}
	}
		
	
	return A;
}

#endif
