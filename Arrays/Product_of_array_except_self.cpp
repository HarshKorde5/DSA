#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        //O(N2)
        vector<int> productExceptSelf1(vector<int>& nums){
            vector<int> result;

            for(int i = 0;i < nums.size(); i++){
                int product = 1;
                for(int j = 0;j < nums.size(); j++){

                    if( i == j) continue;

                    product *= nums[j];
                }

                result.push_back(product);

            }

            return result;

        }

        //prefix and suffix array
        vector<int> productExceptSelf(vector<int>& nums){

            int n = nums.size();

            vector<int> pre(n,0);
            vector<int> post(n,0);
            pre[0] = 1;
            pre[n - 1] = 1;

            

            for(int i = 1;i < n; i++){
                
                pre[i] = pre[i - 1] * nums[i - 1];
            }

            for(int j = n - 2; j >= 0;j--){
                post[j] = post[j + 1] * nums[j + 1];
            }

            vector<int> result(n,0);
            for(int i = 0;i < n;i++){
                result[i] = pre[i] * post[i];
            }

            return result;
        }


};

int main(){

    Solution s;

    vector<int> nums = {1,2,3,4};

    vector<int> ret = s.productExceptSelf(nums);
    for(int num : ret){
        cout<<num<<"\n";
    }
    return 0;
}