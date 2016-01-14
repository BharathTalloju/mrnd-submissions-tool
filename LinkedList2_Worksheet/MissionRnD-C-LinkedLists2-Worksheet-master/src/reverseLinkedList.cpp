/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	return reverse_linkedList(struct node *head, 1);
}

void reverse_linkedList(NODE* head,int flag){
	
	if(head == NULL ){
		return;
	}
	if((head-> next) == NULL){
		return;
	}
	
	reverse_linkedList(head-> next, 0);
	
	(head-> next)-> next = head; 
	if(flag){
		head-> next = NULL;
	}
	
	
}
