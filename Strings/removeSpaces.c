/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <stdlib.h>

char *removeSpaces(char *str){
  int writer = 0, reader = 0;
  int spaces = 0;

  for( ; str[reader] != '\0' ; reader++, writer++){
    while (str[reader] == ' ') {
      reader++;
    }
    str[writer] = str[reader];
    //printf("After removing space: %s\n",str );
  }
  str[writer] = '\0';
  return str;
}

//Test Driver

int main(int argc, char const *argv[]) {

  //Test1
  {
    char str1[] = "";
    if(compareStrings(str1, removeSpaces(str1))){
      printf("\nTest1 passed\n");
    }
    else{
      printf("Test1 Failed\n" );
    }
  }

  //Test2
  {
    char str1[] = "123";
    if(compareStrings(str1, removeSpaces(str1))){
      printf("Test2 passed\n");
    }
    else{
      printf("Test2 Failed\n" );
    }
  }

  //Test3
  {
    char str1[] = "12 w 2e     we  2 3     ";
    if(compareStrings(removeSpaces(str1), "12w2ewe23")){
      printf("Test3 passed\n" );
    }
    else{
      printf("Test3 Failed\n" );
      printf("Expected = %s, Actual = %s\n","12w2ewe23", str1 );
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
