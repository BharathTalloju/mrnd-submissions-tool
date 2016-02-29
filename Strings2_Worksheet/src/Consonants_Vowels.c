/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int is_consonant(char ch);

void count_vowels_and_consonants(char *str,int *consonants, int *vowels){
    int i;

    *vowels = 0;
    *consonants = 0;

    if(str == NULL){
      return ;
    }
    for(i = 0; str[i] != '\0' ; i++){
      switch (is_consonant(str[i])) {
        case 1:
          *consonants += 1;
          break;
        case -1:
          *vowels += 1;
          break;
        default:
          break;
      }
    }

}

int is_consonant(char ch){
    char vowels[11] = "aeiouAEIOU";
    int i = 0;

    if (ch < 'A' || ch > 'z'){
      return 0;
    }

    while (i<10) {
      if (vowels[i] == ch){
        return -1;
      }
      i++;
    }


    return 1;
}

//Test Driver
int main(int argc, char const *argv[]) {
  //Test1
  {
    char str[] = "a";
    int consonants = 0 ;
    int vowels = 0 ;
    count_vowels_and_consonants(str, &consonants, &vowels);
    if(vowels == 1 && consonants == 0){
      printf("Test1 passed\n" );
    }
    else{
      printf("Test1 Failed\n" );
    }
  }

  //Test2
  {
    char str[] = "";
    int consonants ;
    int vowels ;
    count_vowels_and_consonants(str, &consonants, &vowels);

    if(vowels == 0 && consonants == 0){
      printf("Test2 passed\n" );
    }
    else{
      printf("Test2 Failed\n" );
    }
  }

  //Test 3
  {
    char str[] = "a .?2343 BCDE mu";
    int consonants ;
    int vowels ;
    count_vowels_and_consonants(str, &consonants, &vowels);

    if(vowels == 3 && consonants == 4){
      printf("Test3 passed\n" );
    }
    else{
      printf("Test3 Failed\n" );
    }
  }

  //Test4
  {
    char *str=NULL;
    int consonants ;
    int vowels ;
    count_vowels_and_consonants(str, &consonants, &vowels);

    if(vowels == 0 & consonants == 0){
      printf("Test4 Passed\n" );
    }
  }
  return 0;
}
