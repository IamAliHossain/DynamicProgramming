#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7 ;

int main(){
    ios_base:: sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n , x; cin >> n >> x ;
    int a[n+5];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<vector<int> > dp(n+1, vector<int>(x+1));
    // int dp[n+5][x+5]; // show error with this one but don't know why -_-

    /* dp[i][k] = no of ways to generate sum of k such that
     all coins from a[i] are pickable and all coins from a[i] are skipped before a[i]
     */

    // base case
    for(int i=0; i<=n; i++){
        dp[i][0] = 1 ;
    }

    for(int i=n-1; i>=0; i--){
        for(int sum=1; sum<=x; sum++){
            int skipped = dp[i+1][sum] ;
            int picking = 0 ;
            if(a[i] <= sum){
                // transition
                picking = dp[i][sum-a[i]];
            }
            dp[i][sum] = (picking + skipped) % mod;
        }
    }
    // final subproblem
    cout << (dp[0][x]) << endl;
}