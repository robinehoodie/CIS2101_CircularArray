#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Person.h"


int main(){
	Person A;
    A= createPerson("rob", 'm', "cebu");
    displayPersonInfo(A);
    
    printf("\n\n/********* Static ArrayList *******/\n");
    
    printf("\n\n/********* Dynamic ArrayList Version 1 *******/\n");
    PersonDynamicArrayList C;
    init_DAL(&C);
 
    insert_first_DAL(&C, A);
    
  
      
    display_DAL(C);
    
    printf("\n\n/********* Dynamic ArrayList Version 2 *******/");
    
    printf("/********* Linked List *******/");
    
    printf("/********* Cursor Based *******/");
	return 0;
}

