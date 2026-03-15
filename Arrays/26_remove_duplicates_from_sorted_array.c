/*
26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
*/
#include "array.h"
#include<stdio.h>

/*
Optimal approach

If the array is sorted, same elements appear together in groups.
And if we are to store only unqiue elements, that is a new value different then previously seen,
we can maintain a pointer which points to previous element saved, and another pointer iterating over each element in array.
This way we will only update previous pointer if both values mismatch, a new element found and saved.
This is a one pass solution with no extra space used.
Time Complexity : O(N)
Space Complexity : O(1)
*/
int removeDuplicates(int* nums, int numsSize) {
    int idx = 0;

    for(int i = 1; i < numsSize; i++){
        if(nums[i] != nums[idx]){
            idx++;
            nums[idx] = nums[i];
        }
    }

    return ++idx;
}

int main()
{
  int n = 0;
  printf("\nEnter the number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums, n);
  
  int ret = removeDuplicates(nums,n);
  printf("\nSize of array after removing duplicates is : %d\n",ret);
  free(nums);
  return 0;
}
