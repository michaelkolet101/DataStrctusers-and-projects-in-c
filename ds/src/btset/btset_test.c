#include <stdio.h> /* printf */ 
#include <stddef.h> /* size_t, sizeof */
#include <stdlib.h> /* */
#include <string.h> /* memcpy, memcmp */

#include "btset.h"


/****************Tests declarations********************************************/
static void Scenario_1_Tests_Insert_Find(void);
static void Scenario_2_Tests(void);


/*********************Helpers declarations*************************************/

static int CompareInt(const void *elem1, const void *elem2, const void *param);
/******************************Main********************************************/
int main(void)
{
	Scenario_1_Tests_Insert_Find();
	/*Scenario_2_Tests(); */


	return 0;
}

/***********************Tests Implementation***********************************/
static void Scenario_1_Tests_Insert_Find(void)
{
	btset_ty *my_set = NULL;
	int n = 1;
	int *ptr = &n;
	btset_iter_ty start_iter;
	btset_iter_ty end_iter;
	btset_iter_ty inserted_iter;
	btset_iter_ty find_iter;

	int data_arr1[10] = {6,2,23,7,8,1,1,0,6,12};
	bts_cmp_fnc_ty cmp_func = CompareInt;

	printf("Starting scenarion 1:\n");

	/* create new set */
	my_set = BTSetCreate(cmp_func, ptr);
	my_set != NULL ?
		printf("New sorted set created. \t\tTest Passed\n\n") :
		printf("Failed to create new set. \t\tTest Failed!!\n");

	/* Check if empty */
	BTSetIsEmpty(my_set) == 1 ?
			printf("The set is empty. \t\t\tTest Passed\n") :
			printf("The set is not empy. \tTest Failed!!\n");

/*-------------------     Inserting Elements     --------------------------------*/
	/* Insert first element */
	inserted_iter = BTSetInsert(my_set, &data_arr1[0]);

	/* Check if empty */
	BTSetIsEmpty(my_set) == 0 ?
			printf("The set is not empty. \t\t\tTest Passed\n") :
			printf("The set is empy. \tTest Failed!!\n");

	/* Check if the inserted data is correct */
	*(int *)BTSetGetData(inserted_iter) == data_arr1[0] ? 
			printf("Correct value inserted. \t\tTest Passed\n") :
			printf("Wrong inserted value. \tTest Failed!!\n");

	/* Insert second element - left son to the root*/
	inserted_iter = BTSetInsert(my_set, (void *)&data_arr1[1]);

	/* Check if the inserted data is correct */
	*(int *)BTSetGetData(inserted_iter) == data_arr1[1] ? 
			printf("Correct value inserted. \t\tTest Passed\n") :
			printf("Wrong inserted value. \tTest Failed!!\n");

	/* Insert third element - right son to the root*/
	inserted_iter = BTSetInsert(my_set, &data_arr1[2]);

	/* Check if the inserted data is correct */
	*(int *)BTSetGetData(inserted_iter) == data_arr1[2] ? 
			printf("Correct value inserted. \t\tTest Passed\n") :
			printf("Wrong inserted value. \tTest Failed!!\n");

	/* Insert existind value - bad iterator expected */
	BTSetIsIterBad(BTSetInsert(my_set, &data_arr1[0])) ?
			printf("Bad iter for inserting dup value. \tTest Passed\n") :
			printf("Not a Bad iter. \t\t\tTest Failed\n");


/*-------------------        Find Elements     --------------------------------*/
puts("here");	
	/* Find data from the root */
	find_iter = BTSetFind(my_set, &data_arr1[0]);

	/* Check if the found data is correct */
	*(int *)BTSetGetData(find_iter) == data_arr1[0] ? 
			printf("Correct value found. \t\t\tTest Passed\n") :
			printf("Value not found. \tTest Failed!!\n");

	/* Find data from root's left son */
	find_iter = BTSetFind(my_set, &data_arr1[1]);

	/* Check if the found data is correct */
	*(int *)BTSetGetData(find_iter) == data_arr1[1] ? 
			printf("Correct value found. \t\t\tTest Passed\n") :
			printf("Value not found. \t\tTest Failed!!\n");

	/* Find data from root's right son */
	find_iter = BTSetFind(my_set, &data_arr1[2]);

	/* Check if the found data is correct */
	*(int *)BTSetGetData(find_iter) == data_arr1[2] ? 
			printf("Correct value found. \t\t\tTest Passed\n") :
			printf("Value not found. \t\tTest Failed!!\n");


	/* Find nonexisting value - bad iterator expected */
	BTSetIsIterBad(BTSetFind(my_set, &data_arr1[3])) ?
			printf("Bad iter returned for not found value. \tTestPassed\n") :
			printf("Not a Bad iter. \t\t\tTest Failed\n");

	BTSetDestroy(my_set);
}


/****************************Helpers Implementation****************************/

/*0 if equal, 0> if data1 lower then data2, 0< if data1 higher then data2*/
static int CompareInt(const void *data1, const void *data2, const void *param)
{
	UNUSED(param);
	return (*(int *)data1 - *(int *)data2);
}
