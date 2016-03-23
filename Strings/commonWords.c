/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	int start_index = 0;
	int end_index = 0;
	char **common_words = NULL;

	for (end_index = 0 ; str1[end_index] != '\0' ; end_index++){
		if (str1[end_index] == ' '){
			if(word_in(str1, start_index, end_index, str2)){
				char *common_word = (char*) calloc(end_index - start_index + 2, sizeof(char));
			}
		}
	}
	return NULL;
}
