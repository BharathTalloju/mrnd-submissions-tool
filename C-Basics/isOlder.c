/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.
INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".
OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.
ERROR CASES: Return -1 if any DOB is invalid.
NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include <stdio.h>

int isOlder(char *dob1, char *dob2) {
	int len1,len2;
	int result = 0;
	
	len1 = length_of(dob1);			
	len2 = length_of(dob2);
	
	result = check_year(dob1,len1,dob2,len2);
	if(result){			//years are not equal. 
		if(result > 0){
			return result;
		}
		else 
			return -1;			//Invalid year
		
	}
	else{
		//Years are equal. Need to check the months
		len1 = length_of(dob1);
		len2 = length_of(dob2);
		result = check_month(dob1,len1,dob2,len2);
		if(result){			//months are not equal. 
			if(result > 0){
			
				return result;
			}
			else 
				return -1;			//Invalid month
		}
	
		else{
		//Months are equal checking days
		len1 = length_of(dob1);
		len2 = length_of(dob2);
		result = check_days(dob1,len1,dob2,len2);
		if(result){			//days are not equal. 
		if(result > 0){		
			return result;
		}
		else if(result < 0)
			return -1;	
		else{
			return 0;
		}
	}
	
	}

}
}

int check_days(char* dob1,int len1,char* dob2,int len2){
	int day1,day2;
	
	day1 = find_day(dob1,len1);
	if((day1>31) || (day1 < 0)){
		return -1;
	}
	
	day2 = find_day(dob2,len2);
	if((day2>31) || (day2 < 0)){
		return -1;
	}
	
	if((day1 < 0) || (day2 < 0)){
		return -1;
	}
	else if((day1 - day2) > 0){
		return 2;
	}
	else if((day1 - day2) < 0){
		return 1;
	}
	else 
		return 0;
}

int find_day(char *day,int len){
	int date = 0;
	int i = 0;
	int digit;
	
	while(i < len){
		digit = day[i] - '0';
		if((digit > 9) || (digit < 0)){
			return -1;
		}
		date = (date*10) + digit ;
		i++;
	}
	
	return date;
	
}

int check_year(char* dob1,int len1,char* dob2,int len2){			//function to compare the years of the DOB
	int year1,year2;
	
	year1 = find_year(dob1,len1);
	year2 = find_year(dob2,len2);
	
	if((year1 < 0) || (year2 < 0)){
		return -1; 		//Invalid year
	}
	else if((year1 - year2)>0){		//year1 is greater i.e. person2 is Older.
		return 2;
	}
	else if((year1-year2) < 0 ){	//person1 is Older
		return 1;
	}
	else
		return 0;					//years are equal 
}

int find_year(char* dob,int len){
	int year = 0;
	int counter_for_zeroes = 0;
	int digit ;
	int i = 0;
	
	len--;
	for( ; dob[len] != '-' ; len--){ // reading from right till '-' is encountered
		digit = dob[len] - '0' ; 	//changing char to its int value
		if( (digit < 0) || (digit > 9) ){
			return -1;		//Invalid year
		}
		
		while(counter_for_zeroes){
			digit *= 10;
			counter_for_zeroes --;
		}
		counter_for_zeroes = ++i;
		
		year = digit + year;
		//counter_for_zeroes++;
	}
	dob[len] = '\0';
	
	return year;
}

int check_month(char* dob1,int len1,char* dob2,int len2){
	int month1,month2;
	
	month1 = find_year(dob1,len1);
	if(month1 > 12){
		return -1;
	}
	
	month2 = find_year(dob2,len2);
	if(month2 > 12){
		return -1;
	}
	
	if((month1 < 0) || (month2 < 0)){
		return -1; 		//Invalid month
	}
	else if((month1 - month2)>0){		// person2 is Older 
		return 2;
	}
	else if((month1-month2) < 0 ){	//person1 is Older
		return 1;
	}
	else
		return 0;	
}

int length_of(char* s){
	int i;
	for(i = 0 ; s[i] != '\0' ; i++);
	return i;
}

//						END

//Test Driver
int main(){
	char a[] = "12-11-1898";
	char b[] = "13-10-1898";
	
	printf("%d",isOlder(a,b));
}