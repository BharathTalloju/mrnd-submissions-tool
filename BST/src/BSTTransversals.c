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
}

void postorder(struct node *root, int *arr){
	postorderBST(root, arr, 1);
}

//Tests
int main(int argc, char const *argv[]) {

	//Test1
	{
		
	}
	return 0;
}
