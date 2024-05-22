/*Problem Link : https://leetcode.com/problems/triangle/ */
// Author : Ali Hossain
// Date : 23-05-2024

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
*/
#include<bits/stdc++.h>
using namespace std;

/*****************************Solution starts From Below***********************/

/********************Top-Down (Memoization) Approach***************************/

class Solution {
public:
    
    int triangleSum(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if(i == n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + triangleSum(i+1, j, triangle, dp);
        int diagonal = triangle[i][j] + triangleSum(i+1, j+1, triangle, dp);
        return dp[i][j] = min(down, diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return triangleSum(0, 0, triangle, dp);
    }
};


/********************Bottom-Up (Tabulation) Approach***************************/

class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n+5][n+5];
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        
        for(int i=n-2; i>=0; i--){
            int up = 0 , diagonal = 0;
            for(int j=i; j>=0; j--){
                int up = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(up, diagonal);
            }
        }
        return dp[0][0];
    }
};