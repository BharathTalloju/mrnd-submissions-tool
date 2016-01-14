/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
}NODE;

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
    NODE* result = NULL;
  NODE *temp;
  
  if(head1 == NULL){
    return head2;
  }
  if(head2 == NULL){
    return head1;
  }
  
  if((head1-> value) <= (head2-> value)){
    result = head1;
    head1 = head1-> next;
  }
  else{
    result = head2;
    head2 = head2-> next;
  }
  temp = result;
  while(head1 && head2){
    if((head1-> value) <= (head2-> value)){
      result-> next = head1;
      result = head1;
      head1 = head1-> next;
    }
    else{
      result-> next = head2;
      result = head2;
      head2 = head2-> next;
    }
    
    
  }
  result-> next = NULL;
  if(head1){
    result->next = head1;
  }
  if(head2){
    result-> next = head2;
  }
  
  return temp;
  
}
