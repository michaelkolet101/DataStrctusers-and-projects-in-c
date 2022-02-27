#include <stdio.h> /* size_t, printf */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcmp */

#include "priorityq.h"


#define UNUSED(x) (void)x;
#define ARRAY_SIZE 5

typedef struct person
{
	char *name;
	size_t age;
} person_ty;


/*******************static function declarations*******************************/

static void TestPriorityQFunctions();

int CompareAges(const void *age1, const void *age2);

static int IsAgeEqual(const void *data, void *param);

/******************************************************************************/

int main(void)      
{	
	TestPriorityQFunctions();
	
	return 0;
}
/*******************static function implementation*****************************/

static void TestPriorityQFunctions()
{
	int number = 0;
	person_ty *person = {NULL};
		
	person_ty family[] = {{"Lisa", 12},
                            {"Homer", 45},
                            {"Maggie", 2}, 
                            {"Marge", 42},
                            {"Bart", 14}};
	
	pq_ty *pq = PQCreate(&CompareAges);
	
    
	
	printf("test create: %s\n", (pq) ? "SUCCESS" 
						  : "malloc failed");
	
	while (number < ARRAY_SIZE)
	{
		PQEnqueue(pq, &family[number]);
		++number;
	}
	

	printf("test peek: %s\n", (family[1].name == ((person_ty *)PQPeek(pq))->name
								&& family[1].age == ((person_ty *)PQPeek(pq))->age) ?
								"SUCCESS" : "FAIL");
	
	person = (person_ty *)PQDequeue(pq);

	printf("test dequeue %s\n", (family[1].name == person->name
								&& family[1].age == person->age) ?
								"SUCCESS" : "FAIL");
	
	printf("priority queue size %s\n", (4 == PQSize(pq)) ? "SUCCESS" : "FAIL");
	
	printf("test is empty: %s\n", (!PQIsEmpty(pq)) ? "SUCCESS" : "FAIL");
	
	printf("test erase: %s\n", (PQErase(pq, IsAgeEqual, &family[2])) ? "SUCCESS": "FAIL");
	
	printf("priority queue size %s\n", (3 == PQSize(pq)) ? "SUCCESS" : "FAIL");
	
	PQClear(pq);
	
	printf("test is clear: %s\n", (PQIsEmpty(pq)) ? "SUCCESS" : "FAIL");
	
	printf("calling destroy priority queue\n");					  
	PQDestroy(pq);					  	
}

/* older to younger */
int CompareAges(const void *data1, const void *data2)
{
	return (((person_ty *)data2)->age - ((person_ty *)data1)->age);
}


static int IsAgeEqual(const void *data, void *param)
{
	return (((person_ty *)data)->age - ((person_ty *)param)->age);
}