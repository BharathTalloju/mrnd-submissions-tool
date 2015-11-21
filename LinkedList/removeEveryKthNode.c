/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int node_to_be_removed = K;
	struct node* temp = head;
	int step = K,i=1;
	
	while(remove_kth_node(head,K)){
		K += (step-i);
	}
	head = temp;
}

int remove_kth_node(struct node *head, int k){
	int position_counter = 1;
	struct node* temp = NULL;
	
	if(head == NULL){
		return 0;
	}
	k--;
	
	while(position_counter < k){			
		//moving till the k-1 th position
		head = head->next;
		
		if(head == NULL){
			// end of list!
			return 0;
		}
		position_counter++;
	}
	
	
		//removing the kth node fromm the list
		temp = head->next;
		
		head->next = (head->next)->next;
		
		//freeing the memory
		free(temp);
	
	//head = head->next ; //moving the head pointer from k-1 to kth position
	return 1;
	
}

//														END
// Test Driver

struct node * numberToLinkedList(int N) {
	struct node* head = NULL;
	int digit_to_be_inserted;
	struct node* walker = NULL;
	struct node* new = NULL;
	
	if(N<0){
		N = -N;
	}
	
	reverse_number(&N);
	
	while(N){
		digit_to_be_inserted = N % 10;
		N = N / 10 ;

		new = (struct node*) malloc(sizeof(struct node));
		new->data = digit_to_be_inserted;
		new->next = NULL;

		if(head == NULL){
			head = new;
			walker = head;
		}
		else{
			walker->next = new;
			walker = new;
		}
	}
	
	return head;
}

void reverse_number(int* N){
	int result = 0;
	while(*N){
		result = (result*10) + ((*N)%10);
		*N = (*N) / 10;
	}
	*N = result;
}

/* test driver	*/
int main(){
	struct node *head = numberToLinkedList(254782);
	struct node *temp = head;
	
	while(head != NULL){
		printf("%d ,",head->data);
		head = head->next;
	}
	head = temp;
	printf("\n");
	removeEveryKthNode(head,2);
	
	while(head != NULL){
		printf("%d ,",head->data);
		head = head->next;
	}
	
	
}