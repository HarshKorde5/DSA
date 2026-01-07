#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int numIslands(vector<vector<char>>& grid) {
            int numIslands = 0;

            int m = grid.size();
            int n = grid[0].size();

            vector<pair<int,int>> directions = {{1,0},{-1,0}, {0,1},{0,-1}};

            vector<vector<int>> visited(m, vector<int>(m, 0));


            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    if(grid[i][j] == '1' && !visited[i][j]){
                        numIslands++;

                        queue<pair<int,int>> q;
                        q.push({i,j});


                        while(!q.empty()){
                            auto [x,y] = q.front();
                            q.pop();


                            if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1'){
                                continue;
                            }

                            visited[x][y] = 1;   //mark as visited
                            // grid[x][y] = '0'; // mark as visited directly modify the grid no need of extra visited grid


                            for(auto& dir : directions){
                                int nx = x + dir.first;
                                int ny = y + dir.second;

                                if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1' && !visited[nx][ny]){
                                    q.push({nx, ny});
                                    visited[nx][ny] = 1;
                                }
                            }

                        }
                    }
                }
            }
            return numIslands;
        }
};

int main(){
    Solution s;
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout<<s.numIslands(grid);

    return 0;
}