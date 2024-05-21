#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = 2e5+5;

/*
    Problem Link: https://codeforces.com/contest/1881/problem/E
    Author : Ali Hossain
    Date : 21-05-2024
*/

int ar[N];
int n;
ll del(int ind, int dp[]){

    if(ind > n){
        return n;
    }
    if(ind == n){
        return 0;
    }
    if(dp[ind] != 1e9)return dp[ind];
    ll ans = 1 + del(ind+1, dp);
    ans = min(ans, del(ind + ar[ind]+1, dp));
    dp[ind] = ans;
    return dp[ind];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>> t;
    while(t--){
        int dp[N];
        cin >> n; 
        for(int i=0; i<n; i++){
            cin >> ar[i];
            dp[i] = 1e9;
        }
        cout << del(0, dp) << endl;
    }
}