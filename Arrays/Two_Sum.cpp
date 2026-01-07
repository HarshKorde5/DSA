#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums,int target){
            for(int i = 0;i < nums.size();i++){
                for(int j = i + 1; j < nums.size();j++){
                    if(nums[j] == target - nums[i]){
                        return {i,j};
                    }
                }
            }

            return {};
        }


        vector<int> twoSumHash(vector<int>& nums, int target){
            unordered_map<int, int> hash;

            for(int i = 0;i < nums.size(); i++){
                int complement = target - nums[i];

                if(hash.find(complement) != hash.end()){
                    return {hash[complement], i};
                }

                hash[nums[i]] = i;
            }

            return {};
        }
};


int main(){

    vector<int> nums = {2,7,11,15};
    Solution s;
    vector<int> ret = s.twoSumHash(nums, 9);

    for(int i = 0;i < ret.size(); i++ ){
        cout<<ret[i]<<"\n";
    }
    return 0;
}