#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7 ;

int main(){
    int n , x ; cin >> n >> x;
    int a[n+4];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> dp(x+1);
    // dp[i] = no of ways to generate sum of i 
    
    // base case 
    dp[0] = 1 ;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(a[j] <= i){
                // transition
                dp[i] = (dp[i] + dp[i-a[j]]) % MOD ;
            }
        }
    }
    // final subproblem 
    cout << dp[x] << endl;
}