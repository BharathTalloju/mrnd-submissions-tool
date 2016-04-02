/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->211
	->22
	So total number of ways is 4

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include <stdlib.h>
#include <stdio.h>

void my_test(int steps, int expected, int test_no);


int get_steps(int s)
{
	if(s<= 0){
		return 0;
	}
	return get_steps_recursive(s, 1);
}

int get_steps_recursive(int s, int is_first_call)
{
	static int count = 0;

	if(is_first_call){
		count = 0;
	}
	if(s<0){
		return -1;
	}
	if(s == 0){
		count++;
	}
	if(s > 1){
		get_steps_recursive(s-2, 0);
	}

	get_steps_recursive(s-1, 0);


	return count;
}

//Test Driver
int main(int argc, char const *argv[]) {

	//Test1
	{
		my_test(4, 5, 1);
	}

	//Test2
	{
		my_test(0, 0, 2);
	}

	//Test3
	{
		my_test(1, 1, 3);
	}

	//Test4
	{
		int inputs[6] = { 3, 5, 7, 9, 10, 12 };
		int answers[6] = { 3, 8, 21, 55, 89, 233 };
		int i = 0;

		for( ; i<6 ; i++){
			my_test(inputs[i], answers[i], 4);
		}
	}
	return 0;
}

void my_test(int steps, int expected, int test_no){

	if(get_steps(steps) == expected){
		printf("Test%d passed\n", test_no);
	}
	else{
		printf("Test%d failed for steps = %d,\t expected = %d, your result = %d\n", test_no, steps, expected, get_steps(steps));
	}
}
