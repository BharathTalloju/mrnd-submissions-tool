/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
    int i = 0;
    int spaces_count = 0;
    
    if(!str){
        return '\0';
    }
    while(True){
        if(str[i] == ' '){
            spaces_count++;
        }
        str[i] = str[i + spaces_count];
        if(str[i] == '\0'){
            break;
        }
    }
	
}