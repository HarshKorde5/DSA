#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int top = 0, bottom = n - 1, right = matrix[0].size() - 1, left = 0;

        vector<int> result;

        while(top <= bottom && left <= right){

            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main(){

    Solution s;

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> ret = s.spiralOrder(matrix);

    for(int num : ret){
        cout<<num<<"\n";
    }


    return 0;
}