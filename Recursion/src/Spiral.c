/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .
 
*/


#include <stdio.h>
#include <stdlib.h>

void find_result_array(int *result_array,int rows, int cols, int start_row, int start_col, int *input_array, int length);

int *spiral(int rows, int columns, int **input_array)
{
	int *result_array = NULL;

	if(rows * columns){
		result_array = (int*)calloc(rows*columns, sizeof(int));
		find_result_array(result_array, rows, columns, 0, 0,  input_array, rows*columns - 1);
		return result_array;
	}
	return NULL;
}

void find_result_array(int *result_array, int rows, int cols, int start_row, int start_col, int *input_array, int length){
	static int writer = 0;

	if(writer > (length)){
		return ;
	}
	else{
		int walker_row = start_row;
		int walker_col = start_col;

		//move Right
		{
			printf("Moving Right\n" );
			int end_col = cols - start_col;
			while(walker_col < end_col){
				result_array[writer++] = input_array[(walker_row)*(cols) + walker_col];
				printf("walker_row = %d, alker_col = %d, end_col = %d,written = %d \n",walker_row, walker_col, end_col, result_array[writer-1]);
				walker_col++;
			}
			walker_col--;
		}

		//move Down
		{
			printf("Moving Down\n" );
			int end_row = rows - start_row;
			walker_row++;
			while(walker_row < end_row){
				result_array[writer++] = input_array[(walker_row)*(cols) + walker_col];
				printf("walker_row = %d,walker_col =%d, end_row = %d, written = %d\n", walker_row,walker_col, end_row, result_array[writer-1]);
				walker_row++;
			}
			walker_row--;
		}

		//move Left
		{
			printf("Moving Left\n");
			int end_col = start_col;
			walker_col--;
			while(walker_col >= end_col){
				result_array[writer++] = input_array[(walker_row)*(cols) + walker_col];
				printf("walker_row = %d,walker_col = %d, end_col = %d,written = %d \n",walker_row, walker_col, end_col, result_array[writer-1]);
				walker_col--;
			}
			walker_col++;
		}

		//move Up
		{
			printf("Moving Up\n" );
			int end_row = start_row;
			walker_row--;
			while(walker_row > end_row){
				result_array[writer++] = input_array[(walker_row)*(cols) + walker_col];
				printf("walker_row = %d,walker_col = %d, end_row = %d, written = %d\n", walker_row,walker_col, end_row, result_array[writer-1]);
				walker_row--;
			}
			walker_row++;
		}

		//Recursion
		find_result_array(result_array, rows, cols, start_row+1, start_col+1, input_array, length);
	}
}

//Test Driver
int main(int argc, char const *argv[]) {
	int arr[4][4] = {{1,2,3,4}, {4,5,6,7}, {7, 8, 9,5}, {12,34,5,67}};
	int * result_array = spiral(4, 4, arr);
	int i;
	for(i = 0; i < 16 ; i++){
		printf("%d, ", result_array[i]);
	}
	return 0;
}
