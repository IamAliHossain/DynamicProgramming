/*Problem Link : https://leetcode.com/problems/house-robber/  */
// Author : Ali Hossain
// Date : 11-05-2024

/*****************Top-Down Approach (Memoization)************************/
class Solution {
public:
    int sum(int index, vector<int> &nums, vector<int> &dp){
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        
        int pick = nums[index] + sum(index - 2, nums, dp);
        int notPick = 0 + sum(index -1, nums, dp);
        int ans = max(pick, notPick);
        
        return dp[index] = ans;
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return sum(n-1, nums, dp);
    }
};

/**************** Bottom-Up (Tabulation Technique) **********************/

class Solution {
public:
    int sum(int index, vector<int> &nums, vector<int> &dp){

        dp[0] = nums[0];
        for(int i=1; i<index; i++){
            int pick = nums[i] ;
            if(i>1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[index-1];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        return sum(n, nums, dp);
    }
};





/*Below code only for dry run on my own IDE */

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;
ll ar[N], n;

vector<ll> dp1(N, -1), dp2(N);


/* Recursion Code */
ll sum(int index){

    if(index == 0)return ar[index];
    if(index < 0) return 0;

    ll pick = ar[index] + sum(index - 2);
    ll notPick = 0 + sum(index - 1);
    ll ans = max(pick, notPick);
    return ans;
}

/*Top-Down Approach (Memoization) */
ll sum1(int index){

    if(index == 0)return ar[index];
    if(index < 0) return 0;
    if(dp1[index] != -1) return dp1[index];
    ll pick = ar[index] + sum1(index - 2);
    ll notPick = 0 + sum1(index - 1);
    ll ans = max(pick, notPick);
    dp1[index] = ans;
}

/*Bottom-Up Approach (Tabulation) */
ll sum2(int index){

    // if(index == 0)return ar[index];
    // if(index < 0) return 0;
    dp2[0] = ar[0];
    for(int i=1; i<n; i++){
        ll pick = ar[i];
        if(i-2 >= 0) pick += dp2[i-2];
        ll notPick = 0 + dp2[i-1];
        dp2[i] = max(pick, notPick);
    }
    return dp2[index-1];
}


int  main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> ar[i];
    }
    // sum2(n-1);
    cout << sum2(n) << endl;
}