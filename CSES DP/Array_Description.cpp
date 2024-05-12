#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

bool valid(int x, int m){
    return x>=1 and x<=m ;
}

int main(){
    int n, m ; cin >> n >> m ;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];  
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    // dp state
    // dp[i][k] = prefix of length i and last element is k return num of way to
    // generate array
    
    // base case 
    // dp[1][k] = 1, if a[0] = k or a[0] = 0, k = k mane hocce a[0]> 0 so eita change kora possible na
    // a[0] = 0 hoile a[0] = 1 kora possible only , that's why dp[1][k] = 1 only

    for(int k=1; k<=m; k++){
        if(a[0] == 0 or a[0] == k){
            dp[1][k] = 1;
        }
    }

    for(int i=2; i<=n; i++){
        for(int k = 1; k<=m; k++){
            // finding dp[i][k] here
            if(a[i-1] != 0 and a[i-1] != k){
                dp[i][k] = 0 ;
                continue;
            }
            for(int prev = k-1; prev<=k+1; prev++){
                
                // transition state
                dp[i][k] = (prev >= 1 and prev <= m ? (dp[i][k] + dp[i-1][prev]) % mod : dp[i][k]);

            }
        }
    }
    int ans = 0 ;
    for(int i=1; i<=m; i++){
        ans = (ans + dp[n][i]) % mod;
    }
    // final subproblem
    cout << ans << endl;
    
    
}