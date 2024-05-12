#include<bits/stdc++.h>
using namespace std;

// vector<int> digit ;
// using function sol
// int count_num_op(int n){
//     int cnt = 0;
//     while(n > 0){
//         int tem = n ;
//         while(tem > 0){
//             int rem = tem % 10 ;
//             digit.push_back(rem);
//             tem /= 10 ;
//         }
//         sort(digit.rbegin(), digit.rend());
//         n -= digit[0];
//         digit.clear();
//         cnt++;
//     }
//     return cnt ;
// }

int main(){

    int n ; cin >> n ;
    vector<int> dp(n+1, 1e9) ;
    // base case 
    dp[0] = 0 ;

    for(int i=1; i<=n; i++){
        int tem = i ;
        while(tem > 0){
            int digit = tem % 10;
            tem /= 10 ;
            // transition state
            dp[i] = min(dp[i], 1+dp[i-digit]);
        }
    }
    // final state
    cout << dp[n] << endl;
}