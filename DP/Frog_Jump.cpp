
/*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_a*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+5;
int ar[N];


/*Simple Recursive solution, but it gives TLE cause, it has 0(2^n) complexity*/
ll frogJump1(int index){

    if(index == 0)return 0;
    int left = frogJump1(index - 1) + abs(ar[index] - ar[index - 1]);
    int right = INT_MAX;
    if(index > 1)right = frogJump1(index - 2) + abs(ar[index] - ar[index-2]);
    return min(left, right);
}

/*To reduce Overlapping use DP(2 approaches below) now */

/*Top-Down approach (Memoization Technique)*/
vector<int> dp(N, -1);
ll frogJump2(int index){

    if(index == 0)return 0;
    if(dp[index] != -1) return dp[index];

    int left = frogJump2(index-1) + abs(ar[index] - ar[index - 1]);
    int right = INT_MAX;
    if(index > 1)right = frogJump2(index-2) + abs(ar[index] - ar[index - 2]);

    return dp[index] = min(left, right);
}


/*Bottom-Up approach (Tabulatioon Technique)*/
vector<int> dp1(N);
void frogJump3(int len){
    dp1[0] = 0;
    for(int i=1; i<len; i++){
        int left = dp1[i-1] + abs(ar[i] - ar[i-1]);
        int right = INT_MAX;
        if(i > 1)right = dp1[i-2] + abs(ar[i] - ar[i-2]);
        dp1[i] = min(left, right);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>> n;
    
    for(int i=0; i<n; i++)cin >> ar[i];
    frogJump1(n-1);
    frogJump2(n-1);
    frogJump3(n);
    cout << dp[n-1] << endl;
}