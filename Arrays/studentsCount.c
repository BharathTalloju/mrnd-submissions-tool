
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	int i = 0, j = len - 1;
	//ERROR CASES
	if((!Arr) || (len <= 0)){
		return NULL;
	}
	if((score > Arr[j]) || (score < Arr[0])){
		//Error
		return NULL;
	}
	
	while(Arr[i] != score){
		i++;
		if(i == len){
			return NULL;
		}
	}
	*lessCount = i;
	
	while(Arr[i] == score){
		i++;
	}
	*moreCount = len - i;
	
	return 1;
}

//Test Driver

int main(){
	int Arr[] = {10,20,20,30,30,35,36,40,50,50,50,50,60,61,61,70};
	int len = 16;
	int score = 40;
	int lessCount = 0,moreCount = 0;
	
	if(studentsCount(Arr,len,score,&lessCount,&moreCount))
		printf("lesscount  =  %d ;   moreCount = %d\n",lessCount,moreCount);
	else
		fprintf(stderr,"Ha");
}
