/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int start_marker=0,int end_marker = 1;
	
	strrev(input,0,len-1);
	
	while(start_marker < len){
		while(input[end_marker] != ' '){
			end_marker++;
		}
		strrev(input,start_marker,end_marker);
		start_marker = end_marker + 1;
	}
}

int strrev(char *s,int start,int last){
	char temp;
	
	while(start > last){
		temp = s[start];
		s[start] = s[last];
		s[last] = temp;
	}
}