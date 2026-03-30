/*
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
#include "array.h"
#include<stdio.h>

/*
Optimal Solution
We traverse from end of both arrays and sort in reverse order as the structure of first array is given so.
whichever is the larger element gets placed at the end of array.
Time complexity : O(N)
Space complexity : O(1)
*/

void merge(int* A, int as, int m, int* B, int bs, int n) {
    int i = m - 1;
    int j = n - 1;
    int last = m + n - 1;

    while(j >= 0){
        if(i >= 0 && A[i] > B[j]){
            A[last] = A[i];
            i--;
        }else{
            A[last] = B[j];
            j--;
        }

        last--;
    }
}

int main()
{
int m, n;

    printf("\nEnter number of elements in first array: ");
    scanf("%d", &m);

    int* tempA = accept(m);   // only m elements
    printf("First array:\n");
    display(tempA, m);

    printf("\nEnter number of elements in second array: ");
    scanf("%d", &n);

    int* B = accept(n);
    printf("Second array:\n");
    display(B, n);

    // Create A with size m + n
    int* A = (int*)malloc((m + n) * sizeof(int));

    // Copy tempA into A
    for (int i = 0; i < m; i++) {
        A[i] = tempA[i];
    }

    // Fill remaining with 0
    for (int i = m; i < m + n; i++) {
        A[i] = 0;
    }

    // Merge
    merge(A, m + n, m, B, n, n);

    // Display result
    printf("\nMerged array:\n");
    display(A, m + n);

    // Free memory
    free(tempA);
    free(A);
    free(B);

    return 0;

}
