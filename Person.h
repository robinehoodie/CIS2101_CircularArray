#ifndef PERSON_H
#define PERSON_H

#define MAX_LIST 20
#define MAX_VSPACE 30

typedef char String[30];

typedef struct {
    String name;
    char sex;
    String city;
} Person;

typedef struct {
    Person data[MAX_LIST];
    int count;
} PersonStaticArrayList;

typedef struct {
    Person *data;
    int count;
    int max;
} PersonDynamicArrayList, *PersonDynamicArrayListPointer;

typedef struct node{
    Person elem;
    struct node *next;
} PersonNode, *PersonLinkedList;

typedef int Position;
typedef int PersonCusorBasedList;

typedef struct {
    Person elem;
    Position next;
} CNode;

typedef struct {
    CNode data[MAX_VSPACE];
    Position avail;
} VSpace;


Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}


/* Static Array List*/
void init_SAL(PersonStaticArrayList *list)
{
	list->count=0;
}
void insert_first_SAL(PersonStaticArrayList *list, Person p)
{
	int x;
	
	if(list->count < MAX_LIST){
		for(x=list->count-1; x>0; x--){
			list->data[x]= list->data[x-1];
		}
		list->data[x]=p;
		list->count++;
	}
}
void insert_last_SAL(PersonStaticArrayList *list, Person p)
{
	if(list->count < MAX_LIST){
		list->data[list->count++] = p;
	}
}
void insert_at_SAL(PersonStaticArrayList *list, Person p, int index)
{
	int x, y;
	if(list->count < MAX_LIST && list->count >= index){
		for(x=list->count; x>index ; x--){
			list->data[x] = list->data[x-1];	
		}
		list->data[x]= p;
		list->count++;
		
	}
}
void delete_first_SAL(PersonStaticArrayList *list)
{
	int x;
	
	if(list->count > 0){
		for(x=0; x<list->count-1 ; x++){
			list->data[x]=list->data[x+1];
		}
		list->count--;
	}
	
}
void delete_last_SAL(PersonStaticArrayList *list)
{
	if(list->count > 0){
		list->count--;
	}
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex) 
{
	int x=0, y; 
	while(x<list->count){
		if( toupper(list->data[x].sex) == toupper(sex) ){
			for(y=x; y<list->count-1; y++){
				list->data[y]=list->data[y+1];
			}
			list->count--;
		}else{
			x++;
		}
	}
}// all ocurrences
void display_SAL(PersonStaticArrayList list)
{
	while(list.count > 0){
		printf("%s | %c | %s" , list.data[list.count--].name, list.data[list.count--].sex, list.data[list.count--].city);
	}
}

/* Dynamic Array List - v1 
 * Doubles the maximum size of the array when full.
 */
void init_DAL(PersonDynamicArrayList *list)
{
	list->data = (Person *)malloc(sizeof(Person)*MAX_LIST);
	list->count = 0;
	list->max = MAX_LIST;
	
}
void insert_first_DAL(PersonDynamicArrayList *list, Person p)
{
	int x;
	
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}
	
	for(x=list->count-1; x>0; x--){
		list->data[x]= list->data[x-1];
	}
		list->data[x]=p;
		list->count++;
	
}
void insert_last_DAL(PersonDynamicArrayList *list, Person p)
{
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}
	
	list->data[list->count++]=p;
}
void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index)
{
	int x;
	
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}

	if(list->count >= index){
		for(x=list->count; x>index ; x--){
		list->data[x] = list->data[x-1];	
		}
		list->data[x]= p;
		list->count++;
	}
}
void delete_first_DAL(PersonDynamicArrayList *list)
{
	int x;
	
	if(list->count > 0){
		for(x=0; x<list->count-1 ; x++){
			list->data[x]=list->data[x+1];
		}
		list->count--;
	}
}
void delete_last_DAL(PersonDynamicArrayList *list)
{
	if(list->count > 0){
		list->count--;
	}
}
void delete_by_city_DAL(PersonDynamicArrayList *list, String city)
{
	int x=0, y; 
	for(x=0; x<list->count && strcmp(list->data[x].city, city) != 0 ; x++ ){}
	for(y=x; y<list->count-1; y++){
				list->data[y]=list->data[y+1];
			}
			list->count--;
	
}
 // first ocurrence
void display_DAL(PersonDynamicArrayList list)
{
	while(list.count > 0){
		printf("%s | %c | %s" , list.data[list.count--].name, list.data[list.count--].sex, list.data[list.count--].city);
	}
}

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list)
{
	*list = (PersonDynamicArrayListPointer)malloc(sizeof(PersonDynamicArrayList));
	(*list)->data = (Person *)malloc(sizeof(Person)*MAX_LIST);
	(*list)->count = 0;
	(*list)->max = MAX_LIST;
}
void insert_first_DAL_2(PersonDynamicArrayList *list, Person p)
{
	int x;
	
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}
	
	for(x=list->count-1; x>0; x--){
		list->data[x]= list->data[x-1];
	}
		list->data[x]=p;
		list->count++;
}
void insert_last_DAL_2(PersonDynamicArrayList *list, Person p)
{
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}
	
	list->data[list->count++]=p;
}
void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index)
{
		int x;
	
	if(list->count >= list->max){
		list->max *=2;
		list->data = (Person*)realloc(list->data, sizeof(Person)*list->max);
	}

	if(list->count >= index){
		for(x=list->count; x>index ; x--){
		list->data[x] = list->data[x-1];	
		}
		list->data[x]= p;
		list->count++;
	}
}
void delete_first_DAL_2(PersonDynamicArrayList *list)
{
	int x;
	
	if(list->count > 0){
		for(x=0; x<list->count-1 ; x++){
			list->data[x]=list->data[x+1];
		}
		list->count--;
	}
}
void delete_last_DAL_2(PersonDynamicArrayList *list)
{
	if(list->count > 0){
		list->count--;
	}
}
void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name)
{
	int x=0, y=-1, z; 
	for(x=0; x<list->count; x++ ){
		if( strcmp(list->data[x].name,name) != 0 ){
			y=x;
		}
	}
	if(y != -1){
		for(;y<list->count-1; y++){
				list->data[y]=list->data[y+1];
			}
			list->count--;
	}
	
} // last ocurrence

