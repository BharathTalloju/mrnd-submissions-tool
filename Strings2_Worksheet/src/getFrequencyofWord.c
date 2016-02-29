/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include <stdio.h>
int count_word_in_str_way_1(char *str, char *word){
	int count = 0;
	int reader = 0;
	int present ;

	for(reader = 0 ; str[reader] != '\0' ; reader++){
		int reader2 = 0;
		int temp_reader;
		present = 1;
		for(temp_reader = reader ; word[reader2] != '\0' ; reader2++, temp_reader++){
			if (word[reader2] != str[temp_reader]) {
				present = 0;
				break;
			}
		}
		if(present){
			//printf("[%s] present at %d in [%s]\n",word, reader, str );
			count++;
		}
	}
	return count;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

//Test Driver
int main(int argc, char const *argv[]) {
	//Test1
	{
		char sentences[][100] = { "abababa", "he he", "ab cd ab cd", "    ", "1234 aaaaaaa", "asd324", "yzqwer 23425", "a" };
		char words[][100] = { "ab", "he", "ab cd", " ", "aa", "asd324", "x", "a" };
		int counts[100] = { 3,2,2,4,6,1,0};
		int sc = 7;
		int si = 0;
		for (si = 0; si < sc; si++){
			printf("\n\n\t\t\tTest%d sentence = [%s], word = [%s]\n",si, sentences[si], words[si] );
			int temp_c = count_word_in_str_way_1(sentences[si],words[si]);
			if(temp_c == counts[si]){
				printf("Test%d Passed\n",si );
			}
			else{
				printf("Test%d Failed, Required = %d, Got = %d\n",si, counts[si], temp_c );
			}
		}
	}
	return 0;
}
