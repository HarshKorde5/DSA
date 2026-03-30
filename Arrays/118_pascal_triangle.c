/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

#include "array.h"
#include<stdio.h>

/*
Use previous row for next row calculations.
For each cell resulting value is previous row two cells above current cell.

for numRows = 5
1
11
121
1331
14641

Time Complexity : O(N^2)
Space Complexity : O(1) {ignore result array}
*/
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;

    int** res = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // allocate row
        res[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // initialize with 1
        for (int j = 0; j <= i; j++) {
            res[i][j] = 1;
        }

        // fill middle values
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }

    return res;
}

int main()
{
  int n = 0;
  printf("\nEnter number of rows : ");
  scanf("%d", &n);
  
  int returnSize = 0; 
  int* returnColumnSizes = NULL;
  int** result = generate(n, &returnSize, &returnColumnSizes);
  
  printf("\nPascal's triangle is as follows : \n");
  for(int i = 0; i < returnSize;i++){
    for(int j = 0; j < returnColumnSize[i]; j++){
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  
  for(int i = 0; i < returnSize; i++){
    free(result[i]);
  }
  
  free(result);
  free(returnColumnSizes);
    
  return 0;
}
