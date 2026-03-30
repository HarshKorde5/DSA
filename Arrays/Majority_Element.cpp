#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{

    public :

        int majorityELement(vector<int> nums){
            int count = 0;
            int k = 0;

            for(int i = 0;i < nums.size();i++){

                if(count == 0){
                    k = nums[i];
                }

                count += (nums[i] == k) ? 1 : -1;
            }


            return k;
        }

};

int main(){

    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<s.majorityELement(nums);

    return 0;
}