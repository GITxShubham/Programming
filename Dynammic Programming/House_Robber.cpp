// Leetcode 198. 
// Problem Statement: https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;



// Method 1: Using Memorization

// class Solution {
// public:
//     int helper(vector<int>& nums , vector<int>& dp , int n){
//         if(n==0) return nums[0];
//         if(n<0) return 0;
//         if(dp[n] != -1) return dp[n];
//         int pick = nums[n] + helper(nums,dp,n-2);
//         int notpick = 0 + helper(nums,dp,n-1);
//         return dp[n] = max(pick,notpick);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n,-1);
//         return helper(nums,dp,n-1);
//     }
// };



// Method 2 : Using Tabulation Method

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2 ; i < n ;i++){
            int pick = nums[i] + dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
};