/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	
	if(K <= 0){
		return NULL;
	}
	
	if(K > len){
		return NULL;
	}

	quicksort_students(students,0,len - 1);
	
	return (students + (len - K));
	
	
}

int quicksort_students(struct student *students, int first , int last){
	int left = first + 1, right = last ;
	int pivot = (students[first]).score;
	
	if(first < last){
		while(left < right){
			while((students[left]).score <= pivot){
				left++;
			}
			while((students[right]).score > pivot){
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