/*
53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

#include "array.h"
#include<stdio.h>
#include<limits.h>

/*
Kadane's algorithm
Main idea behind this algo is that, Negative prefix will only reduce future sum.
So whenever current sum goes down the current value, or inshort if sum is going negative we restart sum with current element value and only calculate further.
Time Complexity : O(N)
Space Complexity : O(1)
*/
int maxSubArray(int* nums, int numsSize)
{
  int maxSum = nums[0];
  int currentSum = nums[0];

  for (int i = 1; i < numsSize; i++) {
      if (currentSum + nums[i] > nums[i]) {
          currentSum = currentSum + nums[i];
      } else {
          currentSum = nums[i];
      }

      if (currentSum > maxSum) {
          maxSum = currentSum;
      }
  }

  return maxSum;

}

/*
Running subarray sum : Brute Force
Slight optimization in previous approach would be keeping track of current sum every time.
Keep a running sum for subarray [i -> j]
sum(i -> j) = sum(i -> j-1) + nums[j]
Time Complexity : O(N^2)
Space Complexity : O(1)
*/
int maxSubArray_02(int* nums, int numsSize)
{
    int maxSum = INT_MIN;
    
    for(int i = 0; i < numsSize; i++)
    {
      int sum = 0;
      for(int j = i; j < numsSize; j++)
      {       
          sum += nums[j];
          if(maxSum < sum)
          {
            maxSum = sum;
          }
      }
    }
    
    return maxSum;
}

/*
Brute Force
Most basic way would be checking each subarray and its sum with maximum subarray sum achieved till now.
Time complexity : O(N^3)
Space complexity : O(1)
*/
int maxSubArray_01(int* nums, int numsSize) 
{
    int maxSum = INT_MIN;
    
    for(int i = 0; i < numsSize; i++)
    {
      for(int j = i; j < numsSize; j++)
      {
        int sum = 0;
        for(int k = i; k <= j; k++)
        {
          sum += nums[k];
        }
        if(maxSum < sum){
          maxSum = sum;
        }
      }
    }
    
    return maxSum;
}

int main()
{
  int n = 0;
  printf("\nEnter number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums,n);
  
  int ret = maxSubArray(nums, n);
  
  printf("\nMaximum subarray sum in the array is : %d\n", ret);
  free(nums);
  return 0;
}
