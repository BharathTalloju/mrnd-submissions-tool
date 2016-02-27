/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	NODE *walker_x = NULL;	//checks every node
	NODE *walker_2x = NULL;	//checks every alternative node
	
	walker_x = head;
	walker_2x = head;
	
	//																																while(head){
	//																																	printf("%f -> ",head -> value);
	//																																	head = head->next;
	//																																}
	
	if(walker_x == NULL){
		//List is empty
		return 0;
	}
	
	while(1){
		walker_2x = walker_2x -> next;
		if(walker_2x == NULL){
			//Odd no. of nodes
																																		//printf("\nreturnong %f\n",walker_x -> value);
			return walker_x -> num;
		}
		
		walker_2x = walker_2x -> next;
		if(walker_2x == NULL){
			//even no. of nodes
			float median;
			
			median = ((walker_x -> num) + (walker_x -> next)->num ) / 2;
																																			//printf("\nReturning %f",median);
			return median;
		}
		
		walker_x = walker_x -> next;
	}
}
