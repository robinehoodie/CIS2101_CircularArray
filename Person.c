#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Person.h"


int main(){
	Person A;
    A= createPerson("rob", 'm', "cebu");
    displayPersonInfo(A);
    
    printf("/********* Static ArrayList *******/");
    
    printf("/********* Dynamic ArrayList Version 1 *******/");
    
    printf("/********* Dynamic ArrayList Version 2 *******/");
    
    printf("/********* Linked List *******/");
    
    printf("/********* Cursor Based *******/");
	return 0;
}

