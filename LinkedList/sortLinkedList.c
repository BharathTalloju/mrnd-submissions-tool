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
	typedef struct walker{
		int position;
		struct node* link_to_node;
	}WALKER;
	WALKER walker1,walker2;
	int wall;
	int temp;
	
	walker1.position = 1;
	walker2.position = 1;
	for(walker1.link_to_node = head ; walker2.link_to_node != NULL ; walker1.link_to_node = (walker2.link_to_node)->next , walker1.position = walker2.position + 1){
		wall = walker1.position;
		
		walker2.link_to_node = (walker1.link_to_node)->next;
		(walker2.position) = (walker1.position) + 1;
		
		if(walker2.link_to_node != NULL){
			wall = walker2.position;
			
			if((walker2.link_to_node)->num  <  (walker1.link_to_node)->num){	//if a[i+1] < a[i] 
			//swapping a[i] and a[i+1] 
				temp = (walker1.link_to_node)->num;
				(walker1.link_to_node)->num = (walker2.link_to_node)->num;
				(walker2.link_to_node)->num = temp;
			}
		}
		else{
			break;
		}
		
	}
}