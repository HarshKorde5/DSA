/*
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 
*/

#include "array.h"
#include<stdio.h>
#include<stdlib.h>

/*
Brute Force
Try every possible pair (i, j) where j > i
Profit = prices[j] - prices[i]
Track maximum
Time Complexity : O(N ^ 2)
Space Complexity : O(1)
*/
int maxProfit_01(int* prices, int pricesSize) {
    int maxProfit = 0;

    for(int i = 0; i < pricesSize; i++) {
        for(int j = i + 1; j < pricesSize; j++) {
            int profit = prices[j] - prices[i];
            if(profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}


/*
One Pass solution
For each day we only need the minimum price before it.
So, track the minimum so far and compute profit in one pass.
Maintain:
minPrice - best buying price so far
maxProfit - best profit so far
For each day: Update min price -> Compute profit -> Update max profit

Time Complexity : O(N)
Space Complexity : O(1)
*/
int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < pricesSize; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];  // better buying price
        } else {
            int profit = prices[i] - minPrice;
            if(profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}

int main(){
   int n = 0;
  printf("\nEnter number of elements in stocks array : ");
  scanf("%d",&n);
  
  int* arr = accept(n);
  display(arr,n);
  
  int ret = maxProfit(arr, n);
  printf("\nMaximum profit is : %d\n",ret);
  
  free(arr);

  return 0;
}
