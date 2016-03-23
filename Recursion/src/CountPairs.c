/*
You have been given a string and its length .
Two letters are said to be a pair ,If they are equal and have a character in between them .

Ex : In aba ,a[0] and a[2] are pairs becuase both are 'a' and have one letter 'b' in between .

Ex: In abab , There are two pairs ,Two 'a's and ,Two 'b's .

In abbbb; there are Two pairs , (a[1],a[3]),(a[2],a[4]);

Input : String and length of string
Output : return Total number of pairs Count .

Example Input : count_pairs_wrapper("zzzaz",5);
Example Output : 2

Hint : You can use count_pairs_wrapper as a wrapper function for your original recursive function which might take
more parameters .

NOTE : Donot use any Global Variables
*/

#include <stdio.h>
#include <stdlib.h>

void test_run(int test_num, int required, int actual);

//You can use this function ,for the actual recursion .Think of similar functions for all other problems.
int count_pairs(char *str, int len, int start, int end){
	if(end >= len){
		return 0;
	}
	else{
		if(str[start] == str[end]){
			//printf("%d == %d\n",start, end);
			return 1 + count_pairs(str, len, start+1, end+1);
		}
		else{
			return 0 + count_pairs(str, len, start+1, end+1);
		}
	}
}

int count_pairs_wrapper(char *str,int len){
    //Wrapper function which might call a recursive function ,which might take extra parameters .
		if(len == 0){
			return 0;
		}
		if(len == 1 || len == 2){
			return 0;
		}
		if(str == NULL){
			return 0;
		}

		return count_pairs(str, len, 0, 2);
}

//Test Driver
int main(int argc, char const *argv[]) {
	//Test1
	{
		int pairs=count_pairs_wrapper("", 0);
		test_run(1, 0, pairs);
	}

	//Test2
	{
		int pairs = count_pairs_wrapper("abc", 3);
		test_run(2, 0, pairs);
	}

	//Test3
	{
			int pairs = count_pairs_wrapper("aba", 3);
			test_run(3, 1, pairs);
	}

	//Test4
	{
		int pairs = count_pairs_wrapper("ababa",5);
		test_run(4, 3, pairs);
	}

	//Test5
	{
		int pairs = count_pairs_wrapper("abababababxxxyyy", 16);
		test_run(5, 10, pairs);
	}
	return 0;
}

void test_run(int test_num, int required, int actual){
	if(required == actual){
		printf("Test%d Passed\n", test_num);
	}
	else{
		printf("Test%d Failed\t", test_num);
		printf("required: %d\t actual: %d\n", required, actual);
	}
}
