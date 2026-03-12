/*
Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

*/

#include "array.h"
#include<stdio.h>
#include<stdbool.h>

/*
Brute force approach
For brute force approach we can check if by rotating array by one element each time results in a sorted array.
If a sorted array is found at any rotation final result will be true else false after last iteration.
As we need to check each array once for rotating O(N),
and again same time checking for sorted array O(N)

This gives us the time complexity of O(N^2) : Which is not good..
*/
bool check_sorted_asc(int* nums, int numssize)
{
  bool flag = true;
  for(int i = 0; i < numssize - 1; i++)
  {
    if(nums[i] > nums[ i + 1])
    {
      flag = false;
      break;
    }
  }
  return flag;
}

void rotate_array(int* nums, int numssize)
{
  int firstelement = nums[0];
  for(int i = 1; i < numssize; i++)
  {
    nums[i - 1] = nums[i];
  }
  nums[numssize - 1] = firstelement;
}

bool check_if_array_is_sorted_and_rotated_01(int* nums, int numssize)
{
  bool check = false;
  for(int i = 0; i < numssize; i++)
  {
    rotate_array(nums,numssize);
    
    check = check_sorted_asc(nums, numssize);
    
    if(check == true)
    {
      break;
    }
  }
  
  return check;
}

/*
Optimal approach
As per the question description, it is only allowed to have one index in array such that,
Elements are sorted once again from that index in the remaining array.

Example : 4,5,6,1,2,3 
Here upto element '5' array was sorted, looks fine.
Again from element '1' rest array is also sorted, results true.
Count for current element greater than next element is only 1, satisfies our condition.

Example : 5,6,7,8,1,4,2
Here upto element '8' array was sorted, looks fine.
But from 1 array is not sorted till last index.
Count for element greater than next element becomes 2, which contradicts our condition.
*/
bool check_if_array_is_sorted_and_rotated(int* nums, int numssize)
{
  int count = 0;
  for(int i = 0; i < numssize - 1; i++)
  {
    if(nums[i] > nums[i + 1]){
      count++;
    }
  }
  
  return count <= 1;
}

int main()
{ 
  int arrsize = 0;
  printf("Enter number of elements in array : \n");
  scanf("%d", &arrsize);
  
  int* arr = accept(arrsize);
  display(arr, arrsize);
  
  //bool check = check_if_array_is_sorted_and_rotated_01(arr, arrsize);

  bool check = check_if_array_is_sorted_and_rotated(arr, arrsize);
  
  if(check == true)
  {
    printf("Array was sorted and rotated...\n");
  }
  else
  {
    printf("Array was not sorted nor rotated...\n");
  }
  
  free(arr);
  
  return 0;
}

