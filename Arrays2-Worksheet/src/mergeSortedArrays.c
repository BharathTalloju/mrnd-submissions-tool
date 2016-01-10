/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <assert.h>

#define and &&

typedef struct transaction {
	int amount;
	char date[11];
	char description[20];
}TRANSACTION;

TRANSACTION *mergeSortedArrays(TRANSACTION *A, int ALen, TRANSACTION *B, int BLen) {
    int i = 0,j = 0;
    int k = 0;
    TRANSACTION *merged_statement = NULL;
    
    if(!A){
        return B;
    }
    if(!B){
        return A;
    }
    
    
    merged_statement = (TRANSACTION*)calloc(ALen + BLen, sizeof(TRANSACTION));
    
    while(i < ALen && j < BLen){
        if(isGreater((B[j]).date, (A[i]).date)){
            merged_statement[k++] = B[j++];
        }
        else{
            merged_statement[k++] = A[i++];
        }
        
    }
    while(i < ALen){
        merged_statement[k++] = A[i++];
    }
    while(j < BLen){
        merged_statement[k++] = B[j++];
    }
	return merged_statement;
}
int isGreater(char *key, char *date){
    //Return 1 if date > key
	int parsed_key[3];
	int parsed_date[3];
    int count = 3;
    
	parse_date(key, parsed_key);
    parse_date(date, parsed_date);
    
    while(count){
        if(parsed_date[count-1] > parsed_key[count - 1]){
            return 1;
        }
        if(parsed_date[count-1] < parsed_key[count - 1]){
            return 0;
        }
        count--;
    }
    return 0;   //Equal dates
}

void parse_date(char *date, int *parsed_date){
	//Assuming all the dates are valid
	int count = 3;
	int i = 0;

	while(count){
		int number = 0;
		while(date[i] != '-' and date[i] != '\0'){
			number = number * 10  + (date[i] - '0');
			i++;
		}
        parsed_date[3-(count--)] = number;
        i++;
	}
}


//Test Driver
int main(){
    //Test1
    TRANSACTION *merged_statement = mergeSortedArrays(NULL, 2, NULL, 3);
    printf("\nStatement1: NULL");
    printf("\nStatement12: NULL");
    printf("\nResult : %s",(!merged_statement) ? "NULL" : "Failed");
    
    //Test2
    {
        TRANSACTION A[5] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 40, "21-05-2006", "Fourth" }, { 50, "29-11-2007", "Fifth" } };
        TRANSACTION *merged_statement = mergeSortedArrays(A, 5, NULL, 3);
        assert(merged_statement == A);
    }
    //Test3
    {
        TRANSACTION A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
        TRANSACTION B[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
        TRANSACTION *merged_statement = mergeSortedArrays(A,3,B,3);
        int i ;
        printf("\nTest3");
        for(i = 0 ; i < 6 ; i++){
            display(merged_statement[i]);
        }
    }
}

display(TRANSACTION s){
    printf("\n%d, %s, %s",s.amount, s.date, s.description);
}