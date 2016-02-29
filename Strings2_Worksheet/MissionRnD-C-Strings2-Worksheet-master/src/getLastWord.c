/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include <stdio.h>

char * get_last_word(char * str){
	int start_index = 0;
	int null_finder = 0;
	char *last_word = NULL;

	if(str == NULL){
		return NULL;
	}

	for( ; str[null_finder] != '\0' ; null_finder++){
		if (str[null_finder] == ' '){
			start_index = null_finder+1;
		}
	}

	last_word = (char *)calloc(null_finder - start_index + 1, sizeof(char));
	null_finder = 0;
	for( ; str[start_index] != '\0' ; last_word[null_finder++] = str[start_index++]);
	str[start_index] = '\0';
	return last_word;
}

//TEst Driver
int main(int argc, char const *argv[]) {
	//Test1
	{
		char str[] = "I will do this without using String Library";
		if(compareStrings("Library", get_last_word(str))){
			printf("Test1 Passed\n");
		}
		else{
			printf("Test2 Failed\n" );
		}
	}

	//Test2
	{
		char str[] = "";
		if(compareStrings("",get_last_word(str))){
			printf("Test2 Passed\n" );
		}
		else{
			printf("Test2 Failed\n" );
		}
	}

	//Test3
	{
		char str[] = "a";
		if(compareStrings("a", get_last_word(str))){
			printf("Test3 Passed\n" );
		}
		else{
			printf("Test3 Failed, required = %s, Actual = %s\n","a", get_last_word(str) );
		}
	}

	//Test4
	{
		char str[] = "	asd";
		char req[] = "asd";
		char *actual = get_last_word(str);
		if(compareStrings(req, actual)){
			printf("Test4 Passed\n" );
		}
		else{
			printf("Test4 Failed \nActual   = %s \nrequired = %s\n",actual, req );
		}
	}
	return 0;
}

int compareStrings(char *str1, char *str2){
  int i ;

  for(i = 0 ; str1[i] != '\0' || str2[i] != '\0' ; i++ ){
    if(str1[i] != str2[i]){
      return 0;
    }
  }
  return 1;
}
