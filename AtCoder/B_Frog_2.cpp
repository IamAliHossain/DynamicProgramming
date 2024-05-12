#include<bits/stdc++.h>
using namespace std;

/* Problem Link : https://atcoder.jp/contests/dp/tasks/dp_b */

typedef long long ll ;
const int N = 1e5+5;

int n, k; 
int ar[N];
vector<int> dp(N, -1);

/*Recursive Technique it will give TLE cause TC--> 0(k^n)*/
ll jumpCost(int index){

    if(index == 0) return 0;
    
    ll cost = INT_MAX;
    for(int i=1; i<=k; i++){ 
        if(index -i >= 0){
             cost = min(cost,(jumpCost(index-i) + abs(ar[index] - ar[index - i])));   
        }
    }
    return cost;
}

// /* Top-Down approach (Memoization Technique)*/

ll jumpCost1(int index){

    if(index == 0) return 0;
    if(dp[index] != -1) return dp[index];

    ll cost1 = INT_MAX;
    for(int i=1; i<=k; i++){ 
        if(index - i >= 0){
            if(dp[index] == -1){
                ll jump = jumpCost1(index-i) + abs(ar[index] - ar[index - i]);
                cost1 = min(cost1, jump);
            }
            else return dp[index];
        }
    }
    return dp[index] = cost1;
}

/*Bottom-Up approach (Tabulation Technique)*/

vector<int> dp1(N);
void jumpCost2(int n){

    dp1[0]=0;
    for(int i=1; i<=n; i++){
        int jump= 0, mn = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j >= 0 ){
                jump = dp1[i-j] + abs(ar[i] - ar[i-j]);
                mn = min(mn, jump);
            }
        }
        dp1[i] = mn;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++)cin >> ar[i];
    // jumpCost(n-1);
    // cout << jumpCost(n-1) << endl;
    // jumpCost1(n-1);
    // cout << dp[n-1] << endl;

    jumpCost2(n);
    cout << dp1[n-1] << endl;

}