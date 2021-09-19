#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Exercise1.h"

int main(void) 
{
    // To do code logic here.
    CircularArrayQueue list;
    bool retval=false;
    Type dummy;
    list= create_array_queue();
    
    init_array_queue(&list);
    
    Person A;
    
    printf("/********* Create and 3 Enqueue List *******/\n");
    A= createPerson("rob", 'm', "cebu");
    retval = enqueue(&list, A);
    A= createPerson("bine", 'f', "apas");
    retval = enqueue(&list, A);
    A= createPerson("rob", 'f', "as");
    retval = enqueue(&list, A);
    
    printf("the top list is : ");
     dummy = front(list);
    displayPersonInfo(dummy);
    
    printf("\n\n/********* Dequeue List *******/\n");
    printf("the top list is : ");
     dummy = front(list);
    displayPersonInfo(dummy);
    printf("\nafter dequeueing, the top is: ");
    retval = dequeue(&list);
    dummy = front(list);
    displayPersonInfo(dummy);
    
    
    printf("\n\n/********* Front List *******/\n");
    dummy = front(list);
    displayPersonInfo(dummy);
    
    printf("\n\n/********* Empty *******/\n");
    retval=is_empty(list);
    
    if(retval!=0){
     printf("The list is empty" );
	}else{
		printf("The list is not empty" );
	}
   
    
    printf("\n\n/********* Full *******/\n");
    
      retval=is_full(list);
    
    if(retval!=0){
     printf("The list is full" );
	}else{
		printf("The list is not full" );
	}
    
    printf("\n\n/********* Length of the List*******/\n");
    printf("the length of the list is: %d", get_queue_length(list));
    
    printf("\n\n/********* All Females *******/\n");
	PersonLinkedList temp;
	temp = get_all_females(list);
	
	
    return 0;
}
