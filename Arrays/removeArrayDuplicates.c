/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

//If the arrangement of the elements in the output array doesn't matter, we can sort the array first
//If not every element is compared with every other element to its right

void * removeArrayDuplicates(int *Arr, int len)
{
	int i;
	int repeats;
	
	quicksort(Arr,0,len-1);
		
	for(i = 0 ; i < len ;  ){
		repeats = 1;
		while(Arr[i] == Arr[i + repeats]){
			repeats++;
		}
		shift_to_left(Arr,i+1,repeats - 1,len);
		len -= repeats;
		i += repeats;
	}
	
	return NULL;
}


void quicksort(int *x,int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

//Test Driver

int main(){
	int i;
	int len = 9;
	
	int Arr[] = {1,2,2,3,4,4,5,5,5};
	
	removeArrayDuplicates(Arr,len);
	
	for( i = 0 ; i < len ; i++){
		printf("%d,",Arr[i]);
		 
	}
}

void shift_to_left(int *Arr,int start,int k,int len){
	int i;
	
	for( i = start ; (i+k) < len ; i++ ){
		Arr[i] = Arr[i+k];
	}
}