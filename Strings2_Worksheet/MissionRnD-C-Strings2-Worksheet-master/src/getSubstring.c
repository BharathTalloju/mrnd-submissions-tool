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

char * get_sub_string(char *str, int i, int j){
    char *result = NULL;
    int writer;

    if(str == NULL){
      return NULL;
    }
    if(j<i){
      return NULL;
    }
    if(j < 0 || i<0 || j < i){
      return NULL;
    }

    result =(char*)calloc(j-i+2, sizeof(char));
    for(writer = 0; i<=j ; i++, writer++){
      result[writer] = str[i];
      if(result[writer] == '\0'){
        return result;
      }
    }

    return result;
}