void display_DAL_2(PersonDynamicArrayList list)
{
	int x;
	while(list.count > 0){
		x= list.count;
		printf("%s | %c | %s" , list.data[x].name, list.data[x].sex, list.data[x].city);
	}
}

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p)
{
	PersonLinkedList temp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	if(temp!=NULL){
		temp->elem = p;
		temp->next = *list;
		*list= temp;
	}
}

void insert_last_LL(PersonLinkedList *list, Person p)
{
	PersonLinkedList *trav , temp = (PersonLinkedList)malloc(sizeof(PersonNode));

	for(trav=list; *trav!=NULL; trav=&(*trav)->next){}
	
	if(temp!=NULL){
		temp->elem = p;
		temp->next= NULL;
		*trav= temp;
	}
	
}
void insert_after_LL(PersonLinkedList *list, Person p, String name)
{
	PersonLinkedList *trav , temp = (PersonLinkedList)malloc(sizeof(PersonNode));
	
	for(trav=list; *trav!=NULL && strcmp((*trav)->elem.name, name) !=0; trav=&(*trav)->next){}
	if(temp!=NULL){
		temp->elem= p;
		temp->next = *trav;
		*trav= temp;
	}
}

void delete_first_LL(PersonLinkedList *list)
{
	PersonLinkedList temp;
	if(*list!=NULL){
		temp=*list;
		*list= temp->next;
		free(temp);
	}
}
void delete_last_LL(PersonLinkedList *list)
{
	PersonLinkedList temp, *trav;
	for(trav=list; *trav!=NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
	
	if(*trav!=NULL){ 
		temp = *trav;
		*trav = NULL;
		free(temp);
	}
}
void delete_by_city_LL(PersonLinkedList *list, String city)
{
	PersonLinkedList temp, *trav;
	
	for(trav=list; *trav!=NULL; trav=&(*trav)->next){
		if(strcmp((*trav)->elem.city, city)==0){
			temp=*trav;
			*trav= temp->next;
			free(temp);
		}
	}
} // all ocurrences

void display_LL(PersonLinkedList list)
{
	for(;list!=NULL;list=list->next){
		printf("%s | %c | %s", list->elem.name, list->elem.sex, list->elem.city);
	}
}

/* Implement all VSpace conncept and Cusor Based List*/
void init_vspace(VSpace *vs)
{
	int x;
 	for(x=0; x<MAX_VSPACE ; x++){
 		vs->data[x].next= x-1;
	 }
	 vs->avail=x-1;
}

Position alloc_space(VSpace *vs)
{
	Position retval= vs->avail;
	if(vs->avail != -1)
	{
		vs->avail = vs->data[retval].next;
	} 
 	return retval;
}

void free_space(VSpace *vs, Position index)
{
	if(index!= -1 && index<MAX_VSPACE){
 		vs->data[index].next= vs->avail;
 		vs->avail = index;
	 }
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p)
{
	Position alloc= alloc_space(vs);
	if(alloc!=-1){
		vs->data[alloc].elem = p;
 		vs->data[alloc].next = *list;
 		*list=alloc;
	}

}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p)
{
	Position alloc= alloc_space(vs);
	PersonCusorBasedList *trav;
	
	if(alloc!=-1){
	for(trav=list; *trav!=-1; trav=&vs->data[*trav].next){}
		vs->data[alloc].elem = p;
		vs->data[alloc].next= -1;
		*trav= alloc;
	}
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index)
{
	Position alloc = alloc_space(vs);
	PersonCusorBasedList * trav;
	
	if( alloc !=-1){
		for(trav=list; *trav!=-1 && *trav!=index; trav= &vs->data[*trav].next){}
		vs->data[alloc].elem=p;
		vs->data[alloc].next= *trav;
		*trav = alloc;
	}
	
}
void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list)
{
	PersonCusorBasedList temp; 
	if(*list!=-1){
		temp= *list;
		*list= vs->data[temp].next;
		free_space(vs,temp);
	}
	
}
void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list)
{
	PersonCusorBasedList *trav, temp;

	if(*list!=-1){
		for(trav=list; vs->data[*trav].next != -1 ; trav=&vs->data[*trav].next){}
		temp= *trav;
		*trav=-1;
		free_space(vs, temp);
	}
}
void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex)
{
	PersonCusorBasedList temp, *trav;
	
	for(trav=list; *trav!=-1; trav=&vs->data[*trav].next){
		if(vs->data[*trav].elem.sex==sex){
			temp=*trav;
			*trav= vs->data[temp].next;
			free_space(vs, temp);
		}
	}
}// all ocurrences
void display_CBL(VSpace vs, PersonCusorBasedList list)
{
	for(; list!=-1; list=vs.data[list].next){
		printf("%s | %c | %s", vs.data[list].elem.name, vs.data[list].elem.sex , vs.data[list].elem.city);
	}
}
#endif
