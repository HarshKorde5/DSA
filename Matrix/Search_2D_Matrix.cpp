#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target){
            int top = 0;
            int bottom = matrix.size() - 1;

            while(top <= bottom){
                int mid = (top + bottom) / 2;

                if(matrix[mid][0] < target && matrix[mid][matrix[mid].size() - 1] > target){
                    break;
                }else if(matrix[mid][0] > target){
                    bottom = mid - 1;
                }else{
                    top = mid + 1;
                }
            }
            int row = (top + bottom) / 2;
            int left = 0;
            int right = matrix[row].size() - 1;

            while(left <= right){
                int mid = (left + right) / 2;
                if(target == matrix[row][mid]){
                    return true;
                }else if(matrix[row][mid] > target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
                
            return false;
        }
};

int main(){

    Solution s;
    vector<vector<int>> matrix= {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    cout<<s.searchMatrix(matrix,13);

    return 0;
}