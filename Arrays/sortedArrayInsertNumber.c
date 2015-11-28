/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{	
	// Consider num to be a sorted array of length 1, merge both the sorted arrays
	int *result_array = NULL;
	int i = 0;
	
	//ERROR CASES
	if((!Arr) || (len < 0)){
		return NULL;
	}
	
	if(len > 0){
		result_array = (int*)calloc((len+1),sizeof(int));
		
		while(Arr[i] <= num){
			result_array[i] = Arr[i];
			i++;
		}
		result_array[i] = num ;
		while(i < len){
			result_array[i+1] = Arr[i];
		}
		free(Arr);
		return result_array;
		
	}
	else
		return &num;
}