/*

1)Given a BST ,Find its Maximum Height

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input :

    10
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height(struct node *root){

	if(root == NULL){
		return 0;
	}
	else{
		int left = 1 + get_height(root-> left);
		int right = 1 + get_height(root-> right);
		if(left > right){
			return left;
		}
		else{
			return right;
		}
	}
	return 0;
}

int get_sum(struct node *root){
	int sum = 0;
	if(root == NULL){
		return 0;
	}
	else{
		if(root-> left){
			sum  = get_sum(root-> left);
		}
		if(root-> right){
			sum += get_sum(root-> right);
		}
		sum += root-> data;
	}
//	printf("\nAdded %d, returning %d", root-> data, sum);
	return sum;
}

int get_left_subtree_sum(struct node *root){
	//printf("\nLeft");
	if(root == NULL){
		return 0;
	}
	return get_sum(root-> left);
}

int get_right_subtree_sum(struct node *root){
	printf("\nRight");
	if(root == NULL){
		return 0;
	}
	return get_sum(root-> right);
}


//
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

	//test1
	{
		if(get_height(NULL) == 0){
			printf("\nTest1 Passed");
		}
		else{
			printf("Test1 failed");
		}
	}

	//Test2
	{
		struct node root;
		root.left = NULL;
		root.right = NULL;

		if(get_height(&root) == 1){
			printf("\nTest2 Passed");
		}
		else{
			printf("Test2 Failed");
		}

	}

	//Test3 smallHeight
	{
		struct node *root = NULL;
		int nums[20] = {10,5,15};

		for (int i = 0; i < 3; i++){
			root = add_node_spec(root, nums[i]);
		}

		if(get_height(root) == 2){
			printf("\nTest3 Passed");
		}
		else{
			printf("\nTest3 Failed");
		}

	}

	//Test 4 large Height
	{
		struct node *root = NULL;
		int nums[20] = {10,9,8,7,6,5,4,3,2,1,0};

		for (int i = 0; i < 11; i++){
			root = add_node_spec(root, nums[i]);
		}
		if(get_height(root) == 11){
			printf("\nTest4 Passed");
		}
		else{
			printf("\nTest4 Failed");
		}
	}

	//Test get_sum_left
	{
		//NULL Test
		{
			if(get_left_subtree_sum(NULL) == 0){
				printf("\nNull Test Passed");
			}
			else{
				printf("\nNULL Test Failed");
			}
		}

		//small Height
		{
			struct node *root = NULL;
			int nums[20] = {10,5,15};

			for (int i = 0; i < 3; i++){
				root = add_node_spec(root, nums[i]);
			}

			if(get_left_subtree_sum(root) == 5){
				printf("\nsmall Height Test Passed left_sum");
			}
			else{
				printf("\nsmall Height Test Failed left_sum, expected = 15, got = %d", get_left_subtree_sum(root));
			}

			if(get_right_subtree_sum(root) == 15){
				printf("\nsmall Heifgth Testt Passed right_sum");
			}
			else{
				printf("\nsmall Height Test Failed right_sum");
			}
		}

		//Large Height all functions Ctrl-V
		{
			struct node *root = NULL;
			int nums[20] = { 1,2,3,4,5,6,7,8,9,10};

			for (int i = 0; i < 10; i++){
				root = add_node_spec(root, nums[i]);
			}

			int h = get_height(root);
			int ls = get_left_subtree_sum(root);
			int rs = get_right_subtree_sum(root);
			int ans[3] = { 10,0,54};
			int actualans[3] = { h, ls, rs };
			int correct = 0;

			for (int i = 0; i < 3; i++){
				if(ans[i] == actualans[i] ){
					correct++;
				}
				else{
					break;
				}
			}

			if(correct == 3){
				printf("\n Test for large length Passed");
			}
			else{
				printf("\nTest for large length Failed right_sum = %d", get_right_subtree_sum(root));
			}
		}
	}
	return 0;
}
