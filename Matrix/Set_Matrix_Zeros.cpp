#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            bool firstRowHasZero = false;
            bool firstColHasZero = false;

            int rows = matrix.size();
            int cols = matrix[0].size();

            //Check first row for zero
            for(int i = 0;i < cols;i++){
                if(matrix[0][i] == 0){
                    firstRowHasZero = true;
                    break;
                }
            }

            //check first col for zero
            for(int i = 0;i < rows;i++){
                if(matrix[i][0] == 0){
                    firstColHasZero = true;
                    break;
                }
            }


            // check other cells for zero and mark corresponding first row/col as zero
            for(int i = 1;i < rows; i++){
                for(int j = 1;j < cols; j++){
                    if(matrix[i][j] == 0){
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }


            //set row zero 
            for(int i = 1;i < rows;i++){
                if(matrix[i][0] == 0){
                    for(int j = 0;j < cols; j++){
                        matrix[i][j] = 0;
                    }
                }
            }

            //set col zero
            for(int i = 1;i < cols;i++){
                if(matrix[0][i] == 0){
                    for(int j = 0;j < rows; j++){
                        matrix[j][i] = 0;
                    }
                }
            }


            //if first row had zero set whole row to zero
            if(firstRowHasZero){
                for(int i = 0;i < cols; i++){
                    matrix[0][i] = 0;
                }
            }

            //if first col had zero set whole col to zero
            if(firstColHasZero){
                for(int i = 0;i < rows; i++){
                    matrix[i][0] = 0;
                }
            }
        }
};

int main(){

    Solution s;

    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    for(int i = 0;i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }

    s.setZeroes(matrix);

    cout<<"After \n";
    for(int i = 0;i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}