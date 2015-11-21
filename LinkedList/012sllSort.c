/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node *temp = head;
	int count_of_zeroes = 0;
	int count_of_ones = 0;
	
	while(temp != NULL){		//counting the number  0s and 1s
		if(temp->data == 1){
			count_of_ones++;
		}
		else if(temp->data == 0){
			count_of_zeroes++;
		}
		
		temp = temp->next;
	}
	
	temp = head;		
		while(count_of_zeroes){		//placing zeroes in the list
			temp->data = 0;
			temp = temp->next;
			count_of_zeroes--;
		}
		while(count_of_ones){		//placing 1s in the list
			temp->data = 1;
			temp = temp->next;
			count_of_ones--;
		}
		
		while(temp != NULL){		//placing 2s in the list
			temp->data = 2;
			temp = temp->next;
		}
	
	
}