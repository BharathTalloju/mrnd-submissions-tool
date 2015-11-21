/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	
	return NULL;
}

void bubbleSort_LinkedList(struct node* head){
	int wall = 1,current_position = 1;
	int temp;
	int flag;
	struct node *walker = head ;
	
	for(	; walker->next != NULL ; walker = walker->next){
		//first pass to calculate the length of the list
		if((walker->num) > ((walker-next)->num)){		//a[i] > a[i+1]
			//swapping a[i] and a[i+1]
			temp = walker->num;
			walker->num = (walker->next)->num;
			(walker->next)->num = temp;
		}
		wall++;
	}
	for(current_position = 1; current_position < wall ; wall--){
		for(walker = head ; current_position < wall ; walker = walker->next,current_position++){
			if(walker->num > (walker->next)->num){
				temp = walker->num;
				walker->num = (walker->next)->num;
				(walker->next)->num = temp;
			}
		}
	}
}