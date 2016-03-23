/*
OVERVIEW: Given a string, Return the substring of the main string from i index to j index
Indexes start from 0,ith letter and jth letter are included
E.g.: Input: "get_sub_string("abcdefgh",2,5) , Output: "cdef"

INPUTS: A string.

OUTPUT: return substring from [i,j]

INPUT2: I will Code for Mission RnD , 2,10
OUTPUT2:will Code

NOTES: Check Null Strings ,Include stddef for NULL if needed.Create a New string and return it ,dont modfiy
original String
*/

#include <stdio.h>
#include <stdlib.h>

int compareStrings(char *str1, char *str2);

char * get_sub_string(char *str, int i, int j){
    char *result = NULL;
    int writer;

//    printf("i  %d, j = %d\n" );
    if(str == NULL){
      return NULL;
    }

    if(j < 0 || i<0 || j < i){
      return NULL;
    }

    result =(char*)calloc(j-i+2, sizeof(char));
    for(writer = 0; i<=j ; i++, writer++){
      result[writer] = str[i];
      if(result[writer] == '\0'){
//        printf("i,j = %d, %d, str = %s, Result = %s\n",i, j,str, result );
        return result;
      }

    }
    result[writer] = '\0';
//    printf(" str = %s, Result = %s\n",str, result );
    return result;
}
//Test Driver
int main(int argc, char const *argv[]) {
  //Test 1
  {
    char str[] = "abcdefgh";
    int i = 0;
    int j = 2;
    int k;

    if(compareStrings(str+2, get_sub_string(str, 2,7))){
      printf("Test1 Passed\n" );
    }
  return 0;
  }
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
