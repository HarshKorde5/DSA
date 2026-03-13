
/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include "array.h"
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 200003
/*
Brute Force
We essentially check for each index i, is there an element equal to it in the array.
This give Time Complexity of O(N^2), due to nested traversal for each iteration.
*/
bool contains_duplicate_01(int* nums, int numssize)
{
  for(int i = 0; i < numssize; i++)
  {
    for(int j = i + 1; j < numssize; j++)
    {
      if(nums[i] == nums[j]){
        return true;      
      }
    }
  }
  
  return false;
}

/*
Sorting approach
We introduce sorting in this approch.
What sorting does to array is bring all same elements together,
so if any duplicate element is there in array, 
adjacent elements would be same.
We use this observation to detect the duplicate element.
Time complexity : O(N * LOG N)
    Sorting -> O(N *Log N) 
    Iterating through array -> O(N)
*/
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool contains_duplicate_02(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }

    return false;
}

/*
Hash Set
Instead of comparing with everyone and sorting before searching for duplicate, we can use previously seen data.
The Hash Set will store the seen elements in array as we traverse it.
If the new element is already present in set, it denotes reoccurence of same element, which is duplicate.

Time Complexity : O(N)
Space Complexity : O(N) -> For hash set, auxiliary space used.
*/

bool contains_duplicate(int* nums, int numsSize) {

    int* table = calloc(TABLE_SIZE, sizeof(int));

    for(int i = 0; i < numsSize; i++) {

        int key = abs(nums[i]) % TABLE_SIZE;

        while(table[key] != 0) {
            if(table[key] == nums[i])
                return true;

            key = (key + 1) % TABLE_SIZE;
        }

        table[key] = nums[i];
    }

    free(table);
    return false;
}

int main()
{
  int n = 0;
  printf("Enter the number of elements in array : ");
  scanf("%d", &n);
  
  int *arr = accept(n);
  display(arr, n);
  
  bool check = contains_duplicate(arr, n);
  
  if(check == true)
  {
    printf("Array contains duplicate element...\n");
  }
  else
  {
    printf("Array does not contain duplicate element...\n");
  }
  
  free(arr);
  
  return 0;
}
