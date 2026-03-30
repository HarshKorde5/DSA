/*
27. Remove Element
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/

#include "array.h"
#include<stdio.h>

/*
Optimal approach
Best way is to maintain the insert index (idx) for whole array and only add the elements who are not equal to target values.
Time complexity : O(N)
Space complexity : O(1)
*/
int removeElement(int* nums, int numsSize, int val)
{
    int idx = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[idx] = nums[i];
            idx++;
        }
    }

    return idx;
}

int main()
{
  int n = 0;
  printf("\nEnter number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums,n);
  
  int val = 0;
  printf("\nEnter value to remove from array : ");
  scanf("%d",&val);
  
  int ret = removeElement(nums, n, val);
  
  printf("Array after removing all %d : ", val);
  display(nums, n);
  
  free(nums);
  return 0;
}
