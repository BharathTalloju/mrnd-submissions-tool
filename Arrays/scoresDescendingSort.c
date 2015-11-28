/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	//Error CASES
	if(!students){
		return NULL;
	}
	if(len <= 0){
		return NULL;
	}
	
	if(len == 1){
		//Do nothing
	}
	else{
		quicksort_students(students,0,len-1);
	}
	
	return students;
}

int quicksort_students(struct student *students, int first , int last){
	int left = first + 1, right = last ;
	int pivot = (students[first]).score;
	
	if(first < last){
		while(left < right){
			while((students[left]).score >= pivot){
				left++;
			}
			while((students[right]).score < pivot){
				right--;
			}
			if(left < right){
				swap(students,left,right);
			}
		}
		
		swap(students,first,right);
		quicksort_students(students,first,right - 1);
		quicksort_students(students,right + 1,last);
	}
}

void swap(struct student* students,int x,int y){
	char *temp_name;
	int temp_score;
	int i;
	
	temp_score = students[x].score;
	temp_name = &(students[x].name);
	
	students[x].score = students[y].score;
	students[x].name = &(students[y].name);
	
	students[y].score = temp_score;
	students[y].name = temp_name;
}

//Test Driver
int main(){
	struct student students[] = {
		{"stud1",30},
		{"stu2",10},
		{"stu3",20}
	};
	int len = 3;
	
	scoresDescendingSort(students,len);
	
	display(students,len);
}

void display(struct student *students,int len){
	int i;
	
	printf("{\n")
	for(i = 0 ; i < len ; i++){
		printf("\t { %s , %d }\n",students[i].name,students[i].score);
	}
}