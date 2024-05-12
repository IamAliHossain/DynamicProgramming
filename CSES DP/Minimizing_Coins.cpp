#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n , x; cin >> n >> x; 
    int a[n+5]; 
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> dp(x+1, 1e9);
    // dp[i] = min coins to generate sum of i

    // base case 
    dp[0] = 0 ;
    for(int i=1; i<=x; i++){
        // find dp[x] 
        for(int j=0; j<n; j++){
            if(a[j] <= i){
                // transition
                dp[i] = min(dp[i], dp[i-a[j]] + 1) ;
            }
        }
    }
    // final subproblem
    cout << (dp[x] < 1e9 ? dp[x]:-1) << endl;
}