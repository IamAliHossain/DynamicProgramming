/*Problem Link : https://leetcode.com/problems/unique-paths-ii/ */

// Author : Ali Hossain
// Date : 16-05-2024

#include<bits/stdc++.h>
using namespace std;

/*Only Recursion approach will give TLE */

class Solution {
public:
    int pathWithObstacle(int i, int j, vector<vector<int>> &grid){
        if(grid[i][j] == 1){
            return 0;
        }
        if(i == 0 and j == 0){
            return 1;
        }
        int upMove = pathWithObstacle(i-1, j, grid);
        int leftMove = pathWithObstacle(i, j-1, grid);
        
        return upMove+leftMove;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return(n-1, m-1);
    }
};


/* SO to Optimize use Top-Down(Memoization) DP */

class Solution {
public:
    int pathWithObstacle(int i,int j,vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        
        if(i>=0 and j>= 0 and obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == 0 and j == 0){
            return 1;
        }
        if(i < 0 or j < 0){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        
        int upMove = pathWithObstacle(i-1, j, obstacleGrid, dp);
        int leftMove = pathWithObstacle(i, j-1, obstacleGrid, dp);
       
        return  dp[i][j] = upMove+leftMove;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return pathWithObstacle(n-1, m-1, obstacleGrid, dp);
        
    }
};


/*Next is Bottom-Up approach(Tabulation)*/

class Solution {
public:
    int pathWithObstacle(int n, int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        for(int i=0; i<n; i++){
           
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if(i == 0 and j == 0 ){
                    dp[i][j] = 1;
                }
                else{
                    int upMove = 0, leftMove = 0;
                    if(i-1>=0 ){
                        upMove = dp[i-1][j];
                    }
                    if(j-1>=0){
                        leftMove = dp[i][j-1];
                    }
                    dp[i][j] = upMove+leftMove;
                }
            }
        }
        return dp[n-1][m-1];

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        return pathWithObstacle(n, m, obstacleGrid, dp);
    }
};