/*Problem Link : https://leetcode.com/problems/unique-paths/ */

/* Only Recursion this will give TLE */
int paths(int i, int j){
    if(i == 0 and j == 0){
        return 1;
    }
    if(i < 0 or j < 0){
        return 0;
    }
    int upMove = paths(i-1, j);
    int leftMove = paths(i, j-1);

    return upMove + leftMove;
}

/*Since there are overlapping subproblems so need Memoization (Top-Down)*/

class Solution {
public:
    
    int path(int i, int j, vector<vector<int>> &dp){
        if(i == 0 and j == 0){
            return 1;
        }
        if(i < 0 or j < 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int upMove = path(i-1, j, dp);
        int leftMove = path(i, j-1, dp);
        
        return dp[i][j] = upMove+leftMove;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return path(m-1, n-1, dp);
    }
};


/*Bottom-Up Approach(Tabulation)*/

class Solution {
public:
    
    int path(int m, int n, vector<vector<int>> &dp){
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i-1 >=0 ){
                    dp[i][j] += dp[i-1][j];
                }
                if(j-1 >=0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        
        
        return dp[m-1][n-1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return path(m, n, dp);
    }
};