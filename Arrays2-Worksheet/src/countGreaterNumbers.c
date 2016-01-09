/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (only one transaction : { 30, "03-03-2005", "Third" })

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
#define and &&

typedef struct transaction {
	int amount;
	char date[11];
	char description[20];
}statement;

int countGreaterDates(statement *Arr, int len, char *date){
    int walker = 0;
    
    for (walker = 0; walker < len ; walker ++){
        if(isGreater(date, (Arr+walker)->date)){
            break;
        }
    }
    return len - walker;
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

//Test Driver and stubs
int main(){
    int i;
    statement Arr[5] = { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } };
    char date[11] = "11-11-2015";
    //first test case
    printf("\n\nStatement Arr: ");
    for(i = 0 ; i < 5 ; i++){
        display(Arr[i]);
    }
    printf("\nDate: %s", date);
    printf("\nResult: %d", countGreaterDates(Arr, 5, date));
    
    {//Second
    statement Arr[]= { { 60, "09-10-2003", "First" }, { 70, "09-10-2003", "Second" }, { 30, "09-10-2003", "Third" }, { 90, "09-10-2003", "Fourth" }, { 10, "09-10-2003", "Fifth" } } ;
    char date[] = "29-11-2007" ;
    printf("\n\nStatement Arr: ");
    for(i = 0 ; i < 5 ; i++){
        display(Arr[i]);
    }
    printf("\nDate: %s", date);
    printf("\nResult: %d", countGreaterDates(Arr, 5, date));
    }
    {
    //Third
     statement Arr[]= { { 60, "09-10-2003", "First" }, { 70, "09-10-2003", "Second" }, { 30, "09-10-2003", "Third" }, { 90, "09-10-2003", "Fourth" }, { 10, "09-10-2003", "Fifth" } } ;
     char date[] = "09-10-2003" ;
     printf("\n\nStatement Arr: ");
    for(i = 0 ; i < 5 ; i++){
        display(Arr[i]);
    }
    printf("\nDate: %s", date);
    printf("\nResult: %d", countGreaterDates(Arr, 5, date));
    }
    
    {//Fourth
     statement Arr[]= { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } } ;
     char date[] = "09-10-2003" ;
     printf("\n\nStatement Arr: ");
    for(i = 0 ; i < 5 ; i++){
        display(Arr[i]);
    }
    printf("\nDate: %s", date);
    printf("\nResult: %d", countGreaterDates(Arr, 5, date));
    }
    
    {//Fifth
     statement Arr[]= { { 60, "09-10-2003", "First" }, { 70, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" }, { 90, "21-05-2006", "Fourth" }, { 10, "29-11-2007", "Fifth" } } ;
     char date[] = "03-03-2005" ;
     printf("\n\nStatement Arr: ");
    for(i = 0 ; i < 5 ; i++){
        display(Arr[i]);
    }
    printf("\nDate: %s", date);
    printf("\nResult: %d", countGreaterDates(Arr, 5, date));
    }
    
    
    
    
}

display(statement s){
    printf("\n%d, %s, %s",s.amount, s.date, s.description);
}