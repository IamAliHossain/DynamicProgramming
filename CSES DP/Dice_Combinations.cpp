#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7 ;
int dp[1000005];

void num_of_ways(int n){
    // state 
    // dp[i] = num of ways to make sum of i

    dp[0] = 1 ;// base case
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(j <= i){
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }
    // final subproblem
    cout << dp[n] << endl;
}

int main(){
    int n ;
    cin >> n ;
    num_of_ways(n);
}