/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include <stdlib.h>

char KthIndexFromEnd(char *str, int K) {
	int i = 0, j = K;
    
    
	if(!str)
	   return '\0';
    while(str[j] != '\0'){
        j++;
        i++;
    }
    return str[i];
}

//Test Driver
int main(){
    char c = KthIndexFromEnd("123456",3);
    printf("%c\n", c);
}