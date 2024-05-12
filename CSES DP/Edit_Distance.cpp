#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base:: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s,t; cin >> s >> t ;
    
    int n = s.size() ;
    int m = t.size() ;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e6));
    // dp state
    // dp[i][j] = required steps to match 1st i characters form S with 1st j characters from t

    // base case
    // dp[i][0] = i, dp[0][j] = j that means dp[0][0] = 0 ;

    for(int i=0; i<=n; i++){
        dp[i][0] = i ;
        // first string has remaining i characters
        // and second string is finished
    }
    for(int j=0; j<=m; j++){
        dp[0][j] = j ;
        // second string has remaining j characters
        // and first string is finished
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // transition state
            if(s[i-1] == t[j-1]){ // no operation required here
                dp[i][j] = dp[i-1][j-1]; 
            }
            else{ // replace character to match
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            /*finding minimum operation */

            // skip the ith char or add a char after jth char
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); 

            // skip the jth char or add a char after ith char
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); 
        }
    }
    // final subproblem
    cout << dp[n][m] << endl;

    return 0 ;
} 