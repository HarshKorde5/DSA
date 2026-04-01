/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/
#include <stdio.h>
#include "array.h"
/*
UTILITY FUNCTION: Reverse a part of the array
Used in optimal approach.
Time Complexity: O(n)
Space Complexity: O(1)
*/
void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

/*
APPROACH 1: BRUTE FORCE (Rotate one step at a time)
Idea:
- Rotate array by 1 step, k times.
- Each rotation shifts all elements.

Time Complexity: O(n * k)
Space Complexity: O(1)
*/
void rotate_01(int nums[], int n, int k) {
    k = k % n;

    for (int i = 0; i < k; i++) {
        int last = nums[n - 1];

        for (int j = n - 1; j > 0; j--) {
            nums[j] = nums[j - 1];
        }

        nums[0] = last;
    }
}

/*
APPROACH 2: BETTER (Using Extra Array)
Idea:
- Place each element at its correct rotated position:
  new[(i + k) % n] = nums[i]

Time Complexity: O(n)
Space Complexity: O(n)
*/
void rotate_02(int nums[], int n, int k) {
    k = k % n;

    int temp[n];  // extra array

    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

/*
APPROACH 3: OPTIMAL (Reverse Method)
Idea:
1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining elements

Time Complexity: O(n)
Space Complexity: O(1)
*/
void rotate(int nums[], int n, int k) {
    k = k % n;

    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
}

int main() {
    int nums1[] = {1,2,3,4,5,6,7};
    int nums2[] = {1,2,3,4,5,6,7};
    int nums3[] = {1,2,3,4,5,6,7};

    int n = 7;
    int k = 3;

    printf("Brute Force:\n");
    rotate_01(nums1, n, k);
    display(nums1, n);

    printf("Better (Extra Array):\n");
    rotate_02(nums2, n, k);
    display(nums2, n);

    printf("Optimal (Reverse Method):\n");
    rotate(nums3, n, k);
    display(nums3, n);

    return 0;
}
