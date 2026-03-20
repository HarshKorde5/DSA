/*
66. Plus One

You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
*/

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
#include<stdlib.h>

/*
Optimal approach
Simple observation only.
If we're supossed to add one to the existing number,
Ideal approach is checking from the back of array.
Consider the number 1988
Over here even if 9 is present in the number, as it's not present at the one's place it won't increse the number of digits by any chance.
This is because adding +1 to any integer below 9 generates a single integer even 8 , 8 + 1 = 9 which is still a single digit.
But if the number was suppose 1239
Then 9 + 1 = 10 so we place the 0 from 10 and carry on 1 after this operation moving to 3 is adding a +1 to it which was the carry itself and carry is zero, nothing to add further so size still didn't change.

Consider 99 : for 99 first we convert ones place to 0 and carry on the +1, then the tens place to 0 and carry on the 1, at last elements are finished still we have a carry, this means size of array needs to be increased and returned.
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] < 9){
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }

    int* ret = (int*)calloc(sizeof(int),digitsSize+1);
    ret[0] = 1;
    *returnSize = digitsSize + 1;
    return ret;
}

int main()
{
  int n = 0;
  printf("\nEnter number of elements in array : ");
  scanf("%d",&n);
  
  int* nums = accept(n);
  display(nums,n);
  int retSize = 0;
  
  int* ret = removeElement(nums, n, &retSize);
  display(ret, retSize);
  free(nums);
  return 0;
}
