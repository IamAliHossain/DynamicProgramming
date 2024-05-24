/*Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/  */
// Author : Ali Hossain
// Date : 25-05-2024

/* 
Technique : 2D grid DP porblem where several point to start and several poinst to end as well


931. Minimum Falling Path Sum
Tag: Medium

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 
Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

*/

#include<bits/stdc++.h>
using namespace std;

/*****************Top-Down Approach (Memoization)************************/
/**********This is giving TLE but why I don't know yet, I'll fix it later*/
class Solution {
public:
    
    int minimumFallingPathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        
        if(j < 0 || j >= grid[0].size()){
            return 1e9;
        }
        if(i == 0){
            return grid[0][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + minimumFallingPathSum(i-1, j, grid, dp);
        int LeftDiagonal = grid[i][j] + minimumFallingPathSum(i-1, j-1, grid, dp);
        int RightDiagonal = grid[i][j] + minimumFallingPathSum(i-1, j+1, grid, dp);
        
        return dp[i][j] = min(up, min(LeftDiagonal, RightDiagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        for(int j=0; j<m; j++){
            mini = min(mini, minimumFallingPathSum(n-1, j, matrix, dp));
        }
        return mini;
        
    }
};

/*****************Bottom-Up Approach (Memoization)************************/
/*This is AC*/
class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        // int mini = 1e9;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiagonal = matrix[i][j];
                if(j-1 >= 0){
                     leftDiagonal += dp[i-1][j-1];
                }
                else{
                    leftDiagonal += 1e9;
                }
                int rightDiagonal = matrix[i][j];
                if(j+1 < m){
                    rightDiagonal += dp[i-1][j+1];
                }
                else{
                    rightDiagonal += 1e9;
                }
                dp[i][j] = min(up, min(leftDiagonal,  rightDiagonal));
            }
        }
        int mini = 1e9;
        for(int j=0; j<m; j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
        
    }
};
