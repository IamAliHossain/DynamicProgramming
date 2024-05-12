

#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    vector<int> h(n),s(n);

    for(int i=0; i<n; i++) cin>>h[i];

    for(int i=0; i<n; i++) cin>>s[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1,0));
    // base case 
    // dp[0][k] --> since i = 0 , tarmane kono lentgh e select hoy nai
    // so for any dp[0][k] = 0 

    // dp state
    // dp[i][j] = i length sub array er jonno j value niye max page count kora hobe
    // pick korle dp[i-1][j - w]
    // skip korle dp[i-1][j] hobe

    for(int i=1; i<=n; i++){

        for(int j=x; j>=0; j--){
            
            int skip = dp[i-1][j];
            dp[i][j] = skip;
            
            if(j >= h[i-1])
            {   // transition state
                int pick = dp[i-1][j-h[i-1]] + s[i-1] ;
                dp[i][j] = max (skip,pick);  
            }
        }
    }
    // final subproblem
    cout<< dp[n][x] <<endl; // n length array theke x niye max page count return korbe

    return 0;
}