#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public :

        int maxProfit(vector<int>& prices){

            int buy = prices[0];
            int max = 0;

            for(int i = 0;i < prices.size();i++){

                if(buy - prices[i] > 0){
                    buy = prices[i];
                }

                if(prices[i] - buy > max){
                    max = prices[i] - buy;
                }
            }


            return max;
        }
    
};


int main(){

    Solution s;
    vector<int> prices = {7,1,5,3,6,4};

    cout<<s.maxProfit(prices);
    
    return 0;
}