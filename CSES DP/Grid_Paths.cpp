#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n ; cin >> n ;
    string s[n+1];
    for(int i=0; i<n; i++)cin >> s[i];

    vector<vector<int>> dp(n, vector<int> (n));

    // base case
    if(s[n-1][n-1] == '.')
        dp[n-1][n-1] = 1;
    else
        dp[n-1][n-1] = 0 ;
    
    // dp state --> dp[i][j] = no of ways to go from (i,j) to (n-1, n-1) cell

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == n-1 and j == n-1){
                continue;
            }
            // transition state
            if(s[i][j] == '*'){
                dp[i][j] = 0 ;
            }
            else{
                int move1 = i < n-1 ? dp[i+1][j] : 0 ;
                int move2 = j < n-1 ? dp[i][j+1] : 0 ;
                dp[i][j] = (move1 + move2 ) % MOD ;
            }
        }
    }
    // final subproblem
    cout << dp[0][0] << endl; // (0,0) to (n-1, n-1) cell e jabar total ways.
}