#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Person.h"


int main(){
    printf("/********* Create Person A B C *******/\n");
    Person A ,B , C;
    A= createPerson("rob", 'm', "cebu");
    B= createPerson("sav", 'f', "apas");
    C= createPerson("rob", 'm', "apas");
    displayPersonInfo(A);
    displayPersonInfo(B);
    displayPersonInfo(C);
    
    
    printf("\n \nNote: First is at the bottom \n");
    
    printf("\n\n/********* Static ArrayList *******/\n");

    PersonStaticArrayList stArr;
    init_SAL(&stArr);
    
    printf("/*insert*/\n");
    insert_first_SAL(&stArr , A);
    insert_last_SAL(&stArr, B);
    insert_at_SAL(&stArr, C, 1);
    display_SAL(stArr);
    printf("\n /*delete first*/\n");
    delete_first_SAL(&stArr);
    display_SAL(stArr);
    
    printf("\n/*delete last*/\n");
    delete_last_SAL(&stArr);
    display_SAL(stArr);
    
    printf("\n /*insert A and B*/\n");
    insert_first_SAL(&stArr , A);
    insert_last_SAL(&stArr, B);
    display_SAL(stArr);
    
    printf("\n/*delete occurence all male*/\n");
    delete_by_sex_SAL(&stArr, 'M');
    display_SAL(stArr);
    
    printf("\n\n/********* Dynamic ArrayList Version 1 *******/\n");
    
    PersonDynamicArrayList dynArrA;
    init_DAL(&dynArrA);
 
    printf("/*insert*/\n");
    insert_first_DAL(&dynArrA, A);
    insert_last_DAL(&dynArrA, B);
    insert_at_DAL(&dynArrA, C, 1);
    display_DAL(dynArrA);
    
    printf("\n /*delete first*/\n");
    delete_first_DAL(&dynArrA);
    display_DAL(dynArrA);
    
    printf("\n/*delete last*/\n");
    delete_last_DAL(&dynArrA);
    display_DAL(dynArrA);
    
    printf("\n /*insert A and B*/\n");
    insert_first_DAL(&dynArrA , A);
    insert_last_DAL(&dynArrA, B);
    display_DAL(dynArrA);
    
    printf("\n/*delete first city*/\n");
    delete_by_city_DAL(&dynArrA, "apas");
    display_DAL(dynArrA);
    

    printf("\n\n/********* Dynamic ArrayList Version 2 *******/\n");
    PersonDynamicArrayList * dynArrB;
    init_DAL_2(&dynArrB);
    
     printf("/*insert*/\n");
    insert_first_DAL_2(dynArrB, A);
    insert_last_DAL_2(dynArrB, B);
    insert_at_DAL_2(dynArrB, C, 1);
    display_DAL_2(*dynArrB);
    
    printf("\n /*delete first*/\n");
    delete_first_DAL_2(dynArrB);
    display_DAL_2(*dynArrB);
    
    printf("\n/*delete last*/\n");
    delete_last_DAL_2(dynArrB);
    display_DAL_2(*dynArrB);
    
    printf("\n /*insert A and B*/\n");
    insert_first_DAL_2(dynArrB , A);
    insert_last_DAL_2(dynArrB, B);
    display_DAL_2(*dynArrB);
    
    printf("\n/*delete last occurence name*/\n");
    delete_by_name_DAL_2(dynArrB, "rob");
    display_DAL_2(*dynArrB);
    
    
    printf("\n\n/********* Linked List *******/\n");
    
    printf("\n\n/********* Cursor Based *******/\n");
	return 0;
}

