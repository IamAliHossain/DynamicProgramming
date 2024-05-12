#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 1e6+1;
vector<vector<int>> dp(N, vector<int> (2));

int main(){
    int t ; cin >> t ;
    while(t--){
        int n; cin >> n;
        // dp state
        // dp[i][0] = where horizontal cell totaly block
        // dp[i][1] = horizontal block trying to extend vertically

        /* dp[i][0] or dp[i][1] means that no. of ways to build grid
                from ith cell to i+1 th cell
        */
        
        // base case 
        dp[n][0] = dp[n][1] = 1;

        for(int i=n-1; i>=1; i--){
            // transition state
            dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1]) % mod;
            dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0]) % mod;
        }
        // final subproblem
        int ans = (dp[1][0] + dp[1][1] ) % mod ;
        cout << ans << endl;
    }
}