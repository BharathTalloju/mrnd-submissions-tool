/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int return_integer_part_in_reverse(float number);

void number_to_str(float number, char *result,int afterdecimal){
	int writer = 0;
	int integer_part = return_integer_part_in_reverse(number);

	number = number - (int)number;
	printf("Number = %f\n", number);
	while (integer_part) {
		result[writer++] = '0' + (integer_part % 10);
		integer_part = integer_part/10;
	}

	if(afterdecimal){
		result[writer++] = '.';

		while (afterdecimal) {
			printf("\nnumber writing = %f\n",number*10 );
			result[writer++] = '0' + (int)(number * 10);
			number = number*10 - (int)(number*10);
			afterdecimal--;
		}
	}
	result[writer] = '\0';


}

int return_integer_part_in_reverse(float number){
	int n = number;
	int result = 0;

	while (n) {
		result = result*10 + (n%10);
		n /= 10;
	}

	return result;

}

int main(int argc, char const *argv[]) {

	float number = 524.7865;
	int afterdecimal = 2;
	char str[50];

	number_to_str(number,str, afterdecimal);
	printf("%f = %s",number,str );
	return 0;
}
