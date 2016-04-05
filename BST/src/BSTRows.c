/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is
    6                        <-- Copy this first
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct queue_node{
	struct node *tree_node;
	struct queue_node* next;
};

struct queue_head{
	struct queue_node *front;
	struct queue_node *end;
	int is_empty;
};

int *create_array(struct queue_head *result_queue);
void enqueue(struct queue_head *queue, struct node *element);
struct node *dequeue(struct queue_head *queue);
int *create_array(struct queue_head *result_queue);

int* BSTRighttoLeftRows(struct node* root)
{
	int *result = NULL;
	struct node* temp = NULL ;
	struct queue_head *queue= (struct queue_head*)malloc(sizeof(struct queue_head));
	struct queue_head *result_queue = (struct queue_head*)malloc(sizeof(struct queue_head));

	queue-> front = NULL;
	queue-> end = NULL;

	if(root == NULL){
		return NULL;
	}

	enqueue(queue, root);

	while(!(queue-> is_empty)){
		temp = dequeue(queue);
		enqueue(queue, temp-> right);
		enqueue(queue, temp-> left);
		enqueue(result_queue, temp);
	}

	return create_array(result_queue);
}

void enqueue(struct queue_head *queue, struct node *element){

	if(element == NULL){
		return;
	}
	if(queue-> front == NULL){
		queue-> is_empty = 0;
		queue-> front = (struct queue_node*)malloc((sizeof(struct queue_node)));
		queue-> front-> tree_node = element;
		queue-> front-> next = NULL;
		queue-> end = queue-> front;
		printf("Enqueued %d\n", queue-> end-> tree_node-> data);
		return;
	}
	queue-> end-> next = (struct queue_node*)malloc(sizeof(struct queue_node));
	queue-> end = queue-> end-> next;
	queue-> end-> tree_node = element;
	queue-> end-> next = NULL;
	printf("Enqueued %d\n", element-> data);
}

struct node *dequeue(struct queue_head *queue){
	struct node *return_val = NULL;
	struct queue_node *temp = NULL;

	if(queue-> front == NULL){
		printf("Bug in the code: Check id is_empty is updated\n");
		return NULL;
	}
	if(queue-> front-> next == NULL){
		queue-> is_empty = 1;
		return_val  = queue-> front-> tree_node;
		free(queue-> front);
		queue-> front = NULL;
		queue-> end = NULL;
		printf("Dequeued %d", return_val-> data);
		return return_val;
	}
	else{
		return_val  = queue-> front-> tree_node;
		temp = queue-> front;
		queue-> front = queue-> front-> next;
		free(temp);
		printf("Dequeued %d\n", return_val-> data);
		return return_val;
	}
}

int *create_array(struct queue_head *result_queue){
	int size = 0;
	int i = 0;
	int *result_array = NULL;

	struct queue_node *reader = result_queue-> front;

	printf("\nCreating array");
	while(reader){
		reader = reader-> next;
		size++;
	}
	printf("\nSize of Resultant array = %d", size);
	result_array = (int *)calloc(size, sizeof(int));
	reader = result_queue-> front;

	while(i < size){
		result_array[i++] = reader-> tree_node-> data;
		reader = reader-> next;
	}

	return result_array;
}

//Test Driver
struct node * new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}

int main(int argc, char const *argv[]) {

	//Test1
	{
	int *arr = BSTRighttoLeftRows(NULL);
	if(arr == NULL){
		printf("\nTest1 Passed");
	}
}

//Test2
{
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root->data = 6;
	root->left = NULL;
	root->right = NULL;
	int *arr = BSTRighttoLeftRows(root);
	int ans[1] = { 6 };
	int len = 1;
	for(int i = 0; i<len; i++){
		if(arr[i] != ans[i]){
			printf("Test2 Failed, %d != %d\n", arr[i], ans[i] );
			exit(0);
		}
	}
	printf("Test2 passed\n" );
}

//Test3
{
	struct node *root = NULL;
	int nums[10] = { 10, 5, 12, 12, 15 };
	int *arr = NULL;
	int ans[5] = { 10, 12, 5};
	int len = 3;

	for (int i = 0; i < 3; i++){
		root = add_node_spec(root, nums[i]);
	}
	printf("\nBSt: \n");
	display_BST(root);
	printf("\n");
	arr = BSTRighttoLeftRows(root);
	printf("\nResult_array = ");
	for(int i = 0 ; i<len; i++){
		printf("%d, ",arr[i] );
	}
	for(int i = 0 ; i < len ; i++){
		if(arr[i] != ans[i]){
			printf("Test3 Failed \n");
			exit(0);
		}
	}
	printf("\nTest3 Passed");

}

	//Test4
	{
		struct node *root = NULL;
		int nums[10] = { 50,25,75,30,27,60,99,53,51,57};

		for (int i = 0; i < 10; i++){
			root = add_node_spec(root, nums[i]);
		}

		{
			int *arr = BSTRighttoLeftRows(root);
			int ans[10] = { 50,75,25,99,60,30,53,27,57,51 };
			int len = 10;
			for (int i = 0; i < len; i++){
				if(arr[i] != ans[i]){
					printf("\nTest4 Failed\n");
					exit(0);
				}
			}
			printf("\nTest4 Passed\n");
		}
	}
	return 0;
}

void display_BST(struct node *root){
	if(root == NULL){
		return;
	}
	printf("%d, ", root-> data);
	display_BST(root-> left);
	display_BST(root-> right);
}
