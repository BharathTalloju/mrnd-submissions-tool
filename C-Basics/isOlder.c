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

int isOlder(char *dob1, char *dob2) {
	int len1,len2;
	int result = 0;
	
	len1 = length_of(dob1);			
	len2 = length_of(dob2);
	
	result = check_year(dob1,len1,dob2,len2);
	if(!result){
		if(result > 0){
			printf("%d",result);
			return 0;
		}
		else 
			return -1;			//Invalid year
		
	}
	
}

int check_year(char* dob1,int len1,char* dob2,int len2){			//function to compare the years of the DOB
	int year1,year2;
	
	year1 = find_year(dob1,len1);
	year2 = find_year(dob2,len2);
	
	if((year1 < 0) || (year2 < 0)){
		return -1; 		//Invalid year
	}
	else if(year1 - year 2){
		
	}
}

int find_year(char* dob,int len){
	int year = 0;
	int counter_for_zeroes = 0;
	int digit ;
	
	len--;
	for( ; dob[len] != '-' ; len--){
		digit = dob[len] - '0' ;
		if( (digit < 0) || (digit > 9) ){
			return -1;		//Invalid year
		}
			
		while(counter_for_zeroes){
			digit *= 10;
		}
		year = digit + year;
		counter_for_zeroes++;
	}
	dob[len] = '\0';
	
	return year;
}

int length_of(char* s){
	int i;
	for(i = 0 ; s[i] != '\0' ; i++);
	return i;
}