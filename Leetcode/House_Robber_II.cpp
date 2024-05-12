/*Problem Link : https://leetcode.com/problems/house-robber-ii/ */
// Author : Ali Hossain
// Date : 12-05-2024
#include<bits/stdc++.h>
using namespace std;

/*****************************Solution starts From Below***********************/

class Solution {
public:
    
    int sum1(int index, vector<int> &ar, vector<int> &dp1){
        if(index == 0) return ar[index];
        if(index < 0) return 0;
        
        if(dp1[index] != -1) return dp1[index];
        int pick = ar[index] + sum1(index-2, ar, dp1);
        int notPick = 0 + sum1(index - 1, ar, dp1);
        return dp1[index] = max(pick, notPick);
    }
    
    int sum2(int index, vector<int> &ar, vector<int> &dp2){
        if(index == 0) return ar[index];
        if(index < 0) return 0;
        
        if(dp2[index] != -1) return dp2[index];
        int pick = ar[index] + sum2(index-2, ar, dp2);
        int notPick = 0 + sum2(index - 1, ar, dp2);
        return dp2[index] = max(pick, notPick);
    }
    int ans(int index, vector<int> &ar1, vector<int> &ar2, vector<int> &dp1, vector<int> &dp2){
        int x = sum1(index, ar1, dp1);
        int y = sum2(index, ar2, dp2);
        return max(x, y);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n-1, -1),dp2(n-1, -1), tem1, tem2;
        for(int i=0; i<n-1; i++){
            tem1.push_back(nums[i]);
        }
        for(int i=1; i<n; i++){
            tem2.push_back(nums[i]);
        }
        n--;
        return ans(n-1, tem1, tem2, dp1, dp2);
    }
};