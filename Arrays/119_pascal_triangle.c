/*
119. Pascal's Triangle II
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/
#include <stdio.h>
#include <stdlib.h>

/*
Approach: Brute Force
- Build entire Pascal's Triangle up to rowIndex
- Return the last row
Time Complexity: O(n^2)
Space Complexity: O(n^2)
(Not optimal for follow-up)
*/

int* getRow_01(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int** triangle = (int**)malloc((rowIndex + 1) * sizeof(int*));

    for (int i = 0; i <= rowIndex; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));

        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    return triangle[rowIndex];
}

#include <stdio.h>
#include <stdlib.h>

/*
Approach: In-place DP (1D Array)
- Use a single array and update from right to left
- Avoid overwriting needed values
Time Complexity: O(n^2)
Space Complexity: O(n)  <-- satisfies follow-up
*/

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int* row = (int*)malloc((*returnSize) * sizeof(int));

    for (int i = 0; i <= rowIndex; i++) {
        row[i] = 0;
    }

    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

int main() {
    int rowIndex = 5;
    int size;

    int* result = getRow(rowIndex, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
