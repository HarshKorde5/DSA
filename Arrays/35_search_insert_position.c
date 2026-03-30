/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
#include "array.h"
#include<stdio.h>
/*
Binary search
Basic binary search can be implemented to search for target element in a faster way.
Time complexity : O(N * log * N)
Space complexity : O(1)
*/
int searchInsert(int* nums, int numsSize, int target) {
    int low = 0;
    int high = numsSize - 1;

    while(low <= high){
        int mid = (high + low) / 2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            high = mid -1;
        }else{
            low = mid + 1;
        }        
    }

    return low;
}

/*
Brute force
Linear search can be implemented.
Search for element equal to target or element greater than target.
Return the index if found else return the previous index of the greater element which will be the insert position.
Time Complexity : O(N)
Space Complexity : O(1)
*/
int searchInsert_01(int* nums, int numsSize, int target) {
    
  int i = 0;
  for(i = 0; i < numsSize; i++){
    if(nums[i] == target){
      return i;
    }
    if(nums[i] > target){
      return (i - 1);
    }
  }
  
  return numsSize;
}

int main()
{
  int n = 0;
  printf("\nEnter number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums,n);
  
  int target = 0;
  printf("\nEnter target  : ");
  scanf("%d",&target);
  
  int ret = removeElement(nums, n, target);
  
  printf("\nIndex for target %d is %d\n",target, ret); 
  
  free(nums);
  return 0;
}
