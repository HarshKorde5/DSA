/*
33. Search in Rotated Sorted Array
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include "array.h"
#include<stdio.h>

/*
Binary search

Linear way is also possible but,
As we have the input array in a specific order (sorted and rotated), we can directly make jumps based on values.
Slight modification is :
If target value is between low - mid we shift high to mid - 1
If target value is between mid - high we shift low to mid + 1

So only extra checks for target value and that's it with same binary search for rest.

Time Complexity : O(N)
Space Complexity : O(1)
*/

int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
  int n = 0;
  printf("\nEnter number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums,n);
  
  int target = 0;
  printf("\nEnter target value : ");
  scanf("%d",&target);
  
  int ret = search(nums, n, target);
  
  printf("\nTarget element is at pos %d\n", ret);
  
  free(nums);
  return 0;
}
