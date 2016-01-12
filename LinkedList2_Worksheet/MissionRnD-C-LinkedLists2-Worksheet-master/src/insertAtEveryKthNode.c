/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

typedef struct node {
	int num;
	struct node *next;
}NODE;

NODE *insertAtEveryKthNode(NODE *head, int K) {
	
    NODE *walker = head;
    int count ;
    
    if((!head) || (K <= 0)){
        return NULL;
    }
    while(walker){
        count = K;
        
        while((--count) && walker){
            walker = walker-> next;
        }
        
        if(walker){
            NODE *temp = (NODE*)malloc(sizeof(NODE));
            temp-> next = walker-> next;
            walker-> next = temp;
            temp-> num = K;
            walker = temp-> next;
            
        }
        
    }
}

NODE* createNode(int num) {
			NODE *newNode = (NODE*)malloc(sizeof(NODE));
			newNode->num = num;
			newNode->next = NULL;
			return newNode;
}

NODE* createList(int num) {
			NODE *head = createNode(num % 10);
			num /= 10;
			while (num) {
				NODE *newNode = createNode(num % 10);
				newNode->next = head;
				head = newNode;
				num /= 10;
			}
			return head;
}

int main(){
    NODE *list = createList(123456);
    
    insertAtEveryKthNode(list,1);
    while(list){
        printf("%d, ", list-> num);
        list = list-> next;
    }
    printf("\n");
}
