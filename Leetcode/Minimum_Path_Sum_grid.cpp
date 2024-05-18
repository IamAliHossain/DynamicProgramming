/*Problem Link : https://leetcode.com/problems/minimum-path-sum/ */
// Author : Ali Hossain
// Date : 19-05-2024

#include<bits/stdc++.h>
using namespace std;

/*****************************Solution starts From Below***********************/

/**********Top-Down Approach (Memoization)************/

class Solution {
public:
    int minPathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    
        if(i == 0 and j == 0){
            return dp[i][j] = grid[0][0];
        }
        if(i < 0 or j < 0){
            return 1e9; // since we need miminmum sum
        }
        if(dp[i][j] != -1)return dp[i][j];
        
        int left = grid[i][j] + minPathSum(i, j-1, grid, dp);
        int up = grid[i][j] + minPathSum(i-1, j, grid, dp);
        
        int ans = min(left, up);
        dp[i][j] = ans;
        
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minPathSum(n-1, m-1,grid, dp);
    }
};



/**********Bottom-Up Approach (Tabulation)************/

class Solution {
public:
    int minPathSum(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp){
    
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i > 0)left += dp[i-1][j];
                    else left += 1e9;
                    if(j > 0)up += dp[i][j-1];
                    else up += 1e9;
                    
                    dp[i][j] = min(left, up);
                } 
            }
        }
        
        return dp[n-1][m-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        return minPathSum(n, m,grid, dp);
    }
};