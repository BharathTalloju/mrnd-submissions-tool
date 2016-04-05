/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorderBST(struct node *root, int *arr, int first_call){
	static int i = 0;
	if(first_call){
		i = 0;
	}
	if(root == NULL){
		return;
	}
	inorderBST(root-> left, arr, 0);
	arr[i++] = root-> data;
	printf(" %d at arr[%d], ", arr[i-1], i-1);
	inorderBST(root-> right, arr, 0);
}

void inorder(struct node *root, int *arr){
	inorderBST(root, arr, 1);
}

void preorderBST(struct node *root, int *arr, int flag_first_call){
	static int i = 0;
	if(flag_first_call){
		i = 0;
	}
	if(root == NULL){
		return;
	}

	arr[i++] = root-> data;
	printf("%d at arr[%d], ", arr[i-1], i-1);
	preorderBST(root-> left, arr, 0);
	preorderBST(root-> right, arr, 0);
}

void preorder(struct node *root, int *arr){
	preorderBST(root, arr, 1);
}

void postorderBST(struct node *root, int *arr, int first_call){
	static int i = 0;

	if(first_call){
		i = 0;
		first_call--;
	}
	if(root == NULL){
		return;
	}

	postorderBST(root-> left, arr, 0);
	postorderBST(root-> right, arr, 0);
	arr[i++] = root-> data;
	printf("%d at arr[%d], ", arr[i-1], i-1);
}

void postorder(struct node *root, int *arr){
	postorderBST(root, arr, 1);
}

//Tests

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
		struct node *root = NULL;
		int nums[10] = { 10, 5, 12, 12, 15 };
		int arr[20] = {0};
		int len = 5;

		for (int i = 0; i < 5; i++){
			root = add_node_spec(root, nums[i]);
		}
		printf("\nInorder: \n" );
		inorder(root, arr);

		//for(int i = 0; i< 20 ; i++){
			//printf("%d", arr[i]);
		//}

		printf("\nPreordrer\n" );
		preorder(root, arr);

		//for(int i = 0; i< 20 ; i++){
		//	printf("%d", arr[i]);
		//}

		printf("\nPostorder: \n" );
		postorder(root, arr);
		//for(int i = 0; i< 20 ; i++){
		//	printf("%d", arr[i]);
		//}
	}
	//Test2
	{
		printf("\n\t\t\tTest2\n");
		int arr[2] = {0};
		inorder(NULL, arr);
		preorder(NULL, arr);
	}
	return 0;
}
